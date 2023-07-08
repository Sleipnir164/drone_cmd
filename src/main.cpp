#include "drone_cmd.h"
#include <string>

int main(int argc, char * argv[])
{
    if (argc != 6)
    {
        std::cout << "Write the commad as \n$ ./run-cmd <init_pos_x> <init_pos_y> <init_pos_z> <max_vel> <time_step>" << std::endl;
        return(-1);
    }

    Position init_pos; 
    init_pos.x = std::stof(argv[1]);
    init_pos.y = std::stof(argv[2]);
    init_pos.z = std::stof(argv[3]);
    float max_vel = std::stof(argv[4]);
    int dT = std::stoi(argv[5]);

    bool start = true;

    Drone drone(init_pos, max_vel);
    Controller controller(drone, dT);

    while(true)
    {
        if (drone.isStatic())
        {
            Position target_pos;
            if (!start)
            {
                char answer;
                std::cout << "Drone is still, would you like to stop ? y/n: ";
                std::cin >> answer;
                if (answer == 'y')
                    return(0);
            }
            std::cout << "Then please input a target position.\nX: ";
            std::cin >> target_pos.x;
            std::cout << "Y: ";
            std::cin >> target_pos.y;
            std::cout << "Z: ";
            std::cin >> target_pos.z;
            std::cout << "Sending drone to [" << target_pos.x << ", " << target_pos.y << ", " << target_pos.z << "]" << std::endl;

            controller.SendDroneTo(target_pos);
            start = false;
        }
    }
}