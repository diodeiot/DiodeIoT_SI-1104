# SI-1104 - ESP32 4 Kanal Röle Geliştirme Modülü

![Build Status](https://github.com/diodeiot/DiodeIoT_SI-1104/workflows/Arduino%20Library%20CI/badge.svg)

![top](https://user-images.githubusercontent.com/111313342/184736053-74586f82-7117-478b-9c03-7302644e917f.png)

## SI-1104 Nedir?
SI-1104, üzerinde ESP32 mikrodenetleyicisi bulunan 4 Kanal röle geliştirme modülüdür. \
Geliştiriciler zengin örnek kodlara sahip bu kütüphaneyi kullanarak kendi uygulamalarını kolayca geliştirebilirler.

Bu geliştirme modülü:

* Akıllı Evler
* Ev Otomasyonu
* Endüstriyel Otomasyon
* Araç İçi Otomasyon
* Güç Anahtarlama

başta olmak üzere amatör ve profesyonel herhangi bir amaç için kullanılabilir.

## Dökümantasyon
[<img alt="github-pages" width="150px" src="https://user-images.githubusercontent.com/100811304/184258420-58ed4a45-29ce-4329-9260-c54ae8973690.png" />](https://diodeiot.github.io/DiodeIoT_SI-1104)

Kaynak kodların dökümantasyonuna [buradan](https://diodeiot.github.io/DiodeIoT_SI-1104) ulaşabilirsiniz.

## Teknik Özellikler

### Pin Bağlantıları

Eleman | Pin Numarası | Lojik Seviye
-- | :--: | --
BOOT Butonu | 0 | Active Low
LED | 2 | Active Low
Röle 1 | 16 | Active High
Röle 2 | 4 | Active High
Röle 3 | 27 | Active High
Röle 4 | 14 | Active High

### Elektriksel Karakteristikler

Parametre | Minimum | Nomimal | Maximum | Birim
-- | :--: | :--: | :--: | --
Giriş Gerilimi | 4.75 | 5 | 5.5 | V
Giriş Akımı | | 0.28 | | A
Röle Anahtarlama Akımı | | | 10 | A
Röle Anahtarlama Gerilimi | | | 250 | VAC

> :warning: **Uyarı**\
> Sadece 5V güç kaynağı ile kullanın.

> :warning: **Uyarı**\
> Güç kaynağını doğru polaritede bağlayın.

### Termal Bilgiler

Parametre | Minimum | Nomimal | Maximum | Birim
-- | :--: | :--: | :--: | --
Çalışma Sıcaklığı | -40 | | 85 | °C

### Mekanik Bilgiler

Parametre | Minimum | Nomimal | Maximum | Birim
-- | :--: | :--: | :--: | --
Genişlik | | 80 | | mm
Uzunluk | | 64 | | mm
Yükseklik | | 19.1 | | mm

## Gerekenler

## 1. SI-1104 Geliştirme Modülü
SI-1104 geliştirme modülünü aşağıdaki online marketlerden edinebilirsiniz:

[<img alt="özdisan" width="150px" src="https://user-images.githubusercontent.com/111313342/185208516-03412fa5-7c2a-4f45-a1b3-a4b5fa2b1e6d.png" />](https://ozdisan.com/)

[<img alt="direnc net" width="150px" src="https://user-images.githubusercontent.com/111313342/185208523-e1d5a133-d13e-490f-8011-0b83b9cfd852.png" />](https://www.direnc.net/)

[<img alt="robotistan" width="150px" src="https://user-images.githubusercontent.com/111313342/185208535-c1e5e80d-dee9-4cf9-b6ce-97cbf80e2975.png" />](https://www.robotistan.com/)

## 2. USB-UART Dönüştürücü
SI-1104 geliştirme modülünü bilgisayara bağlamak için 3.3V usb-uart dönüştürcü kullanmanız gerekmektedir. 
Dönüştürücünün `RX` `TX` `GND` pinlerini modülün `TX` `RX` `GND` pinlerine bağlayın.

> :warning: **Uyarı**\
> Modülü bilgisayarınıza bağlamak için modüle harici güç kaynağı bağlamanız gerekmektedir.

## 3. 5V Güç kaynağı
SI-1104 geliştirme modülüne 5V minimun 1A güç kaynağı bağlamalısınız.

> :warning: **Uyarı**\
> Güç kaynağını doğru polaritede bağlayın.

## 4. SI-1104 Kütüphanesi
Bu kütüphane SI-1104 geliştirme modülü için yazılmış arduino esp32 kütüphanesidir. Geliştiriciler, zengin örnek kodlara sahip bu kütüphaneyi kullanarak kendi uygulamalarını kolayca geliştirebilirler.

> :warning: **Uyarı**\
> Bu kütüphane sadece Arduino IDE 1.5.x ve üzeri versiyonları ile uyumludur.

### Arduino IDE Kurulumu
Bu kütüphaneyi kullanmak için ilk olarak Arduino IDE gereklidir. Eğer sisteminizde Arduino IDE yüklü değil ise [burada](https://www.arduino.cc/en/software) anlatıldığı şekilde programın son sürümünü yükleyebilirsiniz.

### ESP32 Arduino Çekirdeğini Yükleme
Arduino IDE'nizi kurduktan sonra ESP32 mcu'nuzda kod geliştirmek için kullanacağınız ESP32 arduino çekirdeğini yüklemelisiniz. Bu yüklemeyi [burada](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html) anlatıldığı şekilde arduino ide'nizdeki kütüphane yöneticisi ile kolayca yapabilirsiniz.

### SI-1104 Kütüphanesi Kurulumu

![image](https://user-images.githubusercontent.com/111313342/184738426-d91e421b-248a-4407-a873-3f6d916bcac8.png)

SI-1104 kütüphanesini kurmak için yukarıda görüldüğü gibi kütüphaneyi zip halinde bilgisayarınıza indirin.

![image](https://user-images.githubusercontent.com/111313342/184737637-841fc44f-8a3c-41ec-81a3-65842ae8a2f9.png)

Daha sonra arduino idenizi açıp yukarıda görülen seçeneğe tıklayıp indirdiğiniz SI-1104 kütüphanesini bilgisayarınıza kurun.

Bu adımları tamamladıktan sonra arduino idenizden dilediğiniz SI-1104 kütüphane örneklerini inceleyebilirsiniz.

## Örnek Kodlar
Örnek kodlara [buradan](./examples) erişebilirsiniz.

* [Buton ile Röle Kontrolü](./examples/button_relay_control/button_relay_control.ino) \
Bu örnekte kartın üzerindeki BOOT butonuna her bastığınızda sırası ile röleler açılmaktadır.

* [MQTT Protokolü ile Röle Kontrolü](./examples/mqtt_relay_control/mqtt_relay_control.ino) \
Bu örnekte mqtt ile kartın üzerindeki röleleri uzaktan kontrol ediyoruz.

* [Seri Konsol ile Röle Kontrolü](./examples/serial_terminal_relay_control/serial_terminal_relay_control.ino) \
Bu örnekte seri konsol ile kartın üzerindeki röleleri kontrol ediyoruz.

## Kütüphaneye Katkıda Bulunma
SI-1104 kütüphanesine katkılarınızı memnuniyetle karşılarız.
Kütüphaneye dilediğiniz katkıyı `Pull Request` ile yapabilirsiniz.

## Lisans
LGPL (GNU Kısıtlı Genel Kamu Lisansı)

![license](https://upload.wikimedia.org/wikipedia/commons/thumb/3/3b/LGPLv3_Logo.svg/200px-LGPLv3_Logo.svg.png)
