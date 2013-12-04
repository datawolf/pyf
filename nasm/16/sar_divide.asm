; Division using shifts             SAR_DIVIDE.ASM
; Objective: To divide a 32 bit signed number
;           by a power of 2 using SAR
; Input: Requests two numbers from the user
; Output: Prints the division result.

%include "io.mac"

.DATA
prompt1         db      "Please input numerator: ",0
prompt2         db      "Please input denominator: ",0
out_msg1        db      "The integer division result is: ",0
query_msg       db      "Do you want to quit (Y/N)",0
error_msg       db      "Denominator is zero. ",
                db      "Enter a nonzero value: ",0
.CODE
    .STARTUP
read_input:
    PutStr      prompt1         ; request numerator
    GetLInt     eax
    PutStr      prompt2         ; request denominator
read_denom:
    GetLInt     ebx
    bsr         ecx, ebx        ; ecx receives the position of 
                                ; the leftmost 1 bit in ebx
    ; bsr clears ZF if there is at least 1 bit
    ; in denominator; ZF = 0 if all the bits are zero
    jnz         nonZero
    PutStr      error_msg       ; if denominator  is zero
    jmp         read_denom      ; read again
nonZero:
    sar         eax, cl
    PutStr      out_msg1        ; output the result
    PutLInt     eax
    nwln
    PutStr      query_msg       ; query whether to terminate
    GetCh       al
    cmp         al, 'Y'         ; if response is not 'Y'
    jne         read_input      ; repeat the loop
done:
    .EXIT
