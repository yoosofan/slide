; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Program with BSA for structured input/output routines

        ORG     0
START,  BSA     INPUT
        STA     NUM1

        BSA     INPUT
        STA     NUM2

        LDA     NUM1
        ADD     NUM2
        STA     RESULT

        BSA     OUTPUT

        HLT

INPUT,  HEX     0
POLL,   SKI
        BUN     POLL
        INP
        BUN     (INPUT)

OUTPUT, HEX     0
OUT_P,  SKO
        BUN     OUT_P
        OUT
        BUN     (OUTPUT)

// Data Section
NUM1,   DEC     0
NUM2,   DEC     0
RESULT, DEC     0

        END