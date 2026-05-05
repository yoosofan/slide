    ORG     300

    LDA     C_RD
    RTK

    LDA     MAILBOX
    ADD     FIVE

    STA     MAILBOX
    LDA     C_WR
    RTK

    CLA
    RTK

    C_RD,    DEC 1
    C_WR,    DEC 2
    FIVE,    DEC 5

             ORG 700
    MAILBOX, DEC 0
