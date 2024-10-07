#ifndef BLEUIO_H
#define BLEUIO_H

#include <string>
#include <libserialport.h>

class BleuIO {
private:
    sp_port *port;
    std::string port_name;
    bool init();
    void close();

public:
    BleuIO(const std::string &port_name);
    ~BleuIO();
    std::string send_command(const std::string &command);
};

#endif // BLEUIO_H
