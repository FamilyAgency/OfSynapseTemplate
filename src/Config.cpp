#include "Config.h"

using namespace synapse;

Config::Config()
{

}

Config::~Config()
{

}

void Config::setAppData(const AppData& _appData)
{
	appData = _appData;
}

Config::AppData Config::getAppData()
{
	return appData;
}

void Config::setScoketServer(const SocketServer& _socketServer)
{
	socketServer = _socketServer;
}

Config::SocketServer Config::getSocketServer()
{
	return socketServer;
}

void Config::setCommands(const Commands & _commands)
{
	commands = _commands;
}

Config::Commands Config::getCommands()
{
	return commands;
}