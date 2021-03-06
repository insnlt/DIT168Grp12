[![Build Status](https://travis-ci.org/insnlt/DIT168Grp12.svg?branch=master)](https://travis-ci.org/insnlt/DIT168Grp12)

# DIT168 Industrial IT and Embedded Systems

# Miniature Smart Vehicle

`https://github.com/insnlt/DIT168Grp12`

## Introduction
In this project we will create a Smart Miniature Vehicle where the car will be able to drive autonomously.The vehicle should be able to drive autonomously while following another car. Also, the vehicle will be able to use vehicle to vehicle (V2V) technology. The car is equipped with sensors on the front, back and the sides. Project will be implemented using C/C++ languages and built upon [OpenDaVINCI](http://opendavinci.cse.chalmers.se/www/). The great amount of focus will be spent on delivering high quality standards.

## GitHub Layout
The team will develop the project by using Git's branching system in this project. Every team member will work on his individual branch. We will create a branch for each new feature (feature branches), once the feature is completed, it will be merged into the master branch. When the feature has been implemented, a pull request for merging the beta branch into the master branch will be made. The pull request has to be reviewed by other team members in order to get its approval and then only will it be pushed to the master branch.
## How to clone, build and test

### Cloning:
`$ git clone https://github.com/insnlt/DIT168Grp12.git`

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

## HOW TO PACKAGE AND RELEASE BINARIES OF THIS SOFTWARE

### Package:
We are using Docker for distributing and releasing binaries for the software. To build the project locally you must run this command:

`$ docker build -t dit168grp12.dit -f Dockerfile .`

### Saving as .tar and loading

`$ docker save dit > dit168grp12.dit.tar`

`$ cat dit168grp12.dit.tar | docker load`


### Pulling:
To run docker image you should run the following command:

`$ docker pull insnlt/dit168grp12`

## Demo:
`$ docker run --rm -ti --net=host insnlt/dit168grp12 /opt/dit.Sender`

`$ docker run --rm -ti --net=host insnlt/dit168grp12 /opt/dit.Receiver`

