#include <Arduino.h>
#include <vector>

#define SEND_SIGNATURE 0x81
#define SEND_RAW_SENSOR_VALUES 0x86
// #define SEND_TRIMPOT 0xB0
// #define SEND_BATTERY_MILLIVOLTS 0xB1
#define DO_PLAY 0xB3
#define PI_CALIBRATE 0xB4
// #define DO_CLEAR 0xB7
// #define DO_PRINT 0xB8
// #define DO_LCD_GOTO_XY 0xB9
#define LINE_SENSORS_RESET_CALIBRATION 0xB5
#define SEND_LINE_POSITION 0xB6
#define AUTO_CALIBRATE 0xBA
#define SET_PID 0xBB
#define STOP_PID 0xBC
#define M1_FORWARD 0xC1
#define M1_BACKWARD 0xC2
#define M2_FORWARD 0xC5
#define M2_BACKWARD 0xC6
#define RXD2 16
#define TXD2 17

class m3piesp32
{
private:
    int res;
    int tx;
    int rx;
    std::vector<int> leds;
    void motor(int motor, float speed);
    // virtual int _putc(int c);
    // virtual int _getc();

public:
    m3piesp32(int res, int tx, int rx);
    void reset();
    void serial_init();
    void left_motor(float speed);
    void right_motor(float speed);
    void forward(float speed);
    void backward(float speed);
    void left(float speed);
    void right(float speed);
    void stop();
    float line_postion();
    void calibrate();
    char sensor_auto_calibrate();
    void reset_calibration();
    // void PID_start(int max_speed, int a, int b, int c, int d);
    // void PID_stop();
    // void leds(int val);
    // void play(char *what, int length);
    // void locate(int x, int y);
    // void cls(void);
    // int putc(int c);
    // int getc();
    // int print(char *text, int length);
};