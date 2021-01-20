			global _ft_strcmp

			section .text
_ft_strcmp:
			mov rax, 0
			mov rcx, 0
			mov rdx, 0
while:		cmp byte[rdi + rcx], 0
			je done
			cmp byte[rsi + rcx], 0
			je done
			mov al, byte[rdi + rcx]
			cmp byte[rsi + rcx], al
			jne done
			inc rcx
			jmp while

done:
			mov al, byte[rdi + rcx]
			mov dl, byte[rsi + rcx]
			sub rax, rdx
			ret