; Uppercase conversion of characters        TOUPPER.ASM
;
;       Objective: To convert lowercase letters to
;                   corresponding uppercase letters.
;       Input:  Requests a char. string from the user.
;       Output: Prints the input string in uppercase.

%include "io.mac"

.DATA
name_prompt db  "Please type your name: ",0
out_msg     db  "Your name in capitals is : ",0
.UDATA
in_name     resb        31
.CODE
    .STARTUP
    PutStr  name_prompt         ; request character string
    GetStr  in_name,31          ; read input character string

    PutStr  out_msg
    mov     EBX, in_name        ; EBX = pointer to in_name
process_char:
    mov     AL, [EBX]           ; move the char. to AL
    cmp     AL, 0               ; if it is the NULL character
    je      done                ; conversion done
    cmp     AL, 'a'             ; if (char < 'a') 
    jl      not_lower_case      ; not a lowercase letter
    cmp     AL, 'z'             ; if (char > 'z')
    jg      not_lower_case      ; not a lowercase letter
lower_case:
    add     AL, 'A'-'a'         ; convert to uppercase
not_lower_case:
    PutCh   AL                  ; write the character
    inc     EBX                 ; EBX points to the next char
    jmp     process_char        ; go back to process next char
done:
    nwln
    .EXIT

