.data

msg:    .string "Hola mundo!\n"

.text

        .global main

main:
	push %eax
	push %ecx
	push %edx

	pushl $msg
	call printf
	add $4, %esp

	pop %edx
	pop %ecx
	pop %eax
	ret
	