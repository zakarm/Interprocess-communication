#include "header.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        std::cout << "******* Server *******" << std::endl;
        int socket_s = socket(AF_UNIX, SOCK_STREAM, 0);
        if (socket_s == -1)
        {
            std::cerr << ANSI_COLOR_RED << "Error : socket fail" << std::endl;
            exit(EXIT_FAILURE); 
        }
        struct sockaddr_un server_addr;
        server_addr.sun_family = AF_UNIX;
        strcpy(server_addr.sun_path, "unix_socket");
        int slen = sizeof(server_addr);
        int connection_resault = connect(socket_s, (const struct sockaddr *) &server_addr, slen);
        if (connection_resault == -1)
        {
            std::cerr << ANSI_COLOR_RED << "Error : connection fail" << std::endl;
            exit(EXIT_FAILURE); 
        }
        for (size_t i = 0; i < strlen(argv[1]); i++)
        {
            write(socket_s, &argv[1][i], 1);
            read(socket_s, &argv[1][i], 1);
        }
        close(socket_s);
        std::cout << ANSI_COLOR_YELLOW << "Sent successfully !" << std::endl;
    }
    else
        std::cerr << ANSI_COLOR_RED << "Error : invalid args !" << std::endl;
}
