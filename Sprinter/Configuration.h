#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// BASIC SETTINGS: select your board type, thermistor type, axis scaling, and endstop configuration

//// The following define selects which electronics board you have. Please choose the one that matches your setup
// MEGA/RAMPS up to 1.2  = 3,
// RAMPS 1.3/1.4 = 33
// Gen6 = 5, 
// Gen6 deluxe = 51
// Sanguinololu up to 1.1 = 6
// Sanguinololu 1.2 and above = 62
// Gen 7 @ 16MHZ only= 7
// Gen 7 @ 20MHZ only= 71
// Teensylu (at90usb) = 8
// Printrboard Rev. B (ATMEGA90USB1286) = 9
// Gen 3 Plus = 21
// gen 3  Monolithic Electronics = 22
// Gen3 PLUS for TechZone Gen3 Remix Motherboard = 23
#define MOTHERBOARD 33

//// Calibration variables
// X, Y, Z, E steps per unit
#define _AXIS_STEP_PER_UNIT {2560.0, 2560.0, 2560.0,990}

//// Endstop Settings
#define ENDSTOPPULLUPS // Comment this out (using // at the start of the line) to disable the endstop pullup resistors
// The pullups are needed if you directly connect a mechanical endswitch between the signal and ground pins.
//If your axes are only moving in one direction, make sure the endstops are connected properly.
//If your axes move in one direction ONLY when the endstops are triggered, set [XYZ]_ENDSTOP_INVERT to true here:
const bool X_ENDSTOP_INVERT = true;
const bool Y_ENDSTOP_INVERT = true;

// This determines the communication speed of the printer
#define BAUDRATE 115200
//#define BAUDRATE 250000

//-----------------------------------------------------------------------
//// STORE SETTINGS TO EEPROM
//-----------------------------------------------------------------------
// the microcontroller can store settings in the EEPROM
// M500 - stores paramters in EEPROM
// M501 - reads parameters from EEPROM (if you need reset them after you changed them temporarily).
// M502 - reverts to the default "factory settings". You still need to store them in EEPROM afterwards if you want to.
// M503 - Print settings
// define this to enable eeprom support
//#define USE_EEPROM_SETTINGS

// to disable EEPROM Serial responses and decrease program space by ~1000 byte: comment this out:
// please keep turned on if you can.
//#define PRINT_EEPROM_SETTING

//-----------------------------------------------------------------------
//// ARC Function (G2/G3 Command)
//-----------------------------------------------------------------------
//Uncomment to aktivate the arc (circle) function (G2/G3 Command)
//Without SD function an ARC function the used Flash is smaller 31 kb
#define USE_ARC_FUNCTION

//-----------------------------------------------------------------------
//// ADVANCED SETTINGS - to tweak parameters
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
//-----------------------------------------------------------------------
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define E_ENABLE_ON 0

//Uncomment if you have problems with a stepper driver enabeling too late, this will also set how many microseconds delay there will be after enabeling the driver
//#define DELAY_ENABLE 15

//-----------------------------------------------------------------------
// Disables axis when it's not being used.
//-----------------------------------------------------------------------
const bool DISABLE_X = false;
const bool DISABLE_Y = false;
const bool DISABLE_E = false;

//-----------------------------------------------------------------------
// Inverting axis direction
//-----------------------------------------------------------------------
const bool INVERT_X_DIR = false;
const bool INVERT_Y_DIR = false;
const bool INVERT_E_DIR = true;

//-----------------------------------------------------------------------
//// ENDSTOP SETTINGS:
//-----------------------------------------------------------------------
// Sets direction of endstops when homing; 1=MAX, -1=MIN
#define X_HOME_DIR -1
#define Y_HOME_DIR -1

//#define ENDSTOPS_ONLY_FOR_HOMING // If defined the endstops will only be used for homing

const bool min_software_endstops = false; //If true, axis won't move to coordinates less than zero.
const bool max_software_endstops = true; //If true, axis won't move to coordinates greater than the defined lengths below.


//-----------------------------------------------------------------------
//Max Length for Prusa Mendel, check the ways of your axis and set this Values
//-----------------------------------------------------------------------
const int X_MAX_LENGTH = 200;
const int Y_MAX_LENGTH = 200;

//-----------------------------------------------------------------------
//// MOVEMENT SETTINGS
//-----------------------------------------------------------------------
const int NUM_AXIS = 4; // The axis order in all axis related arrays is X, Y, Z, E
#define _MAX_FEEDRATE {6, 6, 6, 10}       // (mm/sec)
#define _HOMING_FEEDRATE {240, 240, 240}      // (mm/min) !!
#define _AXIS_RELATIVE_MODES {false, false, false, false}

#define MAX_STEP_FREQUENCY 30000 // Max step frequency

