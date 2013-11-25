; Sorting an array by insertion sort            INS_SORT.ASM
;
; Objective: To sort an integer array using insertion sort.
; Input: Requests numbers to fill array
; Output: Display sorted array
;
; the pseudocode for this insertion sort  algorithm
;
;  inserttion_sort(array, size)
;       for( i = 1 to size-1 )
;           temp := array[i]
;           j := i - 1
;           while ( (temp < array[j]) AND ( j >= 0) )
;               array[j+1] := array[j]
;               j := j - 1
;           end  while
;           array[j+1] := temp
;       end for
;   end insertion_sort
;


%include "io.mac"

.DATA
MAX_SIZE        EQU     100
input_prompt    db      "Please enter input array:"
                db      "(negative number terminates input)",0
out_msg         db      "The sorted array is :",0

.UDATA
array           resd        MAX_SIZE
.CODE
    .STARTUP
    PutStr      input_prompt            ; request input array
    mov         ebx, array
    mov         ecx, MAX_SIZE

array_loop:
    GetLInt     eax                     ; read an array number
    cmp         eax,0                   ; negative number?
    jl          exit_loop               ; if so, stop reading numbers
    mov         [ebx], eax              ; otherwise, copy into array
    add         ebx,4                   ; increment array address
    loop        array_loop              ; iterates a maximum of MAX_SIZE
exit_loop:
    mov         edx,ebx                 ; edx keeps the actual array size
    sub         edx,array               ; edx = array size in bytes
    shr         edx,2                   ; divide by 4 to get array size
    push        edx                     ; push array size 
    push        array                   ; push array pointer
    call        insertion_sort
    PutStr      out_msg                 ; dispaly sorted array
    nwln
    mov         ecx, edx                ; ecx = loop count when output the sorted array
    mov         ebx, array
display_loop:
    PutLInt     [ebx]
    nwln
    add         ebx,4
    loop        display_loop
done:
    .EXIT


;-------------------------------------------------------------------
; This procedure receives a pointer to an array of integers
; and the array size via the stack.
; The array is sorted by using insertion sort. all registers are preserved.
;-------------------------------------------------------------------

%define     SORT_ARRAY      ebx 
insertion_sort:
    pushad                          ; save registers
    mov         ebp,esp
    mov         ebx, [ebp+36]       ; copy array pointer
    mov         ecx, [ebp+40]       ; copy array size
    mov         esi, 4              ; array left of ESI is sorted
for_loop:
    ; variables of the algorithm are mapped as follows.
    ; EDX = temp, ESI = i; and EDI = j
    mov         edx, [SORT_ARRAY+esi]       ; temp = array[i]
    mov         edi, esi                    ; j = i-1
    sub         edi,4 
while_loop:
    cmp         edx, [SORT_ARRAY+edi]   ; temp < array[j]
    jge         exit_while_loop
    ; array[j+1] = array[j]
    mov         eax, [SORT_ARRAY+edi]
    mov         [SORT_ARRAY+edi+4], eax
    sub         edi,4                   ; j = j-1
    cmp         edi,0                   ; j >=0
    jge         while_loop
exit_while_loop:
    ; array[j+1] = temp
    mov         [SORT_ARRAY+edi+4], edx
    add         esi,4
    dec         ecx
    cmp         ecx,1                   ; if ecx = 1, we are done
    jne         for_loop
sort_done:
    popad                               ; restore registers
    ret         8
