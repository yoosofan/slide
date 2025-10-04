; Developed with assistance from DeepSeek AI for educational purposes in OS course slides
; Program with Procedure Vector Table (like interrupt vectors)
; Uses polling I/O with indirect BSA calls

        ORG     0
START,  BSA     READ_COUNT
        STA     BYTE_COUNT
        BSA     INIT_LOAD 
        BSA     LOAD_LOOP 
        BSA     EXECUTE   
        BUN     0        
        HLT               

READ_COUNT, HEX 0
RD_CNT, SKI               
        BUN     RD_CNT
        INP               
        BUN     READ_COUNT I 

INIT_LOAD, HEX 0
        LDA     ZERO
        STA     LOAD_PTR   
        STA     CURRENT_IDX
        BUN     INIT_LOAD I

LOAD_LOOP, HEX 0
        LDA     CURRENT_IDX
        SUB     BYTE_COUNT
        SPA              
        BUN     LOAD_BYTE
        BUN     LOAD_LOOP I

LOAD_BYTE,
        BSA     READ_BYTE
        STA     TEMP_BYTE
        
        LDA     LOAD_PTR
        STA     STORE_PTR
        LDA     TEMP_BYTE
        STA     STORE_PTR I 
        
        LDA     LOAD_PTR
        INC
        STA     LOAD_PTR
        LDA     CURRENT_IDX
        INC
        STA     CURRENT_IDX
        BUN     LOAD_LOOP  

READ_BYTE, HEX 0
RD_BYT, SKI             
        BUN     RD_BYT
        INP             
        BUN     READ_BYTE I 

        ORG     128
EXECUTE, HEX 0
        
        LDA     ZERO
        STA     RESULT
        BUN     EXECUTE I
        
        ORG     64     
ZERO,       DEC     0
BYTE_COUNT, DEC     0  
LOAD_PTR,   HEX     128
CURRENT_IDX,DEC     0  
TEMP_BYTE,  DEC     0  
STORE_PTR,  HEX     0  
RESULT,     DEC     0  

        END
