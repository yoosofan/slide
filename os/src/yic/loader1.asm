; Developed with assistance from Grok AI for educational purposes in OS course slides

; ================================================================
; LOADER + ISR + I/O HELPER ROUTINES (modular)
; For Mano's Basic Computer - OS course (after interrupt chapter)
; Uses interrupt-driven I/O (SKI/SKO + INP/OUT)
; Fixed addresses for helpers so user programs can call them
; ================================================================

        ORG     0
        BUN     LOADER_MAIN     ; initial start (loc 0 will be overwritten by interrupt return addr)

        ORG     1
        BUN     ISR             ; interrupt vector (Mano standard)

; ----------------------------------------------------------------
; Loader main (bootstrap loop)
; ----------------------------------------------------------------
        ORG     100
LOADER_MAIN,
        ION                     ; enable interrupts once (Mano requirement)

LOAD_LOOP,
        BSA     READ_WORD       ; 1. read number of words of next program
        STA     PROG_SIZE
        BSA     LOAD_PROGRAM    ; 2. read and load the program bytes/words
        BSA     PROGRAM_BASE    ; 3. BSA to it → execute user program
                                ;    (return address stored at PROGRAM_BASE)
        BUN     LOAD_LOOP       ; after user returns → load next program

; ----------------------------------------------------------------
; Helper: LOAD_PROGRAM subroutine (modular)
; ----------------------------------------------------------------
LOAD_PROGRAM, HEX 0
        LDA     ZERO
        STA     LOAD_INDEX

LOAD_PROGRAM_LOOP,
        LDA     LOAD_INDEX
        SUB     PROG_SIZE
        SPA                     ; index >= size ?
        BUN     LOAD_DONE
        BSA     READ_WORD       ; read next word (value in AC)
        STA     TEMP_DATA
        LDA     LOAD_INDEX
        ADD     PROGRAM_BASE
        STA     TEMP_ADDR
        LDA     TEMP_DATA
        STA     TEMP_ADDR I     ; store at PROGRAM_BASE + index
        LDA     LOAD_INDEX
        INC
        STA     LOAD_INDEX
        BUN     LOAD_PROGRAM_LOOP

LOAD_DONE,
        BUN     LOAD_PROGRAM I

; ----------------------------------------------------------------
; Fixed-address helper: READ_WORD (called by BSA 200)
; Returns input value in AC (interrupt-driven, blocking poll)
; ----------------------------------------------------------------
        ORG     200
READ_WORD, HEX 0
WAIT_FOR_INPUT,
        LDA     INPUT_READY
        SZA
        BUN     HAVE_INPUT
        BUN     WAIT_FOR_INPUT

HAVE_INPUT,
        LDA     INPUT_BUFFER    ; AC = input data
        STA     TEMP_DATA       ; save because we need to clear flag
        LDA     ZERO
        STA     INPUT_READY     ; clear ready flag
        LDA     TEMP_DATA       ; restore value to AC
        BUN     READ_WORD I

; ----------------------------------------------------------------
; Fixed-address helper: WRITE_WORD (called by BSA 300)
; AC contains data to output (interrupt-driven, blocking poll)
; ----------------------------------------------------------------
        ORG     300
WRITE_WORD, HEX 0
        STA     OUTPUT_DATA
        LDA     ONE
        STA     OUTPUT_PENDING

WAIT_FOR_OUTPUT,
        LDA     OUTPUT_PENDING
        SZA
        BUN     WAIT_FOR_OUTPUT
        BUN     WRITE_WORD I

; ----------------------------------------------------------------
; Interrupt Service Routine (ISR) - faithful to Mano flowchart
; ----------------------------------------------------------------
        ORG     400
ISR,    STA     SAVE_AC

        SKI                     ; input flag set?
        BUN     CHECK_OUTPUT
        INP                     ; read from device
        STA     INPUT_BUFFER
        LDA     ONE
        STA     INPUT_READY
        BUN     ISR_EXIT

CHECK_OUTPUT,
        SKO                     ; output flag set?
        BUN     ISR_EXIT
        LDA     OUTPUT_PENDING
        SZA
        BUN     PERFORM_OUTPUT
        BUN     ISR_EXIT

PERFORM_OUTPUT,
        LDA     OUTPUT_DATA
        OUT
        LDA     ZERO
        STA     OUTPUT_PENDING

ISR_EXIT,
        LDA     SAVE_AC
        BUN     0 I             ; return (Mano standard - no hardware re-enable)

; ----------------------------------------------------------------
; Data area
; ----------------------------------------------------------------
        ORG     500
ZERO,           DEC     0
ONE,            DEC     1
PROG_SIZE,      DEC     0
LOAD_INDEX,     DEC     0
TEMP_ADDR,      HEX     0
TEMP_DATA,      DEC     0
INPUT_BUFFER,   DEC     0
INPUT_READY,    DEC     0
OUTPUT_DATA,    DEC     0
OUTPUT_PENDING, DEC     0
SAVE_AC,        DEC     0
PROGRAM_BASE,   HEX     600   ; loaded user programs start here

        END
