import socket

# Define the server address and port to connect to
server_address = "0.0.0.0"  # Replace with the actual server's IP address
port = 12345  # Use the same port as the server

# Create a socket and connect to the server
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((server_address, port))

# Receive data from the server
data = client_socket.recv(1024)
print(f"Received data: {data.decode()}")

# Close the client socket
client_socket.close()
