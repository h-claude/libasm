global ft_strcmp

section .text
ft_strcmp:
	xor RCX, RCX
.loop:
	mov AL, [RDI + RCX]
	mov DL, [RSI + RCX]
	test AL, AL
	je .end
	test DL, DL
	je .end
	cmp AL, DL
	jne .end
	inc RCX
	jmp .loop
.end:
	sub AL, DL
	movzx RAX, AL
	ret