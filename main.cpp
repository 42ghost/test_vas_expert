#include <iostream>
#include <string>
#include <regex>

#include "scanner.hpp"

int main(int argc, const char* argv[]){
    if (argc != 4){
        std::cout << "incorrect number of arguments" << std::endl;
        exit(1);
    }

    std::string ip;
    int start_p, end_p;

    std::regex ip_regex(R"(^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)");
    if (std::regex_match(argv[1], ip_regex)) {
        ip = argv[1];
    } else {
        std::cout << "incorrect ip" << std::endl;
        exit(1);
    }

    try {
        start_p = atoi(argv[2]);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "incorrect start port" << std::endl;
    }
    
    try {
        end_p = atoi(argv[3]);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "incorrect end port" << std::endl;
    }

    if (!(start_p >= 0 && start_p <= 65535 && end_p >= 0 && end_p <= 65535)){
        std::cout << "incorrect port range" << std::endl;
        exit(1);
    }

    Scanner scanner(ip, {start_p, end_p});
    std::cout << scanner.ip << '\n';
    std::cout << scanner.ports.first << ' ' << scanner.ports.second << '\n';

    std::vector<int> open_ports = scanner.scan();
    for(auto i : open_ports) {
        std::cout << i << '\n';
    }

    return 0;
}
