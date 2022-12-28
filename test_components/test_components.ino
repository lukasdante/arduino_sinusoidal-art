#define servo1 3
#define servo2 5
#define servo3 6
#define servo4 9
#define servo5 10
#define soundSensor A1

#include <Servo.h>

int isSound;

void sweep_servo(Servo servo);

void setup() {
    // put your setup code here, to run once:
    servo1.attach(servo1);
    servo2.attach(servo2);
    servo3.attach(servo3);
    servo4.attach(servo4);
    servo5.attach(servo5);

    pinMode(soundSensor, INPUT);

    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    sweep_servo(servo1);
    sweep_servo(servo2);
    sweep_servo(servo3);
    sweep_servo(servo4);
    sweep_servo(servo5);

    isSound = analogRead(soundSensor);
    Serial.print("Sound Intensity: ");
    Serial.println(isSound);
}


void sweep_servo(Servo servo) {
    servo.write(0);
    delay(200);

    for (int pos = 0; pos <= 180; pos += 1) {
        servo.write(pos);
        delay(15);
    }
}