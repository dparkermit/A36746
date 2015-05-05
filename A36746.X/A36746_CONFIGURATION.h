#ifndef __A36746_CONFIGURATION_H
#define __A36746_CONFIGURATION_H


// Required Parameters
#define __USE_CAN_1
#define FCY_CLK                             10000000
#define ETM_CAN_MY_ADDRESS                  ETM_CAN_ADDR_COOLING_INTERFACE_BOARD
#define PIN_CAN_OPERATION_LED               _LATG13
#define ETM_CAN_INTERRUPT_PRIORITY          4  

#define ETM_CAN_AGILE_ID_HIGH               0
#define ETM_CAN_AGILE_ID_LOW                36764
#define ETM_CAN_AGILE_DASH                  0
#define ETM_CAN_AGILE_REV                   'A'                   
#define ETM_CAN_SERIAL_NUMBER               100 // DPARKER need to figure out how to set this in FLASH when programming

#endif
