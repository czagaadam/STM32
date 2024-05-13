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

![100mm](https://github.com/czagaadam/STM32/assets/168843740/2eba928f-78ab-4e58-be31-9b9c07f98bc7)

![IMG_0072](https://github.com/czagaadam/STM32/assets/168843740/5c2a87a3-c5ef-45e6-a6a6-5fc3b9e00b8f)

![150mm](https://github.com/czagaadam/STM32/assets/168843740/fd41ed41-9938-4734-a040-4792f8d8fe12)

![IMG_0069](https://github.com/czagaadam/STM32/assets/168843740/919a9447-70a3-4417-9c50-c2b23b6716e7)

More sensors and CAN bus are coming soon...
