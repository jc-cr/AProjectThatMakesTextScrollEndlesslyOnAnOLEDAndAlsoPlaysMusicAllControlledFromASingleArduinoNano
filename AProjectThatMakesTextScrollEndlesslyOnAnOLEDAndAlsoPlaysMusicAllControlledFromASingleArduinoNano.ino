#include <Adafruit_BusIO_Register.h>

// Create an I2C object.
Adafruit_I2CDevice i2cDevice = Adafruit_I2CDevice(address, &Wire);

void setup() {
  // Initialize the I2C bus.
  Wire.begin();

  // Try to initialize the I2C device.
  if (!i2cDevice.begin()) {
    Serial.println("Failed to initialize device!");
    while (1);
  }
}

void loop() {
  // Create a buffer for the data.
  uint8_t buffer[2] = {register, value};

  // Create a register object.
  Adafruit_I2CRegister reg = Adafruit_I2CRegister(&i2cDevice, buffer, 2, false);

  // Write the data to the register.
  reg.write(value);
}
