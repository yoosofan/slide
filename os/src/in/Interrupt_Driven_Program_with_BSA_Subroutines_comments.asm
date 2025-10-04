; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Interrupt-Driven Program with BSA Subroutines
; Interrupt program with BSA for better structure

        ORG     0
        BUN     MAIN

        ORG     1
        BUN     ISR

        ORG     100

MAIN,   LDA     ZERO
        STA     COUNT
        ION                 // Enable interrupts
        
        // Main work loop using BSA for organization
WORK,   BSA     DO_WORK     // Call work subroutine
        BUN     WORK

// Work Subroutine
DO_WORK,HEX     0           // Return address
        LDA     COUNT
        INC
        STA     COUNT
        BUN     DO_WORK I   // Return

// Interrupt Service Routine with BSA calls
ISR,    STA     SAVE_AC     // Save AC (no BSA since interrupt)
        
        BSA     SAVE_CTX    // Save context using subroutine
        BSA     HANDLE_IO   // Handle I/O using subroutine
        BSA     RESTORE_CTX // Restore context
        
        ION                 // Re-enable interrupts
        LDA     SAVE_AC     // Restore AC
        BUN     ISR_RET     // Special return for interrupt

// Context Save Subroutine
SAVE_CTX,HEX    0
        // Save registers to stack (simplified)
        LDA     AC_SAVE
        STA     STACK_PTR I // Push to stack
        BUN     SAVE_CTX I  // Return

// I/O Handling Subroutine  
HANDLE_IO,HEX   0
        SKI                 // Check input interrupt
        BUN     CHK_OUTPUT
        
        BSA     READ_INPUT  // Call input handler
        BUN     IO_EXIT
        
CHK_OUTPUT,
        SKO                 // Check output interrupt
        BUN     IO_EXIT
        BSA     WRITE_OUTPUT // Call output handler

IO_EXIT,BUN     HANDLE_IO I // Return

// Read Input Subroutine
READ_INPUT,HEX  0
        INP                 // Read input
        STA     INPUT_BUF   // Store in buffer
        BUN     READ_INPUT I

// Write Output Subroutine  
WRITE_OUTPUT,HEX 0
        OUT                 // Output data
        BUN     WRITE_OUTPUT I

// Restore Context Subroutine
RESTORE_CTX,HEX 0
        // Restore registers from stack
        LDA     STACK_PTR I // Pop from stack
        STA     AC_SAVE
        BUN     RESTORE_CTX I

// Interrupt Return (special handling)
ISR_RET, BUN    INDIRECT    // Return to interrupted program

// Data Section
ZERO,       DEC     0
COUNT,      DEC     0
SAVE_AC,    DEC     0
AC_SAVE,    DEC     0
INPUT_BUF,  DEC     0
STACK_PTR,  HEX     250     // Stack pointer
INDIRECT,   HEX     0       // Will hold return address

// Stack area
        ORG     250
STACK,  HEX     0,0,0,0,0,0,0,0,0,0

        END