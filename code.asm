.MODEL SMALL 
.STACK 100H 
.DATA
	t0 DW ?
	t1 DW ?
	t2 DW ?
	t3 DW ?
	t4 DW ?
	t5 DW ?
	t6 DW ?
	t7 DW ?
	t8 DW ?
	t9 DW ?
	t10 DW ?
	t11 DW ?
.CODE 
MAIN PROC 
	mov bx, 0
	add bx, bx
	mov ax, 1
	mov a[bx], ax
	mov bx, 1
	add bx, bx
	mov ax, 5
	mov a[bx], ax
	mov bx, 0
	add bx, bx
	mov ax, a[bx]
	mov t0, ax
	mov bx, 1
	add bx, bx
	mov ax, a[bx]
	mov t1, ax
	mov ax, t0
	mov bx, t1
	add ax, bx
	mov t2, ax
	mov ax, t2
	mov i, ax
	mov ax, 2
	mov bx, 3
	mul bx
	mov t3, ax
	mov ax, 5
	mov bx, 3
	xor dx, dx
	div bx
	mov t4, ah
	mov ax, t4
	cmp ax, 4
	jl L0
	mov t5, 0
	jmp L1
L0:
	mov t5, 1
L1:
	mov ax, t5
	mov bx, 8
	cmp ax, 0
	je L2
	cmp bx, 0
	je L2
	mov t6, 1
	jmp L3
L2 : 
	mov t6, 0
L3 : 
	mov ax, t3
	mov bx, t6
	add ax, bx
	mov t7, ax
	mov ax, t7
	mov bx, 2
	cmp ax, 0
	jne L4
	cmp bx, 0
	jne L4
	mov t8, 0
	jmp L5
L4 : 
	mov t8, 1
L5 : 
	mov ax, t8
	mov j, ax
	mov ax, 3.5
	mov bx, 2
	mul bx
	mov t10, ax
	mov ax, var(1,t9)
	mov bx, t10
	add ax, bx
	mov t11, ax
	mov ax, t11
	mov d, ax

MAIN ENDP
END MAIN
