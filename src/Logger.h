#pragma once
#include "ofMain.h"
#include "Config.h"

namespace synapse
{
	class Logger
	{
	public:
		static Logger& getInstance();
		Logger();

		void init(const string& logPath);

		enum class LogType
		{
			Warning,
			Error,
			Message
		};

		void log(LogType type, const string& message);

	private:
		string logPath;
		ofFile logFile;
		ofBuffer logBuffer;
		string getDate();
		const string dateFormat = "[%Y.%m.%d %H:%M:%S] ";
	};

	inline Logger& logger()
	{
		return Logger::getInstance();
	};
}