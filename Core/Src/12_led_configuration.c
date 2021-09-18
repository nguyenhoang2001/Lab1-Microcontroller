#include "main.h"
#include "12_led_configuration.h"

void clearAllClock() {
// Row set up
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, 0);
	HAL_GPIO_WritePin(ROW_7_GPIO_Port, ROW_7_Pin, 0);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, 0);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, 0);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, 0);
	HAL_GPIO_WritePin(ROW_5_GPIO_Port, ROW_5_Pin, 0);
	HAL_GPIO_WritePin(ROW_6_GPIO_Port, ROW_6_Pin, 0);
// Column set up
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, 0);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, 0);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, 0);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, 0);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, 0);
}
