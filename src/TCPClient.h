#pragma once
#include "ofMain.h"
#include "Config.h"
#include "ofxNetwork\src\ofxNetwork.h"
#include "Timer.h"

namespace synapse
{
	class TCPClient
	{
	public:
		TCPClient();
		~TCPClient();

		void update();
		void connect(const synapse::Config::SocketServer& socketServer);

		ofEvent<string> newMessageEvent;
	private:
		Config::SocketServer serverConfig;

		string ip;
		int port;
		string delimiter;

		bool autoConnect;
		bool isReconnecting;
		Timer reconnectTimer;
		ofxTCPClient tcp;

		void newMessage(const string& message);
		void tryToConnect();
	};
}