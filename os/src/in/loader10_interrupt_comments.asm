; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Relocating Bootstrap Loader with INTERRUPTS
; Uses interrupt-driven I/O instead of polling

        ORG     0
        BUN     BOOTSTRAP     // Reset vector

        ORG     1
        BUN     ISR           // Interrupt vector

        ORG     100

BOOTSTRAP,
        BSA     INIT_SYSTEM
        BSA     READ_PROGRAM_SIZE
        STA     PROG_SIZE
        
        BSA     ALLOCATE_MEMORY
        STA     BASE_REGISTER
        
        // Set up interrupt vectors for loaded program
        BSA     SETUP_INTERRUPT_VECTORS
        
        BSA     LOAD_PROGRAM
        
        // Enable interrupts and start loaded program
        ION
        BSA     EXECUTE_PROGRAM
        
        HLT

// Interrupt Service Routine
ISR,    STA     SAVE_AC       // Save accumulator
        BSA     SAVE_CONTEXT
        
        // Determine interrupt source
        SKI
        BUN     CHECK_OUTPUT
        
        // Input interrupt - handle input
        BSA     HANDLE_INPUT_INTERRUPT
        BUN     ISR_EXIT
        
CHECK_OUTPUT,
        SKO
        BUN     UNKNOWN_INTERRUPT
        
        // Output interrupt - handle output
        BSA     HANDLE_OUTPUT_INTERRUPT
        
UNKNOWN_INTERRUPT,
ISR_EXIT,
        BSA     RESTORE_CONTEXT
        ION
        LDA     SAVE_AC
        BUN     INDIRECT      // Return from interrupt

// Handle Input Interrupt
HANDLE_INPUT_INTERRUPT, HEX 0
        INP                   // Read input character
        STA     INPUT_BUFFER
        
        // Check if bootstrap is loading or program is running
        LDA     LOADING_FLAG
        SZA
        BUN     STORE_TO_PROGRAM
        
        // Program is running - pass to loaded program's input handler
        LDA     BASE_REGISTER
        ADD     PROG_INPUT_HANDLER
        STA     CALL_PTR
        BSA     CALL_PTR I
        BUN     HANDLE_INPUT_INTERRUPT I
        
STORE_TO_PROGRAM,
        // Store input to program memory during loading
        LDA     INPUT_BUFFER
        STA     LOAD_BUFFER
        BUN     HANDLE_INPUT_INTERRUPT I

// Handle Output Interrupt
HANDLE_OUTPUT_INTERRUPT, HEX 0
        // Check if output data available
        LDA     OUTPUT_BUFFER
        SZA
        BUN     SEND_OUTPUT
        
        // No data - check if program wants to output
        LDA     BASE_REGISTER
        ADD     PROG_OUTPUT_HANDLER
        STA     CALL_PTR
        BSA     CALL_PTR I
        BUN     HANDLE_OUTPUT_INTERRUPT I
        
SEND_OUTPUT,
        LDA     OUTPUT_BUFFER
        OUT
        LDA     ZERO
        STA     OUTPUT_BUFFER
        BUN     HANDLE_OUTPUT_INTERRUPT I

// Initialize System
INIT_SYSTEM, HEX 0
        LDA     ZERO
        STA     BASE_REGISTER
        STA     BYTES_LOADED
        STA     LOADING_FLAG
        STA     INPUT_BUFFER
        STA     OUTPUT_BUFFER
        STA     SAVE_AC
        BUN     INIT_SYSTEM I

// Read Program Size (using interrupts)
READ_PROGRAM_SIZE, HEX 0
        LDA     ONE
        STA     LOADING_FLAG   // Set loading mode
        
        // Wait for input interrupt to provide size
        LDA     ZERO
        STA     PROG_SIZE
        
SIZE_WAIT,
        LDA     PROG_SIZE
        SZA
        BUN     SIZE_DONE
        BUN     SIZE_WAIT      // Wait for interrupt to set size
        
SIZE_DONE,
        LDA     ZERO
        STA     LOADING_FLAG
        BUN     READ_PROGRAM_SIZE I

