# STM32

Welcome to STM32 wiki!

Currently I'm interfacing sensor devices to STM32F429I-Discovery board and transmit sensor data via CAN bus.

Here is the datasheet of the first sensor,
it is a VL53L0X TOF Time-of-Flight laser-ranging module.
https://www.pololu.com/product/2490
The core library is the property of STM, I made some small modification to be able to compile with my setup:
https://github.com/czagaadam/STM32/tree/main/vl53l0x/Src/vl53l0x

I made a high level library to easily initialize the sensor via I2C.
https://github.com/czagaadam/STM32/tree/main/vl53l0x/Src

Here is an example how to use the library (currently works with only one sensor, there are some kind of issues with re-addressing devices):
https://github.com/czagaadam/STM32/tree/main/LaserTest

And some measurements:

Target at 100mm
![100mm](https://github.com/czagaadam/STM32/assets/168843740/36243a61-04c1-4131-a16a-59fc5396802d)

Target at 150mm
![150mm](https://github.com/czagaadam/STM32/assets/168843740/fd8d53da-a2aa-41cd-96bb-7fc0bbbc6c27)

I2C message(starts with 0x14) when target at 100mm
![100mm_analyzer](https://github.com/czagaadam/STM32/assets/168843740/af197f4a-13b5-45e3-b0f0-7abbeb04ade0)


More sensors and CAN bus are coming soon...
