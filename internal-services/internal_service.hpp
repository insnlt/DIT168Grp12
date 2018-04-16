#ifndef INTERNAL_SERVICE_H
#define INTERNAL_SERVICE_H

#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
#include "cluon/OD4Session.hpp"
#include "cluon/UDPSender.hpp"
#include "cluon/UDPReceiver.hpp"
#include "cluon/Envelope.hpp"
#include "Messages.hpp"
#include <iostream>

//CID
static const int CID = 230;
static const int V2VCID = 231;
static const int ANGLE = 1700;
static const int SPEED = 1701;
//static cons int DISTANCE = 1702;


class internal_service{
	public: 
		controllerService();
	private:
		std::shared_ptr<cluon::OD4Session> receivedMessage;
		std::shared_ptr<cluon::OD4Session> sendMessage;
};

#endif 