//For the retract (negative Extruder) move this maxiumum Limit of Feedrate is used
//The next positive Extruder move use also this Limit, 
//then for the next (second after retract) move the original Maximum (_MAX_FEEDRATE) Limit is used
#define MAX_RETRACT_FEEDRATE 100    //mm/sec

//-----------------------------------------------------------------------
//// Not used at the Moment
//-----------------------------------------------------------------------

// Min step delay in microseconds. If you are experiencing missing steps, try to raise the delay microseconds, but be aware this
// If you enable this, make sure STEP_DELAY_RATIO is disabled.
//#define STEP_DELAY_MICROS 1

// Step delay over interval ratio. If you are still experiencing missing steps, try to uncomment the following line, but be aware this
// If you enable this, make sure STEP_DELAY_MICROS is disabled. (except for Gen6: both need to be enabled.)
//#define STEP_DELAY_RATIO 0.25

///Oscillation reduction.  Forces x,y,or z axis to be stationary for ## ms before allowing axis to switch direcitons.  Alternative method to prevent skipping steps.  Uncomment the line below to activate.
// At this Version with Planner this Function ist not used
//#define RAPID_OSCILLATION_REDUCTION

#ifdef RAPID_OSCILLATION_REDUCTION
const long min_time_before_dir_change = 30; //milliseconds
#endif

//-----------------------------------------------------------------------
//// Acceleration settings
//-----------------------------------------------------------------------
// X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.
#define _ACCELERATION 1000         // Axis Normal acceleration mm/s^2
#define _RETRACT_ACCELERATION 2000 // Extruder Normal acceleration mm/s^2
#define _MAX_XY_JERK 0.4
#define _MAX_E_JERK 4.0    // (mm/sec)
//#define _MAX_START_SPEED_UNITS_PER_SECOND {25.0,25.0,0.2,10.0}
#define _MAX_ACCELERATION_UNITS_PER_SQ_SECOND {50.0, 50.0, 0.0, 0.0}    // X, Y, Z and E max acceleration in mm/s^2 for printing moves or retracts


// Minimum planner junction speed. Sets the default minimum speed the planner plans for at the end
// of the buffer and all stops. This should not be much greater than zero and should only be changed
// if unwanted behavior is observed on a user's machine when running at very slow speeds.
#define MINIMUM_PLANNER_SPEED 0.05 // (mm/sec)

#define DEFAULT_MINIMUMFEEDRATE       0.0     // minimum feedrate
#define DEFAULT_MINTRAVELFEEDRATE     0.0

#define _MIN_SEG_TIME 20000

// If defined the movements slow down when the look ahead buffer is only half full
#define SLOWDOWN


const int dropsegments=5; //everything with less than this number of steps will be ignored as move and joined with the next movement

//-----------------------------------------------------------------------
// Machine UUID
//-----------------------------------------------------------------------
// This may be useful if you have multiple machines and wish to identify them by using the M115 command. 
// By default we set it to zeros.
#define _DEF_CHAR_UUID "00000000-0000-0000-0000-000000000000"



//-----------------------------------------------------------------------
//// Planner buffer Size
//-----------------------------------------------------------------------

// The number of linear motions that can be in the plan at any give time
// if the SD Card need to much memory reduce the Values for Plannerpuffer (base of 2)
#define BLOCK_BUFFER_SIZE 16  
#define BLOCK_BUFFER_MASK 0x0f

//-----------------------------------------------------------------------
//// SETTINGS FOR ARC FUNCTION (Command G2/G2)
//-----------------------------------------------------------------------

// Arc interpretation settings:
//Step to split a cirrcle in small Lines 
#define MM_PER_ARC_SEGMENT 1
//After this count of steps a new SIN / COS caluclation is startet to correct the circle interpolation
#define N_ARC_CORRECTION 25

//#define CHAIN_OF_COMMAND 1 //Finish buffered moves before executing M42, fan speed, heater target, and so...

//-----------------------------------------------------------------------
// DEBUGING
//-----------------------------------------------------------------------


//Uncomment this to see on the host if a wrong or unknown Command is recived
//Only for Testing !!!
//#define SEND_WRONG_CMD_INFO

// Uncomment the following line to enable debugging. You can better control debugging below the following line
//#define DEBUG
#ifdef DEBUG
  //#define DEBUG_PREPARE_MOVE //Enable this to debug prepare_move() function
  //#define DEBUG_MOVE_TIME //Enable this to time each move and print the result   
  //#define DEBUG_HEAT_MGMT //Enable this to debug heat management. WARNING, this will cause axes to jitter!
  //#define DEBUG_DISABLE_CHECK_DURING_TRAVEL //Debug the namesake feature, see above in this file
#endif

#endif
