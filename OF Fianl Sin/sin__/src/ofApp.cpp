#include "ofApp.h"
#include<stdlib.h>

#define NX 500
#define NY 500
#define SCALE (NX / 6)

#define sign(x) ((x > 0) ? 1 : ((x < 0) ? -1 : 0))

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofToggleFullscreen();
    
    amplitude = 200;
    ofSetBackgroundAuto(true);
    pointX,pointY =0;
    easing = 0.01;
    targetX = ofGetWidth();
    targetY = ofGetHeight();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef();
    cose = cos(time)*amplitude;
    sine = sin(time)*amplitude;
    
    centerX = ofGetWidth()/2;
    centerY = ofGetHeight()/2;
    period = 50;
    
    diam = ofMap(sine, -amplitude, amplitude, 1, 500);
    
    pointX += (targetX-pointX)*easing;
    pointY += (targetY-pointY)*easing;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofLine(centerX, centerY, cose + centerX, sine + centerY);
//    ofCircle(period * time, sine+centerY, 10);
    
//    ofTranslate(centerX, centerY);
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofRotate(sine);
//    ofRect(0, 0, 200, 200);
    
//    ofCircle(centerX, centerY, diam);
    
//    ofCircle(pointX, pointY, 10);
    
    ofBackgroundGradient(0, 155*abs(sin(ofGetElapsedTimef()/2)));
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(200, 200, 200);
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));

    x0,y0,x1,y1=0;
    
//-----------------Clifford Attractors Graphics-----------------------
//    xn+1 = sin(a yn) + c cos(a xn)
//    yn+1 = sin(b xn) + d cos(b yn)
//-----------------Clifford Attractors Graphics-----------------------
    
//    a = -1.8;
//    b = -2.0;
//    c = -0.5+sin(ofGetElapsedTimef());
//    d = -0.9;
//    
//    int n=100000;
//    for(int i =0;i<n;i++){
//        x1 = sin(a*y0)+c*cos(a*x0);
//        y1 = sin(b*x0)+d*cos(b*y0);
//        
//        ofLine(x1-0.01, y1, x1, y1+0.01);
//        
//        x0=x1;
//        y0=y1;
//    }
    
//-----------------Clifford Attractors Graphics-----------------------
    
//---------------Peter de Jong Attractors Graphics--------------------
//    xn+1 = sin(a yn) - cos(b xn)
//    yn+1 = sin(c xn) - cos(d yn)
//---------------Peter de Jong Attractors Graphics--------------------
    
//    a=-1.5+tan(sin(ofGetElapsedTimef()));
//    b=1.3;
//    c=2.4;
//    d=2.15+tan(sin(ofGetElapsedTimef()));
//    
//    a = 1.4+tan(sin(ofGetElapsedTimef())), b = -2.3, c = 2.4, d = -2.1;
//    int n=100000;
//    for(int i =0;i<n;i++){
//        x1 = sin(a*y0)-cos(b*x0);
//        y1 = sin(c*x0)-cos(d*y0);
//        
//        ofLine(x1-0.01, y1, x1, y1+0.01);
//        
//        x0=x1;
//        y0=y1;
//    }

//---------------Peter de Jong Attractors Graphics--------------------
    
    
    
//--------------------Johnny Svensson Graphics------------------------
//    xn+1 = d sin(a xn) - sin(b yn)
//    yn+1 = c cos(a xn) + cos(b yn)
//--------------------Johnny Svensson Graphics------------------------
//    a = 3.40+tan(sin(ofGetElapsedTimef()));
//    b = -2.56;
//    c = 1.40*sin(ofGetElapsedTimef());
//    d = -1.96;
//    
////    ofScale(100, 100);//meteor shower
//    int n=100000;
//    for(int i =0;i<n;i++){
//        x1 = d*sin(a*x0)-sin(b*y0);
//        y1 = c*cos(a*x0)+cos(b*y0);
//        
//        ofLine(x1-0.01, y1, x1, y1+0.01);
//        
//        x0=x1;
//        y0=y1;
//    }
    
//--------------------Johnny Svensson Graphics------------------------

