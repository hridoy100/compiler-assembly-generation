INDEC PROC
    PUSH BX
    PUSH CX
    PUSH DX
BEGIN:
    XOR BX, BX ; Total
    XOR CX, CX ; SIgn bit
    MOV AH,1
    INT 21h
	CMP AL, 'x'
	JE EXIT 

    CMP AL, '-'
    JE MINUS
    CMP AL, '+'
    JE PLUS
    JMP REPEAT2
MINUS:
    MOV CX,1
PLUS:
    INT 21H
REPEAT2:
    CMP AL, '0'
    JNGE NOT_DIGIT
    CMP AL, '9'
    JNLE NOT_DIGIT
    AND AX, 000FH  ;convert to digit 
    PUSH AX
    
    MOV AX, 10
    MUL BX
    POP BX
    ADD BX, AX

    MOV AH,1
    INT 21h
    CMP AL, ' '
    JNE REPEAT2
    MOV AX, BX   ; store in AX
    OR CX, CX    ;neg num
    JE EXIT      ; if not neg exit
    NEG AX       ; else negate
EXIT:
    POP DX
    POP CX
    POP BX
    RET
    
NOT_DIGIT:
    MOV AH,2
    MOV DL, ' '
    INT 21h
    JMP BEGIN
INDEC ENDP