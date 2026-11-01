# Smart Room Automation

A small C++ console application that models a multi-room smart home. It is intentionally scoped to demonstrate practical object-oriented design without requiring a GUI, database, or network service.

## Features

- Add rooms and add or remove fans and lights from each room
- Turn individual devices on or off
- Set fan speed from 0 to 5 and light brightness from 0 to 100
- Turn every device in a room on or off
- View the current state of every room and device

## Design

`SmartHome` owns `Room` objects, and each `Room` owns its `Device` objects through `std::unique_ptr`. `Device` is an abstract base class; `Fan` and `Light` supply their device-specific status and controls. `SmartHomeController` handles console input and delegates domain work to the model.

## Build and run

Requires CMake 3.14+ and a compiler with C++14 support.

```powershell
cmake -S . -B build
cmake --build build
.\build\SmartRoom.exe
```

## Architecture

```text
Console user -> SmartHomeController -> SmartHome -> Room -> Device
                                                        -> Fan
                                                        -> Light
```