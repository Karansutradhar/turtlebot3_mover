/**
 *  Copyright 2020 Karan Sutradhar
 *  @file mover.cpp
 *  @author Karan Sutradhar
 *  @date 11/23/2020
 *
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
 * @brief This is the mover.cpp file which implements the turtlebot3 mover pkg
 *
 *
 */

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include "geometry_msgs/Twist.h"
#include "mover.hpp"

void gm::Mover::laserCallback(const sensor_msgs::LaserScan::ConstPtr& data) {
    distance = data->ranges[180];
    ROS_INFO_STREAM("Distance: " << distance);
}

gm::Mover::Mover(ros::NodeHandle node) {
    // LaserScan for ROS subscriber
    ros::Subscriber laserSubscriber = node.subscribe("/scan", 1000, &Mover::laserCallback, this);

    // velocity topic on ROS publisher
    ros::Publisher velocityPublisher = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);

    // the looprate is 4hz
    ros::Rate rate(4);

    while (ros::ok()) {
        // Defining twist msgs
        geometry_msgs::Twist twist;
        // Initialize all the values to zeros
        twist.linear.x = 0.0;
        twist.linear.y = 0.0;
        twist.linear.z = 0.0;
        twist.angular.x = 0.0;
        twist.angular.y = 0.0;
        twist.angular.z = 0.0;

        if (distance > 0.45) {
            ROS_INFO_STREAM("Moving ahead ...");
            twist.linear.x = -0.12;
        } else {
            ROS_INFO_STREAM("Turing path ...");
            twist.angular.z = 1.25;
        }

        velocityPublisher.publish(twist);
        ros::spinOnce();
        rate.sleep();
    }
}
