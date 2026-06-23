global ft_strcmp

section .text
ft_strcmp:
	xor RCX, RCX
.loop:
	movzx EAX, byte [RDI + RCX]
	movzx EDX, byte [RSI + RCX]
	test AL, AL
	je .end
	test DL, DL
	je .end
	cmp AL, DL
	jne .end
	inc RCX
	jmp .loop
.end:
	sub EAX, EDX
	ret