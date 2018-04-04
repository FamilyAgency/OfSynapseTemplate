#pragma once

#include "ofMain.h"
#include "Config/ConfigController.h"
#include "Config/Config.h"
#include "Utilities/Logger.h"
#include "Network/TCP/TCPAppSender.h"
#include "Network/TCP/TCPClient.h"


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
	
	void setCommandLineArgs(const vector<string>& args);
	string configPath = "B:\\FamilyAgencyBack\\OfTemplateSynapse\\bin\\data\\config.json";
	
	ConfigPtr configPtr;
	ConfigController configController;
	void onConfigSuccess();
	void onConfigError();
	void laodConfig();
	
	TCPAppSender tcpSender;
	void onNewCommand(TCPAppSender::CommandType& command);
};
