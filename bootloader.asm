; Bootloader code
bits 16                 ; tell NASM this is 16 bit code
org 0x7c00              ; tell NASM to start outputting stuff at offset 0x7c00

KERNEL_LOCATION equ 0x1000

; Clear the screen
mov ax, 0x3
int 0x10

boot:
    ; Display booting message
    call delay_5_seconds
    mov bx, booting_msg
    call print
    call delay_5_seconds
    mov bx, newLine_msg
    call print

    ; Jump to read sector
    jmp readSector

; Function to delay for 5 seconds
delay_5_seconds:
    ; Get the current time
    mov ah, 0x00      ; Function to get current time
    int 0x1A          ; Call the interrupt
    mov bx, dx        ; Store current seconds in bx
    add bx, 5         ; Add 5 seconds to bx for the delay

wait_loop:
    mov ah, 0x00      ; Function to get current time
    int 0x1A          ; Call the interrupt
    cmp dx, bx        ; Compare current seconds with the target value
    jb wait_loop      ; If current seconds < target, continue waiting
    ret

halt:
    cli
    hlt

; String data for messages
StringData:
    hello_msg DB "Hello",0
    newLine_msg DB 0xa,0xd,0 ; 0xd remove tab
    booting_msg DB "Booting...",0
    readSectorSu_msg DB "The disk has been read successfully",0
    errorToReadDisk_msg DB "Error To read sector",0

%include "io/print.asm"
%include "disk/sector.asm"
%include "gdt/gdt.asm"

times 510 - ($-$$) db 0
dw 0xaa55
