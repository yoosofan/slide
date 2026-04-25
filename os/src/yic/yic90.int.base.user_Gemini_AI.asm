/ ====================================================================
/ YIC 90 USER PROGRAM
/ Hardware: Logical Addressing (Physical = Logical + Base)
/ ====================================================================
        ORG     0

        / 1. Get Input via OS
        LDA     C_RD          / AC = 1 (Read)
        RTK                   / Call Kernel

        / 2. Process Data (Add 5)
        LDA     MAILBOX
        ADD     FIVE
        STA     MAILBOX

        / 3. Display Result via OS
        LDA     C_WR          / AC = 2 (Write)
        RTK                   / Call Kernel

        / 4. Exit to Loader
        CLA                   / AC = 0 (Exit)
        RTK                   / Call Kernel

/ --- User Data ---
C_RD,    DEC 1
C_WR,    DEC 2
FIVE,    DEC 5
        ORG 010
MAILBOX, DEC 0
        END
