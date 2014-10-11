# Mylasercutter project

![](https://github.com/int-0/mylasercutter/raw/master/cnc_view.png)

This project is a CNC machine similar to reprap 3D printers. Hardware is
designed by me using FreeCAD and software is a fork of other existing
projects: [Sprinter](https://github.com/kliment/Sprinter) and [Pronterface](https://github.com/kliment/Printrun).

## How to build hardware

To make this CNC machine you need a 3D printer (or service) to print some
hardware parts. Other parts are rods, threaded rods, screws, nuts, linear
bearings. The most expensive hardware is all electronic stuff plus stepper
motors. You can buy some "Prusa kit" to get main board, Ramps and so on.
My prototype has been tested with XdrDuino (a 100% compatible Arduino board),
Ramps 1.4 and two stepper drivers.

Couplers have been made in aluminum but a plastic-printed couplers are valid
too.

For step-by-step manual you can check manual/ folder for more info.

## How to compile firmware

This Sprinter software can be made using Arduino IDE: just load Sprinter.ino
and click on "load" button. You can modify "Configuration.h" to setup CNC
sizes or if you need to tunning some parts like endstops, directions, and so on.

## How to check/run

You can test your CNC with Pronterface tool. Connect like a normal 3D printer
but uses only X/Y axis to move. Also you can send M52/M53 command to
enable/disable laser. This program cannot be used to print a gcode file because
it parses gcodes and fails with single-layer prints (or at least it doen't work
for me). In order to send gcode file in a "raw" mode, I write another
command-line tool in software/ folder based in Pronterface core. Just run:

```
$ ./send_cnc <gcode_file>
```

And that's all.

## Future work

The head of this CNC can be completed with some M3 nuts. This can be used
to design others tools like drills, etc. But firmware needs to be improvement
to allow Z movements.

## Known problems

Firmware fails with high feed rates (speed), so F>200 causes blocks
on stepper motors. Make sure that your gcodes don't have higher feed rates.


Please feel free to contribute and enjoy!
