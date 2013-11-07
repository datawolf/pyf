;   Hex equivalent of character         HEX1CHAR.ASM
;
;   Objective: To print the hex equivalent of 
;               ASCII character code
;   Input: Request a character from the user.
;   Output: Prints the ASCII code of the input
;           character in hex.

%include "io.mac"

.DATA
char_prompt     db  "Please input a character: ",0
out_msg1        db  "The ASCII  code of '",0
out_msg2        db  "' in hex is ",0
query_msg       db  "Do you want to quit(Y/N): ",0
.UDATA

.CODE
    .STARTUP
read_char:
    PutStr      char_prompt         ; request a char, input
    GetCh       AL                  ; read input character
    
    PutStr      out_msg1
    PutCh       AL
    PutStr      out_msg2
    mov         AH,AL               ; save input character in AH
    shr         AL,4                ; move upper 4 bits to lower half
    mov         CX,2                ; loop count: 2 hex digits to print
print_digit:
    cmp         AL,9                ; if greater than 9
    jg          A_to_F              ; convert to A through F digits
    add         AL,'0'              ; otherwise convert to 0 through 9
    jmp         skip
A_to_F:
    add         AL, 'A'-10          ; subtract 10 and add 'A'
                                    ; to convert to A through F
skip:
    PutCh       AL                  ; wirte the first hex digit
    mov         AL, AH              ; restore input character in AL
    and         AL, 0FH             ; mask off the upper half byte
    loop        print_digit
    nwln
    PutStr      query_msg           ; query user whether to terminate
    GetCh       AL                  ; read response

    cmp         AL, 'Y'             ; if response is 'Y'
    jne         read_char           ; read another character
done:                               ; otherwise, terminate program
    .EXIT
