			global _ft_strcpy

			section .text
_ft_strcpy:
			mov rcx, 0
while:		cmp byte[rsi + rcx], 0
			je done
			mov al, byte[rsi + rcx]
			mov byte[rdi + rcx], al
			inc rcx
			jmp while

done:       
			mov byte[rdi + rcx], 0
			mov rax, rdi
			ret
