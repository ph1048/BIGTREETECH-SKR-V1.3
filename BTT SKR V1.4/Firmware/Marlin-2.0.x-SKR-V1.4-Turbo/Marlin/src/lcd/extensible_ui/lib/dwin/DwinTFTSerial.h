/**
 * DWIN TFT Support for Anycubic i3 Mega and 4Max Pro
 * Based on the work of Christian Hopp and David Ramiro.
 * Copyright (c) 2020 by Jonas Plamann <https://github.com/Poket-Jony>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "../../../../inc/MarlinConfigPre.h"
#include "../../../../Marlin.h"

#define DwinTFTSerial DWIN_SERIAL

inline void DwinSend(const char* str)
{
  for(const char* p = str; *p; p++) {
    DwinTFTSerial.write((uint8_t)*p);
  }
}

inline void DwinSend(float f)
{
  DwinTFTSerial.printf("%.6f", f);
}

inline void DwinSend(int i)
{
  DwinTFTSerial.printf("%d", i);
}

#define DWIN_TFT_SERIAL_PROTOCOL(x) (DwinSend(x))
#define DWIN_TFT_SERIAL_PROTOCOLPGM DWIN_TFT_SERIAL_PROTOCOL
#define DWIN_TFT_SERIAL_PROTOCOLLN(x) (DwinSend(x),DwinSend("\r\n"))
#define DWIN_TFT_SERIAL_PROTOCOLLNPGM DWIN_TFT_SERIAL_PROTOCOLLN
#define DWIN_TFT_SERIAL_PROTOCOLLNPGM_LOOP(x) (DWIN_TFT_SERIAL_PROTOCOLLNPGM(x),DWIN_TFT_SERIAL_PROTOCOLLNPGM(x))

#define DWIN_TFT_SERIAL_ENTER() (DwinSend("\r\n"))
#define DWIN_TFT_SERIAL_SPACE() (DwinTFTSerial.write(' '))

const char newErr[] = "ERR ";
const char newSucc[] = "OK";

#define DWIN_TFT_SERIAL_ERROR_START (DwinSend(newErr))
#define DWIN_TFT_SERIAL_ERROR(x) DWIN_TFT_SERIAL_PROTOCOL(x)
#define DWIN_TFT_SERIAL_ERRORPGM(x) DWIN_TFT_SERIAL_PROTOCOLPGM(x)
#define DWIN_TFT_SERIAL_ERRORLN(x) DWIN_TFT_SERIAL_PROTOCOLLN(x)
#define DWIN_TFT_SERIAL_ERRORLNPGM(x) DWIN_TFT_SERIAL_PROTOCOLLNPGM(x)

//##define DWIN_TFT_SERIAL_ECHO_START (DwinTFTSerial.write(newSucc))
#define DWIN_TFT_SERIAL_ECHOLN(x) DWIN_TFT_SERIAL_PROTOCOLLN(x)
#define DWIN_TFT_SERIAL_SUCC_START (DwinSend(newSucc))
#define DWIN_TFT_SERIAL_ECHOPAIR(name,value) (serial_echopair_P(PSTR(name),(value)))
#define DWIN_TFT_SERIAL_ECHOPGM(x) DWIN_TFT_SERIAL_PROTOCOLPGM(x)
#define DWIN_TFT_SERIAL_ECHO(x) DWIN_TFT_SERIAL_PROTOCOL(x)

