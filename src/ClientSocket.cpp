/*
 * ClientSocket.cpp
 *
 *  Created on: 2020. 2. 23.
 *      Author: yw
 */

#include "ClientSocket.h"

ClientSocket::ClientSocket(std::string host, int port) {
	if (!Socket::create()) {
		throw SocketException("Client : Could not create socket.\n");
	}

	if (!Socket::connect(host, port)) {
		throw SocketException("Client : Could not bind to port.\n");
	}
}

ClientSocket::~ClientSocket() {

}

const ClientSocket& ClientSocket::operator <<(const std::string &str) const {
	if (!Socket::send(str)) {
		throw SocketException("Could not write to socket.\n");
	}
	return *this;
}
const ClientSocket& ClientSocket::operator >>(std::string &str) const {
	if (!Socket::recv(str)) {
		throw SocketException("Could not read from socket.\n");
	}
	return *this;
}
