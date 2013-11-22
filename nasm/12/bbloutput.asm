; Array output procedure            BBLOUTPUT.ASM
;   Function: to print the values of an array
;   Receives: EBX = array pointer
;             ECX = array size
;   Returns: None.
%include "io.mac"

.CODE
global  output_array

output_array:
    push    EBX
    push    ECX
print_loop:
    PutLInt     [EBX]
    nwln
    add     EBX,4
    loop    print_loop
    pop     ECX
    pop     EBX
    ret
