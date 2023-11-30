# Line Follower Bot



## Overview

Welcome to the Line Follower Bot project! This repository contains the source code and documentation for a robot that follows a line on the ground using analog sensors.

![Line Follower Bot](https://github.com/MrHobbist/Line-follower-1.0/blob/main/IMG_20231130_214423691_BURST000_COVER~2.jpg)
[](https://github.com/MrHobbist/Line-follower-1.0/blob/main/IMG_20231130_214330069~2.jpg)
## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Circuit Diagram](#circuitdiagram)
- [Usage](#usage)
- [Configuration](#configuration)


## Features

- **Line Following:** The bot is designed to autonomously follow a line on the ground using infrared sensors.
- **PID Control:** Proportional-Integral-Derivative control ensures smooth and precise line tracking.
- **Modular Design:** Easily customizable and extendable for different robot configurations.
- **Sensor Calibration:** The bot allows for sensor calibration to adapt to various line colors and surface conditions.

## Requirements

- Hardware requirements (e.g., microcontroller, motor drivers, sensors, resistors, button)
- Software requirements (e.g., Arduino IDE)
- caster wheel
- battery
- jumper wires

## Installation

1. Clone this repository:

    ```
    git clone https://github.com/your-username/line-follower-bot.git
    cd line-follower-bot
    ```

2. Install dependencies:

    install SparkFUN TB6612FNG Motor Driver Library

3. Upload the code to your microcontroller.

## Circuit Diagram

## Usage

- After uploading the code press the calibiration button. During caliberation the bot will read the minimum and maximum values(please keep the bot such that the sensor passes through black and white surface). During caliberation bot will be rotating clockwise.
- After the caliberation is done press the actual run button. This will make the bot follow the line.

## Configuration

- To increase or decrease the speed change the lfspeed value(0 to 255).
- To follow certain patterns add or remove conditions.
- AnalogPins are from A1 to A7.
- Caliberation button is D11 by default (please remember to change this according to your setup).
- Actual run button is D12 by default (please remember to change this according to your setup).
---
