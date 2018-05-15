#include <16F877.h>     // Kullanılacak denetleyicinin başlık dosyası tanıtılıyor.
 
#fuses XT //,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD // Denetleyici konfigürasyon ayarları
 
#use delay(clock=4000000)   // Gecikme fonksiyonu için kullanılan osilatör frekansı belirtiliyor
 
#use fast_io(b) // Port yönlendirme komutları B portu için geçerli
 
/********* ANA PROGRAM FONKSİYONU********/
 
void main ()
{
   setup_psp(PSP_DISABLED);        // PSP birimi devre dışı
   setup_spi(SPI_SS_DISABLED);     // SPI birimi devre dışı
   setup_timer_1(T1_DISABLED);     // T1 zamanlayıcısı devre dışı
   setup_timer_2(T2_DISABLED,0,1); // T2 zamanlayıcısı devre dışı
   setup_adc_ports(NO_ANALOGS);    // ANALOG giriş yok
   setup_adc(ADC_OFF);             // ADC birimi devre dışı
   setup_CCP1(CCP_OFF);            // CCP1 birimi devre dışı
   setup_CCP2(CCP_OFF);            // CCP2 birimi devre dışı
 
   set_tris_b(0x00);    // RB0 portu tümüyle çıkış olarak ayarlandı.
 
   output_b(0x00);      // B portu çıkışı sıfırlanıyor
 
   basla:
 
   delay_ms(500);          // 500 ms'lik gecikme veriliyor
   output_toggle(pin_b0);  // RB0 ucunun çıkış durumu tersleniyor
   delay_ms(500);          // 500 ms'lik gecikme veriliyor
   output_toggle(pin_b1);  // RB1 ucunun çıkış durumu tersleniyor
   delay_ms(500);          // 500 ms'lik gecikme veriliyor
   output_toggle(pin_b2);  // RB2 ucunun çıkış durumu tersleniyor
   delay_ms(500);          // 500 ms'lik gecikme veriliyor
   output_toggle(pin_b3);  // RB3 ucunun çıkış durumu tersleniyor
   delay_ms(500);          // 500 ms'lik gecikme veriliyor
   output_toggle(pin_b4);  // RB4 ucunun çıkış durumu tersleniyor
   delay_ms(500);          // 500 ms'lik gecikme veriliyor
   output_toggle(pin_b5);  // RB5 ucunun çıkış durumu tersleniyor
   delay_ms(500);          // 500 ms'lik gecikme veriliyor
   output_toggle(pin_b6);  // RB6 ucunun çıkış durumu tersleniyor
   delay_ms(500);          // 500 ms'lik gecikme veriliyor
   output_toggle(pin_b7);  // RB7 ucunun çıkış durumu tersleniyor
   delay_ms(500);          // 500 ms'lik gecikme veriliyor
 
   goto basla;

}