//-----------------------Paul Bourke Graphics-------------------------
//    xn+1 = yn - sign(xn) | b xn - c |1/2
//    yn+1 = a - xn
//-----------------------Paul Bourke Graphics-------------------------
    
    
    
    
    
    int n=10000;
    
    a = -0.4+sin(ofGetElapsedTimef()/4), b = -0.6+cos(ofGetElapsedTimef()/4), c = 0, d=0.2;
    for(int i =0;i<n;i++){
        x1 = y0 + sign(x0)*sqrt(abs(b*x0-c));
        y1 = a*cos(y0) - x0;
        
        ofLine(x1-0.01, y1, x1, y1+0.01);
        
        x0=x1;
        y0=y1;
    }
    
    a = -0.4+sin(ofGetElapsedTimef()/4), b = 0.6+cos(ofGetElapsedTimef()/4), c = 0, d=0.2;
    
    for(int i =0;i<n;i++){
        x1 = y0 + sign(x0)*sqrt(abs(b*x0-c));
        y1 = a*cos(y0) - x0;
        
        ofLine(x1-0.01, y1, x1, y1+0.01);
        
        x0=x1;
        y0=y1;
    }
    
    a = 0.3+sin(ofGetElapsedTimef()/4), b = 0+cos(ofGetElapsedTimef()/4), c = 0, d=0.2;
    
    for(int i =0;i<n;i++){
        x1 = y0 + sign(x0)*sqrt(abs(b*x0-c));
        y1 = a*cos(y0) - x0;
        
        ofLine(x1-0.01, y1, x1, y1+0.01);
        
        x0=x1;
        y0=y1;
    }
    
    a = 0.3+sin(ofGetElapsedTimef()/4), b = -0.7+cos(ofGetElapsedTimef()/4), c = 0, d=0.2;
    
    for(int i =0;i<n;i++){
        x1 = y0 + sign(x0)*sqrt(abs(b*x0-c));
        y1 = a*cos(y0) - x0;
        
        ofLine(x1-0.01, y1, x1, y1+0.01);
        
        x0=x1;
        y0=y1;
    }

    
    
    
    
    
    
//-----------------------Paul Bourke Graphics-------------------------


    
    
    
    
    
    
    
    
    
    
    
    
    
    
//!!!not finished yet!!!
//-----------------------Star Julia Graphics--------------------------
//zc = (1 +/- sqrt(1 - 4 * c)) / 2
//zc = (exp(i * n * w) +/- sqrt(exp(i * m * w ) - 4 * c)) / 2
//-----------------------Star Julia Graphics--------------------------
//    int type,s;
//    int ix,iy;
//    float x=0.5,y=0,x1,y1,xa,ya,r,w=0;
//    int n=100000;
//    for (int i=0;i<n;i++) {
//        if ((i % (n/10)) == 0)
//        switch (type) {
//            case 0:
//                xa = -4 * x + cos(4 * w);
//                ya = -4 * y + sin(4 * w);
//                break;
//            case 1:
//                xa = -4 * x + 1;
//                ya = -4 * y;
//                break;
//            case 2:
//                xa = -4 * x + cos(w);
//                ya = -4 * y + sin(w);
//                break;
//        }
//        r = sqrt(xa*xa + ya*ya);
//        w = atan2(ya,xa);
//        switch (type) {
//            case 0:
//                if (rand() % 2 == 0) {
//                    x1 = - cos(w) - sqrt(r) * cos(w/2) / 2;
//                    y1 = - sin(w) + sqrt(r) * sin(w/2) / 2;
//                } else {
//                    x1 = - cos(w) + sqrt(r) * cos(w/2) / 2;
//                    y1 = - sin(w) - sqrt(r) * sin(w/2) / 2;
//                }
//                break;
//            case 1:
//                s = 2 * (rand() % 2) - 1;
//                if (rand() % 2 == 0) {
//                    x1 = - s * cos(w) - sqrt(r) * cos(w/2) / 2;
//                    y1 =   s * sin(w) - sqrt(r) * sin(w/2) / 2;
//                } else {
//                    x1 = - s * cos(w) + sqrt(r) * cos(w/2) / 2;
//                    y1 =   s * sin(w) + sqrt(r) * sin(w/2) / 2;
//                }
//                break;
//            case 2:
//                if (rand() % 2 == 0) {
//                    x1 = - cos(2*w) - sqrt(r) * cos(w/2) / 2;
//                    y1 = - sin(2*w) + sqrt(r) * sin(w/2) / 2;
//                } else {
//                    x1 = - cos(2*w) + sqrt(r) * cos(w/2) / 2;
//                    y1 = - sin(2*w) - sqrt(r) * sin(w/2) / 2;
//                }
//        }
//        x = x1;
//        y = y1;
//        if (i < 100)
//            continue;
//        ix = x * SCALE + NX/2;
//        iy = y * SCALE + NY/2;
//        ofLine(NX, NY, ix, iy);
//    }
    
//-----------------------Star Julia Graphics--------------------------
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

//ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
void ofApp::windowResized(int w, int h){
    
}

//ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
void ofApp::gotMessage(ofMessage msg){
    
}

//ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}