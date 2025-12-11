; recreate read

%define SYS_READ_64 0

%macro MACRO_SYS_READ_64 3
	mov RAX, SYS_READ_64
	mov RDI, %1
	mov RSI, %2
	mov RDX, %3
	syscall
%endmacro

global ft_read

section .text
ft_read:
	MACRO_SYS_READ_64 RDI, RSI, RDX
	ret