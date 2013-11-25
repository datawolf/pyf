; sum of a long integer array           ARRAY_SUM.ASM
;
; Objective: to find sum of all elements of  an array
; Input:  None
; Output: display the sum
;

%include "io.mac"

.DATA
test_marks      dd  90,50,70,94,81,40,55,73,60
NUM_STUDENTS     EQU ($-test_marks)/4            ; number of student
sum_msg         db  'The sum of test marks is : ',0

.CODE
    .STARTUP
    mov     cx, NUM_STUDENTS        ; loop iteration count
    sub     eax, eax                ; sum = 0
    sub     esi, esi                ; array index = 0
add_loop:
    mov     ebx, [test_marks+esi*4]
    PutLInt ebx
    nwln
    add     eax, [test_marks+esi*4]
    inc     esi
    loop    add_loop

    PutStr  sum_msg
    PutLInt eax
    nwln
    .EXIT
