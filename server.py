import socket

# Define the server address and port
server_address = "0.0.0.0"  # Listen on all available network interfaces
port = 12345  # Choose an available port

# Create a socket and bind it to the server address and port
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((server_address, port))
server_socket.listen(5)  # Maximum number of queued connections

print(f"Server is listening on {server_address}:{port}")

while True:
    # Accept incoming client connections
    client_socket, client_address = server_socket.accept()
    print(f"Accepted connection from {client_address}")

    # Handle the connection (you can customize this part)
    message = "Hello, client!"
    client_socket.send(message.encode())

    # Close the client connection
    client_socket.close()
