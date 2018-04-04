#pragma once

#include "ofMain.h"
#include "ConfigController.h"
#include "Config.h"
#include "Logger.h"
#include "TCPClient.h"
#include "TCPAppSender.h"

using namespace synapse;
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

	bool isConfigReady = false;

	void setCommandLineArgs(const vector<string>& args);
	string configPath = "B:\\FamilyAgencyBack\\OfTemplateSynapse\\bin\\data\\config.json";

	ConfigController configController;
	void onConfigSuccess();
	void onConfigError();
	Config* configPtr;

	TCPAppSender tcpSender;

	void onNewCommand(TCPAppSender::CommandType& command);
};
