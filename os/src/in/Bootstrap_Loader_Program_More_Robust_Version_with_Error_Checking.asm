; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Program with Procedure Vector Table (like interrupt vectors)
; Uses polling I/O with indirect BSA calls
; Enhanced bootstrap loader with error checking

        ORG     0

BOOTSTRAP,
        BSA     INIT_SYSTEM     // Initialize system
        
        BSA     READ_COUNT      // Read program size
        STA     PROGRAM_SIZE
        
        // Validate program size
        BSA     VALIDATE_SIZE
        SZA                     // Skip if size valid
        BUN     ERROR_HANDLER   // Handle invalid size
        
        BSA     LOAD_PROGRAM    // Load the program
        
        BSA     EXECUTE_PROGRAM // Execute loaded program
        
        HLT

// Initialize System Subroutine
INIT_SYSTEM, HEX 0
        LDA     ZERO
        STA     LOAD_ADDRESS    // Set to 128
        STA     BYTES_LOADED
        STA     ERROR_FLAG
        BUN     INIT_SYSTEM I

// Read Program Size Subroutine
READ_COUNT, HEX 0
        BSA     READ_INPUT      // Read byte count
        BUN     READ_COUNT I

// Validate Program Size Subroutine
VALIDATE_SIZE, HEX 0
        LDA     PROGRAM_SIZE
        SZA                     // Skip if size ≠ 0
        BUN     CHECK_MAX
        
        // Size is zero - error
        LDA     ONE
        STA     ERROR_FLAG
        BUN     VALIDATE_SIZE I

CHECK_MAX,
        // Check if program fits in memory (128-255 = 128 bytes max)
        SUB     MAX_PROGRAM_SIZE
        SPA                     // Skip if size > max (error)
        BUN     SIZE_OK
        
        // Program too large
        LDA     ONE
        STA     ERROR_FLAG

SIZE_OK,
        LDA     ZERO            // Return AC=0 if valid
        BUN     VALIDATE_SIZE I

// Load Program Subroutine
LOAD_PROGRAM, HEX 0
        // Check if loading should proceed
        LDA     ERROR_FLAG
        SZA
        BUN     LOAD_PROGRAM I  // Error occurred, abort
        
LOAD_LOOP,
        LDA     BYTES_LOADED
        SUB     PROGRAM_SIZE
        SPA                     // Skip if all bytes loaded
        BUN     LOAD_BYTE
        
        // Loading complete
        BUN     LOAD_PROGRAM I

LOAD_BYTE,
        BSA     READ_INPUT      // Read program byte
        STA     TEMP_STORAGE
        
        // Store byte using indirect addressing
        LDA     LOAD_ADDRESS
        ADD     BYTES_LOADED    // Calculate actual address
        STA     STORE_POINTER
        LDA     TEMP_STORAGE
        STA     STORE_POINTER I
        
        // Update counters
        LDA     BYTES_LOADED
        INC
        STA     BYTES_LOADED
        
        BUN     LOAD_LOOP

// Read Input Subroutine (general purpose)
READ_INPUT, HEX 0
INPUT_WAIT,
        SKI                     // Wait for input
        BUN     INPUT_WAIT
        INP                     // Read to AC
        BUN     READ_INPUT I

// Execute Program Subroutine
EXECUTE_PROGRAM, HEX 0
        LDA     ERROR_FLAG
        SZA
        BUN     EXEC_ERROR      // Don't execute if error
        
        // Jump to loaded program using BSA
        // This allows the program to return if needed
        BSA     PROGRAM_ENTRY
        
        // If we return here, the program finished
        BUN     EXECUTE_PROGRAM I

EXEC_ERROR,
        // Handle execution error
        BUN     EXECUTE_PROGRAM I

// Error Handler Subroutine
ERROR_HANDLER, HEX 0
        // Simple error handling - could be enhanced
        LDA     ERROR_MSG_PTR
        STA     OUTPUT_PTR
        
ERROR_LOOP,
        LDA     OUTPUT_PTR I    // Get error message character
        SZA                     // Skip if null terminator
        BUN     OUTPUT_CHAR
        
        BUN     ERROR_HANDLER I

OUTPUT_CHAR,
        // Output error character (simplified)
        OUT
        LDA     OUTPUT_PTR
        INC
        STA     OUTPUT_PTR
        BUN     ERROR_LOOP

// Data Section
        ORG     64
ZERO,           DEC     0
ONE,            DEC     1
PROGRAM_SIZE,   DEC     0
LOAD_ADDRESS,   HEX     128
BYTES_LOADED,   DEC     0
ERROR_FLAG,     DEC     0
TEMP_STORAGE,   DEC     0
STORE_POINTER,  HEX     0
OUTPUT_PTR,     HEX     0
MAX_PROGRAM_SIZE, DEC  128      // Max program size

// Error message
ERROR_MSG_PTR,  HEX     ERROR_MSG
ERROR_MSG,      DEC     69      // 'E'
                DEC     82      // 'R'
                DEC     82      // 'R'
                DEC     79      // 'O'
                DEC     82      // 'R'
                DEC     0       // null

// Program entry point (loaded program starts here)
        ORG     128
PROGRAM_ENTRY,  HEX     0
        // This address will contain the loaded program
        // BSA stores return address here, program code at 129+

        END