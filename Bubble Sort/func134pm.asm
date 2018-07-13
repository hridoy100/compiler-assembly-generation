.MODEL SMALL 
.STACK
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
INPUT:
    
    CALL INDEC
    PUSH AX
    CMP AL, 'x'
    JE END_INPUT
    MOV [BX], AX
    INC DI
    INC BX
    JMP INPUT
END_INPUT:

;sort
    MOV CX, DI
    CMP CX, 1
    JE PRINT
    DEC CX ; CX = n-1;
    
    FOR1:
    MOV BX, CX
    MOV SI, 0
    
    FOR2:
    MOV AX, array[SI]
    MOV DX, array[SI+2]
    CMP AX, DX
    JLE AFTER_SWAP  
    
    MOV array[SI],DX
    MOV array[SI+2], AX
     
    AFTER_SWAP:
    INC SI
    DEC BX
    CMP BX, 0
    
    JNE FOR2
    
    LOOP FOR1 
    ; new line
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
;OUTPUT    
    MOV AH, 9
    LEA DX, MSG2
    INT 21h   
            
    MOV CX, DI
    ;ADD CX, 1
    MOV BX, offset array
    
    PRINT:
    ;XOR AX, AX
    POP AX        
    MOV AX, [BX]
    CALL OUTDEC
    INC BX
    
    MOV AH, 2
    MOV DL, ' '
    INT 21H
    LOOP PRINT
    
    MOV AH, 4CH
    INT 21H
        
    
MAIN ENDP
include IN.asm ; INDEC
include decimal_output.asm ; OUTDEC
END MAIN
    