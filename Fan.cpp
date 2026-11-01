#include "Fan.h"

#include <sstream>

Fan::Fan(const std::string& name)
    : Device(name), speed_(kMinimumSpeed) {}

bool Fan::setSpeed(int speed) noexcept {
    if (speed < kMinimumSpeed || speed > kMaximumSpeed) {
        return false;
    }

    speed_ = speed;
    return true;
}

int Fan::speed() const noexcept {
    return speed_;
}

std::string Fan::type() const {
    return "Fan";
}

std::string Fan::status() const {
    std::ostringstream output;
    output << type() << " \"" << name() << "\": "
           << (isOn() ? "On" : "Off")
           << ", speed " << speed_;
    return output.str();
}