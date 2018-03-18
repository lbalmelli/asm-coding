;
;	NASM Notation sharko 
;	
;	to compile:
;			> nasm -f elf64 hello_sharko.asm && ld -s -o hello_sharko hello_sharko.o
;

section .data
msg	db	"Hello, sharko", 0xa		; string with return
len equ $ - msg					; lenght of string, $ is here

section .text

	global _start

_start:

	mov rdx, len        ; msg length
	mov rcx, msg		; pointer to message
	mov rbx, 1			; 1 = stdout
	mov rax, 4			; sys call tp write
	int 0x80			; call kernel interrupt and exit
	mov rbx, 0			; retun code
	mov rax, 1			; sys call for exit()
	int 0x80

