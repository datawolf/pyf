;Procedures for string processing    STRING.ASM
;   Objective: Use string instructions to write
;            some example string functions.
;      Inputs: Pointers to source and/or dest. strings
;            Each pointer should have segment & offset
;      Output: According to the function. Carry flag is 
;            used to indicate "no string error" if one
;            of the strings is not a string with length
;                less than STR_MAX.
%include "io.mac"

%define    STRING1   [EBP+8]
%define    STRING2   [EBP+16]

STR_MAX   EQU   128   ; maximum string length

.CODE
global  str_len, str_cpy, str_cat, str_cmp
global  str_chr, str_cnv

;---------------------------------------------------
; String length procedure. Receives a string pointer
; (seg:offset) via the stack. If not a string, CF is 
; set; otherwise, string length is returned in EAX 
; with CF = 0.
; Preserves all registers.
;---------------------------------------------------

str_len:
    enter       0,0
    push        ecx
    push        edi
    push        es
    les         edi,STRING1         ; copy string pointer to ES:EDI
    mov         ecx,STR_MAX         ; need to terminate loop if 
                                    ; EDI is not pointing to a string
    cld                             ; forward search
    mov         al,0                ; NULL character
    repne       scasb
    jcxz        s1_no_string        ; if ecx = 0, not a string
    dec         edi                 ; back up to point to NULL
    mov         eax, edi
    sub         eax, [ebp+8]        ; string length in eax
    clc                             ; no error
    jmp         SHORT   s1_done
s1_no_string:
    stc                             ; carry set => no string
s1_done:
    pop         es
    pop         edi
    pop         ecx
    leave
    ret         8                   ; clear stack and return


;-----------------------------------------------------------
;String copy procedure. Receives two string pointers
;(seg:offset) via the stack - string1 and string2. 
;If string2 is not a string, CF is set;
;otherwise, string2 is copied to string1 and the 
;offeset of string1 is returned in EAX with CF = 0.
;Preserves all registers.
;-----------------------------------------------------------
str_cpy:
      enter   0,0
    push    ECX
    push    EDI
    push    ESI
    push    DS
    push    ES
    ; find string length first
    lds     ESI,STRING2  ; src string pointer
    push    DS
    push    ESI        
    call    str_len
    jc      sc_no_string
    mov     ECX,EAX      ; src string length in ECX
    inc     ECX          ; add 1 to include NULL
    les     EDI,STRING1  ; dest string pointer
    cld                  ; forward search
    rep     movsb
    mov     EAX,[EBP+8]  ; return dest string pointer
    clc                  ; no error
    jmp     SHORT sc_done
sc_no_string:
    stc                  ; carry set => no string
sc_done:
    pop     ES
    pop     DS
    pop     ESI
    pop     EDI
    pop     ECX
    leave
    ret     16           ; clear stack and return
    
;-----------------------------------------------------------
;String concatenate procedure. Receives two string pointers
;(seg:offset) via the stack - string1 and string2. 
;If string1 and/or string2 are not strings, CF is set;
;otherwise, string2 is concatenated to the end of string1 
;and the offset of string1 is returned in EAX with CF = 0.
;Preserves all registers.
;-----------------------------------------------------------
str_cat:
    enter   0,0
    push    ECX
    push    EDI
    push    ESI
    push    DS
    push    ES
    ; find string length first
    les     EDI,STRING1 ; dest string pointer
    mov     ECX,STR_MAX ; max string length
    cld                 ; forward search
    mov     AL,0        ; NULL character
    repne   scasb
    jcxz    st_no_string
    dec     EDI         ; back up to point to NULL
    lds     ESI,STRING2 ; src string pointer
    push    DS
    push    ESI
    call    str_len
    jc      st_no_string
    mov     ECX,EAX     ; src string length in ECX
    inc     ECX         ; add 1 to include NULL
    cld                 ; forward search
    rep     movsb
    mov     EAX,[EBP+8] ; return dest string pointer
    clc                 ; no error
    jmp     SHORT st_done
st_no_string:
    stc                 ; carry set => no string
st_done:
    pop     ES
    pop     DS
    pop     ESI
    pop     EDI
    pop     ECX
    leave
    ret     16          ; clear stack and return

