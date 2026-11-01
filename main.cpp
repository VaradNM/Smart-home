#include "SmartHome.h"
#include "SmartHomeController.h"

int main() {
    SmartHome smartHome;
    SmartHomeController controller(smartHome);
    controller.run();
    return 0;
}