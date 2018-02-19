#include "Sender.hpp"

void Sender::msg() {

    cluon::OD4Session od4(111,
        [](cluon::data::Envelope &&envelope) noexcept {});

    uint16_t value;
    std::cout << "We are in sender............ \n";
    std::cout << "Enter a number as a command: \n";
    std::cin >> value;
    MyTestMessage1 msg;
    msg.myValue(value);

    od4.send(msg);
}
