/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                          (c) Copyright 2003-2010; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                         uC/OS-II example code
*                                          Application task one
*
*                                   Energy Micro EFM32 (EFM32LG990F256)
*                                              with the
*                                   Energy Micro DK3650 Development Kit
*
* @file   app_task_one.c  
* @brief
* @author Energy Micro AS
* @version 3.20.0
******************************************************************************
* @section License
* <b>(C) Copyright 2013 Energy Micro AS, http://www.energymicro.com</b>
*******************************************************************************
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
* 4. The source and compiled code may only be used on Energy Micro "EFM32"
*    microcontrollers and "EFR4" radios.
*
* DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Energy Micro AS has no
* obligation to support this Software. Energy Micro AS is providing the
* Software "AS IS", with no express or implied warranties of any kind,
* including, but not limited to, any implied warranties of merchantability
* or fitness for any particular purpose or warranties against infringement
* of any proprietary rights of a third party.
*
* Energy Micro AS will not be liable for any consequential, incidental, or
* special damages, or any other relief, or for any claim by any third party,
* arising from your use of this Software.
*
*********************************************************************************************************
*/
#include <includes.h>


/*
*********************************************************************************************************
*                                         APP_TaskOne()
* @brief      The One task.
*
* @param[in]  p_arg       Argument passed to 'APP_TaskOne()' by 'OSTaskCreate()'.
* @exception  none
* @return     none.
*/
/* Notes      :(1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*
*
*********************************************************************************************************
*/
void APP_TaskOne(void *p_arg)
{
  static uint16_t ledMask = 0x01; /* LED mask variable  */

  (void)p_arg; /* Note(1) */

  while (1)
  { /* Task body, always written as an infinite loop  */

    /* Delay with 100msec                             */
    OSTimeDlyHMSM(0, 0, 0, 100);

    /* Animate LEDs */
    BSP_LedsSet(ledMask);


    if( 0x8000 == ledMask )
    {
      ledMask = 0x01;
    }
    else
    {
      ledMask <<= 1;
    }


    /* Delay task for 1 system tick (uC/OS-II suspends this task and executes
     * the next most important task) */
    OSTimeDly(1);
  }
}
