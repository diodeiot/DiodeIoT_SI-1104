/**
  @file si1104.cpp

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

#include "si1104.h"

#define ARRLEN(x) ((sizeof(x)) / (sizeof(*x)))

#define GET_STATE(x, y) ((!x) != (!y))

SI1104 si1104;

const int SI1104::led[1][2] = {{2, HIGH}};

const int SI1104::button[1][2] = {{0, LOW}};

const int SI1104::ch_lookup[4][2] = {{16, LOW}, {4, LOW}, {27, LOW}, {14, LOW}};

SI1104::SI1104(void)
{
}

SI1104::~SI1104(void)
{
}

void SI1104::init(unsigned long debounce_time)
{
  this->debounce_time = debounce_time;

  previous_steady_state = digitalRead(button[0][0]);
  last_steady_state = previous_steady_state;
  last_fickle_state = previous_steady_state;
  last_debounce_time = 0;

  digitalWrite(led[0][0], GET_STATE(led[0][1], LOW));
  pinMode(led[0][0], OUTPUT);

  pinMode(button[0][0], INPUT);

  for(int i = 0; i < ARRLEN(ch_lookup); i++)
  {
    digitalWrite(ch_lookup[i][0], GET_STATE(ch_lookup[i][1], LOW));
    pinMode(ch_lookup[i][0], OUTPUT);
  }
}

void SI1104::deinit(void)
{
  pinMode(led[0][0], INPUT);

  pinMode(button[0][0], INPUT);

  for(int i = 0; i < ARRLEN(ch_lookup); i++)
  {
    pinMode(ch_lookup[i][0], INPUT);
  }
}

void SI1104::loop(void)
{
  unsigned long current_time = millis();

  int current_state = digitalRead(button[0][0]);

  if(current_state != last_fickle_state)
  {
    last_debounce_time = current_time;
    last_fickle_state = current_state;
  }

  if((current_time - last_debounce_time) >= debounce_time)
  {
    previous_steady_state = last_steady_state;
    last_steady_state = current_state;
  }
}

void SI1104::ledSet(int state)
{
  digitalWrite(led[0][0], GET_STATE(led[0][1], state));
}

void SI1104::ledOn(void)
{
  ledSet(1);
}

void SI1104::ledOff(void)
{
  ledSet(0);
}

bool SI1104::isButtonPressed(void)
{
  return previous_steady_state == HIGH && last_steady_state == LOW;
}

bool SI1104::isButtonReleased(void)
{
  return previous_steady_state == LOW && last_steady_state == HIGH;
}

void SI1104::setRelay(int chNum, int state)
{
  if(chNum < 1 || chNum > ARRLEN(ch_lookup))
  {
    return;
  }

  digitalWrite(ch_lookup[chNum - 1][0], GET_STATE(ch_lookup[chNum - 1][1], state));
}

int SI1104::getRelay(int chNum)
{
  if(chNum < 1 || chNum > ARRLEN(ch_lookup))
  {
    return -1;
  }

  return GET_STATE(ch_lookup[chNum - 1][1], digitalRead(ch_lookup[chNum - 1][0]));
}

void SI1104::allOnRelay(void)
{
  for(int i = 0; i < ARRLEN(ch_lookup); i++)
  {
    digitalWrite(ch_lookup[i][0], GET_STATE(ch_lookup[i][1], HIGH));
  }
}

void SI1104::allOffRelay(void)
{
  for(int i = 0; i < ARRLEN(ch_lookup); i++)
  {
    digitalWrite(ch_lookup[i][0], GET_STATE(ch_lookup[i][1], LOW));
  }
}

void SI1104::openRelay1(void)
{
  setRelay(1, HIGH);
}

void SI1104::closeRelay1(void)
{
  setRelay(1, LOW);
}

int SI1104::getRelay1(void)
{
  return getRelay(1);
}

void SI1104::openRelay2(void)
{
  setRelay(2, HIGH);
}

void SI1104::closeRelay2(void)
{
  setRelay(2, LOW);
}

int SI1104::getRelay2(void)
{
  return getRelay(2);
}

void SI1104::openRelay3(void)
{
  setRelay(3, HIGH);
}

void SI1104::closeRelay3(void)
{
  setRelay(3, LOW);
}

int SI1104::getRelay3(void)
{
  return getRelay(3);
}

void SI1104::openRelay4(void)
{
  setRelay(4, HIGH);
}

void SI1104::closeRelay4(void)
{
  setRelay(4, LOW);
}

int SI1104::getRelay4(void)
{
  return getRelay(4);
}
