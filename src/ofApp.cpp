#include "ofApp.h"
using namespace synapse;
//--------------------------------------------------------------
void ofApp::setup()
{
	cout << "setup " << endl;
}

void ofApp::setCommandLineArgs(const vector<string>& args)
{
	cout << "args printed " << endl;
	if (args.size() > 1)
	{
		for (size_t i = 0; i < args.size(); i++)
		{
			// find config and set configPath
			//configPath
		}		
	}

	laodConfig();	
}

void ofApp::laodConfig()
{
	ofAddListener(configController.configSuccessEvent, this, &ofApp::onConfigSuccess);
	ofAddListener(configController.configErrorEvent, this, &ofApp::onConfigError);

	configController.init(configPath);
}

void ofApp::onConfigSuccess()
{
	// entry point
	configPtr = configController.getConfig();

	logger().init(configPtr->getAppData().logPath);
	logger().log(Logger::LogType::Message, "lol");
	logger().log(Logger::LogType::Error, "lol2");

	ofAddListener(tcpAppMessageClient.newCommandEvent, this, &ofApp::onNewCommand);
	tcpAppMessageClient.connect(configPtr->getSocketServer());
}

void ofApp::onConfigError()
{
	//error message
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
	ofDrawCircle(250, sin(ofGetElapsedTimef()) * 50+250, 0, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
