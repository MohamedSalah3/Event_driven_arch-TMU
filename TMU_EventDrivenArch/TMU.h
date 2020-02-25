/*
 * TMU.h
 *
 * Created: 24/02/2020 01:22:47 م
 *  Author: mo
 */ 


#ifndef TMU_H_
#define TMU_H_
#include "TMU_Config.h"
#include "Timer.h"
#include "DIO.h"
typedef void (*ptr_to_Fun) (void);
uint8_t TMU_Init (const TMU_ConfigType * ConfigPtr );
ERROR_STATUS TMU_Stop_Timer(uint8_t u8_function_index);
ERROR_STATUS TMU_Start_Timer(ptr_to_Fun Function_Consumer,uint8_t  u8_Preodicity,uint8_t u8_function_index,uint8_t u8_Time_delay);

ERROR_STATUS TMU_Main_Function(void);

void Tmu_Fun(void);
void Tmu_For(void);
void Tmu_excute(void);


#endif /* TMU_H_ */