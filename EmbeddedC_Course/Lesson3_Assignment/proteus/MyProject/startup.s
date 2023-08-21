/*startup_cortexM3.s
Eng. Andrew Adel
*/

/*SRAM @ 0x20000000*/

/*Vector Section*/
.section .vectors	
.word 0x20001000		/*Stack_top @ 0x20001000*/
.word _reset 			/*1. address of reset section*/
.word Vector_handler 	/*2. NMI_handler*/
.word Vector_handler	/*3. HARD_FAULT_handler*/
.word Vector_handler	/*4. MM Fault*/
.word Vector_handler	/*5. Bus Fault*/
.word Vector_handler	/*6. Usage Fault*/
.word Vector_handler	/*7. RESERVED*/
.word Vector_handler	/*8. RESERVED*/
.word Vector_handler	/*9. RESERVED*/
.word Vector_handler	/*10. RESERVED*/
.word Vector_handler	/*11. SV call*/
.word Vector_handler	/*12. Debug call*/
.word Vector_handler	/*13. RESERVED*/
.word Vector_handler	/*14. PendSV*/
.word Vector_handler	/*15. SysTick*/
.word Vector_handler	/*16. IRQ0*/
.word Vector_handler	/*17. IRQ1*/
.word Vector_handler	/*18. IRQ2*/
.word Vector_handler	/*19. ...*/
			  /*on to IRQ67*/

.section .text
_reset:
	bl main
	b .

.thumb_func
Vector_handler:
	b _reset
/*_NMI_handler:



_HARD_FAULT_handler:
*/
