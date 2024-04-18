// Mapper3 test program by Takuya Matsubara
#include "fcsub.h"     // �T�u���[�`��

const char colortable[] = {
    C_BLACK ,C_GRAY ,C_LIGHTGRAY ,C_WHITE,  // BG�J���[�p���b�g0
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_LIGHTGRAY ,C_WHITE,  // SP�J���[�p���b�g0
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE,
    C_BLACK ,C_BLUE ,C_RED ,C_WHITE
};

const unsigned char btnname[] = "MAPPER3 TEST PROGRAM";


//---- ���C���֐�
char NesMain(void)
{
    char i,x,y;
    char bank_old,bank_now;
    unsigned char button,button_back;

    fc_init(); // �S�@�\�̏�����
    ppu_palette((char *)colortable,0,8);           // �p���b�g�ݒ�(0)

    i=0;// �^�C���ԍ�
    for(y=0; y<16; y++){
        for(x=0; x<16; x++){
            bg_printch(x+8,y+8,i); // BG A�ɕ`��
            i++;
        }
    }
    bg_printstr(2,2,(char *)btnname);

    bank_now = 0x00;
    bank_old = 0x00;
    *(char*)0xFFF0 = 0x00; // �o���N�L�[
    ppu_enable(1);    // ��ʕ\����L����

    button_back=0;
    i=0;
    while (1){
        button = controller1();   // �R���g���[���[1����
        if( button_back != button ){
            button_back = button;
            if(button & BUTTON_A ){
                pulse1(330);
                bank_now += 1;  // �o���N�ύX
                bank_now &= 3;
            }
            if(button & BUTTON_B ){
                pulse1(660);
                bank_now -= 1;  // �o���N�ύX
                bank_now &= 3;
            }
        }
        ppu_vsync();  // V�u�����N�҂�
        sp_dmastart();    // OMA DMA�]���J�n
        if(bank_old != bank_now){
            bank_old = bank_now;
            *((char*)0xFFF0+bank_now) = bank_now; 
            // �o���N�L�[��������
        }
        bg_scroll(0,0);  // BG�X�N���[��
    }
    return 0;
}


