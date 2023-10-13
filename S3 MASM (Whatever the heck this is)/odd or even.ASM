ASSUME CS:CODE, DS:DATA
DATA SEGMENT
    M1 DB 10, 13, "ENTER THE NUMBER: $"
    M2 DB 10, 13, "THE NUMBER IS ODD $"
    M3 DB 10, 13, "THE NUMBER IS EVEN $"
DATA ENDS
CODE SEGMENT
    START:
    MOV AX, DATA
    MOV DS, AX
    LEA DX, M1
    MOV AH, 09H
    INT 21H
    MOV AH, 01H
    INT 21H
    SUB AL, 30H
    MOV CL, 02H
    DIV CL
    CMP AH, 01H
    JZ label1
    JMP label2
    label1: LEA DX, M2
            MOV AH, 09H
            INT 21H
            JMP exit
    label2: LEA DX, M3
            MOV AH, 09H
            INT 21H
            JMP exit    
    exit:   MOV AH, 4CH
            INT 21H
            CODE ENDS
            END START   
