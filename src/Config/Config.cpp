#include "Config/Config.h"

using namespace synapse;

Config::Config()
{

}

Config::~Config()
{

}


void Config::setFullscreen(bool value)
{
	isFullscreen = value;
}

bool Config::getFullscreen() const
{
	return isFullscreen;
}

void Config::setAppData(const AppData& appData)
{
	this->appData = appData;
}

Config::AppData Config::getAppData() const
{
	return appData;
}

void Config::setScoketServer(const SocketServer& socketServer)
{
	this->socketServer = socketServer;
}

Config::SocketServer Config::getSocketServer() const
{
	return socketServer;
}

void Config::setCommands(const Commands & commands)
{
	this->commands = commands;
}

Config::Commands Config::getCommands() const
{
	return commands;
}