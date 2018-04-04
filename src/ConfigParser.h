#pragma once
#include "ofMain.h"
#include "Config.h"
#include "ofxJSON.h"

namespace synapse
{
	class ConfigParser
	{
	public:
		ConfigParser();
		~ConfigParser();
		void parse(Config* config, const string& configString);
		ofEvent<void> parseConfigSuccessEvent;
		ofEvent<void> parseConfigErrorEvent;
	private:
		ofxJSONElement configResult;
		Config::AppData configAppData;
		Config::SocketServer configSocketServer;
		Config::Commands configCommands;
		Config* config;
	protected:
	};
}
