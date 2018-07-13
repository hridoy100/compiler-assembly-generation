.MODEL SMALL 
.STACK 100H
.DATA  
MSG DB "Enter Input Array: $"
MSG2 DB "Sorted Array: $"   
array DW 16 DUP (?)
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX    
    
    MOV AH, 9
    LEA DX, MSG
    INT 21h
    MOV BX, offset array
    XOR DI, DI ; N
    
BEGIN:
    
    XOR CX, CX ; Total
    
    XOR SI, SI ; SIgn bit
    MOV AH,1
    INT 21h

    CMP AL, '-'
    JE MINUS
    CMP AL, '+'
    JE PLUS
    JMP REPEAT2
    MINUS:
    MOV SI,1
    PLUS:
    INT 21H
    REPEAT2:
    
    ;INC BX
    
    CMP AL, '0'
    JNGE NOT_DIGIT
    CMP AL, '9'
    JNLE NOT_DIGIT
    AND AX, 000FH  ;convert to digit 
    PUSH AX
    ;MOV [BX], AX
    
    MOV AX, 10
    MUL CX
    POP CX
    ADD CX, AX
    ;MOV [BX], AX

    MOV AH,1
    INT 21h
    CMP AL, ' '
    JNE REPEAT2
    INC DI
    MOV AX, CX   ; store in AX
    MOV [BX], AX
    ;INC BX
    OR SI, SI    ;neg num
   
    JE EXIT      ; if not neg exit
    NEG AX       ; else negate
    MOV [BX], AX
    
    
    EXIT:
    INC BX
    POP DX
    POP CX
    POP SI
    JMP NOT_DIGIT
    
    NOT_DIGIT:
    CMP AL, 'x'
    JE ARRAY_CHECK
    MOV AH,2
    MOV DL, ' '
    INT 21h
    ;MOV DL, 0Ah
    ;INT 21h
    
    JMP BEGIN

ARRAY_CHECK:

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
    
    XOR DX, DX
    
    MOV AH, 9
    LEA DX, MSG2
    INT 21h   
            
    MOV CX, DI
    ;ADD CX, 1
    MOV BX, offset array
    
    PRINT:        
    MOV AX, [BX]
    CALL OUTDEC
    INC BX
    MOV AH, 2
    MOV DL, ' '
    INT 21H
    LOOP PRINT
    
    INT 21H 
    ; new line
    MOV AH,2
    MOV DL,0Dh
    INT 21H
    MOV DL,0Ah
    INT 21H
    
    ;TOP:
    ;POP DX
    ;INT 21H
    ;LOOP TOP
    
    MOV AH, 4CH
    INT 21H
    
    
MAIN ENDP
include decimal_output.asm ;include OUTDEC
END MAIN