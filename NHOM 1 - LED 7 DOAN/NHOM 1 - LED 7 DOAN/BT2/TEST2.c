#include <16f877a.h>
#FUSES NOWDT , HS , NOPUT, NOPROTECT
#use delay(crystal =4000000)
#define LED_NGHIN PIN_B0
#define LED_TRAM  PIN_B1
#define LED_CHUC  PIN_B2
#define LED_DONVI PIN_B3
const UNSIGNED int MA_LED[10] = {0XC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92,0x82,0xF8,0x80,0x90};//CAC MA LED NAY DUNG CHO LED 7 DOAN CHUNG ANODE
int16 DEM = 0;
int   NGHIN,TRAM, CHUC, DONVI;
void main()
{
 set_tris_d(0); //KHAI BAO CAC CHAN CONG D DEU OUTPUT
 set_tris_b(0); //KHAI BAO CAC CHAN CONG B DEU OUTPUT
 output_low(LED_NGHIN);
 output_low(LED_TRAM);
 output_low(LED_CHUC);
 output_low(LED_DONVI); // ban dau tat het cac led
 while(TRUE)
 {
 for(DEM =0; DEM<10000; DEM++)
 {
 NGHIN =DEM/1000;
 TRAM = DEM/100%10;
 CHUC = DEM/10%10;
 DONVI = DEM%10;
for (int j=0; j<50;j++) //VONG LAP QUET LED VA TAO DELAY 1s
{
 OUTPUT_B(0b00000001);
 output_d(MA_LED[NGHIN]);
 delay_ms(5);
 OUTPUT_B(0b00000010);
 output_d(MA_LED[TRAM]);
 delay_ms(5);
 OUTPUT_B(0b00000100);
 output_d(MA_LED[CHUC]);
 delay_ms(5);
 OUTPUT_B(0b00001000);
  output_d(MA_LED[DONVI]);
 delay_ms(5);
}
 }
}
}
