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
	test RDI, RDI
	je .is_null
	push RDI
	mov RDI, [RSP]
	FT_STRLEN_FUNCTION RDI
	lea RAX, [RAX + 1]
	MALLOC_FUNCTION RAX
	test RAX, RAX
	je .fail
	pop RSI
	FT_STRCPY_FUNCTION RAX, RSI
	ret
.fail:
	add rsp, 8
	xor RAX, RAX
	ret
.is_null:
	xor RAX, RAX
	ret