#pragma once

#include "ofMain.h"

#define kStreamCount 3

class ofApp : public ofBaseApp{
public:
    class Output : public ofBaseSoundOutput {
    public:
        Output() : pitch(440.0f) {}
        void start() {
            stream.setOutput(this);
            if (!stream.setup(2, 2, 48000, 128, 2))
            {
                ofLogError("error in ofSoundStream::setup()");
            }
        }
        void stop() {
            stream.close();
        }
        float pitch;
    private:
        void audioOut(ofSoundBuffer& buffer) override {
            buffer.fillWithTone(pitch);
        }
        ofSoundStream stream;
    };
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
    Output streams[kStreamCount];
};
