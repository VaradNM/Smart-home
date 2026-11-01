#ifndef ROOM_H
#define ROOM_H

#include "Device.h"

#include <memory>
#include <string>
#include <vector>

class Room {
public:
    explicit Room(std::string name);

    const std::string& name() const noexcept;
    bool addDevice(std::unique_ptr<Device> device);
    bool removeDevice(const std::string& deviceName);
    Device* findDevice(const std::string& deviceName) noexcept;
    const Device* findDevice(const std::string& deviceName) const noexcept;

    void turnAllOn() noexcept;
    void turnAllOff() noexcept;
    std::vector<std::string> deviceStatuses() const;

private:
    std::string name_;
    std::vector<std::unique_ptr<Device>> devices_;
};

#endif