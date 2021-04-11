/*
 *  pressure.cpp - Read a DFRobot Pressure Sensor.
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

#include "Pressure.h"
#include <Arduino.h>

DFRobot_Pressure::DFRobot_Pressure(int pin, float fluid_density_gcm3, float g_nkg)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _density = fluid_density_gcm3;
    _g = g_nkg;
}

float DFRobot_Pressure::read_kpa()
{
    // Range: 0-1.6MPa = 0-1600kPa
    // Output: 0.5-4.5V
    // p = 400kPa/V*U - 200kPa
    // Therefore, 0V = 0 = -200kPa, 5.0V = 1023 = 1800kPa
    // Analog: 1023 = 5V
    // p = 2000kPa/1023*a - 200kPa
    int sensorValue = analogRead(_pin);
    return 2000.0/1023.0 * sensorValue - 200.0;
}

float DFRobot_Pressure::get_depth_mm()
{
    // p = ρgh
    // h = p/ρg
    return read_kpa() / (_density * 1E3 * _g);
}

