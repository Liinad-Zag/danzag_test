#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

constexpr int BUFFER_SIZE = 1024;
constexpr int PORT = 8080;

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[BUFFER_SIZE];

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        std::cerr << "Error: Failed to create socket" << std::endl;
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error: Bind failed" << std::endl;
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error: Listen failed" << std::endl;
        close(serverSocket);
        return 1;
    }

    std::cout << "Server started, listening on port " << PORT << std::endl;

    while (true) {
        socklen_t clientLen = sizeof(clientAddr);

        if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen)) == -1) {
            std::cerr << "Error: Accept failed" << std::endl;
            continue;
        }

        std::cout << "Connection accepted from " << inet_ntoa(clientAddr.sin_addr) << std::endl;

        while (true) {
            memset(buffer, 0, BUFFER_SIZE);
            ssize_t bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0);

            if (bytesRead == -1) {
                std::cerr << "Error: Failed to receive data" << std::endl;
                break;
            } else if (bytesRead == 0) {
                std::cout << "Client disconnected" << std::endl;
                break;
            }

            std::cout << "Received message from client: " << buffer << std::endl;

            const char* response = "Message received";
            if (send(clientSocket, response, strlen(response), 0) == -1) {
                std::cerr << "Error: Failed to send response" << std::endl;
                break;
            }
        }

        close(clientSocket);
    }

    close(serverSocket);

    return 0;
}
