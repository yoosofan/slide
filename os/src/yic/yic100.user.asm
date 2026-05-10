    ORG     0
    LDA     C_RD
    RTK
    LDA     MAILBOX
    ADD     TEN
    STA     MAILBOX
    LDA     C_WR
    RTK
    CLA
    RTK
C_RD,    DEC 1
C_WR,    DEC 2
TEN,     DEC 10
    ORG 700
MAILBOX, DEC 0
        END


; Developed with assistance from Gemini AI for educational purposes in OS course slides

