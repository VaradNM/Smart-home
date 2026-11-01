#ifndef SMART_HOME_H
#define SMART_HOME_H

#include "Room.h"

#include <memory>
#include <string>
#include <vector>

class SmartHome {
public:
    bool addRoom(const std::string& roomName);
    Room* findRoom(const std::string& roomName) noexcept;
    const Room* findRoom(const std::string& roomName) const noexcept;
    std::vector<std::string> roomNames() const;

private:
    std::vector<std::unique_ptr<Room>> rooms_;
};

#endif