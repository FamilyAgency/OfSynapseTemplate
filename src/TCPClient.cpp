#include "TCPClient.h"
using namespace synapse;

TCPClient::TCPClient()
{
	ofAddListener(reconnectTimer.timeOutEvent, this, &TCPClient::tryToReconnect);
}

TCPClient::~TCPClient()
{
}

void TCPClient::connect(const Config::SocketServer& socketServer)
{
	ip =			socketServer.ip;
	port =			socketServer.port;
	autoConnect =	socketServer.autoConnect;
	delimiter =		socketServer.delimiter;
	tcp.setMessageDelimiter(delimiter);
	bool connected = tcp.setup(ip, port);
	if (connected)
	{
		cout << "Connected to: " << ip << ":" << port << endl;
	}
}

void TCPClient::update()
{
	//cout << ".";
	if (tcp.isConnected())
	{
		string str = tcp.receive();
		if (str.length() > 0)
		{
			newMessage(str);
		}
	}
	else
	{
		if (!isReconnecting)
		{
			tryToReconnect();
		}
		else
		{
			reconnectTimer.update();
		}
	}
}

void TCPClient::newMessage(const string& _message)
{
	string message = _message;
	cout << "New TCP message: " << message << endl;
	newMessageEvent.notify(this, message);
}


void TCPClient::tryToReconnect()
{
	if (!tcp.isConnected())
	{
		bool reconnected = tcp.setup(ip, port, false);
		if (reconnected)
		{
			cout << "Reconnected!" << endl;
			isReconnecting = false;
		}
		else
		{
			reconnectTimer.start(3);
			isReconnecting = true;
		}
	}
	else
	{
		isReconnecting = false;	
	}
}

