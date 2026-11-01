#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

class Light final : public Device {
public:
    explicit Light(const std::string& name);

    bool setBrightness(int brightness) noexcept;
    int brightness() const noexcept;

    std::string type() const override;
    std::string status() const override;

private:
    static constexpr int kMinimumBrightness = 0;
    static constexpr int kMaximumBrightness = 100;
    int brightness_;
};

#endif