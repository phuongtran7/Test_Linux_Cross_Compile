#include "SocketHelper.h"

int SocketHelper::start_up() {
	return WSAStartup(MAKEWORD(2, 2), &wsa_data_);
}

bool SocketHelper::create_socket()
{
	return (receive_socket_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) != SOCKET_ERROR;
}

int SocketHelper::set_address(unsigned short port) {
	listen_address_.sin_family = AF_INET;
	listen_address_.sin_port = htons(port);
	inet_pton(AF_INET, INADDR_ANY, &listen_address_.sin_addr);

	if (bind(receive_socket_, (SOCKADDR*)&listen_address_, listen_address_size_) == SOCKET_ERROR)
	{
		close_socket();
		WSACleanup();
		return WSAGetLastError();
	}
	return 0;
}

int SocketHelper::get_data(char* outDataBuffer, int outDataBuffer_Size)
{
	// If care about the sender's information like IP address you can pass the sender_address_ struct into the recvfrom
	//return recvfrom(receive_socket_, outDataBuffer, outDataBuffer_Size, 0, reinterpret_cast<sockaddr*>(&sender_address_), &sender_address_size_);

	return recvfrom(receive_socket_, outDataBuffer, outDataBuffer_Size, 0, nullptr, nullptr);
}

void SocketHelper::close_socket()
{
	closesocket(receive_socket_);
	WSACleanup();
}