#include "main.h"
int autonpreset = 0;
void TAP()
{
    while(true){
        if(slave.get_digital_new_press(DIGITAL_RIGHT))
        {
            autonpreset = autonpreset + 1;
        }
        if(slave.get_digital_new_press(DIGITAL_LEFT))
        {
            autonpreset = autonpreset - 1;
        }
        if (!(autonpreset % 25)) {
      // Only print every 50ms, the controller text update rate is slow
      slave.print(0, 0, "preset: %d", autonpreset);
    }
    autonpreset++;
    pros::delay(10);
}
}