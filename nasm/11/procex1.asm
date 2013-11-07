; Parameter passing via registers       PROCEX1.ASM
;
;   Objective:  To show paramenter passing via registers.
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
    call        sum                 ; returen sum in AX
    PutStr      sum_msg             ; dispaly sum
    PutInt      AX
    nwln
done:
    .EXIT

;-------------------------------------------------------------
;   Procedure sum recieves two integers in CX and DX.
;   Thu sum of the two integers is returned in AX
;-------------------------------------------------------------
sum:
    mov     AX, CX                  ; sum = first number
    add     AX, DX                  ; sum = sum + second number
    ret

