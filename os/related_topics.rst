Fundamental
-----------
https://www.circuitstoday.com/interfacing-hex-keypad-to-8051

Interfacing hex keypad to 8051
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This article is about interfacing a hex key pad to 8051 microcontroller. A clear knowledge on interfacing hex key pad to 8051 is  very essential  while designing embedded system projects which requires character or numeric input or both. For example projects like digital code lock, numeric calculator etc. Before going to the interfacing in detail, let’s have a look at the hex keypad.

Hex keypad
``````````
Hex key pad is essentially a collection of 16 keys arranged in the form of a 4×4 matrix. Hex key pad usually have keys representing numerics 0 to 9 and characters A to F. The simplified diagram of a typical hex key pad is shown in the figure below.

4x4 Keypad Interfacing with ATmega32 Microcontroller
````````````````````````````````````````````````````
https://circuitdigest.com/microcontroller-projects/keypad-interfacing-with-avr-atmega32

.. image:: Keypad-with-ATmega32.jpg

.. image:: ATmega32-Keypad-Circuit.gif

The 8051 Microcontroller and Embedded
`````````````````````````````````````
http://www.iust.ac.ir/files/ee/pages/az/mazidi.pdf

8051__mazidi.pdf

Embedded Systems - Shape The World
``````````````````````````````````
http://users.ece.utexas.edu/~valvano/Volume1/E-Book/C2_FundamentalConcepts.htm

https://circuitdigest.com/microcontroller-projects/4x4-keypad-interfacing-with-pic16f877a
https://technobyte.org/keypad-matrix-8051-interfacing/
https://circuitdigest.com/microcontroller-projects/4x4-keypad-interfacing-with-pic16f877a
https://technobyte.org/keypad-matrix-8051-interfacing/
https://www.edsim51.com/examples.html
https://electrosome.com/interfacing-keypad-8051-microcontroller-keil-c/
http://8051programming.blogspot.com/2014/01/8051-keypad-interface.html
https://www.circuitstoday.com/interfacing-hex-keypad-to-arduino
https://www.ques10.com/p/17241/interface-hex-keypad-and-seven-segment-display-to-/
http://users.ece.utexas.edu/~valvano/Volume1/E-Book/C2_FundamentalConcepts.htm
https://www.slideshare.net/Mrinmoy-Sengupta/keyboard-interfacing-with-8051-microcontroller
https://www.coursehero.com/file/13866143/Interfacing-hex-keypad-to-8051/
https://circuitdigest.com/microcontroller-projects/keypad-interfacing-with-8051-microcontroller
https://circuitdigest.com/microcontroller-projects/keypad-interfacing-with-avr-atmega32
https://www.circuitstoday.com/interfacing-hex-keypad-to-8051
http://8051programming.blogspot.com/2014/01/8051-keypad-interface.html
https://www.edsim51.com/simInstructions.html
https://www.allaboutcircuits.com/projects/use-a-keypad-with-your-arduino/
http://ece-research.unm.edu/jimp/310/slides/8086_IO3.html
https://microcontrollerslab.com/usb-interfacing-pic-microcontroller-code/
https://www.embedded.com/keyboard-and-display-multiplexing-the-traditional-approach/
http://users.ece.utexas.edu/~valvano/Volume1/E-Book/C2_FundamentalConcepts.htm
https://lisha.ufsc.br/~bezerra/disciplinas/Microprocessadores/tools/Edsim/EdSim51UsersGuide.htm
https://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/
https://www.researchgate.net/topic/Microcontroller-Programming
https://www.elprocus.com/matrix-keypad-interfacing-with-microcontroller/
https://www.instructables.com/How-to-choose-a-MicroController/
https://spectrum.ieee.org/computing/hardware/return-of-the-elf-making-a-1976-microcomputer-more-user-friendly
http://www.kswichit.com/8080kit/8080kit.htm
http://www.srinivasbt.com/esystems/keypad.htm
https://www.circuitstoday.com/interfacing-seven-segment-display-to-8051
https://ti.tuwien.ac.at/ecs/teaching/courses/mclu/theory-material/Microcontroller.pdf
https://www.eeeguide.com/8279-block-diagram/
https://www.labvolt.com/downloads/FC7-Microcontroller_compete_course.pdf
https://circuitdigest.com/microcontroller-projects/keypad-interfacing-with-avr-atmega32
https://www.electronicshub.org/led-interfacing-8051/
http://embedded-lab.com/blog/programmable-digital-timer-switch-using-a-pic-microcontroller/

https://circuitdigest.com/microcontroller-projects/4x4-keypad-interfacing-with-pic16f877a

MARIE: An Introduction to a Simple Computer 
````````````````````````````````````````````
https://www2.southeastern.edu/Academics/Faculty/kyang/2006/Fall/CMPS375/ClassNotes/CMPS375ClassNotesChap04.pdf
https://pic-microcontroller.com/pic16f877a-microcontroller-based-projects-list/
https://embeddedsystemdesign.weebly.com/uploads/6/2/6/7/62678637/programming_pic_with_c.pdf
https://www.electronics-tutorials.ws/combination/comb_6.html

Seven Segment Displays and Corresponding Decoders
`````````````````````````````````````````````````
https://www.electronique-et-informatique.fr/anglais/Digit/Digit_10TS2.php
http://www.sasurieengg.com/e-course-material/EEE/III-Year%20Sem%206/EE2354%20%20MPMC.pdf
http://mechasoft0.blogspot.com/2015/06/interfacing-44-hexpadkeypad-with-8051.html
https://www.101computing.net/bbc-microbit-counter-using-a-7-segment-display/7-segment-display-connections/

