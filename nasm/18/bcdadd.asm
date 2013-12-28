; Addition of integers in packed BCD form           BCDADD.ASM
;
; Objective: To demonstrate addition of two integers
;               in the packed BCD representation
; Input: None
; Output: Display the sum
;
%define     SUM_LENGTH      10
%include "io.mac"

.DATA
sum_msg         db      "The sum is: ",0
number1         db      12H,34H,56H,78H,90H
number2         db      10H,98H,76H,54H,32H
ASCIIsum        db      '          ',0      ; add NULL char
.UDATA
BCDsum          resb    5
.CODE
    .STARTUP
    mov     esi,4
    mov     ecx,5           ; loop iteration count
    clc                     ; clear carray flags (we use adc NOT add)
add_loop:
    mov     al,[number1+esi]
    adc     al,[number2+esi]
    daa                     ; ASCII adjust
    mov     [BCDsum+esi],al ; store the sum byte
    dec     esi             ; update ESI
    loop    add_loop
    call    ASCII_convert
    PutStr  sum_msg         ; display sum
    PutStr  ASCIIsum
    nwln
    .EXIT


;-----------------------------------------------------------------
; Converts the packed decimal number (5 digits) in BCDsum
; to ASCII represenation and stores it in ASCIIsum.
; All registers are preserved.
;-----------------------------------------------------------------
ASCII_convert:
    pushad              ; save registers
    ; ESI is uesed as index into ASCIIsum
    mov     esi,SUM_LENGTH-1
    ; EDI is used as index into BCDsum
    mov     edi,4
    mov     ecx,5           ; loop count (# of BCD digits)
cnv_loop:
    mov     al,[BCDsum+edi] ; al = BCD digits
    mov     ah,al           ; save the BCD digits

    ; convert right digits to ASCII & store in ASCIIsum
    and     al,0FH
    or      al,30H
    mov     [ASCIIsum+esi],al
    dec     esi

    mov     al,ah           ; restore the BCD digits

    ; convert left digits to ASCII & store in ASCIIsum
    shr     al,4            ; right shift by 4 positions
    or      al,30H
    mov     [ASCIIsum+esi],al
    dec     esi

    dec     edi             ; update EDI

    loop    cnv_loop
    popad                   ; restore registers
    ret

