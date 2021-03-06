////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <tinyhal.h>
#include <Tests.h>
#include "nativesample.h"

//--//

#ifdef TCPIP_LWIP 
void  Network_PostEvent(UINT32 evt, UINT32 data)
{
}
#endif

HAL_DECLARE_NULL_HEAP();

void ApplicationEntryPoint()
{
    BOOL result;
   
    TimedEvents eventsTest;
    UART        usartTest  ( COMTestPort, 9600, USART_PARITY_NONE, 8, USART_STOP_BITS_ONE, USART_FLOW_NONE );
    GPIO        gpioTest   ( GPIOTestPin );
    Timers      timersTest ( DisplayInterval, TimerDuration );

    do
    {    
        result = eventsTest.Execute( STREAM__LCD );
        result = usartTest.Execute ( STREAM__LCD );
        result = gpioTest.Execute  ( STREAM__LCD );
        result = timersTest.Execute( STREAM__LCD );

    } while(FALSE); // run only once!

    while(TRUE)
    {
        hal_printf(" hello world\r\n");
        Events_WaitForEvents( 0, 5000 );

    }
}

