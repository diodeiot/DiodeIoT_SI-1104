/**
  @file si1104.h

  @authors Diode IoT Inc. <info@diodeiot.com>

  @authors Kadir Sevil <kadir.sevil@diodeiot.com>

  @copyright Copyright (c) 2021-2022 Diode Iot Inc. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef SI1104_H
#define SI1104_H

#include <Arduino.h>

/**
  @class SI1104

  @brief SI1104 geliştirme kartı sınıfı.
*/
class SI1104
{
  public:
  SI1104(void);

  ~SI1104(void);

  /**
    @brief Objeyi başlat.

    @param[in] debounce_time Kartın üzerinde bulunan BOOT butonunun ms cinsinden debounce süresi. Varsayılan değeri 50.
  */
  void init(unsigned long debounce_time = 50);

  /**
    @brief Objeyi sonlandır.
  */
  void deinit(void);

  /**
    @brief Kartın üzerinde bulunan BOOT butonu için debounce işlemlerini yerine getirir. Bir döngü içerisinde çağrılmalıdır.
  */
  void loop(void);

  /**
    @brief Kart üzerindeki ledi ayarla.

    @param[in] state 0: Led kapalı, 1: Led açık.
  */
  void ledSet(int state);

  /**
    @brief Kart üzerindeki ledi aç.
  */
  void ledOn(void);

  /**
    @brief Kart üzerindeki ledi kapat.
  */
  void ledOff(void);

  /**
    @brief Kartın üzerinde bulunan BOOT butonuna basılma durumunu kontrol eder.

    @return Butona basılma durumu.

    @retval true Butona basılmış.

    @retval false Butona basılmamış.
  */
  bool isButtonPressed(void);

  /**
    @brief Kartın üzerinde bulunan BOOT butonunu bırakma durumunu kontrol eder.

    @return Butona basılma durumu.

    @retval true Buton bırakılmış.

    @retval false Buton bırakılmamış.
  */
  bool isButtonReleased(void);

  /**
    @brief Röleyi açar ya da kapatır.

    @param[in] chNum Rölenin kanal numarası.

    @param[in] state 0: Kapalı, 1: Açık.
  */
  void setRelay(int chNum, int state);

  /**
    @brief Rölenin açık/kapalı durumunu döndürür.

    @param[in] chNum Rölenin kanal numarası.

    @retval 0 Röle kapalı.
    @retval 1 Röle açık.
  */
  int getRelay(int chNum);

  /**
    @brief Tüm röleleri açar.
  */
  void allOnRelay(void);

  /**
    @brief Tüm röleleri kapatır.
  */
  void allOffRelay(void);

  /**
    @brief Röle1'i aç.
  */
  void openRelay1(void);

  /**
    @brief Röle1'i kapat.
  */
  void closeRelay1(void);

  /**
    @brief Röle1'in durumunu döndür.

    @retval 0 Röle kapalı.
    @retval 1 Röle açık.
  */
  int getRelay1(void);

  /**
    @brief Röle2'yi aç.
  */
  void openRelay2(void);

  /**
    @brief Röle2'yi kapat.
  */
  void closeRelay2(void);

  /**
    @brief Röle2'in durumunu döndür.

    @retval 0 Röle kapalı.
    @retval 1 Röle açık.
  */
  int getRelay2(void);

  /**
    @brief Röle3'ü aç.
  */
  void openRelay3(void);

  /**
    @brief Röle3'ü kapat.
  */
  void closeRelay3(void);

  /**
    @brief Röle3'ün durumunu döndür.

    @retval 0 Röle kapalı.
    @retval 1 Röle açık.
  */
  int getRelay3(void);

  /**
    @brief Röle4'ü aç.
  */
  void openRelay4(void);

  /**
    @brief Röle4'ü kapat.
  */
  void closeRelay4(void);

  /**
    @brief Röle4'ün durumunu döndür.

    @retval 0 Röle kapalı.
    @retval 1 Röle açık.
  */
  int getRelay4(void);

  private:
  unsigned long debounce_time;

  int previous_steady_state;

  int last_steady_state;

  int last_fickle_state;

  unsigned long last_debounce_time;

  const static int led[1][2];

  const static int button[1][2];

  const static int ch_lookup[4][2];
};

extern SI1104 si1104;

#endif /*SI1104_H*/