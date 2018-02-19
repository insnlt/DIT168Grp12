#include "Reciever.hpp"

void Reciever::recieveMsg() {

   cluon::OD4Session od4(111,
        [](cluon::data::Envelope &&envelope) noexcept {
       
          MyTestMessage1 receivedMsg = cluon::extractMessage<MyTestMessage1>(std::move(envelope));
          std::cout << "Recieved message: "<<receivedMsg.myValue() << "\n" << std::endl;
        
    });
}
