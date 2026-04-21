        ORG     0
        BUN     MAIN
        BUN     ISR
MAIN,   LDA     ZERO
        STA     READY
        ION
WAIT,   LDA     READY
        SZA
        BUN     PROCESS
        BUN     WAIT
PROCESS,LDA     BUFFER
        ADD     TEN
        STA     BUFFER
        BSA     OUT_SUB
        HLT

OUT_SUB,HEX     0
POLL_O, SKO
        BUN     POLL_O
        LDA     BUFFER
        OUT
        BUN     OUT_SUB I

ISR,    BSA     SAVE_SUB
        SKI
        BUN     ISR_EXIT

        INP
        STA     BUFFER
        LDA     ONE
        STA     READY

ISR_EXIT,BSA     RSTR_SUB
        ION
        BUN     0 I

SAVE_SUB,HEX    0
        STA     TEMP_AC
        CIL
        STA     TEMP_E
        BUN     SAVE_SUB I

RSTR_SUB,HEX    0
        LDA     TEMP_E
        CIR
        LDA     TEMP_AC
        BUN     RSTR_SUB I

ZERO,   DEC     0
ONE,    DEC     1
TEN,    DEC     10
READY,  DEC     0
BUFFER, DEC     0
TEMP_AC,DEC     0
TEMP_E, DEC     0
        END


; Developed with assistance from DeepSeek, Grok, Gemini and Grok AI for educational purposes in OS course slides
; Program with Procedure Vector Table (like interrupt vectors)
; Uses polling I/O with indirect BSA calls

