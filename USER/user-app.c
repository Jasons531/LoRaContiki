/*
**************************************************************************************************************
*	@file	user-app.c
*	@author Jason_531@163.com
*	@version 
*	@date    
*	@brief	Э����÷ֲ㷽ʽ��mac app��������
***************************************************************************************************************
*/
#include <math.h>
#include "user-app.h"
#include "board.h"
#include "binhex.h"
#include "LoRaMac.h"
#include "LoRa-cad.h"
#include "LoRaMac-api-v3.h"



/*******************************���巢������************************************/

/*
 *	IntoLowPower:	����͹���ģʽ��ͣ��
 *	����ֵ: 		  ��
 */
void IntoLowPower(void)
{	
		Radio.Sleep( );  ///LoRa������״̬
        
    BoardDeInitMcu(); ///�ر�ʱ����
    
    // Disable the Power Voltage Detector
    HAL_PWR_DisablePVD( );
    
    SET_BIT( PWR->CR, PWR_CR_CWUF );
    /* Set MCU in ULP (Ultra Low Power) */
    HAL_PWREx_EnableUltraLowPower( );
    
    /* Enable the fast wake up from Ultra low power mode */
    HAL_PWREx_EnableFastWakeUp();

    /*****************����ͣ��ģʽ*********************/
    /* Enter Stop Mode */
    __HAL_PWR_CLEAR_FLAG( PWR_FLAG_WU );
    HAL_PWR_EnterSTOPMode( PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI );
    
}


/*--------------------------------------------------------------------------
                                                     0ooo
                                          ooo0      (   )
                                          (   )      ) /
                                           \ (      (_/
                                            \_)
----------------------------------------------------------------------------*/

