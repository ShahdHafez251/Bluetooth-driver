#include "stm32f1xx_hal.h"
extern UART_HandleTypeDef huart1;

// Function Prototypes
void Bluetooth_Init(void);
void Bluetooth_SendCommand(char *command);
void Bluetooth_SendData(char *data);
void Bluetooth_ReceiveData(char *buffer, uint16_t size);