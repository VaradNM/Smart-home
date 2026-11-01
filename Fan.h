#ifndef FAN_H
#define FAN_H

#include "Device.h"

class Fan final : public Device {
public:
    explicit Fan(const std::string& name);

    bool setSpeed(int speed) noexcept;
    int speed() const noexcept;

    std::string type() const override;
    std::string status() const override;

private:
    static constexpr int kMinimumSpeed = 0;
    static constexpr int kMaximumSpeed = 5;
    int speed_;
};

#endif