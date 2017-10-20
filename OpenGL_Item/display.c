//
//  display.c
//  OpenGL_Item
//
//  Created by 杨清宇 on 2017/10/18.
//  Copyright © 2017年 Herbius. All rights reserved.
//

#include "display.h"
#include <iostream>
using namespace std;
#include "map.h"
#include <GLUT/GLUT.h>



void reveal::aniplane_draw(map m)
{
    for( auto x: m.aniPlanes)
    {
        if(x.visible)
        {
            glLineWidth(1);
            GLfloat Toptiphead_x = (x.getLeft() + x.getRight()) /200  ;
            GLfloat Toptiphead_y =  x.getTop()/50 ;
            
            GLfloat Toptiptail_x = (x.getLeft()+x.getRight()) /200  ;
            GLfloat Toptiptail_y =  Toptiphead_y + 0.1;
            
            //第一部分完成
            GLfloat planehead_leftx = Toptiptail_x + 0.05 ;
            GLfloat planehead_rightx= Toptiptail_x - 0.05 ;
            
            GLfloat planehead_lefty =  Toptiptail_y + 0.1;
            GLfloat planehead_righty=  Toptiptail_y + 0.1;
            //第二部分完成
            
            GLfloat planeneck_leftx = planehead_leftx;
            GLfloat planeneck_rightx= planehead_rightx;
            
            GLfloat planeneck_lefty = planehead_lefty  + 0.15;
            GLfloat planeneck_righty= planehead_righty + 0.15;
            
            //第三部分完成
            
            GLfloat planewings_leftx   = planeneck_leftx + 0.22;
            GLfloat planewings_rightx  = planeneck_rightx- 0.22;
            
            GLfloat planewings_lefty   = planeneck_lefty;
            GLfloat planewings_righty  = planeneck_righty;
            
            GLfloat planewingsDepth_leftx = planewings_leftx;
            GLfloat planewingsDepth_lefty = planewings_lefty + 0.18;
            
            GLfloat planewingsDepth_rightx= planewings_rightx;
            GLfloat planewingsDepth_righty= planewings_righty+ 0.18;
            
            GLfloat planewings_tail_leftx = planeneck_leftx ;
            GLfloat planewings_tail_lefty = planewingsDepth_lefty;
            GLfloat planewings_tail_rightx= planeneck_rightx;
            GLfloat planewings_tail_righty= planewingsDepth_righty;
            //第四部分完成
            
            GLfloat planetail_leftx = planewings_tail_leftx + 0.06;
            GLfloat planetail_lefty = planewings_tail_lefty + 0.1;
            
            GLfloat planetail_rightx= planewings_tail_rightx - 0.06;
            GLfloat planetail_righty= planewings_tail_righty + 0.1;
            
            glBegin(GL_LINE_LOOP);
            glVertex2f(planetail_leftx, planetail_lefty);
            glVertex2f(planewings_tail_leftx, planewings_tail_lefty);
            glVertex2f(planewingsDepth_leftx, planewingsDepth_lefty);
            glVertex2f(planewings_leftx, planewings_lefty);
            glVertex2f(planeneck_leftx, planeneck_lefty);
            glVertex2f(planehead_leftx, planehead_lefty);
            glVertex2f(Toptiptail_x, Toptiptail_y);
            glVertex2f(Toptiphead_x, Toptiphead_y);
            glVertex2f(Toptiptail_x, Toptiptail_y);
            glVertex2f(planehead_rightx, planehead_righty);
            glVertex2f(planeneck_rightx, planeneck_righty);
            glVertex2f(planewings_rightx, planewings_righty);
            glVertex2f(planewingsDepth_rightx, planewingsDepth_righty);
            glVertex2f(planewings_tail_rightx, planewings_tail_righty);
            glVertex2f(planetail_rightx, planetail_righty);
            glEnd();
            glFlush();
        }
    }
    
    //第五部分完成
    /*效果图
              |                   --  第一部分
             / \                  --  第二部分
            |   |                 --  第三部分
     - - - -     - - - -
     |                   |
     - - - -     - - - -          --  第四部分
          /_______\               --  第五部分
     
     
     */
    
    //    glColor3f(1, 0, 0);
    //    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //    for (auto x : m.aniPlanes)              //draw aniplanes
    //    {
    //        if (x.visible)
    //        {
    //            GLfloat p1x = x.getLeft() / 100;
    //            GLfloat p2x = x.getRight() / 100;
    //            GLfloat p3x = (x.getLeft() + x.getRight()) / 200;  //设置为他们的中点
    //            GLfloat p1y = x.getTop() / 100;
    //            GLfloat p2y = x.getTop() / 100;
    //            GLfloat p3y = x.getBottom() / 100;
    //            glBegin(GL_TRIANGLES);
    //            glVertex2f(p1x, p1y);
    //            glVertex2f(p2x, p2y);
    //            glVertex2f(p3x, p3y);
    //            glEnd();
    //            glFlush();
    //        }
    //    }
    
}


