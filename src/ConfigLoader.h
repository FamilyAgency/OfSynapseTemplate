#pragma once
#include "ofMain.h"

namespace synapse
{
	class ConfigLoader
	{
	public:
		ConfigLoader();
		~ConfigLoader();
		void load(const string& param);
		void setConfigPath(const string& param);
		ofEvent<string> loadSuccessEvent;
		ofEvent<void> loadErrorEvent;

	private:
		string configPath;
		ofBuffer configBuffer;
	protected:
	};
}
