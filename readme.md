# LED Control using LDR and ADC on ATmega32

This project demonstrates controlling 8 LEDs using a Light-Dependent Resistor (LDR) and an Analog-to-Digital Converter (ADC) on an ATmega32 microcontroller. The LEDs can be further controlled using external interrupts (INT0 and INT1) triggered by buttons.

## Table of Contents
- [Introduction](#introduction)
- [Components Used](#components-used)
- [How to Use](#how-to-use)
- [External Interrupts](#external-interrupts)
- [ADC Usage](#adc-usage)
- [Drivers Used](#drivers-used)

## Introduction

This project utilizes an ATmega32 microcontroller to control 8 LEDs based on the light intensity measured by an LDR. When it's dark, all LEDs turn on, and when there's light, all LEDs turn off. The system also responds to external interrupts, lighting half of the LEDs in response to specific triggers.

## Components Used

- ATmega32 Microcontroller
- Light-Dependent Resistor (LDR)
- LEDs (8)
- Resistors
- Push Buttons (2)

## How to Use

- Depending on the light intensity, the LEDs will turn on or off accordingly.
- Press the buttons connected to external interrupts (INT0 and INT1) to trigger specific LED patterns.

## External Interrupts

- **Interrupt 0 (INT0)**: Pressing a button connected to INT0 triggers the `LedLeft` function, lighting the left half of the LEDs.

- **Interrupt 1 (INT1)**: Pressing a button connected to INT1 triggers the `LedRight` function, lighting the right half of the LEDs.

## ADC Usage

The Analog-to-Digital Converter (ADC) reads the light intensity from the LDR. If the ADC value is below 180, indicating low light (dark), all LEDs are turned on. If the ADC value is above 180, indicating high light, all LEDs are turned off.

## Drivers Used

- **ADC Driver (MCAL)**: This driver handles the initialization and interaction with the Analog-to-Digital Converter (ADC) on the ATmega32 microcontroller.

- **DIO Driver (MCAL)**: The Digital Input/Output (DIO) driver manages the configuration and manipulation of digital pins on the ATmega32 microcontroller.

- **External Interrupt Driver (MCAL)**: This driver enables and manages external interrupts (INT0 and INT1) used in this project for triggering LED patterns.

- **General Interrupt Enable Driver (MCAL)**: This driver manages the general interrupt enable functionality for the microcontroller.
