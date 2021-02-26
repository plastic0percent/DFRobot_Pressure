/*
 *  pressure.h - Read a DFRobot Pressure Sensor.
 *
 *  Copyright (C) 2021 Zhang Maiyun
 *
 *  This file is part of Skymirror_ino.
 *  Skymirror_ino is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Skymirror_ino is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef Pressure_h
#define Pressure_h

#include <Arduino.h>

class DFRobot_Pressure
{
  public:
    DFRobot_Pressure(int pin);
    int read_kpa();
  private:
    int _pin;
};

#endif

