# include "drone_cmd.h"

void Controller::SendDroneTo(Position target_pos)
{
    Velocity desired_vel;

    Position start_pos = drone.GetPos();
    desired_vel.dx = (target_pos.x - start_pos.x) / (10*dT/1000.);
    desired_vel.dy = (target_pos.y - start_pos.y) / (10*dT/1000.);
    desired_vel.dz = (target_pos.z - start_pos.z) / (10*dT/1000.);

    while (ComputeDistance(target_pos, drone.GetPos()) > 0.0001)
    {
        if (ComputeDistance(target_pos, drone.GetPos()) < ComputeDistance(target_pos, start_pos)/10)
        {
            Position cur_pos = drone.GetPos();
            desired_vel.dx = (target_pos.x - cur_pos.x) / (dT/1000.);
            desired_vel.dy = (target_pos.y - cur_pos.y) / (dT/1000.);
            desired_vel.dz = (target_pos.z - cur_pos.z) / (dT/1000.);
        }
        drone.SetSpeed(desired_vel);
        drone.UpdatePos(dT);
        usleep(dT*1000);
    }

    desired_vel.dx = 0;
    desired_vel.dy = 0;
    desired_vel.dz = 0;
    drone.SetSpeed(desired_vel);
}

float Controller::ComputeDistance(Position A, Position B)
{
    float dx = A.x - B.x;
    float dy = A.y - B.y;
    float dz = A.z - B.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}