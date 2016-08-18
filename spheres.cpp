//
//  spheres.cpp
//  CMA_LeapMotion01
//
//  Created by 矢頭　春香 on 2016/08/18.
//
//

#include "spheres.hpp"
void spheres::addsphere(){
    
    ofSpherePrimitive sphere;//key=='a'で追加してたのを関数で
    
    int x = ofRandom(-1000,1000);
    int y = ofRandom(-1000,1000);
    int z = ofRandom(-1000,1000);
    box.setPosition(x,y,z);
    
    //    ofPoint pos = ofPoint(x, y, z); //一旦、posに格納しておく
    //    box.setPosition(pos);
    
    
    box.set(100);
    
    boxes.push_back(box); //一時的に用意したボックスを、別の領域「box」に追加
    
    
}

void CustomBox::draw(){
    
    for(int i=0; i<boxes.size(); i++){
        boxes[i].draw(); //さっきdrawで書いてたやつ
        
    }
    
}