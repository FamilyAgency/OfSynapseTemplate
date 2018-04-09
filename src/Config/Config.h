#pragma once
#include "ofMain.h"

namespace synapse
{
	typedef ofPtr<class Config> ConfigPtr;

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
			float reconnectMills = 3000;
		};

		struct Command
		{
			string metaName;
			string action;			
		};

		typedef vector<Command> Commands;

		Config();
		~Config();

		void setAppData(const AppData& appData);
		void setScoketServer(const SocketServer& socketServer);
		void setCommands(const Commands& commands);

		AppData getAppData() const;
		SocketServer getSocketServer() const;
		Commands getCommands() const;

	private:
		AppData appData;
		SocketServer socketServer;
		Commands commands;

	protected:
	};
}