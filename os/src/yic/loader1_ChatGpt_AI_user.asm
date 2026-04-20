; Developed with assistance from ChatGpt AI for educational purposes in OS courseslides

/ =========================================
/ User Program (Relocatable Style)
/ =========================================
ORG 200

USER,   HEX 0          / entry point for BSA

        BSA READ_CHAR  / AC ← input
        STA VALUE

        LDA VALUE
        ADD TEN
        STA RESULT

        LDA RESULT
        BSA OUTPUT     / print result

        BUN USER I     / return to loader

/ -----------------------------------------
/ Local data
/ -----------------------------------------
VALUE,  HEX 0
RESULT, HEX 0
TEN,    DEC 10
