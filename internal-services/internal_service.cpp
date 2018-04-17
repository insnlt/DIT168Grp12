#include "internal_service.hpp"
#include "V2VService.hpp"

int main() {
	
}

internal_service::controllerService(){

	sendMessage = std::make_shared<cluon::OD4Session>(V2VCID,[this](cluon::data::Envelope && envelope) noexpect {
	std::cout << "OD4 Session" << std::endl;

	switch(envelope.dataType()){
		case ANGLE: {
			steeringAngle steer = cluon::extractMessage<steeringAngle>(std::move(envelope));
			std::cout<< "Angle: " << steer.steeringAngle() << std::endl;
			opendlv::proxy::GroundSteeringReading msgSteering;
			msgSteering.steeringAngle(steer.steeringAngle());
			receivedMessage->send(msgSteering);
			std::cout << "SENT ANGLE TO OUR CAR " << steer.steeringAngle() << std::endl;
			sendMessage->send(steer);
			std::cout << "SENDING ANGLE TO FOLLOWING CAR" << steer.steeringAngle() <<std::endl;
			break;
		}
		case SPEED: {
			Speed sp = cluon::extractMessage<Speed>(std::move(envelope));
			std::cout << "Speed : " << sp.speed() << std::endl;
			opendlv::proxy::PedalPositionReading msgPedal;
			msgPedal.speed(sp.speed());
			receivedMessage->send(msgPedal);
			std::cout << "SENT SPEED TO OUR CAR " << sp.speed() <<std::endl;
			sendMessage->send(sp);
			std::cout << "SENDING SPEED TO FOLLOWING CAR" << msgPedal.speed() << std::endl;
			break;			
		}
		default: std::cout << "FAULTY CASE IN SEND" << envelope.dataType() << std::endl;
	}
	
}); 

	receivedMessage = std::make_shared<cluon::OD4Session>(CID,[this](cluon::data::Envelope && envelope) noexpect {
	switch(envelope.dataType()){
		case RECEIVED_SPEED: {
		Speed sp = cluon::extractMessage<Speed>(std::move(envelope));
		std::cout<< "Recieved Speed from Leader :" << sp.speed() << std::endl;
		break;
		}
		case RECEIVED_ANGLE: {
		steeringAngle angle = cluon::extractMessage<steeringAngle>(std::move(envelope));
		std::cout<< "Recieved Angle from Leader :" << angle.steeringAngle() << std::endl;
		break;		
		}
		default: std::cout<< "FAULTY CASE IN RECEIVED" << envelope.dataType() <<std::endl;

	}
}); 


