/*
 =====================
 Name		: main.cpp
 Author		: LYW
 Version		: 0.0.1
 Desciption	: socket chat server main func
 =====================
 */

#include <iostream>
#include <string>
#include "ClientSocket.h"

int main(int argc, char *argv[]) {
	if (argc != 3) {
		// argv[0] : filename
		// argv[1~2] : 추가로 입력한 인자 -> 만약 이게 없어서 argc가 3dl 아니면 종료.
		fprintf(stdout, "Usage : %s <ip> <port>\n", argv[0]);
		exit(1);
	}

	try {
		ClientSocket client_socket(argv[1], atoi(argv[1]));

		std::string msg;

		try {
			client_socket << "Test message.";
			client_socket >> msg;
		} catch (SocketException&) {
		}

		std::cout << "Received Message: " << msg << "\n\n";
	} catch (SocketException &e) {
		std::cout << "Exception was caught : " << e.description() << "\n";
	}

	return 0;
}
