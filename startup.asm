;----------------------------------------------------------------------------
; startup program (based by Tekepen/NES������)
;----------------------------------------------------------------------------
.setcpu        "6502"
.autoimport    on
.IMPORTZP    sp

.global    _NesMain

; iNES�w�b�_(16 Bytes)
.segment "HEADER"
    .byte   $4E, $45, $53, $1A ; "NES" 
    .byte   $02                ; PRG-ROM�o���N��(16KB x 2)
    .byte   $04                ; CHR-ROM�o���N��(8KB x 4)
    .byte   $31                ; Mapper 3/Vetrical Mirroring
    .byte   $00                ; Mapper 3
    .byte   $00                ; PRG-RAM�T�C�Y
    .byte   $00,$00,$00,$00, $00, $00, $00

.segment "STARTUP"
; ���Z�b�g���荞��
.proc    Reset
    sei
    ldx    #$ff        ; �X�^�b�N�|�C���^������1
    txs 

    lda    #$ff        ; �X�^�b�N�|�C���^������2
    sta    sp
    lda    #$03
    sta    sp + 1

    jsr    _NesMain    ; ���C���֐����Ăяo��
.endproc

.segment "BANKKEY"
    .byte   $00,$01,$02,$03 ; �o���N�L�[

.segment "VECINFO"
    .word    $0000     ; NMI���荞�݃A�h���X
    .word    Reset     ; ���Z�b�g���荞�݃A�h���X
    .word    $0000     ; IRQ���荞�݃A�h���X

; �p�^�[���e�[�u��
.segment "CHARS"
	.incbin	"pattern.chr"

