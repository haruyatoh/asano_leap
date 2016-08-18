#include "ofApp.h"

float circle_centerX;
float circle_centerY;
float circle_centerZ;
float formerX;
float formerY;
float formerZ;

bool ball_thrown;
int camera_mode;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    cam.setOrientation(ofPoint(0,0,0));
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    leap.open();
        
    ball_thrown = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    simpleHands = leap.getSimpleHands();
    if(leap.isFrameNew() && simpleHands.size()){
        fingerPos.clear();
        
        handPos.clear();
        
        leap.setMappingX(-230,230,-ofGetWidth()/2,ofGetWidth()/2);
        leap.setMappingY(90,490,-ofGetHeight()/2,ofGetHeight()/2);
        leap.setMappingZ(-150,150,-200,200);
        
        fingerType fingerTypes[] = {THUMB,INDEX,MIDDLE,RING,PINKY};
        
        
        for(int i = 0; i <simpleHands.size(); i++){
            handPos.push_back(simpleHands[i].handPos);
            for(int f=0; f<5; f++){
                ofPoint mcp = simpleHands[i].fingers[fingerTypes[f]].mcp;
                fingerPos.push_back(mcp);
                
                ofPoint pip = simpleHands[i].fingers[fingerTypes[f]].pip;
                fingerPos.push_back(pip);
                
                ofPoint dip = simpleHands[i].fingers[fingerTypes[f]].dip;
                fingerPos.push_back(dip);
                
                ofPoint tip = simpleHands[i].fingers[fingerTypes[f]].tip;
                fingerPos.push_back(tip);
                
                
            }
        }
        
        
        
        if(ball_thrown == false){
            if(ofDist(fingerPos.at(3).x,fingerPos.at(3).y,fingerPos.at(7).x,fingerPos.at(7).y)>150){
                    circle_centerZ = -3000;
                    ball_thrown = true;
            }else{
                circle_centerX = (fingerPos.at(3).x+fingerPos.at(7).x)/2;
                circle_centerY = (fingerPos.at(3).y+fingerPos.at(7).y)/2;
                circle_centerZ = (fingerPos.at(3).z+fingerPos.at(7).z)/2;
            }
            formerX = (fingerPos.at(3).x+fingerPos.at(7).x)/2;
            formerY = (fingerPos.at(3).y+fingerPos.at(7).y)/2;
            formerZ = (fingerPos.at(3).z+fingerPos.at(7).z)/2;
        }
        
        if(ball_thrown == true){
            circle_centerX  = formerX;
            circle_centerY =  formerY;
            time++;
            circle_centerZ =  - time*30;
            
//            cam.setPosition((handPos.at(0).x+handPos.at(1).x)/2, (handPos.at(0).y+handPos.at(1).y)/2, circle_centerZ+200);
            
            if(circle_centerZ < -3000){
                time =0;
                ball_thrown = false;
                circle_centerZ = 0;
            }

        }
        
    }
    
    leap.markFrameAsOld();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cout << circle_centerZ << endl;
    
        ofBackground(0);
    
    cam.begin();

    for(int i=0; i < simpleHands.size(); i++){
        
        for(int f=0; f<5; f++){
            ofSetColor(220);
            ofDrawSphere(fingerPos.at(20*i+4*f+0),10);
            
            ofSetColor(185);
            ofDrawSphere(fingerPos.at(20*i+4*f+1),10);
            
            ofSetColor(155);
            ofDrawSphere(fingerPos.at(20*i+4*f+2),10);
            
            ofSetColor(120);
            ofDrawSphere(fingerPos.at(20*i+4*f+3),10);
            
            ofLine(fingerPos.at(20*i+4*f+0),fingerPos.at(20*i+4*f+1));
            ofLine(fingerPos.at(20*i+4*f+1),fingerPos.at(20*i+4*f+2));
            ofLine(fingerPos.at(20*i+4*f+2),fingerPos.at(20*i+4*f+3));
            
            
        }
    }
    
        if(fingerPos.size() == 20){
        float distance = sqrt(pow(fingerPos.at(3).x-fingerPos.at(7).x,2)
                              +pow(fingerPos.at(3).y-fingerPos.at(7).y,2)
                              +pow(fingerPos.at(3).z-fingerPos.at(7).z,2));
            ofSetColor(ofColor::fromHsb(ofGetFrameNum()/10%255, 255, 255));
            ofFill();
        
        
            
        if(ball_thrown == false){
        ofDrawSphere((fingerPos.at(3).x+fingerPos.at(7).x)/2,
                     (fingerPos.at(3).y+fingerPos.at(7).y)/2,
                     (fingerPos.at(3).z+fingerPos.at(7).z)/2,
                     distance/4);
                     
            
        }else{
            ofDrawSphere(circle_centerX,circle_centerY, circle_centerZ,30);
        }
    }
    
    
    
    cam.end();
    ofDrawBitmapStringHighlight(ofToString(ball_thrown), 10,10);
    
    
    

}

//--------------------------------------------------------------
void ofApp::exit(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
    
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
