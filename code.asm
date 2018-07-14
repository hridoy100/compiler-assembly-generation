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
t7	DW	 ?
t8	DW	 ?
t9	DW	 ?
t10	DW	 ?
t11	DW	 ?

a2	DW 	 ?
a3	DW 	 ?
b3	DW 	 ?
x3	DW	 ?
t3	DW	 ?
a4	DW	 ?
b4	DW	 ?
t11	DW	 ?

.CODE 
MAIN PROC 
	mov ax, @DATA
	mov ds, ax

	mov ax, 1
	mov a4, ax
	mov ax, 2
	mov b4, ax

	;push register data
	push ax
	push bx
	push cx
	push dx

	push t10
	push t9

	call f

	pop ax		;function's return value in ax register
	mov t11, ax
	pop dx
	pop cx
	pop bx
	pop ax
	mov ax, t11
	mov a4, ax
	MOV AH,2
	MOV DL,0Dh
	INT 21H
	MOV DL,0Ah
	INT 21H
L0: 		;PRINT
	mov ax, a4

	CALL OUTDEC
	MOV AH,2
	MOV DL,0Dh
	INT 21H
	MOV DL,0Ah
	INT 21H
	pop bx		;RETRIEVE RETURN ADDRESS FROM THE CALL.
	push 0		;VALUE TO RETURN 
	push bx		;PUT RETURN ADDRESS BACK.

;return to operationg system
	MOV AH, 4CH
	INT 21H

MAIN ENDP
include decimal_output.asm 	; OUTDEC
f PROC
	pop bx 		;RETRIEVE RETURN ADDRESS FROM THE CALL.
	pop ax		;get value from stack
	mov a2 , ax	;get that value back into the variable..
	push bx 		;PUT RETURN ADDRESS BACK.
	pop bx		;RETRIEVE RETURN ADDRESS FROM THE CALL.
	push t1		;VALUE TO RETURN 
	push bx		;PUT RETURN ADDRESS BACK.
	mov ax, 9
	mov a2, ax
f ENDP
g PROC
	pop bx 		;RETRIEVE RETURN ADDRESS FROM THE CALL.
	pop ax		;get value from stack
	mov a3 , ax	;get that value back into the variable..
	pop ax		;get value from stack
	mov b3 , ax	;get that value back into the variable..
	push bx 		;PUT RETURN ADDRESS BACK.

	;push register data
	push ax
	push bx
	push cx
	push dx

	push t2

	call f

	pop ax		;function's return value in ax register
	mov t3, ax
	pop dx
	pop cx
	pop bx
	pop ax
	mov ax, a3
	mov t4, ax
	mov ax, t3
	mov bx, t4
	add ax, bx
	mov t5, ax
	mov ax, b3
	mov t6, ax
	mov ax, t5
	mov bx, t6
	add ax, bx
	mov t7, ax
	mov ax, t7
	mov x3, ax
	pop bx		;RETRIEVE RETURN ADDRESS FROM THE CALL.
	push t8		;VALUE TO RETURN 
	push bx		;PUT RETURN ADDRESS BACK.
g ENDP
END MAIN
