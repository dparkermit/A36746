#include "P1395_CAN_SLAVE.h"
#include "A36746.h"

//void ETMCanSlaveExecuteCMDBoardSpecific(ETMCanMessage* message_ptr);
//void ETMCanSlaveLogData(unsigned int packet_id, unsigned int word3, unsigned int word2, unsigned int word1, unsigned int word0);

void ETMCanSlaveExecuteCMDBoardSpecific(ETMCanMessage* message_ptr) {
  unsigned int index_word;

  index_word = message_ptr->word3;
  switch (index_word) 
    {
      /*
	Place all board specific commands here
      */
      
    case ETM_CAN_REGISTER_COOLING_CMD_SF6_PULSE_LIMIT_OVERRIDE:
      global_data_A36746.SF6_pulses_available = 25;
      ETMEEPromWritePage(ETM_EEPROM_PAGE_COOLING_INTERFACE, 2, &global_data_A36746.SF6_pulses_available);
      break;
      
    case ETM_CAN_REGISTER_COOLING_CMD_RESET_BOTTLE_COUNT:
      global_data_A36746.SF6_bottle_pulses_remaining = message_ptr->word0;
      ETMEEPromWritePage(ETM_EEPROM_PAGE_COOLING_INTERFACE, 2, &global_data_A36746.SF6_pulses_available);
      break;
      
    case ETM_CAN_REGISTER_COOLING_CMD_SF6_LEAK_LIMIT_OVERRIDE:
      global_data_A36746.SF6_low_pressure_override_counter = message_ptr->word0;
      break;
      
    default:
      local_can_errors.invalid_index++;
      break;
    }
}


void ETMCanSlaveLogCustomPacketC(void) {
  /* 
     Use this to log Board specific data packet
     This will get executed once per update cycle (1.6 seconds) and will be spaced out in time from the other log data
  */

  ETMCanSlaveLogData(ETM_CAN_DATA_LOG_REGISTER_COOLING_SLOW_FLOW_0,
		     global_data_A36746.flow_hvps,
		     global_data_A36746.flow_magnetron,
		     global_data_A36746.flow_linac,
		     global_data_A36746.flow_circulator
		     );
  
}


void ETMCanSlaveLogCustomPacketD(void) {
  /* 
     Use this to log Board specific data packet
     This will get executed once per update cycle (1.6 seconds) and will be spaced out in time from the other log data
  */

  ETMCanSlaveLogData(ETM_CAN_DATA_LOG_REGISTER_COOLING_SLOW_FLOW_1,
		     global_data_A36746.SF6_bottle_pulses_remaining,
		     global_data_A36746.SF6_pulses_available,
		     global_data_A36746.flow_hv_tank,
		     global_data_A36746.flow_spare
		     );
}


void ETMCanSlaveLogCustomPacketE(void) {
  /* 
     Use this to log Board specific data packet
     This will get executed once per update cycle (1.6 seconds) and will be spaced out in time from the other log data
  */

  ETMCanSlaveLogData(
		     ETM_CAN_DATA_LOG_REGISTER_COOLING_SLOW_ANALOG_READINGS,
		     global_data_A36746.coolant_temperature_kelvin,
		     global_data_A36746.analog_input_SF6_pressure.reading_scaled_and_calibrated,
		     global_data_A36746.cabinet_temperature_kelvin,
		     0
		     );
}

void ETMCanSlaveLogCustomPacketF(void) {
  /* 
     Use this to log Board specific data packet
     This will get executed once per update cycle (1.6 seconds) and will be spaced out in time from the other log data
  */
}


  



