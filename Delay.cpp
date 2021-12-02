//
// Created by Brandon Castro on 11/29/21.
//

#include "Delay.h"

void Delay::delay(long long value) {

    std::this_thread::sleep_for(std::chrono::milliseconds(value));
}
