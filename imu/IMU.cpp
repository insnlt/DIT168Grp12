#include <chrono>
#include "cluon/OD4Session.hpp"
#include <stdint.h>
#include <iostream>
#include "cluon/Envelope.hpp"
#include "messages.hpp"
#include <math.h>

extern "C"
{
#include <rc_usefulincludes.h>
#include <roboticscape.h>
}

int main() {
	//auto previousTime = std::chrono::steady_clock::now();
	//auto currentTime = std::chrono::steady_clock::now();
	//auto elapsed = previousTime - currentTime;
    uint8_t distanceTraveled = 0;
	float initial_speed = 0.0;
	float distance = 0; 
	float speed = 0;
	float time = 5;
	float sample = 0.01;
	   	
	readIMU msg;

    	rc_imu_data_t data;
     	
    	// Instantiate a OD4Session object
    	cluon::OD4Session od4(230,[](cluon::data::Envelope &&envelope) noexcept {
                              if (envelope.dataType() == 5000) {
                                  readIMU readmsg = cluon::extractMessage<readIMU>(std::move(envelope));
				 // std::cout << "message" << readmsg.readDistance() << std::endl;
                              }
                          });

    	//terminate in case no OD4 session running
    	if(od4.isRunning() == 0)
    	{
        	std::cout << "ERROR: No od4 running!!!" << std::endl;       	
		return -1;
    	}

    	// initialize hardware first
    	if(rc_initialize()){
        	std::cout << "ERROR: failed to run rc_initialize(), are you root?\n"<< std::endl;
        	return -1;
    	}
	
	rc_imu_config_t conf = rc_default_imu_config();
    	
	if(rc_initialize_imu(&data, conf)){
        	std::cout << "rc_initialize_imu_failed\n"<< std::endl;
        	return -1;
    	}
	
	while (od4.isRunning()) {

        	while (rc_get_state() != EXITING) {
			
			if(rc_read_accel_data(&data)<0){
			std::cout << "read failed" << std::endl;
			}
			//std::cout <<"time" << std::chrono::duration_cast<std::chrono::microseconds>(previousTime - currentTime).count() << std::endl;
        		float x_accel = data.accel[1];
        		float y_accel = data.accel[2];
			//std::cout << "X" << y_accel << std::endl;
			float accel = pow(x_accel,2)+pow(y_accel,2);
			accel = sqrt(accel);
			std::cout << "accel" << accel <<std::endl;
			initial_speed = speed;
			float vel = (accel * time);
			//std::cout << "velocity" << vel << std::endl;
			speed = (vel - initial_speed);
			speed = abs(speed);
			//std::cout << "speed " << speed << std::endl;
			distance += ( speed * time)+((accel * pow(time,2)) /2);
			msg.readDistance(distance);
			//std::cout << "distance " << distance << std::endl;
			od4.send(msg);
        	}

    	}

    	rc_power_off_imu();
    	// exit cleanly
    	rc_cleanup();
    	return 0;
}
