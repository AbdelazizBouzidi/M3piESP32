#include <m3piesp32.h>
m3piesp32 m3pi(4, 32, 33);
int cpt = 0;
void setup()
{
  m3pi.serial_init();
}

void loop()
{
  if (cpt < 3)
  {
    m3pi.forward(0.5);
    delay(500);
    m3pi.left(0.5);
    delay(500);
    m3pi.right(0.5);
    delay(500);
    // m3pi.stop();
  }
}