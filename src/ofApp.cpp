#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i = 0; i < kStreamCount; i++) {
        streams[i].pitch = 220.0f + (i * 1000.0f / kStreamCount);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapStringHighlight("A number from 1 to " + ofToString(kStreamCount) + " to play a single stream, a to play all, 0 to stop all.", 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key >= '1' && key < '1' + kStreamCount)
    {
        int index = key - '1';
        for (int i = 0; i < kStreamCount; i++) {
            streams[i].stop();
        }
        streams[index].start();
    } else if (key == 'a') {
        for (int i = 0; i < kStreamCount; i++) {
            streams[i].start();
        }
    }
    else if (key == '0')
    {
        for (int i = 0; i < kStreamCount; i++) {
            streams[i].stop();
        }
    }
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
