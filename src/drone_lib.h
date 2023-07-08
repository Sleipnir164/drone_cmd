#pragma once

#include <stdlib.h>
#include <vector>
#include <cmath>

#include <iostream>

class Position
{
public:
    float x;
    float y;
    float z;
};

class Velocity
{
public:
    Velocity()
    {
        dx = .0;
        dy = .0;
        dz = .0;
    }
    float dx;
    float dy;
    float dz;
    float norm();
};

class Drone
{
public:
    Drone(Position init_pos, float init_max_vel) : pos(init_pos), max_vel(init_max_vel){}
    // \brief Returns the current position of the drone
    Position GetPos();
    // \brief Update the speed of the drone
    // \param input_vel Desired velocity
    void SetSpeed(Velocity input_vel);
    // \brief Update the position of the drone by one timestep
    // \param dT Elapsed time
    void UpdatePos(int dT);
    bool isStatic();

private:
    // \brief Position of the object in cartesian coordinates
    Position pos;
    // \brief Velocity of the object in cartesian coordinates
    Velocity vel;
    // \brief Maximum velocity of the object
    float max_vel;
};