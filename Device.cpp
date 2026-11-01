#include "Device.h"

#include <utility>

Device::Device(std::string name)
    : name_(std::move(name)), isOn_(false) {}

const std::string& Device::name() const noexcept {
    return name_;
}

bool Device::isOn() const noexcept {
    return isOn_;
}

void Device::turnOn() noexcept {
    isOn_ = true;
}

void Device::turnOff() noexcept {
    isOn_ = false;
}