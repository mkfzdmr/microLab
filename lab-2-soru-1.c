// 0-9 seven segment sayıcı

//   ---------    ---------
//   |   A   |    |   A   |
//  F|       |B  F|       |B
//   |---G---|    |---G---|
//  E|       |C  E|       |C
//   |   D   |    |   D   |
//   ---------    ---------  
// Pin Konfigürasyonu:
// 0 => -FEDCBA
// 1 => ----BC-
// 2 => G-ED-BA
// 3 => G--DCBA
// 4 => GF--CB-
// 5 => GF-DC-A
// 6 => GFEDC-A
// 7 => ----CBA
// 8 => GFEDCBA
// 9 => GF-DCBA

#include <16F887.h>
#fuses XT
#use delay(clock=4M) 
#use fast_io(b)
#define segmentBirler  pin_a1
#define segmentOnlar   pin_a0

const char sSegment[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F };

void main()
{
   set_tris_b(0x00);
   set_tris_a(0x00);
   output_low(segmentOnlar);
   output_high(segmentBirler);

   
   int i=0;
   
   while(1)
   {
   
         output_b(sSegment[i]);      
         delay_ms(500);
         i=(i+1)%10; 
   }
   
}
