[bits 16]
[org 0x7c00]

; Switch to 64-bit mode
cli
mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

; Set up the stack
mov rsp, 0x7c00

; Jump to 64-bit code
jmp 0x10:main

[bits 64]
main:
    ; Call kernel main
    call kernel_main
    hlt

times 510 - ($ - $$) db 0
dw 0xAA55
