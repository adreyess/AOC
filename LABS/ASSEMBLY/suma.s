.data

msgPeticion:    .string "Introduzca dos números\n"
msgNum1:    	.string "Primer número: "
msgNum2:    	.string "Segundo número: "
formatNum:	.string "%d"
msgResultado:	.string "El resultado de la suma es %d, el total es %d\n"
msgContinuar:   .string "¿Desea continuar?(s/n)\n"
formatCont:	.string " %c"
msgFin:		.string "El acumulado supera los 20000"
num1:		.int 0
num2:		.int 0
numTot:		.int 0
cont:		.byte 0

.text

        .global main

lecNum:

	push %ecx
	push %edx

	pushl $msgNum1
	call printf
	add $4, %esp

	pushl $num1
	pushl $formatNum
	call scanf
	add $8, %esp

	pushl $msgNum2
	call printf
	add $4, %esp

	pushl $num2
	pushl $formatNum
	call scanf
	add $8, %esp

	mov num1, %eax
	add num2, %eax

	add %eax, numTot

	pop %edx
	pop %ecx

	ret



mostrarNum:

	push %ecx
	push %edx
	
	pushl numTot
	pushl %eax
	pushl $msgResultado
	call printf
	add $12, %esp


	pop %edx
	pop %ecx
	
	ret


main:
	push %eax
	push %ecx
	push %edx

	bucle:
	
	
	pushl $msgPeticion
	call printf
	add $4, %esp
		
	call lecNum

	cmpl $20000, numTot
	jg end

	call mostrarNum
	
	contin:

	pushl $msgContinuar
	call printf
	add $4, %esp	

	pushl $cont
	pushl $formatCont
	call scanf
	add $8, %esp

	
	cmpb $'s', cont 

	je bucle

	cmpb $'n', cont

	jne contin
	
	end:

	pop %edx
	pop %ecx
	pop %eax
	ret
	

