#include "BleuIO.h"
#include <iostream>

int main() {
    BleuIO dongle("/dev/cu.usbmodem4048FDE52CF21");  // Change to your port
    std::string response = dongle.send_command("AT+CENTRAL"); // central role
    response = dongle.send_command("AT+GAPSCAN=1"); //scan 1 second
    std::cout << "Scan Response:\n" << response << std::endl;

    if (response.find("SCANNING") != std::string::npos) {
        std::cout << "Test Passed: Device scan started successfully." << std::endl;
    } else {
        std::cerr << "Test Failed: Device scan did not start." << std::endl;
    }
    return 0;
}
