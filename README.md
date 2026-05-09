# GraduationProject
### this drive contains all Pdfs and thoeritical parts during my learning journy to learn and work in software automotive industry.

https://drive.google.com/drive/folders/1hNOTLMytGaSwnOHS-EHMTefJDKPlLbzq

## ECU_One embedded stack
- Implemented full MCU software layers (MCAL, HAL, service, and application) under `ECU_One/`, including reusable drivers and application examples ready for AVR builds and Proteus simulations.
- Key directories: `0-MCAL&HAL_Drivers_` (low-level peripherals), `1-SERVICE_LAYER`, `2-APPs`, and `Proteus_Simulation`.

## ECU_One/Testing demos
Four small projects live in `ECU_One/Testing/` to verify the stack on hardware/simulation:
- `TestingOne`: Keypad input echoed to an LCD (4-bit mode), exercising keypad and LCD HAL drivers.
- `TestingTwo`: External interrupt on INT2 triggers an LED pulse, covering EXTI + GIE + DIO configuration.
- `TestingThree/MasterNode` and `SlaveNode`: I2C/TWI master sends incrementing bytes to a slave that mirrors data on PORTA LEDs, validating bus communication.
- `TestingFour/FourUltrasonicWithLcd`: Reads four ultrasonic sensors and displays live distances on an LCD using TIMER, ultrasonic, display abstractions.
