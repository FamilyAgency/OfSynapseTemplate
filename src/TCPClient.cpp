#include "TCPClient.h"
using namespace synapse;

TCPClient::TCPClient():
	autoConnect(false),
	isReconnecting(false)
{
	ofAddListener(reconnectTimer.timeOutEvent, this, &TCPClient::tryToConnect);
}

TCPClient::~TCPClient()
{

}

void TCPClient::connect(const Config::SocketServer& socketServer)
{
	this->serverConfig = serverConfig;

	ip =			socketServer.ip;
	port =			socketServer.port;
	autoConnect =	socketServer.autoConnect;
	delimiter =		socketServer.delimiter;

	tcp.setMessageDelimiter(delimiter);

	////isReconnecting = true;
	//bool connected = tcp.setup(ip, port);

	//if (connected)
	//{
	//	//isReconnecting = false;
	//	cout << "Connected to: " << ip << ":" << port << endl;
	//}

	tryToConnect();
}

void TCPClient::update()
{
	//cout << ".";
	if (tcp.isConnected())
	{
		string message = tcp.receive();
		if (message.length() > 0)
		{
			newMessage(message);
		}
	}
	else if(autoConnect)
	{
		if (!isReconnecting)
		{
			tryToConnect();
		}
		else
		{
			reconnectTimer.update();
		}
	}
}

void TCPClient::newMessage(const string& message)
{
	cout << "New TCP message: " << message << endl;
	newMessageEvent.notify(this, const_cast<string&>(message));
}

void TCPClient::tryToConnect()
{
	if (!tcp.isConnected())
	{
		bool connected = tcp.setup(ip, port, false);
		if (connected)
		{
			cout << "Connected!" << endl;
			isReconnecting = false;
		}
		else
		{
			reconnectTimer.start(serverConfig.reconnectSeconds);
			isReconnecting = true;
		}
	}
	else
	{
		isReconnecting = false;	
	}
}

