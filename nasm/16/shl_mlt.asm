;8-bit multiplication using shifts             SHL_MLT.ASM
;
;        Objective: To multiply two 8-bit unsigned numbers
;                   using SHL rather than MUL instruction.
;            Input: Requests two unsigned numbers.
;           Output: Prints the multiplication result.
%include "io.mac"
.DATA
input_prompt   db  'Please input two short numbers: ',0
out_msg1       db  'The multiplication result is: ',0
query_msg      db  'Do you want to quit (Y/N): ',0

.CODE
    .STARTUP
read_input:
    PutStr  input_prompt ; request two numbers
    GetInt  AX           ; AX = first number
    GetInt  BX           ; BX = second number
    call    mult8        ; mult8 leaves result in AX
    PutStr  out_msg1
    PutInt  AX           
    nwln
    PutStr  query_msg    ; query whether to terminate
    GetCh   AL          
    cmp     AL,'Y'       ; if the response is not 'Y'
    jne     read_input   ; repeat the loop
done:                       
    .EXIT

;---------------------------------------------------------
; mult8 multiplies two 8-bit unsigned numbers passed on
; to it in AL and BL. The 16-bit result is returned in AX.
; This procedure uses the SHL instruction to do the
; multiplication. All registers, except AX, are preserved.
;---------------------------------------------------------
mult8:
    push    CX            ; save registers
    push    DX
    push    SI
    xor     DX,DX         ; DX = 0 (keeps mult. result)
    mov     CX,7          ; CX = # of shifts required
    mov     SI,AX         ; save original number in SI
repeat1:       ; multiply loop - iterates 7 times
    rol     BL,1          ; test number2 bits from left
    jnc     skip1         ; if 0, do nothing
    mov     AX,SI         ; else, AX = number1*bit weight
    shl     AX,CL          
    add     DX,AX         ; update running total in DX
skip1:
    dec     CX
    jnz     repeat1  
    rol     BL,1          ; test the rightmost bit of AL
    jnc     skip2         ; if 0, do nothing
    add     DX,SI         ; else, add number1
skip2:
    mov     AX,DX         ; move final result into AX
    pop     SI            ; restore registers
    pop     DX
    pop     CX
    ret
