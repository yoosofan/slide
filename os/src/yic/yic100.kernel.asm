      ORG  0
      BUN  BOOT
      BUN  ISR
      ORG  030
      HEX  0
      BUN  SYSCALL
BOOT, CLA
      STA  IN_READY
      STA  OUT_READY
      ION
L_TMR,LDA  IN_READY
      SZA
      BUN  HAVE_TMR
      BUN  L_TMR
HAVE_TMR,LDA IN_BUFFER
      ATT
      CLA
      STA  IN_READY
L_SZ, LDA  IN_READY
      SZA
      BUN  HAVE_SZ
      BUN  L_SZ
HAVE_SZ,LDA IN_BUFFER
      STA  PROG_SIZE
      CLA
      STA  IN_READY
      LDA  PROG_BASE
      STA  PTR
L_LOOP,LDA PROG_SIZE
      SZA
      BUN  L_READ
      BUN  L_RUN
L_READ,LDA IN_READY
      SZA
      BUN  L_STORE
      BUN  L_READ
L_STORE,LDA IN_BUFFER
      STA  PTR I
      ISZ  PTR
      CLA
      STA  IN_READY
      LDA  PROG_SIZE
      ADD  M_ONE
      STA  PROG_SIZE
      BUN  L_LOOP
L_RUN, LDA PROG_BASE
      ATB
      CLA
      STA  0
      RTI
SYSCALL,SZA
      BUN  SC_CHECK
SC_EXIT,FSH
      BUN  BOOT
SC_CHECK,ADD M_ONE
      SZA
      BUN  SC_WRITE
      ION
W_IN, LDA  IN_READY
      SZA
      BUN  RD_DONE
      BUN  W_IN
RD_DONE,LDA MAIL_PHYS
      STA  PTR
      LDA  IN_BUFFER
      STA  PTR I
      CLA
      STA  IN_READY
      BUN  SC_RET
SC_WRITE,
      LDA  MAIL_PHYS
      STA  PTR
      LDA  PTR I
      STA  OUT_BUFFER
      LDA  ONE
      STA  OUT_READY
      ION
W_OUT,LDA  OUT_READY
      SZA
      BUN  W_OUT
SC_RET,IOF
      LDA  030
      STA  0
      RTI
ISR,  STA  SAVE_AC
      CIL
      STA  SAVE_E
      SKT
      BUN  CHK_IO
      BUN  BOOT
CHK_IO,SKI
      BUN  CHK_OUT
      INP
      STA  IN_BUFFER
      LDA  ONE
      STA  IN_READY
CHK_OUT,SKO
      BUN  ISR_END
      LDA  OUT_READY
      SZA
      BUN  DO_OUT
      BUN  ISR_END
DO_OUT, LDA  OUT_BUFFER
      OUT
      CLA
      STA  OUT_READY
ISR_END,LDA  SAVE_E
      CIR
      LDA  SAVE_AC
      RTI
PROG_BASE, HEX 300
MAIL_PHYS, HEX 1000
ONE,       DEC 1
M_ONE,     DEC -1
PROG_SIZE, DEC 0
PTR,       HEX 0
IN_READY,  DEC 0
IN_BUFFER, DEC 0
OUT_READY, DEC 0
OUT_BUFFER,DEC 0
SAVE_AC,   DEC 0
SAVE_E,    DEC 0
        END



; Developed with assistance from Gemini AI for educational purposes in OS course slides

/ ====================================================================
/ YIC 100 KERNEL (Firmware)
/ Features: Preemption (TR/FT), HW Card Flush, Single I/O Stream
/ Base = 300, Mailbox Physical = 1000
/ ====================================================================
