#include <lpc214x.h>


// Delay function
void delay(unsigned int time)
{
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 6000; j++);
}


int main()
{
    // Configure P0.0 as input (soil moisture sensor)
    // Configure P0.1 as output (relay / motor)
    IO0DIR = 0x00000002;   // P0.1 output, P0.0 input


    while(1)
    {
        // Check soil moisture sensor
        if((IO0PIN & 0x00000001) == 0)
        {
            // Soil is dry → turn ON motor
            IO0SET = 0x00000002;
        }
        else
        {
            // Soil has enough moisture → turn OFF motor
            IO0CLR = 0x00000002;
        }


        delay(100);
    }
}
