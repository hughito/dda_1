#pragma once

#include "ofMain.h"
#include "Smoother.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void send_command(string msg);
        void exit();
        void videoPosition();
    
    ofSerial serial;
    Boolean sendValues;
    Smoother smooth;
    ofTrueTypeFont font;
    
    ofVideoPlayer video;
    bool isStarted = false;
    float vidpos;
    int vidnum;
    
    /*
     vidpos == 0.152616 (0_normal-start), 0.910120 (0_normal-end)
     vidpos == 0.250492 (1_hug-start), 0.790428 (1_hug-end)
     vidpos == 0.200579 (2_cushion-start), 0.790289 (2_cushion-end)
     vidpos == 0.226057 (3_beachball-start), 0.720102 (3_beachball-end)
     vidpos == 0.334743 (4_drone-start), 0.792007 (4_drone-end)
     vidpos == 0.282232 (5_tree-start), 0.867556 (5_tree-end)
     vidpos == 0.178119 (6_soda-start), 0.770662(6_soda-end)
     vidpos == 0.243033 (7_poll-start), 0.853046 (7_poll-end)
     */
    
    float normal_start = 0.152616;
    float normal_end = 0.910120;
    float hug_start = 0.250492;
    float hug_end = 0.790428;
    float cushion_start = 0.200579;
    float cushion_end = 0.790289;
    float beachball_start = 0.226057;
    float beachball_end = 0.720102;
    float drone_start = 0.334743;
    float drone_end = 0.792007;
    float tree_start = 0.282232;
    float tree_end = 0.867556;
    float soda_start = 0.178119;
    float soda_end = 0.770662;
    float poll_start = 0.243033;
    float poll_end = 0.853046;
		
};
