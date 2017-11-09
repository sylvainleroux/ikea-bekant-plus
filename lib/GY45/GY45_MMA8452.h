#include <arduino.h>
#include <Wire.h>

#define MMA8452_ADDRESS 0x1C

// Define some MMA8452 registers
#define OUT_X_MSB 0x01
#define XYZ_DATA_CFG  0x0E
#define WHO_AM_I   0x0D
#define CTRL_REG1  0x2A

#define GSCALE 2 // Sets full-scale range to +/-2, 4, or 8g. Used to calc real g values.

// Initialize the MMA8452 registers
// See the many application notes for more info on setting all of these registers:
// http://www.freescale.com/webapp/sps/site/prod_summary.jsp?code=MMA8452Q
void initMMA8452();

void readAccelData(int* destination);

// Sets the MMA8452 to standby mode. It must be in standby to change most register settings
void MMA8452Standby();

// Sets the MMA8452 to active mode. Needs to be in this mode to output data
void MMA8452Active();

// Read bytesToRead sequentially, starting at addressToRead into the dest byte array
void readRegisters(byte addressToRead, int bytesToRead, byte * dest);

// Read a single byte from addressToRead and return it as a byte
byte readRegister(byte addressToRead);

// Writes a single byte (dataToWrite) into addressToWrite
void writeRegister(byte addressToWrite, byte dataToWrite);
