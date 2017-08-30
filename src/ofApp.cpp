#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    serial.listDevices();
    vector<ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    if(!serial.setup("/dev/cu.usbmodem1421", baud)) {
        ofLogError() << "could not open serial port - listing serial devices";
        serial.drain();
//        serial.listDevices();
//        OF_EXIT_APP(0);
    }
    
    sendValues = false;

    ofSetFullscreen(true);
    ofSetFrameRate(60);
    
//    video.loadMovie("0_normal.mp4");
    video.setLoopState(OF_LOOP_NONE);
    
    
    reader.startData();
    reader.printValues();
    
//    ofHideCursor();
    

    font.load("font/Helvetica-Bold.ttf", 50);

    vidnum = 0;
    
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
    videoPosition();
    
    if (isStarted) {
        video.update();
    }
    
//    if (vidpos >= normal_start && vidpos <= normal_end){
//        if (sendValues) {
//            serial.writeByte(100);
//        }
//    } else {
//        serial.writeByte(0);
//    }
    
    if (sendValues) {
        if (vidnum == 0) serial.writeByte(0);
        else if (vidnum == 1) serial.writeByte(110);
        else serial.writeByte(ofToFloat(reader.readCurrentData()) * 110);
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
    if (vidnum == 0) {
        font.drawString(ofToString(0, 3), ofGetWidth()/2 - font.stringWidth(ofToString(0.000, 1))/2, ofGetHeight() * 0.65);
    } else if (vidnum == 1) {
        if (sendValues) {
            font.drawString(ofToString(1, 3), ofGetWidth()/2 - font.stringWidth(ofToString(0.000, 1))/2, ofGetHeight() * 0.65);
        } else {
            font.drawString(ofToString(0, 3), ofGetWidth()/2 - font.stringWidth(ofToString(0.000, 1))/2, ofGetHeight() * 0.65);
        }
    } else {
        font.drawString(ofToString(reader.readCurrentData(), 3), ofGetWidth()/2 - font.stringWidth(ofToString(reader.readCurrentData(), 3))/2, ofGetHeight() * 0.65);
    }
}

//--------------------------------------------------------------
void ofApp::videoPosition(){
    
    if (vidnum == 0){
        if (vidpos >= normal_start && vidpos <= normal_end){
            sendValues = true;
//            reader.startData();
        } else {
            sendValues = false;
        }
    } else if (vidnum == 1) {
        if (vidpos >= hug_start && vidpos <= hug_end){
            sendValues = true;
//            reader.startData();
        } else {
            sendValues = false;
        }
    } else if (vidnum == 2) {
        if (vidpos >= cushion_start && vidpos <= cushion_end){
            sendValues = true;
            reader.startData();
        } else {
            sendValues = false;
        }
    } else if (vidnum == 3){
        if (vidpos >= beachball_start && vidpos <= beachball_end){
            sendValues = true;
            reader.startData();
        } else {
            sendValues = false;
        }
    } else if (vidnum == 4){
        if (vidpos >= drone_start && vidpos <= drone_end){
            sendValues = true;
            reader.startData();
        } else {
            sendValues = false;
        }
    } else if (vidnum == 5){
        if (vidpos >= tree_start && vidpos <= tree_end){
            sendValues = true;
            reader.startData();
        } else {
            sendValues = false;
        }
    } else if (vidnum == 6){
        if (vidpos >= soda_start && vidpos <= soda_end){
            sendValues = true;
            reader.startData();
        } else {
            sendValues = false;
        }
    } else if (vidnum == 7){
        if (vidpos >= poll_start && vidpos <= poll_end){
            sendValues = true;
            reader.startData();
        } else {
            sendValues = false;
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    serial.writeByte(0);
//    ofExit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '0':
            vidnum = 0;
            video.loadMovie("0_normal.mp4");
            break;
        case '1':
            vidnum = 1;
            video.loadMovie("1_hug.mp4");
            break;
        case '2':
            vidnum = 2;
            video.loadMovie("2_cushion.mp4");
            reader.readFile("txt/pillow-1.txt");
            reader.endData();
            break;
        case '3':
            vidnum = 3;
            video.loadMovie("3_beachball.mp4");
            reader.readFile("txt/ball-2.txt");
            reader.endData();
            break;
        case '4':
            vidnum = 4;
            video.loadMovie("4_drone.mp4");
            reader.readFile("txt/drone-1.txt");
            reader.endData();
            break;
        case '5':
            vidnum = 5;
            video.loadMovie("5_tree.mp4");
            reader.readFile("txt/tree-1.txt");
            reader.endData();
            break;
        case '6':
            vidnum = 6;
            video.loadMovie("6_vendingmachine.mp4");
            reader.readFile("txt/soda-1.txt");
            reader.endData();
            break;
        case '7':
            vidnum = 7;
            video.loadMovie("7_poll.mp4");
            reader.readFile("txt/pole-1.txt");
            reader.endData();
            break;
        default:
            break;
    }
    video.play();
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