void reveal::mainplane_draw(map m)
{
    auto & x = m.mainPlane;
    
    GLfloat Toptip_headx = (x.getLeft() + x.getRight()) / 200 ;
    GLfloat Toptip_heady = x.getTop() / 100;
    GLfloat Toptip_tailx = Toptip_headx;
    GLfloat Toptip_taily = Toptip_heady + 0.1 ;
    //第一部分完成
    GLfloat planehead_leftx = Toptip_tailx + 0.05 ;
    GLfloat planehead_rightx= Toptip_tailx - 0.05 ;
    
    GLfloat planehead_lefty =  Toptip_taily - 0.1;
    GLfloat planehead_righty=  Toptip_taily - 0.1;
    //第二部分完成
    
    GLfloat planeneck_leftx = planehead_leftx;
    GLfloat planeneck_rightx= planehead_rightx;
    
    GLfloat planeneck_lefty = planehead_lefty  - 0.15;
    GLfloat planeneck_righty= planehead_righty - 0.15;
    
    //第三部分完成
    
    GLfloat planewings_leftx   = planeneck_leftx + 0.22;
    GLfloat planewings_rightx  = planeneck_rightx- 0.22;
    
    GLfloat planewings_lefty   = planeneck_lefty;
    GLfloat planewings_righty  = planeneck_righty;
    
    GLfloat planewingsDepth_leftx = planewings_leftx;
    GLfloat planewingsDepth_lefty = planewings_lefty - 0.18;
    
    GLfloat planewingsDepth_rightx= planewings_rightx;
    GLfloat planewingsDepth_righty= planewings_righty- 0.18;
    
    GLfloat planewings_tail_leftx = planeneck_leftx ;
    GLfloat planewings_tail_lefty = planewingsDepth_lefty;
    GLfloat planewings_tail_rightx= planeneck_rightx;
    GLfloat planewings_tail_righty= planewingsDepth_righty;
    //第四部分完成
    
    GLfloat planetail_leftx = planewings_tail_leftx + 0.06;
    GLfloat planetail_lefty = planewings_tail_lefty - 0.1;
    
    GLfloat planetail_rightx= planewings_tail_rightx - 0.06;
    GLfloat planetail_righty= planewings_tail_righty - 0.1;
    
    glBegin(GL_LINE_LOOP);
    glVertex2f(planetail_leftx, planetail_lefty);
    glVertex2f(planewings_tail_leftx, planewings_tail_lefty);
    glVertex2f(planewingsDepth_leftx, planewingsDepth_lefty);
    glVertex2f(planewings_leftx, planewings_lefty);
    glVertex2f(planeneck_leftx, planeneck_lefty);
    glVertex2f(planehead_leftx, planehead_lefty);
    glVertex2f(Toptip_tailx, Toptip_taily);
    glVertex2f(Toptip_headx, Toptip_heady);
    glVertex2f(Toptip_tailx, Toptip_taily);
    glVertex2f(planehead_rightx, planehead_righty);
    glVertex2f(planeneck_rightx, planeneck_righty);
    glVertex2f(planewings_rightx, planewings_righty);
    glVertex2f(planewingsDepth_rightx, planewingsDepth_righty);
    glVertex2f(planewings_tail_rightx, planewings_tail_righty);
    glVertex2f(planetail_rightx, planetail_righty);
    glEnd();
    glFlush();
    //
    //    glBegin(GL_TRIANGLES);
    //    glVertex2f(x.getLeft() / 100, x.getBottom() / 100);
    //    glVertex2f(x.getRight() / 100, x.getBottom() / 100);
    //    glVertex2f((x.getLeft() + x.getRight()) / 200, x.getTop() / 100);
    //    glEnd();
    //    glFlush();
    //
}




GLuint interface::LoadTexture(int width, int height)
{
    GLuint  texture ;

    //正整形纹理
    unsigned char *data;
    FILE *file;

    //读入背景文件
    file = fopen("../../Picture/background.bmp","rb");
    if(file==NULL){
        exit(0);
    }
    data = (unsigned char *)malloc(width * height * 3);
    fread(data , width * height * 3 , 1 , file);
    fclose (file);

    glGenTextures(1, &texture);
    //初始化纹理函数 将texture的数值 设定为1
    glBindTexture(GL_TEXTURE_2D, texture);                  //绑定可活动的纹理目标 texture是纹理对象
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);  //设定像素的界别函数  固定模式

    //线性滤图
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER , GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER , GL_LINEAR);   //设置贴图图片的参数属性   第一个参数是对象 第二个参数设置贴图的像素模式
    //第三个参数设置 纹理坐标如果接近多个不同颜色的坐标 那么将靠近这个颜色 的像素颜色加权求平均值

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);        //第二个参数表示在S方向上进行贴图
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);        //重复进行贴图

    //开始生成纹理
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

    free(data);
    return texture;
}


void interface::background(GLuint texture)
{
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex2d(-1.0, -1.0);
    glTexCoord2d(1.0, 0.0); glVertex2d(+1.0, -1.0);
    glTexCoord2d(1.0, 1.0); glVertex2d(+1.0, +1.0);
    glTexCoord2d(0.0, 1.0); glVertex2d(-1.0, +1.0);
    glEnd();
}


void interface::start_scene()
{
    glDisable(GL_DEPTH_TEST);
    glLoadIdentity();
    //导入纹理
    GLuint texture  =  LoadTexture(600 , 600);

    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glScalef(100, 100 , 0);
    glTranslatef(0, 0, -150);
    background(texture);                   //背景方块
    glPopMatrix();
}


