#include "Config/ConfigParser.h"
using namespace synapse;

ConfigParser::ConfigParser()
{

}

ConfigParser::~ConfigParser()
{

}

void ConfigParser::parse(ConfigPtr config, const string& configString)
{
	bool parsingSuccessful = configResult.parse(configString);

	if (parsingSuccessful)
	{
		Config::AppData configAppData;
		configAppData.version = configResult["version"].asString();
		configAppData.appTypeId = configResult["appTypeId"].asInt();
		configAppData.appId = configResult["appId"].asInt();
		configAppData.logPath = configResult["logPath"].asString();
		config->setAppData(configAppData);

		Config::SocketServer configSocketServer;
		configSocketServer.ip = configResult["socketServer"]["ip"].asString();
		configSocketServer.port = configResult["socketServer"]["port"].asInt();
		configSocketServer.autoConnect = configResult["socketServer"]["autoConnect"].asBool();
		configSocketServer.delimiter = configResult["socketServer"]["delimeter"].asString();
		config->setScoketServer(configSocketServer);
		
		Config::Commands configCommands;		
		for (int i = 0; i < configResult["commands"].size(); i++)
		{
			Config::Command tempCommand;
			tempCommand.metaName = configResult["commands"][i]["metaName"].asString();
			tempCommand.actrion = configResult["commands"][i]["action"].asString();
			configCommands.push_back(tempCommand);
		}
		config->setCommands(configCommands);
		parseConfigSuccessEvent.notify(this);
	}
	else
	{
		parseConfigErrorEvent.notify(this);
	}
}

