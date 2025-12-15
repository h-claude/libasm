; make the same function as strlen

global ft_strlen ; Make ft_strlen visible for linker

section .text
ft_strlen:
	xor RCX, RCX ; initialize RCX = 0
.loop:
	mov AL, [RDI + RCX] ; put the index caractere to AL
	test AL, AL ; test if zero
	je .done ; finish if yes
	inc RCX
	jmp .loop
.done:
	mov RAX, RCX
	ret
