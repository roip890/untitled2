/*
 * Server.h
 *
 *  Created on: Dec 22, 2015
 *      Author: tomericko
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <map>

enum ConType{TCP, UDP};
enum State{FAILURE, SUCCESS};
using namespace std;

/*******************************************************************************
* class name : Server
*******************************************************************************/
class Server{
protected:
	int port;
	struct sockaddr_in sin;
	int sock;
	int client_sock;
	char* dataReceived;
	char* ip;
	vector<pthread_t> threads;


	/*******************************************************************************
	* function name : Server												       *
	* input : port as int.													       *
	* output : nothing.														       *
	* explanation : constructor of a Server.									   *
	*******************************************************************************/

public:
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{

	}

	void invokeThread(int id);
	void addThread(pthread_t ptrd);
	Server(int port);
	vector<pthread_t>& getThreads();

	/*******************************************************************************
	* function name : Server												       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : constructor of a Server.									   *
	*******************************************************************************/
	Server();



	/*******************************************************************************
	* function name : ~Server												       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : destructor of a Server.										   *
	*******************************************************************************/
	virtual ~Server();


	virtual void connect()=0;


	void close(int socket);

	/*******************************************************************************
	* function name : getPort												       *
	* input : nothing.														       *
	* output : port as int.													       *
	* explanation : return the port as int.										   *
	*******************************************************************************/
	int getPort();

	/*******************************************************************************
	* function name : getIP													       *
	* input : nothing.														       *
	* output : ip as string.												       *
	* explanation : return the ip address as string.							   *
	*******************************************************************************/
	char*  getIP();

	/*******************************************************************************
	* function name : setIP													       *
	* input : ip as string.													       *
	* output : nothing.														       *
	* explanation : set the ip member with string.								   *
	*******************************************************************************/
	void setIP(char* ip);

	/*******************************************************************************
	* function name : setPort												       *
	* input : port as int.													       *
	* output : nothing.														       *
	* explanation : set the port member with int.								   *
	*******************************************************************************/
	void setPort(int port);

	/*******************************************************************************
	* function name : getSocket												       *
	* input : nothing.														       *
	* output : the socket.													       *
	* explanation : return the socket.											   *
	*******************************************************************************/
	int getSocket();

	/*******************************************************************************
	* function name : setSocket												       *
	* input : ip address as string and socket as int.						       *
	* output : nothing.														       *
	* explanation : setting the socket.											   *
	*******************************************************************************/
	void setSocket(char* ip, int port);

	/*******************************************************************************
	* function name : sendData												       *
	* input : data as string.												       *
	* output : nothing.														       *
	* explanation : sending the data to the socket.								   *
	*******************************************************************************/
	virtual void sendData(string str, int sock)=0;

	/*******************************************************************************
	* function name : dataReceiver											       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : receive the massage to the buffer.							   *
	*******************************************************************************/
	virtual string dataReceiver(int sock)= 0;

	/*******************************************************************************
	* function name : bindSocket											       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : make bind to a client.										   *
	*******************************************************************************/
	virtual void bindSocket()=0;

	/*******************************************************************************
	* function name : createSocket											       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : creating a socket in this connection.						   *
	*******************************************************************************/
	virtual void createSocket()=0;

	/*******************************************************************************
	* function name : getDataReceived										       *
	* input : nothing.														       *
	* output : the massage as string.										       *
	* explanation : return the massage as string.								   *
	*******************************************************************************/
	string getDataReceived();

	/*******************************************************************************
	* function name : setSocket												       *
	* input : socket as int.						       *
	* output : nothing.														       *
	* explanation : setting the socket.											   *
	*******************************************************************************/
	void setSocket(int sock);
};




#endif /* SERVER_H_ */
