/**
 *  Copyright 2020 Karan Sutradhar
 *  @file mover.cpp
 *  @author Karan Sutradhar
 *  @date 11/23/2020
 *
 *  @brief This is the mover.cpp file which implements the turtlebot3 mover pkg
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
