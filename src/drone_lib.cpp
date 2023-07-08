#include "drone_lib.h"

float Velocity::norm()
{
    return sqrt(dx*dx + dy*dy + dz*dz);
}

Position Drone::GetPos()
{
    return pos;
}

void Drone::SetSpeed(Velocity input_vel)
{
    if (input_vel.norm() <= max_vel)
        vel = input_vel;
    else
    {
        vel.dx = input_vel.dx / input_vel.norm() * max_vel;
        vel.dy = input_vel.dy / input_vel.norm() * max_vel;
        vel.dz = input_vel.dz / input_vel.norm() * max_vel;
    }
}

void Drone::UpdatePos(int dT)
{
    pos.x += vel.dx * dT / 1000;
    pos.y += vel.dy * dT / 1000;
    pos.z += vel.dz * dT / 1000;
    std::cout << "Position: [" << pos.x << ", " << pos.y << ", " << pos.z << "]" << std::endl;
}

bool Drone::isStatic()
{
    if (vel.norm() == 0)
        return true;
    else
        return false;
}