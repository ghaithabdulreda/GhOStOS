bits 32
global _start  ; Make _start the entry point

KERNEL_LOCATION equ 0x1000

_start:
    ; Call the GDT loader if needed
    ; call loadGDT

    mov eax, 0xB8000  ; Move the address to eax register
    mov byte [eax], 'A'  ; Move the character 'A' to the memory address
    

    ; Set up protected mode segments (if needed)
    ; ...

    extern main
    call main

    ; Hang the system if main returns
    jmp $


; الكود الخاص بك في C++

