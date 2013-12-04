;8 bit multiplication using shifts   SHL_MLT2.ASM
;
;        Objective: To multiply two 8-bit unsigned numbers
;                   using SHL rather than MUL instruction.
;                   Uses bit instructions BSF and BTC.
;            Input: Requests two unsigned numbers from user.
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
    PutStr  query_msg    ; query user whether to terminate
    GetCh   AL           
    cmp     AL,'Y'       ; if response is not 'Y'
    jne     read_input   ; repeat the loop
done:                      
        .EXIT

;---------------------------------------------------------
; mult8 multiplies two 8-bit unsigned numbers passed on
; to it in AL and BL. The 16-bit result is returned in AX.
; This procedure uses the SHL instruction to do the
; multiplication. All registers, except AX, are preserved.
; Demonstrates the use of bit instructions BSF and BTC.
;---------------------------------------------------------
mult8:
    push    CX           ; save registers
    push    DX
    push    SI
    xor     DX,DX        ; DX = 0 (keeps mult. result)
    mov     SI,AX        ; save original number in SI
repeat1:
    bsf     CX,BX        ; CX = first 1 bit position
    jz      skip1        ; if ZF=1, no 1 bit in B
    mov     AX,SI        ; else, AX = number1*bit weight
    shl     AX,CL
    add     DX,AX        ; update running total in DX
    btc     BX,CX        ; complement the bit found by BSF
    jmp     repeat1
skip1:
    mov     AX,DX        ; move final result into AX
    pop     SI           ; restore registers
    pop     DX
    pop     CX
    ret

