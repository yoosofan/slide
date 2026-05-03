/ ====================================================================
/ YIC 90 KERNEL (Firmware)
/ Hardware: Physical Addressing (MODE = 0)
/ ====================================================================
        ORG     0
        BUN     BOOT          / CPU starts here at power-on
        BUN     ISR           / Hardware Interrupts jump here (Addr 1)

/ --- System Call Entry Point (Entered via RTK) ---
        ORG     030
        HEX     0             / RTK saves User's logical PC here
        BUN     SYSCALL       / Hardware jumps here after RTK saves PC

/ --- OS Boot and Loader ---
BOOT,   CLA                   / Initialize Kernel Flags
        STA     IN_READY
        STA     OUT_READY
        ION                   / Enable Interrupts

        / Step 1: Read Program Size from Card Reader
L_GETSZ,LDA     IN_READY
        SZA
        BUN     L_HAVE_SZ
        BUN     L_GETSZ
L_HAVE_SZ,LDA   IN_BUFFER
        STA     PROG_SIZE
        CLA
        STA     IN_READY      / Clear flag for next byte

        LDA     PROG_PHYS     / Start loading at physical 500
        STA     PTR

        / Step 2: Load User Program Bytes
L_LOOP, LDA     PROG_SIZE
        SZA                   / If Size == 0, loading is finished
        BUN     L_READ
        BUN     L_RUN
L_READ, LDA     IN_READY
        SZA
        BUN     L_STORE
        BUN     L_READ
L_STORE,LDA     IN_BUFFER
        STA     PTR I         / Store in physical RAM
        ISZ     PTR
        CLA
        STA     IN_READY
        LDA     PROG_SIZE
        ADD     M_ONE         / PROG_SIZE--
        STA     PROG_SIZE
        BUN     L_LOOP

        / Step 3: Jump to User Program
L_RUN,  LDA     PROG_BASE
        ATB                   / Set Base Register = 500
        CLA                   / User program starts at logical 0
        STA     0             / Put "0" in M[0] to fool RTI
        RTI                   / Atomic: PC=M[0], MODE=1, IEN=1

/ --- Syscall Handler ---
SYSCALL,SZA                   / Check AC for command
        BUN     SC_CHECK
        BUN     BOOT          / AC=0: Exit (Reload Loader)

SC_CHECK,ADD    M_ONE         / Subtract 1
        SZA                   / If result 0, AC was 1
        BUN     SC_WRITE

        / Syscall 1: Read
        ION
W_IN,   LDA     IN_READY
        SZA
        BUN     RD_DONE
        BUN     W_IN
RD_DONE,LDA     PROG_PHYS     / Point to User's Mailbox (500 + 10)
        ADD     MAIL_OFF
        STA     PTR
        LDA     IN_BUFFER
        STA     PTR I         / Move data to User Space
        CLA
        STA     IN_READY
        BUN     SC_RET

SC_WRITE, / Syscall 2: Write
        LDA     PROG_PHYS
        ADD     MAIL_OFF
        STA     PTR
        LDA     PTR I         / Get data from User Space
        STA     OUT_BUFFER
        LDA     ONE
        STA     OUT_READY
        ION                   / Let ISR handle actual OUT
W_OUT,  LDA     OUT_READY
        SZA
        BUN     W_OUT         / Wait for ISR to clear it

SC_RET, IOF
        LDA     030           / Get User's logical return address
        STA     0             / Move to M[0]
        RTI                   / Return to User Space!

/ --- Interrupt Service Routine ---
ISR,    STA     SAVE_AC
        CIL
        STA     SAVE_E
        SKI
        BUN     I_OUT
        INP
        STA     IN_BUFFER
        LDA     ONE
        STA     IN_READY
I_OUT,  SKO
        BUN     I_END
        LDA     OUT_READY
        SZA
        BUN     I_DO_OUT
        BUN     I_END
I_DO_OUT,LDA    OUT_BUFFER
        OUT
        CLA
        STA     OUT_READY
I_END,  LDA     SAVE_E
        CIR
        LDA     SAVE_AC
        ION
        RTI

/ --- Kernel Data ---
ONE,       DEC 1
M_ONE,     DEC -1
PROG_PHYS, HEX 500
PROG_SIZE, DEC 0
PTR,       HEX 0
MAIL_OFF,  HEX 010
IN_READY,  DEC 0
IN_BUFFER, DEC 0
OUT_READY, DEC 0
OUT_BUFFER,DEC 0
SAVE_AC,   DEC 0
SAVE_E,    DEC 0
        END
