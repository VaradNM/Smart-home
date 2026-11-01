#include "SmartHomeController.h"

#include "Fan.h"
#include "Light.h"

#include <iostream>
#include <memory>
#include <stdexcept>

SmartHomeController::SmartHomeController(SmartHome& smartHome)
    : smartHome_(smartHome) {}

void SmartHomeController::run() {
    std::cout << "Smart Room controller started.\n";

    while (true) {
        std::cout << "\n1. Add room\n2. Add device\n3. Remove device\n"
                  << "4. Control device\n5. Control room\n6. View status\n7. Exit\n";

        switch (readMenuChoice()) {
        case 1: addRoom(); break;
        case 2: addDevice(); break;
        case 3: removeDevice(); break;
        case 4: controlDevice(); break;
        case 5: controlRoom(); break;
        case 6: displayStatus(); break;
        case 7:
            std::cout << "Goodbye.\n";
            return;
        default:
            std::cout << "Choose a number from 1 to 7.\n";
        }
    }
}

std::string SmartHomeController::readLine(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int SmartHomeController::readMenuChoice(const std::string& prompt) {
    try {
        return std::stoi(readLine(prompt));
    } catch (const std::exception&) {
        return -1;
    }
}

void SmartHomeController::addRoom() {
    const std::string roomName = readLine("Room name: ");
    std::cout << (smartHome_.addRoom(roomName)
        ? "Room added.\n"
        : "Room names must be non-empty and unique.\n");
}

void SmartHomeController::addDevice() {
    Room* room = smartHome_.findRoom(readLine("Room name: "));
    if (room == nullptr) {
        std::cout << "Room not found.\n";
        return;
    }

    const int kind = readMenuChoice("Device type (1 Fan, 2 Light): ");
    const std::string name = readLine("Device name: ");
    std::unique_ptr<Device> device;

    if (kind == 1) {
        device = std::make_unique<Fan>(name);
    } else if (kind == 2) {
        device = std::make_unique<Light>(name);
    } else {
        std::cout << "Choose 1 for Fan or 2 for Light.\n";
        return;
    }

    std::cout << ((name.empty() || !room->addDevice(std::move(device)))
        ? "Device names must be non-empty and unique within a room.\n"
        : "Device added.\n");
}

void SmartHomeController::removeDevice() {
    Room* room = smartHome_.findRoom(readLine("Room name: "));
    if (room == nullptr) {
        std::cout << "Room not found.\n";
        return;
    }

    std::cout << (room->removeDevice(readLine("Device name: "))
        ? "Device removed.\n"
        : "Device not found.\n");
}

void SmartHomeController::controlDevice() {
    Room* room = smartHome_.findRoom(readLine("Room name: "));
    if (room == nullptr) {
        std::cout << "Room not found.\n";
        return;
    }

    Device* device = room->findDevice(readLine("Device name: "));
    if (device == nullptr) {
        std::cout << "Device not found.\n";
        return;
    }

    const int action = readMenuChoice("Action (1 On, 2 Off, 3 Setting): ");
    if (action == 1) {
        device->turnOn();
    } else if (action == 2) {
        device->turnOff();
    } else if (action == 3) {
        if (Fan* fan = dynamic_cast<Fan*>(device)) {
            std::cout << (fan->setSpeed(readMenuChoice("Speed (0-5): "))
                ? "Fan speed updated.\n" : "Speed must be between 0 and 5.\n");
        } else if (Light* light = dynamic_cast<Light*>(device)) {
            std::cout << (light->setBrightness(readMenuChoice("Brightness (0-100): "))
                ? "Brightness updated.\n" : "Brightness must be between 0 and 100.\n");
        }
    } else {
        std::cout << "Invalid action.\n";
        return;
    }

    std::cout << device->status() << '\n';
}

void SmartHomeController::controlRoom() {
    Room* room = smartHome_.findRoom(readLine("Room name: "));
    if (room == nullptr) {
        std::cout << "Room not found.\n";
        return;
    }

    const int action = readMenuChoice("Action (1 All on, 2 All off): ");
    if (action == 1) {
        room->turnAllOn();
        std::cout << "All devices turned on.\n";
    } else if (action == 2) {
        room->turnAllOff();
        std::cout << "All devices turned off.\n";
    } else {
        std::cout << "Invalid action.\n";
    }
}

void SmartHomeController::displayStatus() const {
    const auto names = smartHome_.roomNames();
    if (names.empty()) {
        std::cout << "No rooms have been added.\n";
        return;
    }

    for (const auto& name : names) {
        const Room* room = smartHome_.findRoom(name);
        std::cout << '\n' << room->name() << ":\n";
        for (const auto& status : room->deviceStatuses()) {
            std::cout << "  - " << status << '\n';
        }
    }
}