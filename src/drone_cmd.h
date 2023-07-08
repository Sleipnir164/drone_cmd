#pragma once

#include "drone_lib.h"
#include <unistd.h>

class Controller
{
public:
    Controller(Drone& target_drone, int init_dT) : drone(target_drone), dT(init_dT){}
    void SendDroneTo(Position target_pos);
    float ComputeDistance(Position A, Position B);

private:
    // \brief Drone linked to controller
    Drone& drone;
    // \brief Duration of a time step in ms
    int dT;

};