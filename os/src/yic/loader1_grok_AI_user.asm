; Developed with assistance from Grok AI for educational purposes in OS courseslides

; ================================================================
; USER PROGRAM (loaded at PROGRAM_BASE = 600)
; Simple example for OS course:
;   1. Read one input value
;   2. Add 10
;   3. Output the result
;   4. Return to loader via indirect BUN
; Uses helper routines from loader (no duplication)
; ================================================================

        ORG     600
USER_ENTRY, HEX 0       ; ← will be overwritten by loader's BSA
                        ; (stores return address here)

        BSA     200     ; call READ_WORD (fixed address in loader)
                        ; AC now contains the input value

        ADD     TEN
        BSA     300     ; call WRITE_WORD (fixed address in loader)

        BUN     USER_ENTRY I   ; return to loader

TEN,    DEC     10

        END
