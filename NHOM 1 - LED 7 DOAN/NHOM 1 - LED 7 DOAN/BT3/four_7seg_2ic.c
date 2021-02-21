#include <16F877A.h>
#FUSES NOWDT,NOBROWNOUT,NOLVP
#use delay(crystal=4000000)
#define SHCP PIN_B0
#define DS PIN_B1
#define STCP PIN_B2
const unsigned int8 MA_LED[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
//CAC MA LED NAY DUNG CHO LED 7 DOAN CHUNG ANODE
const int8 CA[5] = {0b0000, 0b1000, 0b0100, 0b0010, 0b0001};
//TRANG THAI 4 CHAN ANODE
void HIEN_THI(unsigned int8 DATA, int8 CA)
{
   #bit bit_0_CA = CA.0      //DAT TEN CHO BIT THU 0 CUA BIEN CA LA bit_0_CA
   int8 i;
   for(i = 0; i <= 3; i++)   //VONG LAP DICH 4 BIT TRANG THAI CHAN ANODE VAO THANH GHI DICH
   {
   output_bit(DS, bit_0_CA); 
   output_low(SHCP);         //TAO 1 XUNG VAO CHAN SHCP DE DICH 1 BIT VAO THANH GHI DICH
   output_high(SHCP);
   CA = CA >> 1;             //DICH PHAI 1 BIT
   }
   ////////////////////
   #bit bit_0_DATA = DATA.0 //DAT TEN CHO BIT THU 7 CUA BIEN DATA LA bit_0_DATA
   for(i = 0; i <= 7; i++)  //VONG LAP DICH 8 BIT VAO THANH GHI DICH
   {
   output_bit(DS, bit_0_DATA);
   output_low(SHCP);        //TAO 1 XUNG VAO CHAN SHCP DE DICH 1 BIT VAO THANH GHI DICH
   output_high(SHCP);
   DATA = DATA >> 1;        //DICH PHAI 1 BIT
   }
   //SAU KHI DICH 8 BIT NAY VAO THI 4 BIT KIA SE O THANH GHI DICH CUA IC THU 2
   output_low(STCP);        //TAO 1 XUNG VAO CHAN STCP DE XUAT DU LIEU CHO THANH GHI LUU TRU CUA 2 IC
   output_high(STCP);
}
void main()
{
   set_tris_b(0);           //SET CAC CHAN CONG B DEU OUTPUT
   int8 NGHIN, TRAM, CHUC, DONVI;
   while(TRUE)
   {
      for(int16 DEM = 0; DEM<=9999; DEM++)
      {
      NGHIN = DEM/1000;
      TRAM = DEM/100%10;
      CHUC = DEM/10%10;
      DONVI = DEM%10;
      for(int8 j = 1; j <= 50; j++)  //VONG LAP QUET LED VA TAO DELAY 1s
      {
      HIEN_THI(MA_LED[NGHIN], CA[1]);
      delay_ms(5);
      HIEN_THI(MA_LED[NGHIN], CA[0]);
      //////////////////////////////
      HIEN_THI(MA_LED[TRAM], CA[2]);
      delay_ms(5);
      HIEN_THI(MA_LED[TRAM], CA[0]);
      //////////////////////////////
      HIEN_THI(MA_LED[CHUC], CA[3]);
      delay_ms(5);
      HIEN_THI(MA_LED[CHUC], CA[0]);
      //////////////////////////////
      HIEN_THI(MA_LED[DONVI], CA[4]);
      delay_ms(5);
      HIEN_THI(MA_LED[DONVI], CA[0]);
      }
      }
   }
}
