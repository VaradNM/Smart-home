#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
public:
    explicit Device(std::string name);
    virtual ~Device() = default;

    const std::string& name() const noexcept;
    bool isOn() const noexcept;
    void turnOn() noexcept;
    void turnOff() noexcept;

    virtual std::string type() const = 0;
    virtual std::string status() const = 0;

private:
    std::string name_;
    bool isOn_;
};

#endif