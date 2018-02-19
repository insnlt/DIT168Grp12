#include <cstdint>
#include <chrono>
#include <iostream>
#include <string>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "Sender.hpp"
#include "messages.hpp"

int main(int /*argc*/, char** /*argv*/) {

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
