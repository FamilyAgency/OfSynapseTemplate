#pragma once

#include "ofMain.h"
#include "Config/ConfigController.h"
#include "Config/Config.h"
#include "tools/logger/Logger.h"
#include "Network/TCP/Client/TCPAppMessageClient.h"


class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	void setCommandLineArgs(const vector<string>& args);
	string debugString, configPath = "config.json";
	
	synapse::ConfigPtr configPtr;
	synapse::ConfigController configController;
	void onConfigSuccess();
	void onConfigError();
	void loadConfig();

	void startApp();
	
	synapse::TCPAppMessageClient tcpAppMessageClient;
	void onNewCommand(synapse::TCPAppMessageClient::CommandType& command);
};
