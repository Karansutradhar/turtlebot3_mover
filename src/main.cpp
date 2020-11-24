/**
 *  Copyright 2020 Karan Sutradhar
 *  @file main.cpp
 *  @author Karan Sutradhar
 *  @date 11/23/2020
 *
 * @brief The main.cpp file for turtlebot3 mover project
/**
 * @brief main function of the program.
 * @param None.
 * @return 0.
 */

#include <ros/ros.h>
#include "../include/mover.hpp"

int main(int argc, char** argv) {
    ros::init(argc, argv, "mover");
    ros::NodeHandle node;
    gm::Mover mover(node);
}