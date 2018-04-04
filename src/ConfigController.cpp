#include "ConfigController.h"
using namespace synapse;

ConfigController::ConfigController()
{

}

ConfigController::~ConfigController()
{

}

void ConfigController::init(string path)
{
	configPath = path;
	ofAddListener(configLoader.loadSuccessEvent, this, &ConfigController::onConfigLoadSuccess);
	ofAddListener(configLoader.loadErrorEvent, this, &ConfigController::onConfigLoadError);
	configLoader.load(configPath);

}

void ConfigController::onConfigLoadSuccess(string & rawConfig)
{
	ofAddListener(configParser.parseConfigSuccessEvent, this, &ConfigController::onConfigParseSuccess);
	configParser.parse(&config, rawConfig);
}

void ConfigController::onConfigParseSuccess()
{
	//parsed!
	configSuccessEvent.notify(this);
}

Config * ConfigController::getConfig()
{
	return &config;
}



void ConfigController::onConfigLoadError()
{
	configSuccessEvent.notify(this);
}

void ConfigController::onConfigParseError()
{
	configErrorEvent.notify(this);
}