; Addition of two integers in ASCII form        ASCIIADD.ASM
; Objective: To demonstrate addition of two integers
;           in the ASCII representation.
; Input: None
; Output: Display the sum
;

%include "io.mac"

.DATA
sum_msg     db      'The sum is: ',0
number1     db      '1234567890'
number2     db      '1098765432'
sum         db      '          ',0          ; add NULL char to use PutStr
.CODE
    .STARTUP
    ; ESI is used as index into number1, number2 and sum
    mov     esi,9               ; ESI points to rightmost digit
    mov     ecx,10              ; iteration count (# of digits)
    clc                         ; clear carry (we use ADC not ADD)
add_loop:
    mov     al,[number1+esi]
    adc     al,[number2+esi]
    aaa                         ; ASCII adgust
    pushf                       ; save flags because OR
    or      al,30H              ;   changes CF that we need
    popf                        ;   in the next iteration
    mov     [sum+esi],al        ; store the sum byte
    dec     esi                 ; update ESI
    loop    add_loop
    PutStr  sum_msg             ; display sum
    PutStr  sum
    nwln
    .EXIT
