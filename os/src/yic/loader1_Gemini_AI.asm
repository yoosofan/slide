; Developed with assistance from Gemini AI for educational purposes in OS slides

/ ====================================================================
/ PROGRAM 1: OS Kernel and Loader
/ ====================================================================

        ORG     0
        BUN     OS_START
        BUN     ISR             / Hardware interrupt vectors here

/ --------------------------------------------------------------------
/ OS System Call Table (Fixed Memory Addresses for User Programs)
/ --------------------------------------------------------------------
        ORG     010             / SYS_READ is always at address 010
SYS_READ, HEX   0
R_WAIT, LDA     IN_READY        / Check if ISR got a character
        SZA
        BUN     R_GOT           / If not zero, data is ready
        BUN     R_WAIT          / Loop and wait
R_GOT,  LDA     IN_BUFFER
        STA     TMP_AC          / Save character safely
        LDA     ZERO
        STA     IN_READY        / Clear flag to acknowledge receipt
        LDA     TMP_AC          / Put character in AC for user
        BUN     SYS_READ I      / Return to caller

        ORG     020             / SYS_WRITE is always at address 020
SYS_WRITE, HEX  0
        STA     OUT_BUFFER      / Save AC (user data) to buffer
        LDA     ONE
        STA     OUT_READY       / Signal ISR to print
W_WAIT, LDA     OUT_READY
        SZA                     / Wait until ISR clears this to 0
        BUN     W_WAIT
        BUN     SYS_WRITE I     / Return to caller

/ --------------------------------------------------------------------
/ Boot & Loader Logic
/ --------------------------------------------------------------------
        ORG     030
OS_START, LDA   ZERO
        STA     IN_READY
        STA     OUT_READY
        ION                     / Enable hardware interrupts

/ Step 1: Read the number of bytes for the next program
LOAD_L, BSA     SYS_READ        / Call OS Read subroutine
        STA     PROG_SIZE       / Save the size
        LDA     PROG_BASE
        STA     PTR             / Initialize memory pointer to 500

/ Step 2: Loop to read the bytes
READ_B, LDA     PROG_SIZE       / Check remaining bytes
        SZA
        BUN     READ_C          / If > 0, read character
        BUN     EXEC_P          / If 0, done reading, go execute!
READ_C, BSA     SYS_READ
        STA     PTR I           / Store byte at memory[PTR]
        ISZ     PTR             / Increment memory pointer
        LDA     PROG_SIZE
        ADD     M_ONE           / Decrement program size
        STA     PROG_SIZE
        BUN     READ_B

/ Step 3: Execute User Program
EXEC_P, BSA     500             / Jump to User Space (stores return at 500)
        BUN     LOAD_L          / When user returns, wait for next program

/ --------------------------------------------------------------------
/ Interrupt Service Routine (Kernel Space)
/ --------------------------------------------------------------------
ISR,    STA     SAVE_AC         / Context Save
        CIL
        STA     SAVE_E

        SKI                     / Check Input Flag
        BUN     CHK_OUT
        INP
        STA     IN_BUFFER
        LDA     ONE
        STA     IN_READY
        BUN     ISR_EXIT

CHK_OUT, SKO                    / Check Output Flag
        BUN     ISR_EXIT
        LDA     OUT_READY
        SZA                     / Did the user request a print?
        BUN     DO_OUT
        BUN     ISR_EXIT        / If no request, ignore (solves FGO=1 quirk)

DO_OUT, LDA     OUT_BUFFER
        OUT                     / Hardware prints character
        LDA     ZERO
        STA     OUT_READY       / Clear flag to tell SYS_WRITE we are done

ISR_EXIT, LDA   SAVE_E          / Context Restore
        CIR
        LDA     SAVE_AC
        ION
        BUN     0 I             / Return to interrupted code

/ --------------------------------------------------------------------
/ OS Variables
/ --------------------------------------------------------------------
ZERO,       DEC 0
ONE,        DEC 1
M_ONE,      DEC -1
IN_READY,   DEC 0
IN_BUFFER,  DEC 0
OUT_READY,  DEC 0
OUT_BUFFER, DEC 0
TMP_AC,     DEC 0
SAVE_AC,    DEC 0
SAVE_E,     DEC 0
PROG_SIZE,  DEC 0
PROG_BASE,  HEX 500
PTR,        HEX 0
        END
