#pragma once

#include "ofMain.h"

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
		
        ofSpherePrimitive sphere;
        ofPlanePrimitive ground;
        ofBoxPrimitive box;
        ofLight light;
        ofTexture mTex1, mTex2;
        ofEasyCam cam;
    ofVec3f top1,top2,p1,p2;
    ofVec3f vertex;
    
    ofMesh mesh;
    ofVec3f vel;
    ofPoint b[5000];
    ofVec3f a;
    ofConePrimitive grass[5000];
    float radius[5000];
};