;-----------------------------------------------------------
;String locate a character procedure. Receives a character
;and a string pointer (seg:offset) via the stack. 
;char should be passed as a 16-bit word.
;If string1 is not a string, CF is set;
;otherwise, locates the first occurrence of char in string1
;and returns a pointer to the located char in EAX (if the 
;search is successful; otherwise EAX = NULL) with CF = 0.
;Preserves all registers.
;-----------------------------------------------------------
str_chr:
    enter   0,0
    push    ECX
    push    EDI
    push    ES
    ; find string length first
    les     EDI,STRING1  ; src string pointer
    push    ES
    push    EDI        
    call    str_len
    jc      sh_no_string
    
    mov     ECX,EAX      ; src string length in ECX
    inc     ECX
    mov     AX,[EBP+16]  ; read char. into AL
    cld                  ; forward search
    repne   scasb
    dec     EDI          ; back up to match char.
    xor     EAX,EAX      ; assume no char. match (EAX=NULL)
    jcxz    sh_skip
    mov     EAX,EDI      ; return pointer to char.
sh_skip:
    clc                  ; no error
    jmp     SHORT sh_done
sh_no_string:
    stc                  ; carry set => no string
sh_done:
    pop     ES
    pop     EDI
    pop     ECX
    leave
    ret     10           ; clear stack and return

;-----------------------------------------------------------
;String convert procedure. Receives two string pointers
;(seg:offset) via the stack - string1 and string2. 
;If string2 is not a string, CF is set;
;otherwise, string2 is copied to string1 and lowercase
;letters are converted to corresponding uppercase letters.
;string2 is not modified in any way. 
;It returns a pointer to string1 in EAX with CF = 0.
;Preserves all registers.
;-----------------------------------------------------------
str_cnv:
    enter   0,0
    push    ECX
    push    EDI
    push    ESI
    push    DS
    push    ES
    ; find string length first
    lds     ESI,STRING2  ; src string pointer
    push    DS
    push    ESI        
    call    str_len
    jc      sn_no_string
    
    mov     ECX,EAX      ; src string length in ECX
    inc     ECX          ; add 1 to include NULL
    les     EDI,STRING1  ; dest string pointer
    cld                  ; forward search
loop1:
    lodsb
    cmp     AL,'a'       ; lowercase letter?
    jb      sn_skip
    cmp     AL,'z'
    ja      sn_skip      ; if no, skip conversion
    sub     AL,20H       ; if yes, convert to uppercase
sn_skip:
    stosb
    loop    loop1
    rep     movsb
    mov     EAX,[EBP+8]  ; return dest string pointer
    clc                  ; no error
    jmp     SHORT sn_done
sn_no_string:
    stc                  ; carry set => no string
sn_done:
    pop     ES
    pop     DS
    pop     ESI
    pop     EDI
    pop     ECX
    leave
    ret     16           ; clear stack and return

;---------------------------------------------------
; String compare procedure.
; Receives two string pointers(seg:offset) via the stack
; string1 and string2
; If string2 is not a string, CF is set;
; otherwise, string1 and string2 are compared and returns
; a value in EAX with CF = 0 as shown below:
;   eax = negative value        if string1 < string2
;   eax = 0                     if string1 = string2
;   eax = positive value        if string1 > string2
; Preserves all registers
;---------------------------------------------------

str_cmp:
    enter       0,0
    push        ecx
    push        edi
    push        esi
    push        ds
    push        es

    ; find string length first
    les         edi,STRING2         ; string2 pointer
    push        es
    push        edi
    call        str_len
    jc          sm_no_string

    mov         ecx,eax             ; string1 length in ecx
    inc         ecx                 ; add 1 to include NULL
    lds         esi,STRING1         ; string1 poinger
    cld                             ; forward search
    repe        cmpsb
    je          same
    ja          above
below:
    mov         eax,-1
    clc                             ; eax = -1 => string1 < string2
    jmp         SHORT sm_done
same:
    xor         eax,eax             ; eax = 0 => string match
    clc
    jmp         SHORT sm_done
above:
    mov         eax, 1              ; eax = 1 => string1 > string2
    clc         
    jmp         SHORT sm_done
sm_no_string:
    stc                             ; carry set => no string
sm_done:
    pop         es
    pop         ds
    pop         esi
    pop         edi
    pop         ecx
    leave
    ret         16                  ; clear and return


















