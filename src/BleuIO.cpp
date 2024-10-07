#include "BleuIO.h"
#include <iostream>

BleuIO::BleuIO(const std::string &port_name) : port_name(port_name) {
    if (!init()) {
        std::cerr << "Failed to initialize port." << std::endl;
    }
}

BleuIO::~BleuIO() {
    close();
}

bool BleuIO::init() {
    if (sp_get_port_by_name(port_name.c_str(), &port) != SP_OK) {
        std::cerr << "Cannot find the port!" << std::endl;
        return false;
    }
    if (sp_open(port, SP_MODE_READ_WRITE) != SP_OK) {
        std::cerr << "Cannot open the port!" << std::endl;
        return false;
    }
    sp_set_baudrate(port, 115200);
    return true;
}

void BleuIO::close() {
    sp_close(port);
    sp_free_port(port);
}

std::string BleuIO::send_command(const std::string &command) {
    std::string response;
    std::string command_with_newline = command + "\r\n";
    sp_blocking_write(port, command_with_newline.c_str(), command_with_newline.length(), 1000);

    char buffer[1024];
    int bytes_read = sp_blocking_read(port, buffer, sizeof(buffer) - 1, 3000);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        response = std::string(buffer);
    } else {
        response = "No response or timeout.";
    }
    return response;
}
