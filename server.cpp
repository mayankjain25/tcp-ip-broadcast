#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    // Create a socket for the server
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        perror("Failed to create socket");
        return 1;
    }

    // Bind the server socket
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);      // Choose a port
    serverAddress.sin_addr.s_addr = INADDR_ANY; // Listen on all available network interfaces

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        perror("Bind failed");
        close(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == -1)
    {
        perror("Listen failed");
        close(serverSocket);
        return 1;
    }

    std::cout << "Server is listening for incoming connections..." << std::endl;

    // Accept and handle incoming connections
    while (true)
    {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLen = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
        if (clientSocket == -1)
        {
            perror("Accept failed");
            continue;
        }

        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddress.sin_addr), clientIP, INET_ADDRSTRLEN);
        std::cout << "Client connected from " << clientIP << ":" << ntohs(clientAddress.sin_port) << std::endl;

        // You can add code here to handle client messages and broadcast them to other clients

        close(clientSocket);
        std::cout << "Client disconnected" << std::endl;
    }

    // Cleanup
    close(serverSocket);

    return 0;
}
