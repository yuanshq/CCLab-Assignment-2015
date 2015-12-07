#include "ofApp.h"

#define NUM_STARS 1500

float StarX[NUM_STARS];
float StarY[NUM_STARS];
float StarRad[NUM_STARS];
int StarR[NUM_STARS];
int StarG[NUM_STARS];
int StarB[NUM_STARS];

float lastdistance = 0;


//Function of drawing Stars of npts/2 vertex angles(or npts vertexs)
void drawStar(float xpos, float ypos, float radius, int npts)
{
    bool useInner=false;
    ofBeginShape();
    for(int l=0; l<360; l +=360/npts)
    {
        int r = useInner ? radius*.6 : radius;
        int x = xpos + cos( ofDegToRad(l) ) * r;
        int y = ypos + sin( ofDegToRad(l) ) * r;
        ofVertex(x, y);
        useInner = !useInner;
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetFrameRate(24);
    
    for(int i=0; i<NUM_STARS; i++)
    {
        StarX[i] = ofRandom(0, ofGetWidth());
        StarY[i] = ofRandom(0, ofGetHeight());
        StarRad[i] = ofRandom(5, 15);
        
        StarR[i] = ofRandom(0, 255);
        StarG[i] = ofRandom(0, 255);
        StarB[i] = ofRandom(0, 255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    int angle = 0;
    for(int i=0; i<NUM_STARS; i++)
    {
//        StarX[i] += cos( ofDegToRad(angle) ) * ofRandom(0, 2);
//        StarY[i] += sin( ofDegToRad(angle) ) * ofRandom(0, 2);
        StarX[i] += ofRandom(-2, 2);
        StarY[i] += ofRandom(-2, 2);
        angle += 10;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor::yellowGreen, ofColor(255,255,255), OF_GRADIENT_CIRCULAR);
    
    ofSetBackgroundAuto(false);
    drawStar(mouseX, mouseY, 20, 10);
    ofEnableAlphaBlending();
    
    for(int i=0; i<NUM_STARS; i++)
    {
        ofSetColor(StarR[i], StarG[i], StarB[i]);
        drawStar(StarX[i], StarY[i], StarRad[i], 10);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    float distanceS = ofDist(mouseX, mouseY, x, y);

    
    for(int i=0; i<NUM_STARS; i++)
    {
        StarX[i] = ofRandom(0, ofGetWidth());
        StarY[i] = ofRandom(0, ofGetHeight());
        StarRad[i] = ofRandom(5, 15);
        
        StarR[i] = ofRandom(0, 255);
        StarG[i] = ofRandom(0, 255);
        StarB[i] = ofRandom(0, 255);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    float distance = ofDist(ofGetWidth(), ofGetHeight(), x, y);
    
    
    if(distance > lastdistance)
    {
        for(int i=0; i<NUM_STARS; i++)
        {
            StarRad[i] += 2;
            
            StarB[i] += 4;
        }
    }
    else
    {
        for(int i=0; i<NUM_STARS; i++)
        {
            StarRad[i] -= 2;
            
            StarB[i] -= 4;
        }
    }
    
    lastdistance = distance;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

//    xPos = ofRandom( ofGetWindowWidth() );
//    yPos = ofRandom( ofGetWindowHeight() );
    
    for(int i=0; i<NUM_STARS; i++)
    {
        StarX[i] = ofRandom(0, ofGetWidth());
        StarY[i] = ofRandom(0, ofGetHeight());
        StarRad[i] = ofRandom(5, 15);
        
        StarR[i] = ofRandom(0, 255);
        StarG[i] = ofRandom(0, 255);
        StarB[i] = ofRandom(0, 255);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
