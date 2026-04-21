        ORG     0
        BUN     MAIN
        BUN     ISR

MAIN,   LDA     ZERO
        STA     COUNT
        ION

WORK,   LDA     COUNT
        INC
        STA     COUNT
        BUN     WORK

ISR,    STA     SAVE
        BSA     IO
        LDA     SAVE
        ION
        BUN     0  I

IO,     HEX     0
        SKI
        BUN     OUTPUT
        INP
        STA     BUFFER
        BUN     IO  I
OUTPUT, SKO
        BUN     IO  I
        OUT
        BUN     IO  I

ZERO,   DEC     0
COUNT,  DEC     0
SAVE,   DEC     0
BUFFER, DEC     0
        END

; Developed with assistance from DeepSeek, Grok, Gemini and Grok AI for educational purposes in OS course slides
; Program with Procedure Vector Table (like interrupt vectors)
; Uses polling I/O with indirect BSA calls

