.MODEL SMALL
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
       
    XOR CX, CX ; N
    MOV AH, 1 
    INT 21h
    INPUT:
    INC BX
    CMP AL, 'x'
    JE END_INPUT
    ;PUSH AX
    MOV [BX], AL
    INC CX
    INT 21H
    JMP INPUT
   
    END_INPUT: 
    
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
    
    MOV AH, 9
    LEA DX, MSG2
    INT 21h   
            
    MOV CX, 16
    MOV BX, offset array
    
    PRINT:        
    MOV AH,2
    MOV DL, [BX]
    INT 21h
    MOV DL, ' '
    INT 21h
    INC BX
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
END MAIN
    