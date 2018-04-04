#include "TCPAppSender.h"
using namespace synapse;

TCPAppSender::TCPAppSender()
{
	ofAddListener(TCPClient::newMessageEvent, this, &TCPAppSender::onNewMessage);
	commandMap.insert(pair<string, CommandType>("clientAuth",	CommandType::ClientAuth));
	commandMap.insert(pair<string, CommandType>("keepAlive",	CommandType::KeepAlive));
	commandMap.insert(pair<string, CommandType>("changeColor",	CommandType::ChangeColor));
	commandMap.insert(pair<string, CommandType>("sayHello",		CommandType::SayHello));
}

TCPAppSender::~TCPAppSender()
{

}

void TCPAppSender::onNewMessage(string& message)
{
	ofxJSONElement messageResult;
	bool parseSeuccess = messageResult.parse(message);
	if (parseSeuccess)
	{
		//cout << messageResult["command"]["type"].asString()<< endl;
		CommandType newCommandType = commandMap[messageResult["command"]["type"].asString()];
		newCommandEvent.notify(this, newCommandType);
	}
}
