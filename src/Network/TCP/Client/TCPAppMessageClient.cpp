#include "TCPAppMessageClient.h"

using namespace synapse;

TCPAppMessageClient::TCPAppMessageClient()
{	
	commandMap.insert(pair<string, CommandType>("clientAuth",		CommandType::ClientAuth));
	commandMap.insert(pair<string, CommandType>("keepAliveToggle",	CommandType::KeepAliveToggle));
	commandMap.insert(pair<string, CommandType>("changeColor",		CommandType::ChangeColor));
	commandMap.insert(pair<string, CommandType>("sayHello",			CommandType::SayHello));
	commandMap.insert(pair<string, CommandType>("getInfo",			CommandType::GetInfo));
	ofAddListener(TCPClient::newMessageEvent, this, &TCPAppMessageClient::onNewMessage);
}

TCPAppMessageClient::~TCPAppMessageClient()
{

}

void TCPAppMessageClient::onNewMessage(string& message)
{
	cout << "message  " << message;
	ofxJSONElement messageResult;
	bool parseSeuccess = messageResult.parse(message);

	if (parseSeuccess)
	{
		CommandType newCommandType = commandMap[messageResult["command"]["type"].asString()];

		switch (newCommandType)
		{
		case CommandType::ClientAuth:
			sendAuthMessage();
			break;

		case CommandType::KeepAliveToggle:
			break;

		case CommandType::ChangeColor:
			break;

		case CommandType::SayHello:
			break;

		case CommandType::GetInfo:
			sendAppInfo();
			break;
		}
		newCommandEvent.notify(this, newCommandType);
	}
}

void TCPAppMessageClient::sendAuthMessage()
{
	auto appId = to_string(config->getAppData().appId);
	auto appTypeId = to_string(config->getAppData().appTypeId);
	string authMessage = "{\"response\":{\"type\":\"clientAuth\",\"appTypeId\":" + appTypeId + ",\"appId\":" + appId + "}}";

	tcp.send(authMessage);
}

void TCPAppMessageClient::sendAppInfo()
{

}

