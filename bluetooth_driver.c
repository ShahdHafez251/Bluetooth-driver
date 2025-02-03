#include "bluetooth_driver.h"

#include <string.h>



// Function to Send AT Commands
void Bluetooth_SendCommand(char *command) {
    HAL_UART_Transmit(&huart1, (uint8_t*)command, strlen(command), HAL_MAX_DELAY);
}

// Function to Initialize Bluetooth Module
void Bluetooth_Init() {
    char *initCommands[] = {
        "AT+NAME=MyDevice\r\n",  // rename the device
        "AT+UART=9600,1,0\r\n",  //  setup Baud Rate
        "AT+ROLE=0\r\n"          // setup Role (Slave)
    };

    for (int i = 0; i < 3; i++) {
        Bluetooth_SendCommand(initCommands[i]);
        HAL_Delay(100);  // wait 100ms for each command
    }
}

// Function to Send Data
void Bluetooth_SendData(char *data) {
    HAL_UART_Transmit(&huart1, (uint8_t*)data, strlen(data), HAL_MAX_DELAY);
}

// Function to Receive Data
void Bluetooth_ReceiveData(char *buffer, uint16_t size) {
    HAL_UART_Receive(&huart1, (uint8_t*)buffer, size, HAL_MAX_DELAY);
}