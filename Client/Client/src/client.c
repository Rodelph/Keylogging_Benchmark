// Server side C/C++ program to demonstrate Socket
// programming

#include "headers/client.h"

//https://www.geeksforgeeks.org/socket-programming-cc/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
void client()
{

}

#else
void client()
{
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        printf("\n Socket creation error \n");
    }
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
  
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<= 0) 
    {
        printf("\nInvalid address/ Address not supported \n");
    }
  
    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) 
    {
        printf("\nConnection Failed \n");
    }
    char* ch = "";
    scanf("%s", &ch);
    /*

        Encryption Handling

    */
    send(client_fd, &ch, strlen(&ch), 0);
    printf("----Message sent----\n");
    valread = read(client_fd, buffer, 1024);
    printf("%s\n", buffer);
  
    // closing the connected socket
    close(client_fd);
}
#endif