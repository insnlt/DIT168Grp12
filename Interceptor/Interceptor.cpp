/*
* This module was developed by Group-13 and the code was modified according to our needs.
*/
#include <cstdint>
#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>
#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "messages.hpp"


int main() {
  std::cout << "Interceptor online" << std::endl;
  std::cout << "Receiving at CID of 232, sending to 230, sensor connected to 231" << std::endl;
   
	cluon::OD4Session movement{230};
	float steer;
	float speed;
 	float minDistance=0.1;
	float velocity = 0;
	opendlv::proxy::PedalPositionReading carSpeed;
	opendlv::proxy::GroundSteeringReading carSteering;
  float sensor;

  // An OD4 session for getting sensor readings 
  cluon::OD4Session sensorValues(231,[&sensor](cluon::data::Envelope &&envelope) noexcept {
          
        if (envelope.dataType() == opendlv::proxy::DistanceReading::ID()) {
            opendlv::proxy::DistanceReading receivedMsg = cluon::extractMessage<opendlv::proxy::DistanceReading>(std::move(envelope));
            std::cout << "Sensor reading: " << receivedMsg.distance() << "." << std::endl;
            sensor = (receivedMsg.distance());
        }
    });

  while(1){
        // An OD4 session for getting Car steering angle and speed values
        cluon::OD4Session controller(232,[&steer,&speed](cluon::data::Envelope &&envelope) noexcept {
        // Getting messages from V2V or PS4
        if (envelope.dataType() == opendlv::proxy::GroundSteeringReading::ID()) {
            opendlv::proxy::GroundSteeringReading receivedMsg = cluon::extractMessage<opendlv::proxy::GroundSteeringReading>(std::move(envelope));
            std::cout << "Sent a message for ground steering to " << receivedMsg.steeringAngle() << "." << std::endl;
		        steer=receivedMsg.steeringAngle();
            }
        else if (envelope.dataType() == opendlv::proxy::PedalPositionReading::ID()) {
            opendlv::proxy::PedalPositionReading receivedMsg = cluon::extractMessage<opendlv::proxy::PedalPositionReading>(std::move(envelope));
            std::cout << "Sent a message for pedal position to " << receivedMsg.percent() << "." << std::endl;
            speed=receivedMsg.percent();
            
            if(speed > 0.16){
              speed=0.17;
            }
        }
    });

  // If the sensors detects an object while moving, we change the speed to zero
    if ((sensor < minDistance) && (speed > velocity)){
        carSpeed.percent(0);
        movement.send(carSpeed);
        carSteering.steeringAngle(steer);
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        movement.send(carSteering);
    } else {
        carSpeed.percent(speed);
        movement.send(carSpeed);
        carSteering.steeringAngle(steer);
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        movement.send(carSteering);
        }
    }

    return 0;
}