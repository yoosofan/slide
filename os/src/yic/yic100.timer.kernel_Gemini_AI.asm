
/ ====================================================================
/ YIC 100 KERNEL (Firmware)
/ Features: Preemption (TR/FT), HW Card Flush, Single I/O Stream
/ Base = 300, Mailbox Physical = 1000
/ ====================================================================
        ORG     0
        BUN     BOOT          / CPU starts here at power-on
        BUN     ISR           / Hardware Interrupts jump here (Addr 1)

/ --- System Call Entry Point (Entered via RTK) ---
        ORG     030
        HEX     0             / RTK saves User's logical PC here
        BUN     SYSCALL       / Hardware jumps here after RTK

/ --- OS Boot and Loader ---
BOOT,   CLA
        STA     IN_READY
        STA     OUT_READY
        ION                   / Enable Interrupts to read cards

        / Step 1: Read Timer Limit (Card 1)
L_TMR,  LDA     IN_READY
        SZA
        BUN     HAVE_TMR
        BUN     L_TMR
HAVE_TMR,LDA    IN_BUFFER
        ATT                   / HW: TR <- AC (Set Timer Register)
        CLA
        STA     IN_READY      / Clear flag for next card

        / Step 2: Read Program Size (Card 2)
L_SZ,   LDA     IN_READY
        SZA
        BUN     HAVE_SZ
        BUN     L_SZ
HAVE_SZ,LDA     IN_BUFFER
        STA     PROG_SIZE
        CLA
        STA     IN_READY

        LDA     PROG_BASE     / Start loading at physical 300
        STA     PTR

        / Step 3: Load User Program Code (Cards 3 to N)
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

        / Step 4: Context Switch to User Space
L_RUN,  LDA     PROG_BASE
        ATB                   / Set Base Register = 300
        CLA
        STA     0             / Put "0" in M[0] to fake return address
        RTI                   / Atomic: PC=M[0], MODE=1, IEN=1, TR starts!

/ --- Syscall Handler ---
SYSCALL,SZA                   / Check AC for command
        BUN     SC_CHECK

        / Syscall 0: Normal Exit
SC_EXIT,FSH                   / HW: Tell CR to flush leftover cards to FFFF
        BUN     BOOT          / Load next user program

SC_CHECK,ADD    M_ONE
        SZA                   / If result 0, AC was 1
        BUN     SC_WRITE

        / Syscall 1: Read (Input from CR to Mailbox)
        ION
W_IN,   LDA     IN_READY
        SZA
        BUN     RD_DONE
        BUN     W_IN
RD_DONE,LDA     MAIL_PHYS     / Point directly to Physical 1000
        STA     PTR
        LDA     IN_BUFFER
        STA     PTR I         / Move data to Mailbox
        CLA
        STA     IN_READY
        BUN     SC_RET

SC_WRITE, / Syscall 2: Write (Output from Mailbox to Printer)
        LDA     MAIL_PHYS
        STA     PTR
        LDA     PTR I         / Get data from Mailbox
        STA     OUT_BUFFER
        LDA     ONE
        STA     OUT_READY
        ION                   / Let ISR handle actual OUT
W_OUT,  LDA     OUT_READY
        SZA
        BUN     W_OUT         / Wait for ISR to print it

SC_RET, IOF
        LDA     030           / Get User's logical return address
        STA     0             / Move to M[0]
        RTI                   / Return to User Space (Timer resumes)

/ --- Interrupt Service Routine ---
ISR,    STA     SAVE_AC
        CIL
        STA     SAVE_E

        / 1. Check for Preemption / Security Trap
        SKT                   / HW: If FT==1, skip next & clear FT
        BUN     CHK_IO
        / TRAP OCCURRED: HW already pulsed FLUSH to card reader.
        BUN     BOOT          / Abandon user, load next job.

        / 2. Normal I/O Handling
CHK_IO, SKI
        BUN     CHK_OUT
        INP
        STA     IN_BUFFER
        LDA     ONE
        STA     IN_READY

CHK_OUT,SKO
        BUN     ISR_END
        LDA     OUT_READY
        SZA
        BUN     DO_OUT
        BUN     ISR_END
DO_OUT, LDA     OUT_BUFFER
        OUT
        CLA
        STA     OUT_READY

ISR_END,LDA     SAVE_E
        CIR
        LDA     SAVE_AC
        ION
        RTI

/ --- Kernel Data ---
ONE,       DEC 1
M_ONE,     DEC -1
PROG_BASE, HEX 300
MAIL_PHYS, HEX 1000
PROG_SIZE, DEC 0
PTR,       HEX 0
IN_READY,  DEC 0
IN_BUFFER, DEC 0
OUT_READY, DEC 0
OUT_BUFFER,DEC 0
SAVE_AC,   DEC 0
SAVE_E,    DEC 0
        END
