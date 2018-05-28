#include <16f877A.h>     // Kullan�lacak denetleyicinin ba�l�k dosyas� tan�t�l�yor.
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD // Denetleyici konfig�rasyon ayarlar�
#use delay(clock=4000000)   // Gecikme fonksiyonu i�in kullan�lan osilat�r frekans� belirtiliyor
#use fast_io(b) // Port y�nlendirme komutlar� B portu i�in ge�erli
#use fast_io(c)

                  void main  ()
   {
                     setup_psp (PSP_DISABLED); // PSP birimi devre d���
                     setup_spi (SPI_SS_DISABLED); // SPI birimi devre d���
                     setup_timer_1 (T1_DISABLED); // T1 zamanlay�c�s� devre d���
                     setup_timer_2 (T2_DISABLED, 0, 1); // T2 zamanlay�c�s� devre d���
                     setup_adc_ports (NO_ANALOGS); // ANALOG giri� yok
                     setup_adc (ADC_OFF); // ADC birimi devre d���
                     setup_CCP1 (CCP_OFF); // CCP1 birimi devre d���
                     setup_CCP2 (CCP_OFF); // CCP2 birimi devre d���
                     
                     char i = 0, j = 0;

                  int speed;	//harflerin displayde g�z�kme h�z�
                  
                  speed = 50;
                  set_tris_b (0x00);	// B portunu ��k�� yapma bilgi g�ndermek i�in
                  set_tris_c (0x00);	// C portunu ��k�� yapma s�tunlar� kontrol etmek i�in
                  
                  int s[5] = {0b01111001, 0b01001001, 0b01001001, 0b01001001, 0b01001111}; 	//S Harfi
                  int a[5] = {0b01111111, 0b01001000, 0b01001000, 0b01001000, 0b01111111};	//A Harfi
                  int m[5] = {0b01111111, 0b00100000, 0b00010000, 0b00100000, 0b01111111};	//M Harfi
                  int e[5] = {0b01111111, 0b01001001, 0b01001001, 0b01001001, 0b01001001};	//E Harfi
                  int t[5] = {0b01000000, 0b01000000, 0b01111111, 0b01000000, 0b01000000};	//T Harfi
                  
                  
                  int dot[5] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000};  //S�tun bilgisi
                  
                
                  while (1)
                  {
                     // S harfinin yanmas� i�in
                     for (j = 0; j < speed; j++)
                     {
                        for (i = 0; i < 5; i++)
                        {
                           output_b (s[i]);		//hangi ledlerin yanaca��n� B portuna g�nder
                           output_c (dot[i]);		//hangi s�tun aktif 1 olacak belirle ve C portuna g�nder
                           delay_ms (2);		//s�tunlar aras�nda k�sa s�reli ge�ikme
                        }
                     }

                     output_c (0x00); // ekran� temizle
                     delay_ms (1000); // harfler aras� ge�i� s�resi
                    
		     // A harfinin yanmas� i�in
                     for (j = 0; j < speed; j++)
                     {
                        for (i = 0; i < 5; i++)
                        {
                           output_b (a[i]);
                           output_c (dot[i]);
                           delay_ms (2);
                        }
                     }

                     output_c (0x00);	// ekran� temizle
                     delay_ms (1000);	// harfler aras� ge�i� s�resi

		     // M harfinin yanmas� i�in
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
                     
                     // E harfinin yanmas� i�in
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

		     // T harfinin yanmas� i�in
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
