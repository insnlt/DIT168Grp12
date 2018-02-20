# DIT168 Industrial IT and Embedded Systems

# Miniature Smart Vehicle

https://github.com/insnlt/DIT168Grp12

## Introduction
In this project we will create a Smart Miniature Vehicle where the car will be able to drive autonomously.The vehicle should be able to drive autonomously while following a lane , pass other vehicles and park. Also, the vehicle will be able to use vehicle to vehicle (V2V) technology. The car is equipped with sensors on the front, back and the sides, we will also use a camera for tracking the markings of the road. Project will be implemented using C/C++ languages and built upon [OpenDaVINCI](http://opendavinci.cse.chalmers.se/www/). The great amount of focus will be spent on testing and delivering high quality standards.

## GitHub Layout
The team will develop the project by using Git's branching system in this project. Every team member will work on his individual branch. We will create a branch for each new feature (feature branches), once the feature is completed, it will be merged into the beta branch. There shall be no direct pushes to the master branch. When the feature has been implemented, a pull request for merging the beta branch into the master branch will be made. The pull request has to be reviewed by other team members in order to get its approval and then only will it be pushed to the master branch. The team will push the changes to the appropriate branch, and once the feature is ready to be tested, it will be pushed to the beta branch. When the beta branch is deemed to work properly, it will be merged to the master branch and assigned a version number.
## How to clone, build and test

### Cloning:
$ git clone https://github.com/insnlt/DIT168Grp12.git

### Building:
Go into the project folder, launch the terminal and enter the commands below.

```
$ mkdir build && cd build

$ cmake ..

$ make
```
### Test:
Go inside build>src, launch the terminal and enter the commands below.

$ `./dit.Sender`

Open another terminal:

$ `./dit.Receiver`
