#include <iostream>
#include "SocketHelper.h"
#include <vector>
#include <array>

SocketHelper send_socket;

int main()
{
	std::cout << "Hello World!\n";

	auto startup_result = send_socket.start_up();
	if (startup_result != NO_ERROR) {
		std::cout << "Socket startup failed: {}" << std::to_string(startup_result) << "\n";
		return 0;
	}

	auto create_socket_result = send_socket.create_socket();
	if (!create_socket_result) {
		std::cout << "Cannot create socket.\n";
		return 1;
	}

	auto bind_result = send_socket.set_address(9605);
	if (bind_result != 0) {
		std::cout <<  "Cannot bind address with error: {}" << bind_result << "\n";
		return 1;
	}

	while (1) {
		std::array<char, 50> buffer{};
		auto byte_received = send_socket.get_data(buffer.data(), sizeof(buffer));
		if (byte_received != 0) {
			std::cout << "Got " << byte_received << " bytes.\n";
		}
	}

	return 0;
}

