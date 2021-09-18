#include "main.h"
#include "12_led_configuration.h"
#define Default_numbers 			12
#define Num_Row						5
#define first_state					0
#define second_state				1
#define third_state					2
#define fourth_state				3
#define fifth_state					4

static uint8_t RowOn[Default_numbers] = {0x3f, 0x3f, 0x5f, 0x6f, 0x77, 0x7b, 0x7b, 0x7b, 0x77, 0x6f, 0x5f, 0x3f};
static uint8_t ColOn[Default_numbers] = {0x04, 0x02, 0x01, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08};

static uint8_t Row[Default_numbers][Num_Row] = {
		0x47,	0x3b,	0x7b,	0x3b,	0x47,
		0x47,	0x3b,	0x3b,	0x7b,	0x47,
		0x47,	0x3b,	0x3b,	0x3b,	0x67,
		0x47,	0x3b,	0x3b,	0x3b,	0x57,
		0x47,	0x3b,	0x3b,	0x3b,	0x4f,
		0x47,	0x3b,	0x3b,	0x3f,	0x47,
		0x47,	0x3b,	0x3f,	0x3b,	0x47,
		0x47,	0x3f,	0x3b,	0x3b,	0x47,
		0x4f,	0x3b,	0x3b,	0x3b,	0x47,
		0x57,	0x3b,	0x3b,	0x3b,	0x47,
		0x67,	0x3b,	0x3b,	0x3b,	0x47,
		0x47,	0x7b,	0x3b,	0x3b,	0x47 };

void clearAllClock() {
// Row set up
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, 0);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, 0);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, 0);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, 0);
	HAL_GPIO_WritePin(ROW_5_GPIO_Port, ROW_5_Pin, 0);
	HAL_GPIO_WritePin(ROW_6_GPIO_Port, ROW_6_Pin, 0);
	HAL_GPIO_WritePin(ROW_7_GPIO_Port, ROW_7_Pin, 0);
// Column set up
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, 0);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, 0);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, 0);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, 0);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, 0);
}

void setNumberOnClock(int num) {
	if(num < 0 || num >= 12)
		return;
	uint8_t row = RowOn[num];
	uint8_t col = ColOn[num];

	// Set up the columns from 5 --> 1
	if(col & 0x01)
		HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, 1);
	else
		HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, 0);

	if(col & 0x02)
		HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, 1);
	else
		HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, 0);

	if(col & 0x04)
		HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, 1);
	else
		HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, 0);

	if(col & 0x08)
		HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, 1);
	else
		HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, 0);

	if(col & 0x10)
		HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, 1);
	else
		HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, 0);

	// Set up the rows from 7 --> 1

	if(row & 0x01)
		HAL_GPIO_WritePin(ROW_7_GPIO_Port, ROW_7_Pin, 1);
	else
		HAL_GPIO_WritePin(ROW_7_GPIO_Port, ROW_7_Pin, 0);

	if(row & 0x02)
		HAL_GPIO_WritePin(ROW_6_GPIO_Port, ROW_6_Pin, 1);
	else
		HAL_GPIO_WritePin(ROW_6_GPIO_Port, ROW_6_Pin, 0);

	if(row & 0x04)
		HAL_GPIO_WritePin(ROW_5_GPIO_Port, ROW_5_Pin, 1);
	else
		HAL_GPIO_WritePin(ROW_5_GPIO_Port, ROW_5_Pin, 0);

	if(row & 0x08)
		HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, 1);
	else
		HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, 0);

	if(row & 0x10)
		HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, 1);
	else
		HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, 0);

	if(row & 0x20)
		HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, 1);
	else
		HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, 0);

	if(row & 0x40)
		HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, 1);
	else
		HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, 0);

}

void setUpRow(uint8_t row) {
	// Set up the rows from 5 --> 1
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, row & 0x40);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, row & 0x20);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, row & 0x10);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, row & 0x08);
	HAL_GPIO_WritePin(ROW_5_GPIO_Port, ROW_5_Pin, row & 0x04);
}

void clearNumberOnClock(int num) {
	if(num < 0 || num >= 12)
		return;
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, 1);
	setUpRow(Row[num][first_state]);
	HAL_Delay(1);

	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, 0);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, 1);
	setUpRow(Row[num][second_state]);
	HAL_Delay(1);

	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, 0);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, 1);
	setUpRow(Row[num][third_state]);
	HAL_Delay(1);

	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, 0);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, 1);
	setUpRow(Row[num][fourth_state]);
	HAL_Delay(1);

	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, 0);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, 1);
	setUpRow(Row[num][fifth_state]);
	HAL_Delay(1);

	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, 0);

}
