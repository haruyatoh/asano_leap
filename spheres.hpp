//
//  spheres.hpp
//  CMA_LeapMotion01
//
//  Created by 矢頭　春香 on 2016/08/18.
//
//

#ifndef spheres_hpp
#define spheres_hpp

#include "ofMain.h" //ofMain.hを使いたい

class spheres{
public:
    void addsphere();
    void draw(); //draw宣言してdraw実装しますよ
private:
    vector<ofSpherePrimitive> spheres; //ボックス型が入るvectorを用意
};


#endif /* spheres_hpp */
