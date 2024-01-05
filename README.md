# ROS-Exploration-with-RPIB

## Purpose
THis repository was created as a place to store ongoing experiements with ROS2 Humble on an RPi 4B.

## Short Intro and First Steps
ROS stands for Robot Operating System and is a "middleware" which high level communication between different machines.
It is most commonly used in robotics because of the various library packages and privledges it allows the "master". 
ROS is organized through a listener-subscriber systeem where one machine, or "node", can subscibe to a particular "topic" which is 
in the form of a data package. To do this both the master and the nodes need to be on the same network.

The first part of this project was to set up ROS on two machines. The first is the RPi 4B which was done by flashing a microSD with Ubuntu 22.04.
I then set up a virtual machine running Ubuntu 22.04 on my computer and installed ROS2 Humble. 
