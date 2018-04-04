#include "Config/ConfigLoader.h"
using namespace synapse;

ConfigLoader::ConfigLoader()
{

}

ConfigLoader::~ConfigLoader()
{

}

void ConfigLoader::load(const string& param, LoadType type)
{
	if (type == LoadType::LocalFile)
	{
		if (param.length() > 0)
		{
			setConfigPath(param);
			configBuffer = ofBufferFromFile(configPath);
			string configText = configBuffer.getText();
			loadSuccessEvent.notify(this, configText);
		}
		else
		{

		}

		//@TODO: notify file error
	}	
}

void ConfigLoader::setConfigPath(const string& param)
{
	configPath = param;
}