# Interprocess_communication
This program is an implementation of interprocess communication using sockets. It allows processes to communicate with each other and synchronize their actions. The communication between these processes can be seen as a method of co-operation between them. Processes can communicate with each other through both shared memory and message passing.

The implementation of this program is done in C++ and uses the Unix domain sockets. The Unix domain sockets are used for communication between processes on the same machine efficiently. The program creates a socket and binds it to a local address. Then it listens for incoming connections from clients. Once a client connects, the server accepts the connection and starts communicating with the client.
