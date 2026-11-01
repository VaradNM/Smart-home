#include "Room.h"

#include <algorithm>
#include <utility>

Room::Room(std::string name)
    : name_(std::move(name)) {}

const std::string& Room::name() const noexcept {
    return name_;
}

bool Room::addDevice(std::unique_ptr<Device> device) {
    if (!device || findDevice(device->name()) != nullptr) {
        return false;
    }

    devices_.push_back(std::move(device));
    return true;
}

bool Room::removeDevice(const std::string& deviceName) {
    const auto device = std::find_if(devices_.begin(), devices_.end(),
        [&deviceName](const std::unique_ptr<Device>& candidate) {
            return candidate->name() == deviceName;
        });

    if (device == devices_.end()) {
        return false;
    }

    devices_.erase(device);
    return true;
}

Device* Room::findDevice(const std::string& deviceName) noexcept {
    for (const auto& device : devices_) {
        if (device->name() == deviceName) {
            return device.get();
        }
    }
    return nullptr;
}

const Device* Room::findDevice(const std::string& deviceName) const noexcept {
    for (const auto& device : devices_) {
        if (device->name() == deviceName) {
            return device.get();
        }
    }
    return nullptr;
}

void Room::turnAllOn() noexcept {
    for (const auto& device : devices_) {
        device->turnOn();
    }
}

void Room::turnAllOff() noexcept {
    for (const auto& device : devices_) {
        device->turnOff();
    }
}

std::vector<std::string> Room::deviceStatuses() const {
    std::vector<std::string> statuses;
    statuses.reserve(devices_.size());

    for (const auto& device : devices_) {
        statuses.push_back(device->status());
    }
    return statuses;
}