#include <BT1.h>
const UNSIGNED int MA_LED[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
int DEM=0;
void main()
 
{
set_tris_b(0);
   while(TRUE)
   {
      for(DEM=0;DEM<10;DEM++)
      {
      output_b(MA_LED[DEM]);
      delay_ms(1000);
      }//TODO: User Code
   }

}
