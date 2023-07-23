ASSUME CS:CODE,DS:DATA
DATA SEGMENT
NUM1 DB ?
FACT DB ?
DATA ENDS
CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AH, 01H 
    INT 21H
    SUB AL, 30H
    MOV BL, AL
    MOV CX, AL 
    DEC CX      
    MOV AX, 0001H
    L1:
        MUL CX 
        LOOP L1
    MOV FACT, AL 
    MOV AH, 09H 
    MOV DX, OFFSET RESULT
    INT 21H
    MOV DL, FACT
    ADD DL, AL
    MOV AH, 02H
    INT 21H
    MOV AH, 4CH
    INT 21H

RESULT DB 'Factorial of input is: $'

CODE ENDS
END START