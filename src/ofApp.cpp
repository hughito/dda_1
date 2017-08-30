#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    serial.listDevices();
    vector<ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.listDevices();
    if(!serial.setup("/dev/cu.usbmodem1421", baud)) {
        ofLogError() << "could not open serial port - listing serial devices";
        serial.drain();
        serial.listDevices();
        OF_EXIT_APP(0);
    }
    
    sendValues = true;

    ofSetFullscreen(false);
    ofSetFrameRate(60);
    
    video.loadMovie("0_normal.mp4");
    video.setLoopState(OF_LOOP_NORMAL);
    
//    ofHideCursor();
    
}

//--------------------------------------------------------------
void ofApp::send_command(string msg){
    unsigned char* msguc = new unsigned char[msg.size()];
    //get
    memcpy(msguc, msg.c_str(),msg.size());
    serial.writeBytes(msguc, msg.size());
    delete [] msguc;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (!isStarted) {
        isStarted = true;
        video.play();
    }

    vidpos = video.getPosition();
    
    if (isStarted) {
        video.update();
    }
    
    if (vidpos >= normal_start && vidpos <= normal_end){
        if (sendValues) {
            serial.writeByte(100);
        }
    } else {
        serial.writeByte(0);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    if (isStarted) {
        video.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    }
    
    ofSetColor(0);
    ofDrawBitmapString(vidpos, ofGetWidth()/2, ofGetHeight()/2);
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    serial.writeByte(0);
    ofExit();
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
