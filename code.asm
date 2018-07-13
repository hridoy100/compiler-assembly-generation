.MODEL SMALL 
.STACK 100H 
.DATA

t0	DW	 ?
t1	DW	 ?
t2	DW	 ?
t3	DW	 ?

su2	DW 	 ?
vu2	DW 	 ?
a3	DW	 ?
c3	DW	 ?
i3	DW	 ?
j3	DW	 ?
d3	DW	 ?
t3	DW	 ?

.CODE 
MAIN PROC 

	;push register data
	push ax
	push bx
	push cx
	push dx

	push t2
	push t1
	call fuu
	pop ax	;function's return value in ax register
	mov t3, ax
	pop dx
	pop cx
	pop bx
	pop ax

MAIN ENDP
include input.asm ; INDEC 
include decimal_output.asm ; OUTDEC
fuu PROC
	mov ax, vu2
	mov t0, ax
	mov ax, t0
	mov su2, ax
fuu ENDP
END MAIN
