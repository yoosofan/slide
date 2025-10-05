; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Simple User Program - Loads at absolute address 500
; Uses system calls via fixed memory locations

  ORG     500
MAIN, HEX     0
  ION
  BSA SYS_READ
  STA NUM1
  BSA SYS_READ  
  STA NUM2
  LDA NUM1
  ADD NUM2
  STA RESULT
  BSA SYS_WRITE
  BUN MAIN I

SYS_READ, HEX   0
  LDA ZERO
  STA USER_INPUT
READ_WAIT,
  LDA USER_INPUT
  SZA
  BUN READ_DONE
  BUN READ_WAIT
READ_DONE,
  LDA USER_INPUT
  STA SYS_READ I    // Return input in AC
  LDA ZERO
  STA USER_INPUT    // Clear for next
  BUN SYS_READ I

SYS_WRITE, HEX  0
  STA USER_OUTPUT
  LDA ONE
  STA USER_OUT_PENDING
  SKO
  BUN OUTPUT_NOW
WRITE_WAIT,
  LDA USER_OUT_PENDING
  SZA
  BUN WRITE_WAIT
  BUN SYS_WRITE I
OUTPUT_NOW,
  LDA USER_OUTPUT
  OUT                // ← THIS sends the data
  LDA ZERO
  STA USER_OUT_PENDING
  BUN SYS_WRITE I

NUM1,        DEC     0
NUM2,        DEC     0
RESULT,      DEC     0
USER_INPUT,  DEC     0
USER_OUTPUT, DEC     0
USER_OUT_PENDING, DEC 0
ZERO,        DEC     0
ONE,         DEC     1
        END
