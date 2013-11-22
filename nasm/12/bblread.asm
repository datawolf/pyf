; Array read procedure          BBLREAD.ASM
;   Function: To read a set of nonzero integers values into an array.
;               Input is terminated by entering zero.
;   Receives: EBX = array pointer
;             ECX = array size
;   Returns:  EAX = number of values read.

%include "io.mac"

.CODE
global      read_array

read_array:
    push        EDX
    push        EBX
    sub         EDX, EDX        ; number count = 0
read_loop:
    GetLInt     EAX             ; read input number
    cmp         EAX, 0          ; if the number is zero
    je          read_done       ; no more numbers to read
    mov         [EBX], EAX      ; copy the number into array
    add         EBX, 4          ; EBX points the next element
    inc         EDX             ; increment number count
    loop        read_loop       ; reads a max of MAX_SIZE numbers
read_done:
    mov         EAX, EDX        ; returns the # of values read
    pop         EBX
    pop         EDX
    ret
