;-----------------------------------------------------------
; This procedure receives a pinter to an array of integers
; and the size of the array via the stack. It sorts the
; array in ascending order using the bubble sort algorithm.
;-----------------------------------------------------------

%include "io.mac"

SORTED      EQU     0
UNSORTED    EQU     1

.CODE
global  bubble_sort
bubble_sort:
    pushad
    mov     EBP, ESP

    ; ECX serves the same purpose as the end_index variable
    ; in the C procedure. ECX keeps the number of comparisons
    ; to be done in each pass.
    ; Note that ECX is decremented by 1 after each pass.
    mov     ECX, [EBP+40]       ; load array size into ECX

next_pass:
    dec     ECX             ; if # of comparisons is zero
    jz      sort_done       ; then we are done 
    mov     EDI, ECX        ; else start another pass

    ; DL is used to keep SORTED/UNSORTED status
    mov     DL, SORTED      ; set status to SORTED
    
    mov     ESI,[EBP+36]    ; load array address into ESI
    ; ESI points to element i and ESI+4 to the next element
pass:
    ; This loop represents one pass of the algorithm
    ; Each iteration compares elements at [ESI] and [ESI+4]
    ; and swaps them if ([ESI] ) < ([ESI+4])
    
    mov     EAX, [ESI]
    mov     EBX, [ESI+4]
    cmp     EAX, EBX
    jg      swap
increment:
    ; increment ESI by 4 to point to the next element
    add     ESI, 4
    dec     EDI
    jnz     pass
    
    cmp     EDX, SORTED     ; if status remains SORTED
    je      sort_done       ; then sorted is done
    jmp     next_pass       ; else  initiate another pass
swap:
    ; swap elements at [ESI] and [ESI+4]
    mov     [ESI+4], EAX    ; copy [ESI] in EAX to [ESI+4]
    mov     [ESI], EBX      ; copy [ESI+4] in EBX to [ESI]
    mov     EDX, UNSORTED   ; set status to UNSORTED
    jmp     increment

sort_done:
    popad
    ret     8













    
