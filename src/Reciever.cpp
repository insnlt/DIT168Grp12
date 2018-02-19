#include <cstdint>
#include <chrono>
#include <iostream>
#include <string>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "Reciever.hpp"
#include "messages.hpp"

int main(int /*argc*/, char** /*argv*/) {

   cluon::OD4Session od4(111,
        [](cluon::data::Envelope &&envelope) noexcept {
       
          MyTestMessage1 receivedMsg = cluon::extractMessage<MyTestMessage1>(std::move(envelope));
          std::cout << "Recieved message: "<<receivedMsg.myValue() << "\n" << std::endl;
        
    });

 using namespace std::literals::chrono_literals;
    while (od4.isRunning()) {
        std::this_thread::sleep_for(1s);
}
}
