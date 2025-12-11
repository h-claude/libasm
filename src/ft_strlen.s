; make the same function as strlen

global ft_strlen ; Make ft_strlen visible for linker

section .text
ft_strlen:
	xor RCX, RCX
	