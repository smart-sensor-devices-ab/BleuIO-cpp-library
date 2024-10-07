#include <iostream>
#include "BleuIO.h"

int main() {
    BleuIO dongle("/dev/cu.usbmodem4048FDE52CF21");  // Change to the correct port on your system
    // put the dongle into central role
    std::string response = dongle.send_command("AT+CENTRAL");

    // Example: Scan for nearby BLE devices
    response = dongle.send_command("AT+GAPSCAN=3");
    std::cout << "Response:\n" << response << std::endl;

    return 0;
}
