#include "Logger.h"
using namespace synapse;

Logger& Logger::getInstance()
{
	static Logger logger;
	return logger;
}

Logger::Logger()
{

}

void Logger::init(const string& logPath)
{
	this->logPath = logPath;
	bool doesFileExist = logFile.doesFileExist(logPath, false);

	logFile.open(logPath, ofFile::ReadWrite, false);

	if (!doesFileExist)
	{
		//file does not exist - create
		ofFile logFile(ofToDataPath(logPath));
		logFile.create();
	}
	cout << "Curent log file: " << logPath << endl;
}

void Logger::log(LogType type, const string& message)
{
	string logTypeText;
	switch (type)
	{
	case Logger::LogType::Warning:
		logTypeText = "[WARNING!] ";
		break;
	case Logger::LogType::Error:
		logTypeText = "[ERROR!] ";
		break;
	case Logger::LogType::Message:
		logTypeText = "";
		break;
	default:
		break;
	}
	//bool doesFileExist = logFile.exists();
	//cout << doesFileExist << endl;
	
	logFile << getDate() << logTypeText << message << endl;
}

string Logger::getDate()
{
	time_t rawtime = time(0);
	struct tm * timeinfo;
	char buffer[80];
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, dateFormat.c_str(), timeinfo);
	return buffer;
}




