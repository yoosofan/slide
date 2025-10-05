; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Simple User Program - Loads at absolute address 500
; Uses system calls via fixed memory locations
// User Program with Proper Output

        ORG     500

MAIN,   HEX     0
        ION
        
        // Get first number
        BSA     SYS_READ
        STA     NUM1
        
        // Get second number
        BSA     SYS_READ  
        STA     NUM2
        
        // Calculate sum
        LDA     NUM1
        ADD     NUM2
        STA     RESULT
        
        // Output result
        BSA     SYS_WRITE
        
        BUN     MAIN I

// System Call: Read Input
SYS_READ, HEX   0
        LDA     ZERO
        STA     USER_INPUT
        
READ_WAIT,
        LDA     USER_INPUT
        SZA
        BUN     READ_DONE
        BUN     READ_WAIT
        
READ_DONE,
        LDA     USER_INPUT
        STA     SYS_READ I    // Return input in AC
        LDA     ZERO
        STA     USER_INPUT    // Clear for next
        BUN     SYS_READ I

// System Call: Write Output
SYS_WRITE, HEX  0
        // Data to output is already in AC
        STA     USER_OUTPUT
        LDA     ONE
        STA     USER_OUT_PENDING
        
        // Try to output immediately if device ready
        SKO
        BUN     OUTPUT_NOW
        
        // Wait for output interrupt
WRITE_WAIT,
        LDA     USER_OUT_PENDING
        SZA
        BUN     WRITE_WAIT
        BUN     SYS_WRITE I
        
OUTPUT_NOW,
        LDA     USER_OUTPUT
        OUT                    // ← THIS sends the data
        LDA     ZERO
        STA     USER_OUT_PENDING
        BUN     SYS_WRITE I

// Data
NUM1,        DEC     0
NUM2,        DEC     0
RESULT,      DEC     0
USER_INPUT,  DEC     0
USER_OUTPUT, DEC     0
USER_OUT_PENDING, DEC 0
ZERO,        DEC     0
ONE,         DEC     1

        END