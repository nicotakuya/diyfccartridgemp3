// Mapper3 test program by Takuya Matsubara
#include "fcsub.h"     // サブルーチン

const char colortable[] = {
    C_BLACK ,C_GRAY ,C_LIGHTGRAY ,C_WHITE,  // BGカラーパレット0
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_LIGHTGRAY ,C_WHITE,  // SPカラーパレット0
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE
};

const unsigned char btnname[] = "MAPPER3 TEST PROGRAM";


//---- メイン関数
char NesMain(void)
{
    char i,x,y;
    char bank_old,bank_now;
    unsigned char button,button_back;

    fc_init(); // 全機能の初期化
    ppu_palette((char *)colortable,0,8);           // パレット設定(0)

    i=0;// タイル番号
    for(y=0; y<16; y++){
        for(x=0; x<16; x++){
            bg_printch(x+8,y+8,i); // BG Aに描画
            i++;
        }
    }
    bg_printstr(2,2,(char *)btnname);

    bank_now = 0x00;
    bank_old = 0x00;
    *(char*)0xFFF0 = 0x00; // バンクキー
    ppu_enable(1);    // 画面表示を有効化

    button_back=0;
    i=0;
    while (1){
        button = controller1();   // コントローラー1入力
        if( button_back != button ){
            button_back = button;
            if(button & BUTTON_A ){
                pulse1(330);
                bank_now += 1;  // バンク変更
                bank_now &= 3;
            }
            if(button & BUTTON_B ){
                pulse1(660);
                bank_now -= 1;  // バンク変更
                bank_now &= 3;
            }
        }
        ppu_vsync();  // Vブランク待ち
        sp_dmastart();    // OMA DMA転送開始
        if(bank_old != bank_now){
            bank_old = bank_now;
            *((char*)0xFFF0+bank_now) = bank_now; 
            // バンクキー書き込み
        }
        bg_scroll(0,0);  // BGスクロール
    }
    return 0;
}


