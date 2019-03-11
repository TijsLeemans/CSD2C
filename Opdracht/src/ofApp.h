#pragma once

#include "ofMain.h"
#include "ofxOsc.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
   void keyPressed(int key);

    ofImage image;
    ofxOscSender sender;

    float timeSent;


    double dual_h, dual_w;
    int mul;

    int count = 0;
    int x = 0;
    int y = 0;
    int w, h;
    int a = 0;
    int b = 0;
    int segment;
    int speed = 0;


    ofPixels pix;

  private:
    int port;

};
