/*
 * ClientSocket.h
 *
 *  Created on: 2020. 2. 23.
 *      Author: yw
 */

#ifndef CLIENTSOCKET_H_
#define CLIENTSOCKET_H_

#include "Socket.h"

class ClientSocket: public Socket {
public:
	ClientSocket(std::string host, int port);
	virtual ~ClientSocket();

	const ClientSocket& operator << (const std::string& ) const;
	const ClientSocket& operator >> ( std::string& ) const;
};

#endif /* CLIENTSOCKET_H_ */
