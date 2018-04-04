#include "ConfigParser.h"
using namespace synapse;

ConfigParser::ConfigParser()
{

}

ConfigParser::~ConfigParser()
{

}

void ConfigParser::parse(Config* _config, const string& configString)
{
	config = _config;
	bool parsingSuccessful = configResult.parse(configString);
	if (parsingSuccessful)
	{
		configAppData.version = configResult["version"].asString();
		configAppData.appTypeId = configResult["appTypeId"].asInt();
		configAppData.appId = configResult["appId"].asInt();
		configAppData.logPath = configResult["logPath"].asString();
		config->setAppData(configAppData);

		configSocketServer.ip = configResult["socketServer"]["ip"].asString();
		configSocketServer.port = configResult["socketServer"]["port"].asInt();
		configSocketServer.autoConnect = configResult["socketServer"]["autoConnect"].asBool();
		configSocketServer.delimiter = configResult["socketServer"]["delimeter"].asString();
		config->setScoketServer(configSocketServer);

		Config::Command tempCommand;
		for (int i = 0; i < configResult["commands"].size(); i++)
		{
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

