global ft_strcpy

section .text
ft_strcpy:
	xor RCX, RCX
.loop:
	mov AL, [RSI + RCX]
	test AL, AL
	je  .end
	mov [RDI + RCX], AL
	inc RCX
	jmp .loop
.end:
	mov byte [RDI + RCX], 0
	mov RAX, RDI
	ret