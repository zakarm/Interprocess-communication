#include "header.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    std::cout << "******* Server *******" << std::endl;
    int socket_s = socket(AF_UNIX, SOCK_STREAM, 0), socket_c;
    if (socket_s == -1)
    {
        std::cerr << ANSI_COLOR_RED << "Error : socket fail" << std::endl;
        exit(EXIT_FAILURE); 
    }
    struct sockaddr_un server_addr;
    struct sockaddr_un client_addr;

    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, "unix_socket");
    int slen = sizeof(server_addr);
    bind(socket_s, (const struct sockaddr *) &server_addr, slen);

    listen(socket_s, 5);
    while (true)
    {
        char c;
        socklen_t clen;
        clen = sizeof(client_addr);
        socket_c = accept(socket_s, (struct sockaddr *) &client_addr, &clen);
        std::string data;
        int i = 0;
        while (i < 30000 && read(socket_c, &c, 1))
        {
            data += c;
            write (socket_c, &c, 1);
        }
        std::cout << data << std::endl;
        close(socket_c);
    }
}
