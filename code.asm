.MODEL SMALL 
.STACK 100H 
.DATA

t0	DW	 ?
t1	DW	 ?
t2	DW	 ?
t3	DW	 ?
t4	DW	 ?

a2	DW	 ?
b2	DW	 ?
i2	DW	 ?

.CODE 
MAIN PROC 
	mov ax, @DATA
	mov ds, ax

	mov ax, 0
	mov b2, ax
	mov ax, 0
	mov i2, ax
L4:		;FOR
	mov ax, i2
	mov t0, ax
	mov ax, t0
	cmp ax, 4
	jl L0
	mov t1, 0
	jmp L1
L0:
	mov t1, 1
L1:
	cmp t1, 0 	
	je L5	;END FOR
	mov ax, 3
	mov a2, ax
	mov ax, a2
	dec ax
	mov t3, axL2:		;WHILE
	cmp t3, 0 	
	je L3	;END WHILE
	mov ax, b2
	inc ax
	mov t4, ax	
	mov ax, a2
	dec ax
	mov t3, axL2:		;WHILE
	cmp t3, 0 	
	je L3	;END WHILE
	mov ax, b2
	inc ax
	mov t4, ax	
	
	jmp L2	;WHILE
L3:	;END WHILE
	
	mov ax, i2
	inc ax
	mov t2, ax	
	jmp L4	;FOR
L5:	;END FOR
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
