#include "i2c.h"
#include "vl53l0x.h"
#include "vl53l0x/vl53l0x_platform.h" //typedef VL53L0X_Dev_t
#include "vl53l0x/vl53l0x_api.h"
#include "stdlib.h"





/* USER CODE BEGIN PV */
  uint8_t DeviceIndexer;
  VL53L0X_Dev_t* Devices;
  uint16_t* GPIODpins;
  uint8_t NumofDevices = 1;

/**
  * @brief  Memory allocation for VL53L0X_Dev_t structures and gpio pins
  *             @arg numofDevices:	Specifies the number of sensor devices
  */
void VL53L0X_InitHandlerClass(uint8_t numofDevices)
{
	NumofDevices = numofDevices;
	Devices = (VL53L0X_Dev_t*) calloc(NumofDevices + 1, sizeof(VL53L0X_Dev_t));
	DeviceIndexer = 0;
	GPIODpins = (uint16_t*) calloc(NumofDevices + 1, sizeof(uint16_t));
}

VL53L0X_Dev_t VL53L0X_GetDevice(uint8_t Indexer)
{
	return Devices[Indexer];
}

VL53L0X_Dev_t VL53L0X_GetLastDevice()
{
	return Devices[DeviceIndexer];
}

uint8_t VL53L0X_GetDeviceIndexer()
{
	return DeviceIndexer;
}

void VL53L0X_DefineAndPutDevice(uint16_t gpioDxshutpin, uint8_t type, uint8_t speed, uint8_t address)
{
	//DeviceIndexer++;
	VL53L0X_Dev_t device;
	device.comms_type      =  type;
	device.comms_speed_khz =  speed;
	device.I2cDevAddr = address;
	Devices[DeviceIndexer] = device;
	GPIODpins[DeviceIndexer] = gpioDxshutpin;
	DeviceIndexer++;
}

void VL53L0X_DeleteDevice()
{
	DeviceIndexer--;
}

void VL53L0X_APPStart(void) {
  //VL53L0X_Init();
}

void VL53L0X_APPStartCustomAddress(uint8_t Indexer) {
  /* initialization */
  VL53L0X_CustomAddressInit(&(Devices[Indexer]));
}

void VL53L0X_APPStartCustomLastAddress() {
  /* initialization */
  VL53L0X_CustomAddressInit(&(Devices[DeviceIndexer]));
}

void VL53L0X_ResetNodes()

{
	for(int i = 1; i < NumofDevices + 1; i++)
	{
	HAL_GPIO_WritePin(GPIOD,GPIODpins[i],GPIO_PIN_RESET);
	}
	HAL_Delay(100);
}

void VL53L0X_ActiveNodeAddress(uint8_t Indexer){
	//sTempMyDevice = GetDeviceDescriptor();

	uint8_t tempAddr = Devices[Indexer].I2cDevAddr;
	Devices[Indexer].I2cDevAddr = 0x52;

	HAL_GPIO_WritePin(GPIOD,GPIODpins[Indexer],GPIO_PIN_SET);
	HAL_Delay(500);

	VL53L0X_SetDeviceAddress(&(Devices[Indexer]), tempAddr);

	Devices[Indexer].I2cDevAddr = tempAddr;

	HAL_Delay(500);
}

void VL53L0X_ActiveLastNodeAddress(){
	//sTempMyDevice = GetDeviceDescriptor();

	uint8_t tempAddr = Devices[DeviceIndexer].I2cDevAddr;
	Devices[DeviceIndexer].I2cDevAddr = 0x52;

	HAL_GPIO_WritePin(GPIOD,GPIODpins[DeviceIndexer],GPIO_PIN_SET);
	HAL_Delay(100);

	VL53L0X_SetDeviceAddress(&(Devices[DeviceIndexer]), tempAddr);

	Devices[DeviceIndexer].I2cDevAddr = tempAddr;

	HAL_Delay(500);
}

uint16_t VL53L0X_NodeMeasure(uint8_t Indexer) {
	uint16_t meas = 0;
	VL53L0X_MeasureSingle(&meas,&(Devices[Indexer]));
	return meas;
}

uint16_t VL53L0X_LastNodeMeasure() {
	uint16_t meas = 0;
	VL53L0X_MeasureSingle(&meas,&(Devices[DeviceIndexer]));
	return meas;
}
