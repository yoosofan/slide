; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Simple Bootstrap Loader with Absolute Addressing
; No base register - uses fixed physical addresses
; Uses interrupt-driven I/O

        ORG     0
        BUN     BOOTSTRAP

        ORG     1
        BUN     ISR

        ORG     100

BOOTSTRAP,
        BSA     INIT_SYSTEM
        BSA     READ_PROGRAM_SIZE
        STA     PROG_SIZE
        BSA     LOAD_PROGRAM
        ION
        BSA     PROGRAM_MAIN
        HLT

// Interrupt Service Routine
ISR,    STA     SAVE_AC
        
        SKI
        BUN     CHECK_OUTPUT
        
        // Input interrupt
        INP
        STA     INPUT_BUFFER
        BUN     ISR_EXIT
        
CHECK_OUTPUT,
        SKO
        BUN     ISR_EXIT
        
        // Output interrupt - device is ready for more data
        // Check if we have pending output
        LDA     OUTPUT_PENDING
        SZA
        BUN     HAS_PENDING_OUTPUT
        BUN     ISR_EXIT
        
HAS_PENDING_OUTPUT,
        LDA     OUTPUT_DATA
        OUT                    // ← THIS actually sends data to device
        LDA     ZERO
        STA     OUTPUT_PENDING // Clear pending flag
        
ISR_EXIT,
        LDA     SAVE_AC
        BUN     INDIRECT

// System Call: Write Output (Corrected)
SYS_WRITE_HANDLER, HEX 0
        // AC contains data to output
        STA     OUTPUT_DATA
        LDA     ONE
        STA     OUTPUT_PENDING
        
        // Check if output device is ready now
        SKO
        BUN     DEVICE_READY
        
        // Device not ready - interrupt will handle it later
        BUN     SYS_WRITE_RETURN
        
DEVICE_READY,
        // Device is ready - send immediately
        LDA     OUTPUT_DATA
        OUT                    // ← THIS sends data
        LDA     ZERO
        STA     OUTPUT_PENDING
        
SYS_WRITE_RETURN,
        BUN     SYS_WRITE_HANDLER I

// Read Program Size
READ_PROGRAM_SIZE, HEX 0
        LDA     ZERO
        STA     PROG_SIZE
        STA     INPUT_BUFFER
        
SIZE_WAIT,
        LDA     INPUT_BUFFER
        SZA
        BUN     STORE_SIZE
        BUN     SIZE_WAIT
        
STORE_SIZE,
        LDA     INPUT_BUFFER
        STA     PROG_SIZE
        STA     INPUT_BUFFER   // Clear buffer
        BUN     READ_PROGRAM_SIZE I

// Load Program
LOAD_PROGRAM, HEX 0
        LDA     ZERO
        STA     LOAD_INDEX
        
LOAD_LOOP,
        LDA     LOAD_INDEX
        SUB     PROG_SIZE
        SPA
        BUN     WAIT_FOR_BYTE
        BUN     LOAD_DONE
        
WAIT_FOR_BYTE,
        LDA     INPUT_BUFFER
        SZA
        BUN     STORE_BYTE
        BUN     WAIT_FOR_BYTE
        
STORE_BYTE,
        LDA     LOAD_INDEX
        ADD     PROGRAM_BASE
        STA     STORE_ADDR
        LDA     INPUT_BUFFER
        STA     STORE_ADDR I
        STA     INPUT_BUFFER   // Clear buffer
        
        LDA     LOAD_INDEX
        INC
        STA     LOAD_INDEX
        BUN     LOAD_LOOP
        
LOAD_DONE,
        BUN     LOAD_PROGRAM I

// Data Section
ZERO,           DEC     0
ONE,            DEC     1
PROG_SIZE,      DEC     0
LOAD_INDEX,     DEC     0
INPUT_BUFFER,   DEC     0
OUTPUT_DATA,    DEC     0
OUTPUT_PENDING, DEC     0
SAVE_AC,        DEC     0
STORE_ADDR,     HEX     0
PROGRAM_BASE,   HEX     500
PROGRAM_MAIN,   HEX     500
INDIRECT,       HEX     0

        END
       