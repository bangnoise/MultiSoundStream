#pragma once

#include "ofMain.h"

#define kStreamCount 3

class ofApp : public ofBaseApp{
public:
    class Output : public ofBaseSoundOutput {
    public:
        Output() : pitch(440.0f) {}
        void start() {
            bool result;
#if OF_VERSION_MINOR < 10
            stream.setOutput(this);
            result = stream.setup(2, 2, 48000, 128, 2));
#else
            ofSoundStreamSettings settings;
            settings.setOutListener(this);
            settings.numOutputChannels = 2;
            settings.numInputChannels = 2;
            settings.sampleRate = 48000;
            settings.bufferSize = 128;
            settings.numBuffers = 2;
            result = stream.setup(settings);
#endif
            if (!result)
            {
                ofLogError("error in ofSoundStream::setup()");
            }
        }
        void stop() {
            stream.close();
        }
        float pitch;
        void audioOut(ofSoundBuffer& buffer) override {
            buffer.fillWithTone(pitch);
        }
    private:
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
