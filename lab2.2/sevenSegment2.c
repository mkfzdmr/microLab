// 0-60 seven segment sayýcý
//#include <stdio.h>
//#include <stdlib.h>
#include "16F887.h"
#fuses XT
#use delay(clock=4M)
#use fast_io(a)
#use fast_io(b)


//deka v6 için segment binleri ra0 ra1
#define segmentBirler   pin_a1
#define segmentOnlar    pin_a0

const char sSegment[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F };

void main()
{
   set_tris_b(0x00);
   set_tris_a(0x00);
   output_d(0x00);
      
   int i=0,sayici=0;
   
   while(1)
   {
  
     int onlarBasamagi = i/10;
     int birlerBasamagi= i%10;
                 
         output_b(sSegment[birlerBasamagi]);      
         output_high(segmentBirler);
         delay_ms(5); output_low(segmentBirler);
         output_b(sSegment[onlarBasamagi]);
         output_high(segmentOnlar);
         delay_ms(5); output_low(segmentOnlar);
    
         if(sayici>=100)  // 4*1/4m =1uS 
           {
             i=(i+1)%61; // if i ==61 i=0;
             sayici=0;
           }
          else
          {
             sayici++;
          }
          
   }
   
}