// Allocate Memory for Program
ALLOCATE_MEMORY, HEX 0
        LDA     NEXT_FREE
        STA     BASE_REGISTER
        LDA     NEXT_FREE
        ADD     PROG_SIZE
        ADD     BUFFER_SPACE
        STA     NEXT_FREE
        LDA     BASE_REGISTER
        BUN     ALLOCATE_MEMORY I

// Setup Interrupt Vectors for Loaded Program
SETUP_INTERRUPT_VECTORS, HEX 0
        // Set up loaded program's interrupt vector at logical address 1
        LDA     BASE_REGISTER
        ADD     LOGICAL_INT_VEC  // Logical address 1
        STA     PHYS_INT_VEC
        
        // Store address of loaded program's ISR
        LDA     BASE_REGISTER
        ADD     PROG_ISR         // Logical address of program's ISR
        STA     TEMP_ADDR
        LDA     TEMP_ADDR
        STA     PHYS_INT_VEC I
        
        BUN     SETUP_INTERRUPT_VECTORS I

// Load Program with Interrupts
LOAD_PROGRAM, HEX 0
        LDA     ONE
        STA     LOADING_FLAG
        LDA     ZERO
        STA     LOAD_INDEX
        STA     BYTES_LOADED
        
LOAD_LOOP,
        LDA     BYTES_LOADED
        SUB     PROG_SIZE
        SPA
        BUN     WAIT_FOR_BYTE
        BUN     LOAD_DONE
        
WAIT_FOR_BYTE,
        // Wait for input interrupt to provide next byte
        LDA     LOAD_BUFFER
        SZA
        BUN     STORE_BYTE
        BUN     WAIT_FOR_BYTE
        
STORE_BYTE,
        // Store byte at physical address
        LDA     BASE_REGISTER
        ADD     LOAD_INDEX
        STA     PHYS_ADDR
        LDA     LOAD_BUFFER
        STA     PHYS_ADDR I
        STA     LOAD_BUFFER     // Clear buffer
        
        // Next byte
        LDA     LOAD_INDEX
        INC
        STA     LOAD_INDEX
        LDA     BYTES_LOADED
        INC
        STA     BYTES_LOADED
        BUN     LOAD_LOOP
        
LOAD_DONE,
        LDA     ZERO
        STA     LOADING_FLAG
        BUN     LOAD_PROGRAM I

// Execute Loaded Program
EXECUTE_PROGRAM, HEX 0
        // Transfer control to loaded program
        // The loaded program will handle its own interrupts
        LDA     BASE_REGISTER
        STA     CALL_PTR
        BSA     CALL_PTR I      // Call loaded program's main
        
        BUN     EXECUTE_PROGRAM I

// Context Save/Restore Subroutines
SAVE_CONTEXT, HEX 0
        // Save registers to stack
        LDA     AC_SAVE
        STA     STACK_PTR I
        // Add more register saves as needed
        BUN     SAVE_CONTEXT I

RESTORE_CONTEXT, HEX 0
        // Restore registers from stack
        LDA     STACK_PTR I
        STA     AC_SAVE
        // Add more register restores as needed
        BUN     RESTORE_CONTEXT I

// Data Section for Bootstrap Loader
ZERO,           DEC     0
ONE,            DEC     1
PROG_SIZE,      DEC     0
BASE_REGISTER,  DEC     0
BYTES_LOADED,   DEC     0
LOAD_INDEX,     DEC     0
LOADING_FLAG,   DEC     0
INPUT_BUFFER,   DEC     0
OUTPUT_BUFFER,  DEC     0
LOAD_BUFFER,    DEC     0
SAVE_AC,        DEC     0
AC_SAVE,        DEC     0
PHYS_ADDR,      HEX     0
PHYS_INT_VEC,   HEX     0
TEMP_ADDR,      HEX     0
CALL_PTR,       HEX     0
NEXT_FREE,      HEX     500    // Start after bootstrap
BUFFER_SPACE,   DEC     50
STACK_PTR,      HEX     400    // Stack area

// Logical addresses for loaded program
LOGICAL_INT_VEC,HEX     1      // Interrupt vector at logical 1
PROG_ISR,       HEX     50     // Program's ISR at logical 50
PROG_INPUT_HANDLER, HEX 100    // Program's input handler
PROG_OUTPUT_HANDLER, HEX 120   // Program's output handler

INDIRECT,       HEX     0      // For interrupt return

        END
