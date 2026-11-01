#include "SmartHome.h"

bool SmartHome::addRoom(const std::string& roomName) {
    if (roomName.empty() || findRoom(roomName) != nullptr) {
        return false;
    }

    rooms_.push_back(std::make_unique<Room>(roomName));
    return true;
}

Room* SmartHome::findRoom(const std::string& roomName) noexcept {
    for (const auto& room : rooms_) {
        if (room->name() == roomName) {
            return room.get();
        }
    }
    return nullptr;
}

const Room* SmartHome::findRoom(const std::string& roomName) const noexcept {
    for (const auto& room : rooms_) {
        if (room->name() == roomName) {
            return room.get();
        }
    }
    return nullptr;
}

std::vector<std::string> SmartHome::roomNames() const {
    std::vector<std::string> names;
    names.reserve(rooms_.size());

    for (const auto& room : rooms_) {
        names.push_back(room->name());
    }
    return names;
}