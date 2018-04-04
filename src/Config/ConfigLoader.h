#pragma once
#include "ofMain.h"

namespace synapse
{
	class ConfigLoader
	{
	public:
		enum class LoadType
		{
			None,
			LocalFile,
			Url
		};

		ConfigLoader();
		~ConfigLoader();

		void load(const string& param, LoadType type = LoadType::LocalFile);
		void setConfigPath(const string& param);

		ofEvent<string> loadSuccessEvent;
		ofEvent<void> loadErrorEvent;

	private:
		string configPath;
		ofBuffer configBuffer;

	protected:
	};
}
