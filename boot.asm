/*
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
*/


[bits 16]
[org 0x7c00]
start:
    cli
    lgdt [gdtr]    ; Load GDT
    mov eax, cr0
    or al, 1       ; Enable protected mode
    mov cr0, eax
    jmp 0x08:protected_mode

[bits 32]
protected_mode:
    mov ax, 0x10   ; Setup segments
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x7e00     ; Jump to kernel

gdtr:
    dw 23          ; GDT limit
    dd gdt         ; GDT address

gdt:
    dq 0           ; Null descriptor
    dw 0xFFFF      ; Code segment
    dw 0
    db 0
    db 0x9A
    db 0xCF
    db 0
    dw 0xFFFF      ; Data segment
    dw 0
    db 0
    db 0x92
    db 0xCF
    db 0

times 510-($-$$) db 0
dw 0xAA55
