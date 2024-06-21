#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <array>
#include <string>
#include <vector>
#include <iostream>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class Scanner{
    public:
        std::string ip;
        std::pair<int, int> ports;
    public:
        Scanner();
        Scanner(std::string, std::pair<int, int>);
        std::vector<int> scan();
        std::vector<int> scan(std::pair<int, int>);

        bool isPortOpen(int);

        // void set_start_port(int);
        // void set_start_port(int);
        // void set_ports(std::pair<int, int>);
};

#endif  // SCANNER_HPP
