
global _start

section .data
    align   2
    str:    db  'Hello, World',0xA
    strlen: equ $-str

section .bss
section .text
        _start:

        mov     edx, strlen
        mov     ecx, str
        mov     ebx, 1
        mov     eax, 4
        int     0x80

        mov     ebx, 0
        mov     eax, 1
        int     0x80
