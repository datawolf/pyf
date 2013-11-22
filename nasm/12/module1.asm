; Multimodule program for string length         MODULE1.ASM
;
;  Objective: To show how to programe using multimodule
;  Input: Requests an string
;  Output: Outputs the length of the input string
;
;
BUF_SIZE     EQU     41      ; string buffer size
%include "io.mac"

.DATA
prompt_msg      db      "Please input a string: ", 0
length_msg      db      "String length is: ", 0

.UDATA
string1         resb        BUF_SIZE

.CODE
extern      string_length
    .STARTUP
    PutStr      prompt_msg          ; request a string
    GetStr      string1, BUF_SIZE   ; read string from input

    mov         EBX, string1        ; EBX := string pointer
    call        string_length       ; return string length in AX
    PutStr      length_msg          ; display string length
    PutInt      AX
    nwln
done:
    .EXIT

