#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    // Create a socket for the client
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
    {
        perror("Failed to create socket");
        return 1;
    }

    // Specify the server's address and port to connect to
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);                      // Use the same port as the server
    inet_pton(AF_INET, "127.0.0.1", &(serverAddress.sin_addr)); // Replace with the server's IP address

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        perror("Connect failed");
        close(clientSocket);
        return 1;
    }

    std::cout << "Connected to the server." << std::endl;

    // You can add code here to send and receive messages with the server

    // Close the client socket
    close(clientSocket);

    return 0;
}
