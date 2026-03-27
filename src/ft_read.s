; recreate read
extern __errno_location

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
	test RAX, RAX
	js .error
	ret
.error
	neg RAX
	push RAX
	call __errno_location wrt ..plt
	pop QWORD [RAX]
	mov RAX, -1
	ret