#include "ofApp.h"
using namespace synapse;

void ofApp::setCommandLineArgs(const vector<string>& args)
{
	cout << "args printed " << endl;
	if (args.size() > 1)
	{
		for (size_t i = 0; i < args.size(); i++)
		{
			auto data = tools().splitString(args[i], '=');
			if (data.size() > 1)
			{
				if (data[0].find("config") != -1)
				{
					configPath = data[1];
				}
			}
		}
	}

	loadConfig();
}

//--------------------------------------------------------------
void ofApp::setup()
{
	cout << "setup " << endl;	
}

void ofApp::loadConfig()
{
	ofAddListener(configController.configSuccessEvent, this, &ofApp::onConfigSuccess);
	ofAddListener(configController.configErrorEvent, this, &ofApp::onConfigError);

	configController.init(configPath);
}

void ofApp::onConfigSuccess()
{
	// entry point
	configPtr = configController.getConfig();
	startApp();
}

void ofApp::onConfigError()
{
	// error message
}

//--------------------------------------------------------------
void ofApp::startApp()
{
	ofSetFullscreen(configPtr->getFullscreen());

	logger().init(configPtr->getAppData().logPath);
	logger().log(Logger::LogType::Message, "message test");
	logger().log(Logger::LogType::Error, "error message test");

	ofAddListener(tcpAppMessageClient.newCommandEvent, this, &ofApp::onNewCommand);
	tcpAppMessageClient.connect(configPtr);
}

void ofApp::onNewCommand(TCPAppMessageClient::CommandType& command)
{

}

//--------------------------------------------------------------
void ofApp::update()
{
	tcpAppMessageClient.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofDrawCircle(250, sin(ofGetElapsedTimef()) * 50 + 250, 0, 50);
	ofDrawBitmapString(debugString, 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	//cout << key << endl;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
