        ORG 0
        BUN BOOT
        BUN ISR

        ORG 030
        HEX 0
        BUN SYSCALL

BOOT,   CLA
        STA IN_READY
        STA OUT_READY
        ION

GETSZ,  LDA IN_READY
        SZA
        BUN HAVE_SZ
        BUN GETSZ
HAVE_SZ,LDA IN_BUFFER
        STA PROG_SIZE
        CLA
        STA IN_READY

        LDA PROG_PHYS
        STA PTR

L_LOOP, LDA PROG_SIZE
        SZA
        BUN L_READ
        BUN L_RUN
L_READ, LDA IN_READY
        SZA
        BUN L_STORE
        BUN L_READ
L_STORE,LDA IN_BUFFER
        STA PTR I
        ISZ PTR
        CLA
        STA IN_READY
        LDA PROG_SIZE
        ADD M_ONE
        STA PROG_SIZE
        BUN L_LOOP

L_RUN,  LDA PROG_PHYS
        ATB
        CLA
        STA 0
        RTI

SYSCALL,SZA
        BUN SC_CHECK
        BUN BOOT

SC_CHECK,ADD  M_ONE
        SZA
        BUN  SC_WRITE

        ION
W_IN,   LDA  IN_READY
        SZA
        BUN  RD_DONE
        BUN  W_IN
RD_DONE,
        LDA  IN_BUFFER
        STA  MAILBOX
        CLA
        STA  IN_READY
        BUN  SC_RET

SC_WRITE,
        LDA  MAILBOX
        STA  OUT_BUFFER
        LDA  ONE
        STA  OUT_READY
        ION
W_OUT,  LDA  OUT_READY
        SZA
        BUN  W_OUT

SC_RET, IOF
        LDA  030
        STA  0
        RTI

ISR,    STA  SAVE_AC
        CIL
        STA  SAVE_E
        SKI
        BUN  I_OUT
        INP
        STA  IN_BUFFER
        LDA  ONE
        STA  IN_READY
I_OUT,  SKO
        BUN  I_END
        LDA  OUT_READY
        SZA
        BUN  DO_OUT
        BUN  I_END
DO_OUT, LDA OUT_BUFFER
        OUT
        CLA
        STA  OUT_READY
I_END,  LDA  SAVE_E
        CIR
        LDA  SAVE_AC
        RTI

ONE,       DEC 1
M_ONE,     DEC -1
PROG_PHYS, HEX 300
PROG_SIZE, DEC 0
PTR,       HEX 0
IN_READY,  DEC 0
IN_BUFFER, DEC 0
OUT_READY, DEC 0
OUT_BUFFER,DEC 0
SAVE_AC,   DEC 0
SAVE_E,    DEC 0

	   ORG 1000
MAILBOX,   HEX 0
        END

/ ====================================================================
/ YIC 90 KERNEL (Firmware) , Developed with assistance from  Gemini AI
/ Hardware: Physical Addressing (MODE = 0)
/ ====================================================================
