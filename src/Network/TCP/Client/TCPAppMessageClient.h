#pragma once
#include "ofMain.h"
#include "TCPClient.h"
#include "Config/Config.h"
#include "ofxNetwork\src\ofxNetwork.h"
#include "ofxJSON.h"

namespace synapse
{
	class TCPAppMessageClient : public synapse::TCPClient
	{
	public:
		TCPAppMessageClient();
		virtual ~TCPAppMessageClient();
		enum class CommandType
		{
			ClientAuth,
			KeepAliveToggle,
			ChangeColor,
			SayHello
		};
		ofEvent<CommandType> newCommandEvent;

	private:
		map<string, CommandType> commandMap;
		void onNewMessage(string& message);

		void sendAuthMessage();
	};
}

