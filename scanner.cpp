#include "scanner.hpp"

Scanner::Scanner(){
}

Scanner::Scanner(std::string ip, std::pair<int, int> ports){
    this->ip = ip;    
    this->ports = ports;
}

std::vector<int> Scanner::scan(){
    std::vector<int> res = {};
    for (size_t i = ports.first; i <= ports.second; i++) {
        if (isPortOpen(i)){
            res.push_back(i);
        }
    }
    return res;
}

bool Scanner::isPortOpen(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Ошибка создания сокета" << std::endl;
        return false;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip.c_str()); // адрес
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0){
        //std::cout << port << " open\n";
        close(sockfd);
        return true;
    } else { 
        //std::cout << port << " closed\n";
        close(sockfd);
        return false;
    }
}
