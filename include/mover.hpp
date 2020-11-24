#pragma once
/**
 *  Copyright 2020 Karan Sutradhar
 *  @file mover.hpp
 *  @author Karan Sutradhar
 *  @date 11/23/2020
 *
 *  @brief Mover class which makes the robot move in the world
 *  Header file for Robot Mover Class 
 *
 */

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>

namespace gm {
/**
 * @brief Mover class
 * **/
class Mover {
 private:
    /**
     * @brief stores distance data from obstacle (in meters)
     * **/
    double distance;
 public:
    /**
     * @brief Mover class constructor
     * @param node ROS Nodehandle
     * **/
    explicit Mover(ros::NodeHandle node);
    
    /**
     * @brief Laserscan subscriber callback
     * @param planar laser range finder to scan single data
     * **/
    void laserCallback(const sensor_msgs::LaserScan::ConstPtr& data);
};
} // namespace gm