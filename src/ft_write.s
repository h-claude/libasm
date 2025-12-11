; recreate write function in asm

%define SYS_WRITE_64 1
%define STDOUT 1

%macro MACRO_SYS_WRITE_64 3
	mov RAX, SYS_WRITE_64 ; set which function we want to call (1)
	mov RDI, %1 ; set which std output
	mov RSI, %2 ; first argument
	mov RDX, %3 ; second argument
	syscall
%endmacro

global ft_write

section .text
ft_write:
	MACRO_SYS_WRITE_64 RDI,RSI,RDX
	ret