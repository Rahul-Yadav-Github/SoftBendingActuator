# Calibration Guide

Follow these steps to calibrate the flex sensor for accurate angle measurements.

## Steps

1. Upload the provided Arduino code to your board.
2. Open the Serial Monitor (Tools > Serial Monitor) and set the baud rate to 9600.
3. Bend the flex sensor to its minimum and maximum positions.
4. Note the minimum and maximum sensor values displayed in the Serial Monitor.
5. Adjust the `SENSOR_MIN` and `SENSOR_MAX` values in the Arduino code based on your observations.
6. Re-upload the adjusted code to the Arduino.

## Example

If the minimum value observed is 600 and the maximum value is 900, set:

```cpp
#define SENSOR_MIN 600
#define SENSOR_MAX 900
