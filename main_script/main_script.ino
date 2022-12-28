#define servo1 3
#define servo2 5
#define servo3 6
#define servo4 9
#define servo5 10
#define soundSensor A1

#include <Servo.h>

const int DIFF = 10;
const int SERVO_DEG = 90;

int leftRange, rightRange, speed;

int amplitude;

void oscillate(int amplitude, Servo servo[5]);
int hear();

void setup() {
    servo1.attach(servo1);
    servo2.attach(servo2);
    servo3.attach(servo3);
    servo4.attach(servo4);
    servo5.attach(servo5);

    pinMode(soundSensor, INPUT);

    Serial.begin(9600);
}

void loop() {
    amplitude = hear();
    oscillate(amplitude, servo1, speed);
    delay(DIFF);
    oscillate(amplitude, servo2, speed);
    delay(DIFF);
    oscillate(amplitude, servo3, speed);
    delay(DIFF);
    oscillate(amplitude, servo4, speed);
    delay(DIFF);
    oscillate(amplitude, servo5, speed);
    delay(DIFF);
}

int hear() {
    amplitude = analogRead(soundSensor);
    amplitude = map(0, 90, amplitude, 1023);
    return amplitude;
}

void oscillate(int amplitude, Servo servo, int interval) {
    leftRange = SERVO_DEG - amplitude;
    rightRange = SERVO_DEG + amplitude;
    for (int i = 0; i < 5; i++) {
        for (int pos = leftRange; pos < rightRange; pos++) {
            servo.write(pos);
            delay(interval);
        }
    }
    // check if millis() should be used for delays
}