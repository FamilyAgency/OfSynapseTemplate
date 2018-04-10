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

		VIEW_TYPES viewType = VIEW_TYPES::ONE_ARTWORK;
		const float SCREEN_WIDTH = 1080 * 0.5;// 1080;//720
		const float SCREEN_HEIGHT = 1920 * 0.5;// 1920;// 1280
		const float SCREEN_LARGE_WIDTH = SCREEN_WIDTH * 3;
		bool artRotateMode = true;
		float changeArtSeconds = 1 * 60.0f;
		const int	fboNumSamples = 2;

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

		void setFullscreen(bool value);
		bool getFullscreen() const;

		void setShowCursor(bool value);
		bool getShowCursor() const;

		struct ConfigObject
		{
			VIEW_TYPES viewType;
			float typeSeconds;
			float oneArtSeconds;
		};
		std::vector<ConfigObject> configRotator;

	private:
		AppData appData;
		SocketServer socketServer;
		Commands commands;
		bool isFullscreen = false;
		bool showCursor = false;

	};
}