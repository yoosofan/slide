; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Program with BSA for structured input/output routines

        ORG     100

START,  BSA     INPUT       // Call input subroutine
        STA     NUM1        // Store first number
        
        BSA     INPUT       // Call input subroutine again
        STA     NUM2        // Store second number
        
        // Process numbers
        LDA     NUM1
        ADD     NUM2
        STA     RESULT
        
        BSA     OUTPUT      // Call output subroutine
        
        HLT

// Input Subroutine: Returns with input in AC
INPUT,  HEX     0           // BSA stores return address here
POLL,   SKI                 // Poll input flag
        BUN     POLL        // Wait for input
        INP                 // Read input to AC
        BUN     INPUT I     // Return to caller

// Output Subroutine: Outputs AC content
OUTPUT, HEX     0           // Return address storage
OUT_P,  SKO                 // Poll output flag
        BUN     OUT_P       // Wait for output ready
        OUT                 // Output AC content
        BUN     OUTPUT I    // Return to caller

// Data Section
NUM1,   DEC     0
NUM2,   DEC     0
RESULT, DEC     0

        END