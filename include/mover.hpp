#pragma once
/**
 *  Copyright 2020 Karan Sutradhar
 *  @file mover.hpp
 *  @author Karan Sutradhar
 *  @date 11/23/2020
 *
 *  @section LICENSE
 *  
 * MIT License
 * Copyright (c) 2020 Karan Sutradhar
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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