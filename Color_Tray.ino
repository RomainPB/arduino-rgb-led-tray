#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

void setup() {
  //Serial.begin(9600);
  pwm2.begin();
  pwm2.setPWMFreq(100);  // Analog servos run at ~60 Hz updates
  pwm.begin();
  pwm.setPWMFreq(100);  // Analog servos run at ~60 Hz updates
}

void loop() {

  int min_v = 0;
  int max_v = 2048;
  int vit = 16;
  int i;
  uint16_t l;
  const int color[] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1};

  for (i = 0; i < 22; i = i + 3) {

    for (l = min_v; l < max_v + 1; l += vit) {
      for (uint8_t rgb = 0; rgb < 17; rgb += 3) {
        if (color[i] == 0) {
          pwm.setPWM(rgb, 0, 0);
          pwm2.setPWM(rgb, 0, 0);
        }
        if (color[i] == 1) {
          pwm.setPWM(rgb, 0, l);
          pwm2.setPWM(rgb, 0, l);
        }
        if (color[i + 1] == 0) {
          pwm.setPWM(rgb + 1, 0, 0);
          pwm2.setPWM(rgb + 1, 0, 0);
        }
        if (color[i + 1] == 1) {
          pwm.setPWM(rgb + 1, 0, l);
          pwm2.setPWM(rgb + 1, 0, l);
        }
        if (color[i + 2] == 0) {
          pwm.setPWM(rgb + 2, 0, 0);
          pwm2.setPWM(rgb + 2, 0, 0);
        }
        if (color[i + 2] == 1) {
          pwm.setPWM(rgb + 2, 0, l);
          pwm2.setPWM(rgb + 2, 0, l);
        }
      }
    }

    for (l = max_v; l > min_v; l -= vit) {
      for (uint8_t rgb = 0; rgb < 17; rgb += 3) {
        if (color[i] == 0) {
          pwm.setPWM(rgb, 0, 0);
          pwm2.setPWM(rgb, 0, 0);
        }
        if (color[i] == 1) {
          pwm.setPWM(rgb, 0, l);
          pwm2.setPWM(rgb, 0, l);
        }
        if (color[i + 1] == 0) {
          pwm.setPWM(rgb + 1, 0, 0);
          pwm2.setPWM(rgb + 1, 0, 0);
        }
        if (color[i + 1] == 1) {
          pwm.setPWM(rgb + 1, 0, l);
          pwm2.setPWM(rgb + 1, 0, l);
        }
        if (color[i + 2] == 0) {
          pwm.setPWM(rgb + 2, 0, 0);
          pwm2.setPWM(rgb + 2, 0, 0);
        }
        if (color[i + 2] == 1) {
          pwm.setPWM(rgb + 2, 0, l);
          pwm2.setPWM(rgb + 2, 0, l);
        }
      }
    }

  }

}
