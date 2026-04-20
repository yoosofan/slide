; Developed with assistance from Gemini AI for educational purposes in OS slides

/ ====================================================================
/ PROGRAM 2: User Application (Loaded dynamically by Kernel)
/ ====================================================================

        ORG     500
MAIN,   HEX     0               / OS Loader's BSA stores return address here
                                / Execution actually starts at 501

        / Step 4.1: Read input using OS System Call
        BSA     OS_READ I
        STA     INPUT_VAL

        / Step 4.2: Add 10 to the input
        ADD     TEN

        / Step 4.3: Show result using OS System Call
        BSA     OS_WRITE I

        / Step 4.4: Return to the loader gracefully
        BUN     MAIN I

/ --------------------------------------------------------------------
/ User Variables & OS Pointers
/ --------------------------------------------------------------------
INPUT_VAL,  DEC     0
TEN,        DEC     10

/ These are the indirect pointers mapping to the OS Kernel's addresses
OS_READ,    HEX     010         / Fixed address of SYS_READ in Kernel
OS_WRITE,   HEX     020         / Fixed address of SYS_WRITE in Kernel

        END
