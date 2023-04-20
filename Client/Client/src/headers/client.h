#ifndef __CLIENT__
#define __CLIENT__

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <winsock2.h>
#include <iostream>
#include <fstream>
#else
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

#endif

void client();

#endif