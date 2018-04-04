#pragma once
#include "ofMain.h"

namespace synapse
{
	class Config
	{
	public:
		struct AppData
		{
			string version;
			int appTypeId;
			int appId;
			string logPath;
		};
		struct SocketServer
		{
			string ip;
			int port;
			bool autoConnect;
			string delimiter;
		};
		struct Command
		{
			string metaName;
			string actrion;
		};
		typedef  vector<Command> Commands;

		Config();
		~Config();

		void setAppData(const AppData& _appData);
		void setScoketServer(const SocketServer& _socketServer);
		void setCommands(const Commands& _commands);
		AppData getAppData();
		SocketServer getSocketServer();
		Commands getCommands();

	private:
		AppData appData;
		SocketServer socketServer;
		Commands commands;
	protected:
	};
}