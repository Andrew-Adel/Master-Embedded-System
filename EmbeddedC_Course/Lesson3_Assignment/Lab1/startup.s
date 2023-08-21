@@Created by Eng. Andrew Adel (for learn-in-depth Diploma)
.globl reset
reset:
		ldr sp, =stack_top
		bl main
stop: 	b stop