https://sites.google.com/site/tanglindigitalelectronics/basic-digital-circuits/bcd-to-seven-segment-display

7-segment-display-connections
`````````````````````````````
https://www.101computing.net/bbc-microbit-counter-using-a-7-segment-display/7-segment-display-connections/
https://semesters.in/theory-of-light-emitting-diode-light-emitting-diode-working-principle-pdf/diode34/

Process Synchronization
-----------------------
Hardware solution
^^^^^^^^^^^^^^^^^
ARM
```
LDREX and STREX
~~~~~~~~~~~~~~~
Load and Store Register Exclusive.

https://developer.arm.com/documentation/dui0489/c/arm-and-thumb-instructions/memory-access-instructions/ldrex-and-strex?lang=en

Syntax

LDREX{cond} Rt, [Rn {, #offset}]

STREX{cond} Rd, Rt, [Rn {, #offset}]

LDREXB{cond} Rt, [Rn]

STREXB{cond} Rd, Rt, [Rn]

LDREXH{cond} Rt, [Rn]

STREXH{cond} Rd, Rt, [Rn]

LDREXD{cond} Rt, Rt2, [Rn]

STREXD{cond} Rd, Rt, Rt2, [Rn]

where:

cond
is an optional condition code.

Rd
is the destination register for the returned status.

Rt
is the register to load or store.

Rt2
is the second register for doubleword loads or stores.

Rn
is the register on which the memory address is based.

offset
is an optional offset applied to the value in Rn. offset is permitted only in Thumb-2 instructions. If offset is omitted, an offset of 0 is assumed.

LDREX
LDREX loads data from memory.

If the physical address has the Shared TLB attribute, LDREX tags the physical address as exclusive access for the current processor, and clears any exclusive access tag for this processor for any other physical address.
Otherwise, it tags the fact that the executing processor has an outstanding tagged physical address.
STREX
STREX performs a conditional store to memory. The conditions are as follows:

If the physical address does not have the Shared TLB attribute, and the executing processor has an outstanding tagged physical address, the store takes place, the tag is cleared, and the value 0 is returned in Rd.
If the physical address does not have the Shared TLB attribute, and the executing processor does not have an outstanding tagged physical address, the store does not take place, and the value 1 is returned in Rd.
If the physical address has the Shared TLB attribute, and the physical address is tagged as exclusive access for the executing processor, the store takes place, the tag is cleared, and the value 0 is returned in Rd.
If the physical address has the Shared TLB attribute, and the physical address is not tagged as exclusive access for the executing processor, the store does not take place, and the value 1 is returned in Rd.
Restrictions
PC must not be used for any of Rd, Rt, Rt2, or Rn.

For STREX, Rd must not be the same register as Rt, Rt2, or Rn.

For ARM instructions:

SP can be used but use of SP for any of Rd, Rt, or Rt2 is deprecated in ARMv6T2 and above
For LDREXD and STREXD, Rt must be an even numbered register, and not LR
Rt2 must be R(t+1)
offset is not permitted.
For Thumb instructions:

SP can be used for Rn, but must not be used for any of Rd, Rt, or Rt2
for LDREXD, Rt and Rt2 must not be the same register
the value of offset can be any multiple of four in the range 0-1020.
Usage
Use LDREX and STREX to implement interprocess communication in multiple-processor and shared-memory systems.

For reasons of performance, keep the number of instructions between corresponding LDREX and STREX instruction to a minimum.

Note
The address used in a STREX instruction must be the same as the address in the most recently executed LDREX instruction. The result of executing a STREX instruction to a different address is unpredictable.

Architectures
ARM LDREX and STREX are available in ARMv6 and above.

ARM LDREXB, LDREXH, LDREXD, STREXB, STREXD, and STREXH are available in ARMv6K and above.

All these 32-bit Thumb instructions are available in ARMv6T2 and above, except that LDREXD and STREXD are not available in the ARMv7-M architecture.

There are no 16-bit versions of these instructions.

Examples

    MOV r1, #0x1                ; load the 'lock taken' value
try
    LDREX r0, [LockAddr]        ; load the lock value
    CMP r0, #0                  ; is the lock free?
    STREXEQ r0, r1, [LockAddr]  ; try and claim the lock
    CMPEQ r0, #0                ; did this succeed?
    BNE try                     ; no - try again
    ....                        ; yes - we have the lock

SWP and SWPB
~~~~~~~~~~~~
The use of SWP and SWPB is deprecated in ARMv6 and above. You can use LDREX and STREX instructions to implement more sophisticated semaphores in ARMv6 and above.

https://developer.arm.com/documentation/dht0008/a/swp-and-swpb/legacy-synchronization-instructions/swp-and-swpb

SWP (Swap) and SWPB (Swap Byte) provide a method for software synchronization that does not require disabling interrupts. This is achieved by performing a special type of memory access, reading a value into a processor register and writing a value to a memory location as an atomic operation. Example A.1 shows the implementation of simple mutex functions using the SWP instruction. SWP and SWPB are not supported in the Thumb instruction set, so the example must be assembled for ARM.

    EXPORT lock_mutex_swp
lock_mutex_swp PROC
    LDR r2, =locked
    SWP r1, r2, [r0]       ; Swap R2 with location [R0], [R0] value placed in R1
    CMP r1, r2             ; Check if memory value was 'locked'
    BEQ lock_mutex_swp     ; If so, retry immediately
    BX  lr                 ; If not, lock successful, return
    ENDP

    EXPORT unlock_mutex_swp
unlock_mutex_swp
    LDR r1, =unlocked
    STR r1, [r0]           ; Write value 'unlocked' to location [R0]
    BX  lr
    ENDP

In the SWP instruction in Example A.1, R1 is the destination register that receives the value from the memory location, and R2 is the source register that is written to the memory location. You can use the same register for destination and source.

The requirements for memory barriers mentioned in Memory barriers still apply for processors implementing architecture versions earlier than ARMv6. Where required, use the Drain Write Buffer or Drain Store Buffer CP15 operation on processors implementing versions of the architecture earlier than ARMv6.

10.140 SWP and SWPB
~~~~~~~~~~~~~~~~~~~
https://www.keil.com/support/man/docs/armasm/armasm_dom1361289909499.htm

Swap data between registers and memory.

Syntax
SWP{B}{cond} Rt, Rt2, [Rn]
where:
cond
is an optional condition code.
B
is an optional suffix. If B is present, a byte is swapped. Otherwise, a 32-bit word is swapped.
Rt
is the destination register. Rt must not be PC.
Rt2
is the source register. Rt2 can be the same register as Rt. Rt2 must not be PC.
Rn
contains the address in memory. Rn must be a different register from both Rt and Rt2. Rn must not be PC.
Usage
You can use SWP and SWPB to implement semaphores:
Data from memory is loaded into Rt.
The contents of Rt2 are saved to memory.
If Rt2 is the same register as Rt, the contents of the register are swapped with the contents of the memory location.
Note
The use of SWP and SWPB is deprecated in ARMv6 and above. You can use LDREX and STREX instructions to implement more sophisticated semaphores in ARMv6 and above.
Architectures
These ARM instructions are available in all versions of the ARM architecture.
There are no Thumb SWP or SWPB instructions.

x86
```
How does the CPU handle XCHG internally?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
https://electronics.stackexchange.com/questions/151631/how-does-the-cpu-handle-xchg-internally

XCHG--Exchange Register/Memory with Register
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
http://www.nacad.ufrj.br/online/intel/vtune/users_guide/mergedProjects/analyzer_ec/mergedProjects/reference_olh/mergedProjects/instructions/instruct32_hh/vc326.htm

CHG--Exchange Register/Memory with Register
Opcode
Instruction
Description
90+rw
XCHG AX, 16
Exchange r16 with AX
90+rw
XCHG r16, X
Exchange AX with r16
90+rd
XCHG EAX, r32
Exchange r32 with EAX
90+rd
XCHG r32, EAX
Exchange EAX with r32
86 /r
XCHG r/m8, r8
Exchange r8 (byte register) with byte from r/m8
86 /r
XCHG r8, r/m8
Exchange byte from r/m8 with r8 (byte register)
87 /r
XCHG r/m16, r16
Exchange r16 with word from r/m16
87 /r
XCHG r16, r/m16
Exchange word from r/m16 with r16
87 /r
XCHG r/m32, r32
Exchange r32 with doubleword from r/m32
87 /r
XCHG r32, r/m32
Exchange doubleword from r/m32 with r32

Description
Exchanges the contents of the destination (first) and source (second) operands. The operands can be two general-purpose registers or a register and a memory location. If a memory operand is referenced, the processor's locking protocol is automatically implemented for the duration of the exchange operation, regardless of the presence or absence of the LOCK prefix or of the value of the IOPL. (See the LOCK prefix description in this chapter for more information on the locking protocol.)
This instruction is useful for implementing semaphores or similar data structures for process synchronization. (See "Bus Locking" in Chapter 7 of the IA-32 Intel(R) Architecture Software Developer's Manual, Volume 3, for more information on bus locking.)
The XCHG instruction can also be used instead of the BSWAP instruction for 16-bit operands.
Operation
TEMP  DEST
DEST  SRC
SRC  TEMP
Flags Affected
None.
Protected Mode Exceptions
#GP(0) - If either operand is in a nonwritable segment. If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit. If the DS, ES, FS, or GS register contains a null segment selector.
#SS(0) - If a memory operand effective address is outside the SS segment limit.
#PF(fault-code) - If a page fault occurs.
#AC(0) - If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.
Real-Address Mode Exceptions
#GP - If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
#SS - If a memory operand effective address is outside the SS segment limit.
Virtual-8086 Mode Exceptions
#GP(0) - If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
#SS(0) - If a memory operand effective address is outside the SS segment limit.
#PF(fault-code) - If a page fault occurs.
#AC(0) - If alignment checking is enabled and an unaligned memory reference is made.
 
processor xchg instructions
```````````````````````````
Instruction type XCHG in 8085 Microprocessor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
https://www.tutorialspoint.com/instruction-type-xchg-in-8085-microprocessor#:~:text=In%208085%20Instruction%20set%2C%20there,1-Byte%20in%20the%20memory.

XCHG — Exchange Register/Memory with Register
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
https://www.felixcloutier.com/x86/xchg

Memory
------
File:Steps In a Translation Lookaside Buffer.png
https://en.wikipedia.org/wiki/Translation_lookaside_buffer

Translation Lookaside Buffer (TLB) in Paging
https://www.geeksforgeeks.org/translation-lookaside-buffer-tlb-in-paging/amp/

Old
----
https://www.cs.rutgers.edu/~pxk/416/notes/07-scheduling.html

Process Scheduling
Who gets to run next?
Paul Krzyzanowski
February 18, 2015

---

operating system memory management base register

https://www.tutorialspoint.com/operating_system/os_memory_management.htm
https://stackoverflow.com/questions/9578772/how-are-base-registers-limit-registers-and-relocation-registers-used
https://www.geeksforgeeks.org/logical-and-physical-address-in-operating-system/
https://www.inf.ed.ac.uk/teaching/courses/os/slides/09-memory16.pdf
https://web.cs.wpi.edu/~cs3013/c07/lectures/Section08-Memory_Management.pdf


linux gprof sample
http://www.thegeekstuff.com/2012/08/gprof-tutorial/
gcc -Wall -pg test_gprof.c test_gprof_new.c -o test_gprof
./test_gprof 
gprof test_gprof gmon.out > analysis.txt

---

http://stackoverflow.com/questions/375913/what-can-i-use-to-profile-c-code-in-linux/378024#378024

http://stackoverflow.com/questions/2497211/how-to-profile-multi-threaded-c-application-on-linux

http://code.google.com/p/jrfonseca/wiki/Gprof2Dot

http://code.google.com/p/google-perftools/

http://en.wikipedia.org/wiki/Valgrind

http://en.wikipedia.org/wiki/VTune

http://en.wikipedia.org/wiki/DTrace


