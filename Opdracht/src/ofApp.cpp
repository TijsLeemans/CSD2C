#include "ofApp.h"

//TODO //Set port number
port = ;

//--------------------------------------------------------------
void ofApp::setup(){

    //load image
    image.load("1.jpg");
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    image.resize(800, 600);

    sender.setup("localhost", port);

}

//--------------------------------------------------------------
void ofApp::update(){

    //osc-Stuff
    timeSent = ofGetElapsedTimef();

    //TODO //Create Osc opject and name it OutputMessage
    OutputMessage.setAddress("/time");
    OutputMessage.addTriggerArg();

    //gets Pixels from image (stored in an array)
    unsigned char * pixels = image.getPixels().getData();

    w = image.getWidth();
    h = image.getHeight();

    int red;
    int green;
    int blue;

    //for loop for upper pixel of rect
    for(int i = a; i < a + segment; i++){
        red = pixels[a];
        green = pixels[a+1];
        blue = pixels[a+2];
        //std::cout << "red " << red << " green " << green << " blue " << blue << std::endl;
        if( (red > 150 && green < 200 && blue < 200) && !(red == green) ){
            //std::cout << "red " << red << " green " << green << " blue " << blue << std::endl;

            //TODO //Send osc message
        }
        else{
            //for loop for lower pixel of rect
            for(int i = b; i < b + segment; i++){
                red = pixels[b];
                green = pixels[b+1];
                blue = pixels[b+2];
                if( (red > 150 && green < 200 && blue < 200) && !(red == green) ){
                    sender.sendMessage(OutputMessage);
                }
            }
        }
    }

    //make cursor jump from very right back to the left side


    // cursor backwards
    if(speed < 0){
        segment = -speed*3;

        //from up left to bottom right
        if(x <= 1 && y <= 1){
            x = w;
            y = h - 10;
            std::cout << "x y < 0" << std::endl;
        }

        //if y < 0 start from bottom, but keep x value
        if(y < 0){
            y = h - 10;
        }

        //jumps from bottom to top if y bigger then height
        if(y > (h - 10)){
            y = 0;
        }

        //from left to right in a row 10 pixels up
        if(x <= 1){
            y = y-10;
            x = w;
        }
    }

    //cursor forwards
    else{
        segment = speed * 3;

        //cursor jumps from right back to left, 10 pixels down
        if(x >= w){
            y = y+10;
            x =0;
            //a = a + (w * 10);
        }

        //makes cursor jump from bottom left to up right
        if(x >= w && y >= (h-10)){
            x = 0;
            y = 0;
        }

        //jumps from bottom to upper part
        if(y > (h - 10)){
            y = 0;
        }

        //jumps from upper part to buttom
        if(y < 0){
            y = h - 10;
        }

    }

    //controls speed (x) of cursor
    x = x + speed;

    //value of PixelArray: iterates over array in relation to cursor speed
    a = 3 * (x + w * y);
    b = 3 * (x + 10*w + w * y);

}

//--------------------------------------------------------------
void ofApp::draw(){

    //image
    image.draw(0, 0);

    ofFill();

    //cursor
    ofDrawRectangle(x, y, 2, 10);

}


void ofApp::keyPressed(int key) {

    if(key == OF_KEY_RIGHT) {
        speed = speed + 1;
    }
    if(key == OF_KEY_LEFT) {
        speed = speed - 1;
    }
    if(key == OF_KEY_DOWN) {
        y = y+10;
    }
    if(key == OF_KEY_UP) {
        y = y-10;
    }
    if(key == OF_KEY_TAB) {
        speed = 0;
    }
    if(key == 'l'){
        int l;
        y = y - 10;
    }
    if(key == '1') {
        speed = 1;
    }
    if(key == '2') {
        speed = 2;
    }
    if(key == '3') {
        speed = 3;
    }
    if(key == '4') {
        speed = 4;
    }
    if(key == '5') {
        speed = 5;
    }
    if(key == '5') {
        speed = 5;
    }
    if(key == '5') {
        speed = 5;
    }
    if(key == '6') {
        speed = 6;
    }
    if(key == '7') {
        speed = 7;
    }
    if(key == '8') {
        speed = 8;
    }

}
