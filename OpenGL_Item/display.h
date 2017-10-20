//
//  display.h
//  OpenGL_Item
//
//  Created by 杨清宇 on 2017/10/18.
//  Copyright © 2017年 Herbius. All rights reserved.
//

#ifndef display_h
#define display_h

#include "map.h"
#include "GLUT/GLUT.h"


class reveal: public map
{
private:

public:
    //绘制飞机函数
    void aniplane_draw(map x);
    void mainplane_draw(map x);
    
};

class interface
{
private:
    
public:
    GLuint LoadTexture(int width , int height);
    void background(GLuint texture);
    void start_scene();
};





#endif /* display_h */


