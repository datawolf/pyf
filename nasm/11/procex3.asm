; Parameter passing via stack           PROCEX3.ASM
;
;   Objective:  To show paramenter passing via stack.
;   Input:  Requests two integers from the user
;   Output: Outputs the sum of the input integers.

%include "io.mac"

.DATA
prompt_msg1     db  "Please input the first number: ",0
prompt_msg2     db  "Please input the second number: ",0
sum_msg         db  "The sum is ",0
.CODE
    .STARTUP
    PutStr      prompt_msg1         ; request the first number
    GetInt      CX                  ; CX = first number
    
    PutStr      prompt_msg2         ; request the second number
    GetInt      DX                  ; DX = second number
    push        CX                  ; place first number on stack
    push        DX                  ; place second number on stack
    call        sum                 ; returen sum in AX
    PutStr      sum_msg             ; dispaly sum
    PutInt      AX
    nwln
done:
    .EXIT

;-------------------------------------------------------------
;   Procedure sum recieves two integers via the stack 
;   Thu sum of the two integers is returned in AX
;-------------------------------------------------------------
sum:
    enter   0,0                     ; save EBP
    mov     AX, [EBP+10]            ; sum = first number
    add     AX, [EBP+8]             ; sum = sum + second number
    leave                           ; restore EBP
    ret     4                       ; return and clear parameters

