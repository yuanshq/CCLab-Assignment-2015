#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    R = 300;
    
    
    ofEnableSmoothing();
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(true);
    
    ofSetVerticalSync(true);//Syncs the refresh-rate with your video-cards refresh-rate, thus fast moving stuff will be looking more accurate.
    ofSetCircleResolution(256);//Sets the resolution for the ofCircle command. By default, the circle is 22 points, but if you need to draw larger circles, you can adjust the resolution using this command.(for ofCircle() method)
    
    ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void drawStar(float xpos, float ypos, float radius, int npts)
{
    bool getinto=false;
    ofBeginShape();
    for(int i=0; i<=360; i+=360/npts)
    {
        int r = getinto ? radius*.6 : radius;
        int x = xpos + cos( ofDegToRad(i) ) * r;
        int y = ypos + sin( ofDegToRad(i) ) * r;
        ofVertex(x, y);
        getinto = !getinto;
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient((-cos(time)+1)*100,  230);
//    ofBackgroundGradient( ofColor(255), ofColor(180), OF_GRADIENT_CIRCULAR);

    
    time = ofGetElapsedTimef();
    //slow motion time
//    time = ofGetElapsedTimef()/2;
    
    ofSetColor((sin(time)+1)*125);
    
    ofNoFill();
    
    //----------------------------------Circles----------------------------------
    //second hand
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+cos(time)*R, ofGetHeight()/2+sin(time)*R);
//    for(int i=0;i<10;i++){
//        int n = 16;
//        ofCircle(ofGetWidth()/2+cos(time)*R, ofGetHeight()/2+sin(time)*R, ofRandom(15,25)*cos(time+PI*i/n));
//    }
//    
//    //slow minute hand
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+cos(5*time)*R, ofGetHeight()/2+sin(5*time)*R);
//    for(int i=0;i<10;i++){
//        int n = 16;
//        ofCircle(ofGetWidth()/2+cos(5*time)*R, ofGetHeight()/2+sin(5*time)*R, ofRandom(15,25)*cos(5*time+PI*i/n));
//    }
    
    //crazy circle
    for(int i=0;i<10;i++){
        int n = 16;
        ofCircle(ofGetWidth()/2+cos(5*time)*R, ofGetHeight()/2+sin(time)*R, ofRandom(15,25)*cos(time+PI*i/n));
//        ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+cos(5*time)*R, ofGetHeight()/2+sin(time)*R);
    }
    for(int i=0;i<10;i++){
        int n = 16;
        ofCircle(ofGetWidth()/2+cos(time)*R, ofGetHeight()/2+sin(5*time)*R, ofRandom(15,25)*cos(time+PI*i/n));
//        ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2+cos(time)*R, ofGetHeight()/2+sin(5*time)*R);
    }

    //inner wave-
    for(int i=0;i<10;i++){
        int n = 64;
//        ofRotate(sin(time));
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100*cos(time+PI*i/n));
    }
    for(int i=10;i>0;i--){
        int n = 512;
//        ofRotate(sin(time));
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100*cos(time+PI*i/n));
    }
    for(int i=0;i<10;i++){
        int n = 64;
//        ofRotate(sin(time));
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100*cos(time+PI*i/n));
    }
    
    //outer wave
    for(int i=0;i<10;i++){
        int n = 1280;
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, R*cos(time+PI*i/n));
    }
    for(int i=10;i>0;i--){
        int n = 32;
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, R*cos(time+PI*i/n));
    }
    for(int i=0;i<10;i++){
        int n = 1280;
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, R*cos(time+PI*i/n));
    }
    
    //spreading wave
    for(int i=0;i<10;i++){
        int n = 1280;
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, R*tan((time+PI*i/n)/2));
    }
    for(int i=10;i>0;i--){
        int n = 32;
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, R*tan((time+PI*i/n)/2));
    }
    
    //----------------------------------Stars----------------------------------
    for(int i=0;i<10;i++){
        int n = 1280;
//        ofRotateZ(time);
        drawStar(ofGetWidth()/2, ofGetHeight()/2, R*cos(time+PI*i/n), 10);//10*abs(cos(time+PI*i/n))
    }
    for(int i=10;i>0;i--){
        int n = 32;
//        ofRotate(ofGetFrameNum() * .01, 0, 0, 1);//ofGetFrameNum returns the current frame as an int, counting up to (depending on your system) 2147483647 before rolling over back to 0.
        drawStar(ofGetWidth()/2, ofGetHeight()/2, R*cos(time+PI*i/n), 10);//*ofRandom(0.1, 1)
    }
    for(int i=0;i<10;i++){
        int n = 1280;
        drawStar(ofGetWidth()/2, ofGetHeight()/2, R*cos(time+PI*i/n), 10);
    }
    
    //----------------------------------Ellipse----------------------------------
//    for(int i=0;i<10;i++){
//        int n = 256;
//        ofEllipse(ofGetWidth()/2, ofGetHeight()/2, 1*R*cos(time+PI*i/n), 3*R*cos(time+PI*i/n));
//    }
//    for(int i=0;i<10;i++){
//        int n = 32;
//        ofEllipse(ofGetWidth()/2, ofGetHeight()/2, 1*R*cos(time+PI*i/n), 3*R*cos(time+PI*i/n));
//    }
//    
//    
//    for(int i=0;i<10;i++){
//        int n = 32;
//        ofEllipse(ofGetWidth()/2, ofGetHeight()/2, 3*R*cos(time+PI*i/n), R*cos(time+PI*i/n));
//    }
    
    
//    ofPushMatrix();
//    ofRotate(45);
//    ofTranslate(0, 0);
//    for(int i=0;i<10;i++){
//        int n = 256;
//        ofEllipse(ofGetWidth()/2, ofGetHeight()/2, 3*R*cos(time+PI*i/n), R*cos(time+PI*i/n));
//    }
//    ofPopMatrix();
//    ofPushMatrix();
//    ofRotate(45);
//    for(int i=0;i<10;i++){
//        int n = 256;
//        ofEllipse(ofGetWidth()/2, ofGetHeight()/2, 1*R*cos(time+PI*i/n), 3*R*cos(time+PI*i/n));
//    }
//    ofPopMatrix();

    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
