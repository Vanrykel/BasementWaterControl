# Basement Water Control

![Overview](./resources/Overview.png)

## About the project

The basement is consistently flooded with groundwater. To address this issue, a hole has been made in the floor to collect the water, which is then pumped out using a submersible pump. However, due to the shallow depth of the hole, the pump's float switch cannot function effectively. To address this issue, an Arduino is used to detect when the hole in the floor is filled with water. Upon detection, the Arduino will activate a relay to power the submersible pump. The float switch of the pump will be fixed to ensure continuous operation.

**Sequence of operation**

1. Position two loose wires at the upper detection level.

1. Connect the submersible pump to the outlet linked to the relay.
2. Plug in the USB cable of the Arduino.
3. The Arduino awaits water detection (short-circuit pins from step 1).
4. Upon continuous water detection for more than 5 seconds (debounce), activate relay
5. The pump is activated for 10 seconds.

## Materials and methods

- Kärcher SP 9 Flat
- Arduino
- Jumper wires
- Relay board TC-9072472
- Extension cable
- 1 Core Electrical Cable, 0.75 mm

## Results

Different configurations were tested. It all started with a time-based design, but a DIY sensor was quickly added to the project. The DIY sensor was nothing more than two wires running to the detection level of the water hole. One wire was connected to ground and the other to a digital input. The digital input was pulled up to 5V with an external resistor to prevent floating values. Next, I researched using internal pull-up resistors on the Arduino with success. When extending the sensing wires with Wago clamps and 1.5mm wire, the detection of water was not always guaranteed.

Replacing the wires with smaller diameter ones was not an option because the resistance would increase from input to ground. Lowering the pull-up resistor was considered because the internal resistance of the Arduino Uno seems to be 20k-50k ohms. Unfortunately, this did not succeed. Next, the Wago clamps were removed because they could also add to the resistance from input to ground. Therefore, two 0.75mm wires were used so they could be plugged directly into the Arduino Uno. This resulted in great success. Unfortunately, switching the Arduino from laptop power to USB adapter power seemed to have a negative effect on the detection process. Up to four different USB adapters were tested, and only one passed the test. We assume that the ground reference was the issue here.

> ### Special notice !
> Check the USB power supply

## Getting started

Nothing as frustrating if you find a nice repo and nice code but have no idea how to get this thing started

- [ ] Place a step-by-step plan (an how-to) here. 
- [ ] Explain how to run the program
- [ ] use step-by-step bullets if needed
- [ ] place remarks such as #defines which needs to be uncommented if some special (hardware-)case is being used.

```c
//#define AREA_CIR

...
    
#if !defined(AREA_CIR)
    bSwitch = TRUE;
	nCount = 50;
#endif
````

If the project consist of different component, references can be made to the different folder of each component which contains a more detailed getting started e.g. [see the TwinCAT Solution](./TwinCAT).



## Future work and issues

An example for Future work is the connectivity between the PLC and Indradrive, the PLC can get data from a phone but still needs to controll the linear slider by sending commands to the Indradrive. An other example is that the PLC gets the orientation and angle acceleration values from the phone using the [App](https://github.com/PXLDigital/2EAI-POZ-PEN-2122-Pendulum/tree/main/SolutionBosch/APP), but the app still has a [problem](https://github.com/PXLDigital/2EAI-POZ-PEN-2122-Pendulum/tree/main/SolutionBosch/APP#polariteit-angle-probleem) and this needs to be fixed. The parameters on twinCAT for the IndraDrive need to be researched.  

Another future project is to control the Indradrive with a phone without the use of a PLC. [more info here](https://github.com/PXLDigital/2EAI-POZ-PEN-2122-Pendulum/blob/main/SolutionBosch/PhoneNoPLC.md)

A PSOC 6 can also be used to replace the phone app.

An issue in the future is the homing on the base of current limitation. There is an option for this called Positive stop.



## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated. 

Check out our [contributing page](.github/contributing.md) for how to add issues, features and make pull requests.

## People

- **Dieter Vanrykel** - _OWNER_ - [Dieter Vanrykel](https://github.com/Vanrykel)
