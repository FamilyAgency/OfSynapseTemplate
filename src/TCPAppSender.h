#pragma once
#include "ofMain.h"
#include "TCPClient.h"
#include "Config.h"
#include "ofxNetwork\src\ofxNetwork.h"
#include "ofxJSON.h"

namespace synapse
{
	class TCPAppSender : public synapse::TCPClient
	{
	public:
		TCPAppSender();
		virtual ~TCPAppSender();
		enum class CommandType
		{
			ClientAuth,
			KeepAlive,
			ChangeColor,
			SayHello
		};
		ofEvent<TCPAppSender::CommandType> newCommandEvent;
	private:
		map<string, TCPAppSender::CommandType> commandMap;

		void onNewMessage(string& message);
	};
}

