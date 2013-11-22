; Bubble sort procedure			BBLMAIN.ASM
;   Objective: To implement the bubble sort algorithm.
;   Input: A set of nonzero integers to be sorted.
;           Input is terminated by entering zero.
;   Output: Outputs the numbers in asceding order.
;
%define     CRLF        0DH,0AH
MAX_SIZE    EQU         20
%include "io.mac"

.DATA
prompt_msg      db  "Enter nozero intergers to be sorted.", CRLF
                db  "Enter zero to terminate the input.", 0
output_msg      db  "Input numbers in ascending order:", 0
error_msg       db  "No input entered.", 0

.UDATA
array           resd        MAX_SIZE            ; input array for integers

.CODE
extern      bubble_sort
extern      read_array
extern      output_array
    .STARTUP
    PutStr      prompt_msg          ; request input numbers
    nwln
    mov         EBX, array          ; EBX = array pointer
    mov         ECX, MAX_SIZE       ; ECX = array size

    call        read_array          ; reads input into the array
    ; returns the number of values read in EAX

    cmp         EAX,0               ; if no input is given
    ja          input_OK            ; dispaly error message
    PutStr      error_msg
    nwln
input_OK:
    push        EAX                 ; push array size onto stack
    push        array               ; push array pointer on stack
    call        bubble_sort

    PutStr      output_msg          ; display sorted input numbers
    nwln
    mov         EBX, array
    mov         ECX, EAX
    call        output_array
done:
    .EXIT

