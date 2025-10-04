; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Program with Procedure Vector Table (like interrupt vectors)
; Uses polling I/O with indirect BSA calls

        ORG     0
        BUN     MAIN

        ORG     50    // Procedure Vector Table
PVT,    HEX     100   // [50] = Address of INPUT procedure
        HEX     120   // [51] = Address of OUTPUT procedure  
        HEX     140   // [52] = Address of DELAY procedure

        ORG     100   // Main Program
MAIN,   LDA     ZERO
        STA     COUNT
        
        // Get input using vector table
        LDA     PVT_INPUT
        STA     CALL_PTR
        BSA     CALL_PTR I   // Indirect call to INPUT
        
        STA     NUM1
        
        // Get second input
        LDA     PVT_INPUT
        STA     CALL_PTR
        BSA     CALL_PTR I   // Indirect call to INPUT
        
        STA     NUM2
        
        // Process data
        LDA     NUM1
        ADD     NUM2
        STA     RESULT
        
        // Output result using vector table
        LDA     PVT_OUTPUT
        STA     CALL_PTR
        BSA     CALL_PTR I   // Indirect call to OUTPUT
        
        HLT

// Input Procedure (at fixed address)
        ORG     200
INPUT,  HEX     0     // Return address stored here
IN_POLL,SKI
        BUN     IN_POLL
        INP           // Character in AC
        BUN     INPUT I

// Output Procedure (at fixed address)  
        ORG     220
OUTPUT, HEX     0     // Return address stored here
        STA     TEMP_OUT
        
OUT_POLL,SKO
        BUN     OUT_POLL
        LDA     TEMP_OUT
        OUT
        
        // Call delay via vector table
        LDA     PVT_DELAY
        STA     CALL_PTR
        BSA     CALL_PTR I   // Indirect call to DELAY
        
        BUN     OUTPUT I

// Delay Procedure (at fixed address)
        ORG     240
DELAY,  HEX     0     // Return address stored here
        LDA     DELAY_COUNT
        STA     DELAY_CTR
        
DELAY_LOOP,
        LDA     DELAY_CTR
        SZA
        BUN     CONTINUE_DELAY
        BUN     DELAY I
        
CONTINUE_DELAY,
        DEC
        STA     DELAY_CTR
        BUN     DELAY_LOOP

// Data Section
        ORG     300
ZERO,       DEC     0
COUNT,      DEC     0
NUM1,       DEC     0
NUM2,       DEC     0
RESULT,     DEC     0
TEMP_OUT,   DEC     0
DELAY_COUNT,DEC     10
DELAY_CTR,  DEC     0
CALL_PTR,   HEX     0

// Vector table pointers (point to the vectors)
PVT_INPUT,  HEX     50      // Points to PVT[0]
PVT_OUTPUT, HEX     51      // Points to PVT[1]  
PVT_DELAY,  HEX     52      // Points to PVT[2]

        END
