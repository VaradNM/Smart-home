#include "Light.h"

#include <sstream>

Light::Light(const std::string& name)
    : Device(name), brightness_(kMaximumBrightness) {}

bool Light::setBrightness(int brightness) noexcept {
    if (brightness < kMinimumBrightness || brightness > kMaximumBrightness) {
        return false;
    }

    brightness_ = brightness;
    return true;
}

int Light::brightness() const noexcept {
    return brightness_;
}

std::string Light::type() const {
    return "Light";
}

std::string Light::status() const {
    std::ostringstream output;
    output << type() << " \"" << name() << "\": "
           << (isOn() ? "On" : "Off")
           << ", brightness " << brightness_ << '%';
    return output.str();
}