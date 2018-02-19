#ifndef RECIEVER
#define RECIEVER

#include <cstdint>
#include <chrono>
#include <iostream>
#include <sstream>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "messages.hpp"

class Reciever{
	public:void recieveMsg();
};

#endif
