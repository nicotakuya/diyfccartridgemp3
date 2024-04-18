;----------------------------------------------------------------------------
; startup program (based by Tekepen/NES研究所)
;----------------------------------------------------------------------------
.setcpu        "6502"
.autoimport    on
.IMPORTZP    sp

.global    _NesMain

; iNESヘッダ(16 Bytes)
.segment "HEADER"
    .byte   $4E, $45, $53, $1A ; "NES" 
    .byte   $02                ; PRG-ROMバンク数(16KB x 2)
    .byte   $04                ; CHR-ROMバンク数(8KB x 4)
    .byte   $31                ; Mapper 3/Vetrical Mirroring
    .byte   $00                ; Mapper 3
    .byte   $00                ; PRG-RAMサイズ
    .byte   $00,$00,$00,$00, $00, $00, $00

.segment "STARTUP"
; リセット割り込み
.proc    Reset
    sei
    ldx    #$ff        ; スタックポインタ初期化1
    txs 

    lda    #$ff        ; スタックポインタ初期化2
    sta    sp
    lda    #$03
    sta    sp + 1

    jsr    _NesMain    ; メイン関数を呼び出す
.endproc

.segment "BANKKEY"
    .byte   $00,$01,$02,$03 ; バンクキー

.segment "VECINFO"
    .word    $0000     ; NMI割り込みアドレス
    .word    Reset     ; リセット割り込みアドレス
    .word    $0000     ; IRQ割り込みアドレス

; パターンテーブル
.segment "CHARS"
	.incbin	"pattern.chr"

