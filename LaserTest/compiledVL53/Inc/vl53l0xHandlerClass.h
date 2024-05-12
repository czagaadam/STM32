/*
 * vl53l0xHandlerClass.h
 *
 *  Created on: 2019. szept. 21.
 *      Author: czagaa
 */

#ifndef VL53L0XHANDLERCLASS_H_
#define VL53L0XHANDLERCLASS_H_

void VL53L0X_InitHandlerClass(uint8_t numofDevices);

VL53L0X_Dev_t VL53L0X_GetDevice(uint8_t Indexer);

VL53L0X_Dev_t VL53L0X_GetLastDevice();
uint8_t VL53L0X_GetDeviceIndexer();

void VL53L0X_DefineAndPutDevice(uint16_t gpioDxshutpin, uint8_t type, uint8_t speed, uint8_t address);

void VL53L0X_DeleteDevice();

void VL53L0X_APPStart(void);

void VL53L0X_APPStartCustomAddress(uint8_t Indexer);

void VL53L0X_APPStartCustomLastAddress();
void VL53L0X_ResetNodes();
void VL53L0X_ActiveNodeAddress(uint8_t Indexer);

void VL53L0X_ActiveLastNodeAddress();

uint16_t VL53L0X_NodeMeasure(uint8_t Indexer);

uint16_t VL53L0X_LastNodeMeasure();
#endif /* VL53L0XHANDLERCLASS_H_ */
