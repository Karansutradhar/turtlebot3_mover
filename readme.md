# Turtlebot3 Mover Package
[![License:MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/Karansutradhar/turtlebot3_mover/blob/Week12_HW/LICENSE)

## Author

Karan Sutradhar

## Overview

Thsi ROS package implements a simple object avoidance algorrithm gor the turtlebot3. It moves around the gazebo world to with the helkp of sensor attached to it it avoids obstacles. It normallay moves ahead and detects obstacles to turn at 1.25 radians. It moves around the world without stopping.

## License

Standard MIT License Clause

## Dependencies

- Creation and implemenation of this ROS package was on ROS Melodic Ubuntu 18.04 (Linux) and Gazebo 9.0.0 version.
- Catkin is used for building this package.
- Follow the C++ 11 standard style of coding.
- A standard turtlebot3 pkg needs to be installed in order to run this project.

## Installation link for turtlebot3 package:

The instructions to install the standard turtlebot3 ROS package can be found [here](https://automaticaddison.com/how-to-launch-the-turtlebot3-simulation-with-ros/).

## Steps to run this package
Open terminal and follow this:
```
cd << your catkin_ws/src >>
git clone https://github.com/Karansutradhar/turtlebot3_mover.git
cd ..
catkin_make
source ~/catkin_ws/devel/setup.bash
roscore
```
Open second terminal and follow the code
```
roslaunch turtlebot3_mover turtlebot3_mover.launch
```
### Instructions for recording ROSbag

Navigate to the launch folder in the package
Open the turtlebot3_mover.launch file and change the arg value of record to "true". 

### Instructions for running ROSbag file
In terminal one
```
roscore
```
In terminal two
```
cd catkin_ws/src/turtlebot3_mover/results
rosbag play turtlebot3_mover.bag

```

### Instructions for Inspection of ROSbag file
In terminal 1
```
cd catkin_ws/src/turtlebot3_mover/results
rosbag info turtlebot3_mover.bag

```

## Cpplint check
```
cd  <path to repository>
cpplint $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" )

```

## Cppcheck check
```
cd <path to repository>
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )

```
