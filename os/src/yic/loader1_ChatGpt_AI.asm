; Developed with assistance from ChatGpt AI for educational purposes in OS courseslides

/ =========================================
/ Interrupt Vector (Mano compliant)
/ =========================================
ORG 0
RETADR, HEX 0          / return address storage

ORG 1
        BUN ISR

/ =========================================
/ Loader Program
/ =========================================
ORG 10

START,  ION            / enable interrupts

LOADER_LOOP,
        BSA READ_LEN   / AC ← program length
        STA COUNT

        LDA USER_BASE
        STA PTR        / PTR ← start address

LOAD_LOOP,
        LDA COUNT
        SZA
        BUN LOAD_CONT
        BUN EXECUTE    / if COUNT == 0 → done

LOAD_CONT,
        BSA READ_CHAR  / AC ← next word
        STA PTR I      / M[PTR] ← AC

        ISZ PTR        / PTR++
        ISZ COUNT      / COUNT--
        BUN LOAD_LOOP

/ -----------------------------------------
/ Execute loaded program
/ -----------------------------------------
EXECUTE,
        BSA USER_BASE  / call user program
        BUN LOADER_LOOP

/ =========================================
/ ISR (Input-driven)
/ =========================================
ISR,    STA SAVE

        SKI
        BUN ISR_DONE

        INP            / read input
        STA INBUF
        ISZ INFLAG     / signal "input ready"

ISR_DONE,
        LDA SAVE
        ION            / enable interrupts safely
        BUN RETADR I

/ =========================================
/ READ_LEN: read one word (length)
/ =========================================
READ_LEN, HEX 0

WAIT_LEN,
        LDA INFLAG
        SZA
        BUN GOT_LEN
        BUN WAIT_LEN

GOT_LEN,
        LDA INBUF
        STA TEMP
        CLA
        STA INFLAG     / clear flag
        LDA TEMP
        BUN READ_LEN I

/ =========================================
/ READ_CHAR: read one word from input
/ =========================================
READ_CHAR, HEX 0

WAIT_CHAR,
        LDA INFLAG
        SZA
        BUN GOT_CHAR
        BUN WAIT_CHAR

GOT_CHAR,
        LDA INBUF
        STA TEMP
        CLA
        STA INFLAG
        LDA TEMP
        BUN READ_CHAR I

/ =========================================
/ OUTPUT routine
/ =========================================
OUTPUT, HEX 0

WAIT_OUT,
        SKO
        BUN WAIT_OUT

        OUT
        BUN OUTPUT I

/ =========================================
/ DATA AREA
/ =========================================
USER_BASE, HEX 200     / load address

COUNT,     HEX 0
PTR,       HEX 0

INBUF,     HEX 0
INFLAG,    HEX 0

SAVE,      HEX 0
TEMP,      HEX 0
