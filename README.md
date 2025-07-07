# STM32




# 🎯 Sensor Integration via CAN Bus
I'm currently working on integrating sensor devices with the STM32F429I-Discovery board and transmitting the collected data over the CAN bus.

📏 Sensor – VL53L0X Time-of-Flight Module

The first integrated sensor is the VL53L0X, a Time-of-Flight laser-ranging module.
📄 VL53L0X Datasheet – [Pololu #2490](https://www.pololu.com/product/2490)

The core library, originally provided by STMicroelectronics, has been slightly modified to compile with my current STM32 setup.
🔗 [View core source](https://github.com/czagaadam/STM32/tree/main/vl53l0x/Src/vl53l0x)

On top of that, I’ve implemented a high-level library to simplify initialization and communication over I2C:
🔗 [High-level abstraction layer](https://github.com/czagaadam/STM32/tree/main/vl53l0x/Src)

⚙️ Example Usage

Here is a basic example demonstrating how to use the library (currently tested with a single sensor only — readdressing multiple devices is still under investigation):
🔗 [LaserTest Example](https://github.com/czagaadam/STM32/tree/main/LaserTest)

📊 Sample Measurements
Target at 100mm → stable reading around 100mm
![100mm](https://github.com/czagaadam/STM32/assets/168843740/36243a61-04c1-4131-a16a-59fc5396802d)
Target at 150mm → consistent 150mm response
![150mm](https://github.com/czagaadam/STM32/assets/168843740/fd8d53da-a2aa-41cd-96bb-7fc0bbbc6c27)
I2C capture → message starts with 0x14 for 100mm distance

![100mm_analyzer](https://github.com/czagaadam/STM32/assets/168843740/af197f4a-13b5-45e3-b0f0-7abbeb04ade0)

# 🛠️ Support for multiple VL53L0X sensors with I2C re-addressing

CAN bus integration using the MCP2551 transceiver

Real-time sensor data transmission over CAN

🚀 Work-in-progress CAN test project:
🔗 [LaserTestWithCAN](https://github.com/czagaadam/STM32/tree/main/LaserTestWithCAN)
![transfer_laster_measurement](https://github.com/czagaadam/STM32/assets/168843740/7d8cb43b-8d6a-434d-9049-f515deecc511)



Currently I'm interfacing sensor devices to STM32F429I-Discovery board and transmit sensor data via CAN bus.

Here is the datasheet of the first sensor,
it is a VL53L0X TOF Time-of-Flight laser-ranging module.

The core library is the property of STM, I made some small modification to be able to compile with my setup.


I made a high level library to easily initialize the sensor via I2C.


Here is an example how to use the library (currently works with only one sensor, there are some kind of issues with re-addressing devices):


And some measurements:

Target at 100mm


Target at 150mm


I2C message(starts with 0x14) when target at 100mm



More sensors and CAN bus are coming soon...

Interfacing MCP2551 CAN transceiver and sending VL53 I2C sensor data via CAN bus.
https://github.com/czagaadam/STM32/tree/main/LaserTestWithCAN


