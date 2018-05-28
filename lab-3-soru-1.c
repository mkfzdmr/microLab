#include <16f877A.h>     // Kullanýlacak denetleyicinin baþlýk dosyasý tanýtýlýyor.
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD // Denetleyici konfigürasyon ayarlarý
#use delay(clock=4000000)   // Gecikme fonksiyonu için kullanýlan osilatör frekansý belirtiliyor
#use fast_io(b) // Port yönlendirme komutlarý B portu için geçerli
#use fast_io(c)

                  void main  ()
   {
                     setup_psp (PSP_DISABLED); // PSP birimi devre dýþý
                     setup_spi (SPI_SS_DISABLED); // SPI birimi devre dýþý
                     setup_timer_1 (T1_DISABLED); // T1 zamanlayýcýsý devre dýþý
                     setup_timer_2 (T2_DISABLED, 0, 1); // T2 zamanlayýcýsý devre dýþý
                     setup_adc_ports (NO_ANALOGS); // ANALOG giriþ yok
                     setup_adc (ADC_OFF); // ADC birimi devre dýþý
                     setup_CCP1 (CCP_OFF); // CCP1 birimi devre dýþý
                     setup_CCP2 (CCP_OFF); // CCP2 birimi devre dýþý
                     
                     char i = 0, j = 0;

                  int speed;	//harflerin displayde gözükme hýzý
                  
                  speed = 50;
                  set_tris_b (0x00);	// B portunu çýkýþ yapma bilgi göndermek için
                  set_tris_c (0x00);	// C portunu çýkýþ yapma sütunlarý kontrol etmek için
                  
                  int s[5] = {0b01111001, 0b01001001, 0b01001001, 0b01001001, 0b01001111}; 	//S Harfi
                  int a[5] = {0b01111111, 0b01001000, 0b01001000, 0b01001000, 0b01111111};	//A Harfi
                  int m[5] = {0b01111111, 0b00100000, 0b00010000, 0b00100000, 0b01111111};	//M Harfi
                  int e[5] = {0b01111111, 0b01001001, 0b01001001, 0b01001001, 0b01001001};	//E Harfi
                  int t[5] = {0b01000000, 0b01000000, 0b01111111, 0b01000000, 0b01000000};	//T Harfi
                  
                  
                  int dot[5] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000};  //Sütun bilgisi
                  
                
                  while (1)
                  {
                     // S harfinin yanmasý için
                     for (j = 0; j < speed; j++)
                     {
                        for (i = 0; i < 5; i++)
                        {
                           output_b (s[i]);		//hangi ledlerin yanacaðýný B portuna gönder
                           output_c (dot[i]);		//hangi sütun aktif 1 olacak belirle ve C portuna gönder
                           delay_ms (2);		//sütunlar arasýnda kýsa süreli geçikme
                        }
                     }

                     output_c (0x00); // ekraný temizle
                     delay_ms (1000); // harfler arasý geçiþ süresi
                    
		     // A harfinin yanmasý için
                     for (j = 0; j < speed; j++)
                     {
                        for (i = 0; i < 5; i++)
                        {
                           output_b (a[i]);
                           output_c (dot[i]);
                           delay_ms (2);
                        }
                     }

                     output_c (0x00);	// ekraný temizle
                     delay_ms (1000);	// harfler arasý geçiþ süresi

		     // M harfinin yanmasý için
                     for (j = 0; j < speed; j++)
                     {
                        for (i = 0; i < 5; i++)
                        {
                           output_b (m[i]);
                           output_c (dot[i]);
                           delay_ms (2);
                        }
                     }

                     output_c (0x00);
                     delay_ms (1000);
                     
                     // E harfinin yanmasý için
                     for (j = 0; j < speed; j++)
                     {
                        for (i = 0; i < 5; i++)
                        {
                           output_b (e[i]);
                           output_c (dot[i]);
                           delay_ms (2);
                        }
                     }

                     output_c (0x00);
                     delay_ms (1000);

		     // T harfinin yanmasý için
                     for (j = 0; j < speed; j++)
                     {
                        for (i = 0; i < 5; i++)
                        {
                           output_b (t[i]);
                           output_c (dot[i]);
                           delay_ms (2);
                        }
                     }

                     output_c (0x00);
                     delay_ms (1000);
                     
                  }
   }
