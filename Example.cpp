#include <cstdint>
#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>
#include <string>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"

#include "messages.hpp"

char stringInput;
bool quit = false;

int main(int /*argc*/, char** /*argv*/) {
	// creates od4 - 111 and receives data 
    cluon::OD4Session od4(222,[](cluon::data::Envelope &&envelope) noexcept {
        if (envelope.dataType() == opendlv::proxy::GroundSteeringReading::ID()) {
            opendlv::proxy::GroundSteeringReading receivedMsg = cluon::extractMessage<opendlv::proxy::GroundSteeringReading>(std::move(envelope));
            std::cout << "Sent a message for ground steering to " << receivedMsg.steeringAngle() << "." << std::endl;
        }
        else if (envelope.dataType() == opendlv::proxy::PedalPositionReading::ID()) {
            opendlv::proxy::PedalPositionReading receivedMsg = cluon::extractMessage<opendlv::proxy::PedalPositionReading>(std::move(envelope));
            std::cout << "Sent a message for pedal position to " << receivedMsg.percent() << "." << std::endl;
        }
    });

    if(od4.isRunning() == 0)
    {
        std::cout << "ERROR: No od4 running!!!" << std::endl;
        return -1;
    }

    std::cout << "Hello World again!" << std::endl;

    opendlv::proxy::GroundSteeringReading msgSteering;
    opendlv::proxy::PedalPositionReading msgPedal;
	const int delay = 1000;

	while(!quit){
	std::cout << "Press WSADR" << std::endl;
	std::cin >> stringInput;
	switch(stringInput){
		case 'W':
		msgPedal.percent(0.4);
		od4.send(msgPedal);
		break;
		case 'S':
		msgPedal.percent(-0.4);
		od4.send(msgPedal);
		break;
		case 'A':
		msgSteering.steeringAngle(15.0);
		od4.send(msgSteering);
		break;
		case 'D':
		msgSteering.steeringAngle(-15.0);
		od4.send(msgSteering);
		break;
		case 'R':
		msgPedal.percent(0.0);
		od4.send(msgPedal);
		msgSteering.steeringAngle(0.0);
		od4.send(msgSteering);
		break;
		case 'Q':
		quit = true;
		break;
		default:
		std::cout<< "Wrong Input!" << std::endl;
	}
}

   // const int delay = 1000;
/*
    std::cout << "Now move forward ..." << std::endl;
    msgSteering.steeringAngle(0.0);
    od4.send(msgSteering);
    msgPedal.percent(0.4);
    od4.send(msgPedal);
    std::this_thread::sleep_for(std::chrono::milliseconds(2 * delay));

    std::cout << "Now turn left a little bit ..." << std::endl;
    msgPedal.percent(0.2);
    od4.send(msgPedal);
    msgSteering.steeringAngle(-15.0);
    od4.send(msgSteering);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    std::cout << "Now turn right a little bit ..." << std::endl;
    msgSteering.steeringAngle(15.0);
    od4.send(msgSteering);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    std::cout << "Now move forward again..." << std::endl;
    msgSteering.steeringAngle(0.0);
    od4.send(msgSteering);
    msgPedal.percent(0.4);
    od4.send(msgPedal);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    std::cout << "Now Stop ..." << std::endl;
    msgPedal.percent(0.0);
    od4.send(msgPedal);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
*/

    return 0;
}


