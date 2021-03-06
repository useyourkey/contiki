/*
 * Copyright (c) 2015, ICT/COS/NSLab, KTH Royal Institute of Technology
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 */

/**
 * \file
 *      dcdc/status read-only parameters for power monitoring
 * \author
 *      Voravit Tanyingyong <voravit@kth.se>
 */

#include "contiki.h"
/* #include "lib/sensors.h" */
#include "dev/dc-status-sensor.h"

const struct sensors_sensor dc_status_sensor;

/*
 * Status contains 4 parameters
 * status[0] VOUT
 * status[1] VIN
 * status[2] IOUT
 * status[3] IIN
 */

uint32_t volatile s[4] = { 18, 20, 1, 2 };

static int
value(int type)
{
  switch(type) {
  case 0:
    return s[0];

  case 1:
    return s[1];

  case 2:
    return s[2];

  case 3:
    return s[3];
  }
  return -1;
}
static int
configure(int type, int c)
{
  return 0;
}
static int
status(int type)
{
  return 1;
}
SENSORS_SENSOR(dc_status_sensor, "DC status sensors", value, configure, status);

