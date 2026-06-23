%macro MALLOC_FUNCTION 1
	mov RDI, %1
	call malloc wrt ..plt
%endmacro

%macro FT_STRLEN_FUNCTION 1
	mov RDI, %1
	call ft_strlen wrt ..plt
%endmacro

%macro FT_STRCPY_FUNCTION 2
	mov RDI, %1
	mov RSI, %2
	call ft_strcpy wrt ..plt
%endmacro

default rel
global ft_strdup
extern ft_strlen
extern malloc
extern ft_strcpy

section .text
ft_strdup:
	push R12
	test RDI, RDI
	je .is_null
	mov R12, RDI
	FT_STRLEN_FUNCTION RDI
	inc RAX
	MALLOC_FUNCTION RAX
	test RAX, RAX
	je .fail
	FT_STRCPY_FUNCTION RAX, R12
	pop R12
	ret
.fail:
	pop R12
	xor RAX, RAX
	ret
.is_null:
	pop R12
	xor RAX, RAX
	ret