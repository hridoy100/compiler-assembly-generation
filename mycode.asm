.MODEL SMALL 
.STACK 100H 
.DATA

t0	DW	 ?
t1	DW	 ?
t2	DW	 ?
t3	DW	 ?
t4	DW	 ?
t5	DW	 ?
t6	DW	 ?

a2	DW	 ?
b2	DW	 ?

.CODE 
MAIN PROC 
	mov ax, @DATA
	mov ds, ax

	mov ax, 2
	mov bx, 3
	add ax, bx
	mov t0, ax
	mov ax, 1
	mov bx, t0
	mul bx
	mov t1, ax
	mov ax, t1
	mov bx, 3
	xor dx, dx
	div bx
	mov t2, ah
	mov ax, t2
	mov a2, ax
	mov ax, 1
	cmp ax, 5
	jl L0
	mov t3, 0
	jmp L1
L0:
	mov t3, 1
L1:
	mov ax, t3
	mov b2, ax
	mov ax, a2
	mov t4, ax
	mov ax, b2
	mov t5, ax
	mov ax, t4
	mov bx, t5
	cmp ax, 0
	je L2
	cmp bx, 0
	je L2
	mov t6, 1
	jmp L3
L2: 
	mov t6, 0
L3: 
	mov ax, t6
	cmp ax, 0
	je L4	;ELSE
	jmp L5	;ENDIF
L4:		;ELSE
L5:		;ENDIF
	MOV AH,2
	MOV DL,0Dh
	INT 21H
	MOV DL,0Ah
	INT 21H
L6: 		;PRINT
	mov ax, a2

	CALL OUTDEC
	MOV AH,2
	MOV DL,0Dh
	INT 21H
	MOV DL,0Ah
	INT 21H
	MOV AH,2
	MOV DL,0Dh
	INT 21H
	MOV DL,0Ah
	INT 21H
L7: 		;PRINT
	mov ax, b2

	CALL OUTDEC
	MOV AH,2
	MOV DL,0Dh
	INT 21H
	MOV DL,0Ah
	INT 21H

MAIN ENDP
include decimal_output.asm 	; OUTDEC
END MAIN