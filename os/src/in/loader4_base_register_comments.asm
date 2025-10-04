; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Relocating Bootstrap Loader with Base Register
; Loaded program thinks it starts at 0, but physical address = base register

        ORG     0

BOOTSTRAP,
        BSA     INIT_SYSTEM
        BSA     READ_PROGRAM_SIZE
        STA     PROG_SIZE
        
        BSA     ALLOCATE_MEMORY
        STA     BASE_REGISTER  // Store base address for loaded program
        
        BSA     LOAD_PROGRAM   // Load program to base address
        
        // Set up procedure vector table for loaded program
        BSA     SETUP_PVT
        
        // Execute loaded program with base register
        BSA     EXECUTE_PROGRAM
        
        HLT

// Initialize System
INIT_SYSTEM, HEX 0
        LDA     ZERO
        STA     BASE_REGISTER
        STA     BYTES_LOADED
        BUN     INIT_SYSTEM I

// Read Program Size
READ_PROGRAM_SIZE, HEX 0
        BSA     READ_INPUT
        BUN     READ_PROGRAM_SIZE I

// Allocate Memory for Program
ALLOCATE_MEMORY, HEX 0
        // Simple allocation: use next available memory
        LDA     NEXT_FREE
        STA     BASE_REGISTER
        // Update next free address
        LDA     NEXT_FREE
        ADD     PROG_SIZE
        ADD     BUFFER_SPACE  // Add some buffer
        STA     NEXT_FREE
        LDA     BASE_REGISTER // Return base in AC
        BUN     ALLOCATE_MEMORY I

// Load Program with Base Addressing
LOAD_PROGRAM, HEX 0
        LDA     ZERO
        STA     LOAD_INDEX
        
LOAD_LOOP,
        LDA     LOAD_INDEX
        SUB     PROG_SIZE
        SPA                     // Skip if loaded all bytes
        BUN     LOAD_BYTE
        BUN     LOAD_PROGRAM I  // Return

LOAD_BYTE,
        BSA     READ_INPUT      // Read program byte
        STA     TEMP_BYTE
        
        // Calculate physical address: base + index
        LDA     BASE_REGISTER
        ADD     LOAD_INDEX
        STA     PHYS_ADDR
        
        // Store byte at physical address
        LDA     TEMP_BYTE
        STA     PHYS_ADDR I
        
        // Next byte
        LDA     LOAD_INDEX
        INC
        STA     LOAD_INDEX
        BUN     LOAD_LOOP

// Setup Procedure Vector Table for Loaded Program
SETUP_PVT, HEX 0
        // PVT is at fixed logical address 150 in loaded program's view
        // Physical address = base + 150
        
        LDA     BASE_REGISTER
        ADD     LOGICAL_PVT
        STA     PHYS_PVT
        
        // Store input procedure address (logical 200 -> physical base+200)
        LDA     BASE_REGISTER
        ADD     LOGICAL_INPUT
        STA     TEMP_ADDR
        LDA     TEMP_ADDR
        STA     PHYS_PVT I      // PVT[0] = base + 200
        
        // Store output procedure address (logical 220 -> physical base+220)
        LDA     BASE_REGISTER
        ADD     LOGICAL_OUTPUT
        STA     TEMP_ADDR
        LDA     TEMP_ADDR
        STA     PHYS_PVT I      // PVT[1] = base + 220
        
        BUN     SETUP_PVT I

// Execute Program with Base Register
EXECUTE_PROGRAM, HEX 0
        // The loaded program expects to run from address 0
        // We need to adjust all addresses by base register
        
        // For demonstration, we'll call the program's main routine
        // Assume main is at logical address 0 (physical = base + 0)
        
        LDA     BASE_REGISTER
        STA     CALL_PTR
        BSA     CALL_PTR I      // Call main routine
        
        BUN     EXECUTE_PROGRAM I

// Read Input Subroutine
READ_INPUT, HEX 0
INPUT_WAIT,
        SKI
        BUN     INPUT_WAIT
        INP
        BUN     READ_INPUT I

// Data Section for Bootstrap Loader
ZERO,           DEC     0
PROG_SIZE,      DEC     0
BASE_REGISTER,  DEC     0
BYTES_LOADED,   DEC     0
LOAD_INDEX,     DEC     0
TEMP_BYTE,      DEC     0
PHYS_ADDR,      HEX     0
PHYS_PVT,       HEX     0
TEMP_ADDR,      HEX     0
CALL_PTR,       HEX     0
NEXT_FREE,      HEX     256    // Start loading after bootstrap
BUFFER_SPACE,   DEC     50     // Extra space for data

// Logical addresses from loaded program's perspective
LOGICAL_PVT,    HEX     150    // PVT at logical address 150
LOGICAL_INPUT,  HEX     200    // Input proc at logical 200
LOGICAL_OUTPUT, HEX     220    // Output proc at logical 220

        END
