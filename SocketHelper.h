#pragma once
// For some reason, inet_pton is not recognized in the ws2tcpip.h header unless we define what version
// of Windows we are targeting. In this case we are targeting Windows 10
#define _WIN32_WINNT 0x0A00
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

class SocketHelper {
private:
	WSADATA wsa_data_ = {};
	SOCKET receive_socket_ = 0;
	sockaddr_in listen_address_ = {};

private:
	int listen_address_size_ = sizeof(listen_address_);
	sockaddr_in sender_address_;
	int sender_address_size_ = sizeof(sender_address_);

public:
	int start_up();
	bool create_socket();
	int set_address(unsigned short port);
	int get_data(char* data, int dataSize);
	void close_socket();
};