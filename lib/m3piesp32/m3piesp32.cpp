#include <m3piesp32.h>

m3piesp32::m3piesp32(int res, int tx, int rx)
{
    this->tx = tx;
    this->rx = rx;
    this->leds.assign(8, 0);
    this->reset();
}
void m3piesp32::serial_init()
{
    Serial.begin(115200, RXD2, TXD2);
}
void m3piesp32::reset()
{
    digitalWrite(this->res, LOW);
    delay(10);
    digitalWrite(this->res, HIGH);
    delay(100);
}
void m3piesp32::motor(int motor, float speed)
{
    char opcode = 0x0;
    if (speed > 0.0)
    {
        if (motor == 1)
            opcode = M1_FORWARD;
        else
            opcode = M2_FORWARD;
    }
    else
    {
        if (motor == 1)
            opcode = M1_BACKWARD;
        else
            opcode = M2_BACKWARD;
    }
    unsigned char arg = 0x7f * abs(speed);
    Serial.write(opcode);
    Serial.write(arg);
}
void m3piesp32::left_motor(float speed)
{
    motor(0, speed);
}
void m3piesp32::right_motor(float speed)
{
    motor(1, speed);
}
void m3piesp32::forward(float speed)
{
    motor(0, speed);
    motor(1, speed);
}
void m3piesp32::backward(float speed)
{
    motor(0, -1.0 * speed);
    motor(1, -1.0 * speed);
}
void m3piesp32::left(float speed)
{
    motor(0, speed);
    motor(1, -1.0 * speed);
}
void m3piesp32::right(float speed)
{
    motor(1, speed);
    motor(0, -1.0 * speed);
}
void m3piesp32::stop(void)
{
    motor(0, 0.0);
    motor(1, 0.0);
}
float m3piesp32::line_postion()
{
    int pos;
    Serial.write(SEND_LINE_POSITION);
    pos = Serial.read();
    float fpos = ((float)pos - 2048.0) / 2048.0;
    return (fpos);
}
char m3piesp32::sensor_auto_calibrate()
{
    Serial.write(AUTO_CALIBRATE);
    return Serial.read();
}
void m3piesp32::calibrate()
{
    Serial.write(PI_CALIBRATE);
}
void m3piesp32::reset_calibration()
{
    Serial.write(LINE_SENSORS_RESET_CALIBRATION);
}