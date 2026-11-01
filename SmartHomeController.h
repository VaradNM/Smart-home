#ifndef SMART_HOME_CONTROLLER_H
#define SMART_HOME_CONTROLLER_H

#include "SmartHome.h"

#include <string>

class SmartHomeController {
public:
    explicit SmartHomeController(SmartHome& smartHome);
    void run();

private:
    SmartHome& smartHome_;

    static std::string readLine(const std::string& prompt);
    static int readMenuChoice(const std::string& prompt = "Choice: ");
    void addRoom();
    void addDevice();
    void removeDevice();
    void controlDevice();
    void controlRoom();
    void displayStatus() const;
};

#endif