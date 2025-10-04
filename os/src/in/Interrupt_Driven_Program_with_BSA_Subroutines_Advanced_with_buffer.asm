; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Interrupt_Driven_Program_with_BSA_Subroutines_Advanced_with_buffer.asm
; Advanced: Buffered Input with BSA Subroutines
; Complete buffered input system using BSA for modularity

        ORG     0
        BUN     MAIN

        ORG     1
        BUN     ISR

        ORG     100

MAIN,   BSA     INIT_SYSTEM // Initialize using subroutine
        ION
        
APP_LOOP,BSA   CHECK_INPUT // Check for input data
        SZA                 // Skip if no data
        BUN     PROCESS     // Process available data
        
        BSA     DO_WORK     // Do background work
        BUN     APP_LOOP

PROCESS,BSA    GET_CHAR    // Get character from buffer
        BSA     PROCESS_CHAR // Process the character
        BUN     APP_LOOP

// Initialization Subroutine
INIT_SYSTEM,HEX 0
        LDA     ZERO
        STA     IN_IDX
        STA     OUT_IDX
        STA     BUF_COUNT
        BUN     INIT_SYSTEM I

// Check Input Subroutine: Sets AC non-zero if data available
CHECK_INPUT,HEX 0
        LDA     BUF_COUNT   // Return buffer count in AC
        BUN     CHECK_INPUT I

// Get Character Subroutine: Returns character in AC
GET_CHAR,HEX   0
        LDA     OUT_IDX
        ADD     BUFFER
        STA     GET_PTR
        LDA     GET_PTR I   // Get character from buffer
        
        // Update buffer management
        BSA     DEC_BUFFER  // Decrement buffer count
        BUN     GET_CHAR I

// Process Character Subroutine
PROCESS_CHAR,HEX 0
        // Example: convert to uppercase
        STA     TEMP
        // ... processing logic ...
        LDA     TEMP
        BUN     PROCESS_CHAR I

// Work Subroutine
DO_WORK,HEX    0
        LDA     WORK_CTR
        INC
        STA     WORK_CTR
        BUN     DO_WORK I

// Interrupt Service Routine
ISR,    STA     SAVE_AC
        BSA     HANDLE_INTERRUPT
        ION
        LDA     SAVE_AC
        BUN     INDIRECT

// Handle Interrupt Subroutine
HANDLE_INTERRUPT,HEX 0
        SKI
        BUN     HANDLE_OUTPUT
        
        BSA     READ_INPUT_BUFFER
HANDLE_OUTPUT,
        SKO
        BUN     INTR_EXIT
        BSA     WRITE_OUTPUT_BUFFER
        
INTR_EXIT,BUN  HANDLE_INTERRUPT I

// Read Input to Buffer Subroutine
READ_INPUT_BUFFER,HEX 0
        LDA     BUF_COUNT
        SUB     BUF_SIZE
        SPA                 // Skip if buffer not full
        BUN     STORE_INPUT
        
        // Buffer full - can't store
        BUN     READ_INPUT_BUFFER I

STORE_INPUT,
        INP                 // Read input
        STA     TEMP_CHAR
        
        // Store in buffer
        LDA     IN_IDX
        ADD     BUFFER
        STA     PUT_PTR
        LDA     TEMP_CHAR
        STA     PUT_PTR I
        
        // Update buffer management
        BSA     INC_BUFFER
        BUN     READ_INPUT_BUFFER I

// Buffer Management Subroutines
INC_BUFFER,HEX 0
        LDA     BUF_COUNT
        INC
        STA     BUF_COUNT
        LDA     IN_IDX
        INC
        AND     BUF_MASK
        STA     IN_IDX
        BUN     INC_BUFFER I

DEC_BUFFER,HEX 0
        LDA     BUF_COUNT
        DEC
        STA     BUF_COUNT
        LDA     OUT_IDX
        INC
        AND     BUF_MASK
        STA     OUT_IDX
        BUN     DEC_BUFFER I

// Data Section
ZERO,       DEC     0
IN_IDX,     DEC     0
OUT_IDX,    DEC     0
BUF_COUNT,  DEC     0
WORK_CTR,   DEC     0
TEMP,       DEC     0
TEMP_CHAR,  DEC     0
SAVE_AC,    DEC     0
GET_PTR,    HEX     0
PUT_PTR,    HEX     0
INDIRECT,   HEX     0
BUF_SIZE,   DEC     16
BUF_MASK,   HEX     15
BUFFER,     HEX     200

        ORG     200
INPUT_BUF,  HEX     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

        END