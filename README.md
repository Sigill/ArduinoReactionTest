# Arduino - Reaction Tester

This sketch will measure you reaction time to a visual signal.

Connect:

* a [96x96 OLED display](http://www.seeedstudio.com/wiki/index.php?title=Grove_-_OLED_Display_96*96), connected to any I2C port (make sure to install the LCD_Display library).
* a [button](http://www.seeedstudio.com/wiki/Grove_-_Button) (or any digital input component) to the D2 port.
* a [led](http://www.seeedstudio.com/wiki/Grove_-_LED) (or any digital output component) to the D3 port.

Press the button as soon as the the led turns on to measure your reaction time. It will be averaged over 8 tries.

## License

This source code is released under the terms of the MIT License. See the LICENSE.txt file for more details.