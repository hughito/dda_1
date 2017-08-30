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
//        OF_EXIT_APP(0);
    }
    
    sendValues = true;

    ofSetFullscreen(false);
    ofSetFrameRate(60);
    
    video.loadMovie("0_normal.mp4");
    video.setLoopState(OF_LOOP_NORMAL);
    
    reader.readFile("txt/ball-2.txt");
    reader.startData();
    reader.printValues();
    
//    ofHideCursor();
    
    font.load("font/Helvetica-Bold.ttf", 50);
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
    font.drawString(ofToString(reader.readCurrentData(), 3), ofGetWidth()/2 - font.stringWidth(ofToString(0.000, 3))/2, ofGetHeight() * 0.65);
}

//--------------------------------------------------------------
void ofApp::exit(){
    if (serial.isInitialized()) {
        serial.writeByte(0);
    }
//    ofExit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '0':
            video.loadMovie("0_normal.mp4");
            break;
        case '1':
            video.loadMovie("1_hug.mp4");
            break;
        case '2':
            video.loadMovie("2_cushion.mp4");
            break;
        case '3':
            video.loadMovie("3_beachball.mp4");
            break;
        case '4':
            video.loadMovie("4_drone.mp4");
            break;
        case '5':
            video.loadMovie("5_tree.mp4");
            break;
        case '6':
            video.loadMovie("6_vendingmachine.mp4");
            break;
        case '7':
            video.loadMovie("7_poll.mp4");
            break;
        default:
            break;
    }
    video.play();
    reader.startData();
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
