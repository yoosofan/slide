
/ ====================================================================
/ YIC 100 USER PROGRAM
/ Base = 300. Mailbox Logical = 700 (Resolves to Physical 1000)
/ ====================================================================
        ORG     0

        / 1. Request Input via OS
        LDA     C_RD          / AC = 1 (Syscall: Read)
        RTK                   / OS puts CR data into Mailbox

        / 2. Process Data
        LDA     MAILBOX       / Logical 700 -> Physical 1000
        ADD     TEN
        STA     MAILBOX

        / 3. Display Result via OS
        LDA     C_WR          / AC = 2 (Syscall: Write)
        RTK                   / OS prints data from Mailbox

        / 4. Exit gracefully
        CLA                   / AC = 0 (Syscall: Exit)
        RTK                   / OS will FSH remaining cards and reboot

/ --- User Data (Code Segment) ---
C_RD,    DEC 1
C_WR,    DEC 2
TEN,     DEC 10

/ --- User Shared Memory (Data Segment) ---
        ORG 700
MAILBOX, DEC 0                / Hardware maps this to Physical 1000
        END
