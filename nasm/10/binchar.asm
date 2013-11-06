; Binary equivalent of characters       BINCHAR.ASM
;
;   Objective:  To print the binary equivalent of
;               ASCII character code.
;   Input:  Requests a character from the user.
;   Output: Prints the ASCII code of the 
;           input character in binary.
;   Date: 2013年 11月 06日 星期三 17:15:17 CST

%include "io.mac"

.DATA
char_prompt         db  "Please input a character: ",0
out_msg1            db  "The ASCII code of '",0
out_msg2            db  "' in binary is ",0
query_msg           db  "Do you want to quit (Y/N): ",0
.UDATA
.CODE
     .STARTUP
read_char:
    PutStr      char_prompt         ; request a char, input
    GetCh       AL                  ; read input character

    PutStr      out_msg1
    PutCh       AL
    PutStr      out_msg2
    mov         AH,80H              ; mask  byte = 80H
    mov         CX,8                ; loop count to print 8 bits
print_bit:
    test        AL,AH               ; test does not modify AL
    jz          print_0             ; if tested bit is 0, print it
    PutCh       '1'                 ; otherwise, print1
    jmp     skip1
print_0:
    PutCh       '0'
skip1:
    shr         AH,1                ; right shift mask bit to test
                                    ; next bit of the ASCII code
    loop        print_bit
    nwln
    PutStr      query_msg           ; query user whether to terminate
    GetCh       AL                  ; read response
    cmp         AL,'Y'              ; if response is not 'Y'
    jne         read_char           ; read another character
done:
    .EXIT
