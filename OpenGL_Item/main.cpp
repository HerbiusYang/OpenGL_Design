//
//  main.cpp
//  OpenGL_Item
//
//  Created by 李磊 杨清宇 on 2017/9/7.
//  Copyright © 2017年 Herbius. All rights reserved.
//


/*  
 修复界面中飞机的速度
 修复了关于内存的浪费问题 
 添加了 关于敌对飞机的相关参数设置  
 */

#include <GLTools.h>
#include <GLUT/freeglut.h>
#include <GLShaderManager.h>
#include <GLUT/GLUT.h>
#include <iostream>
#include <GLTools.h>
#include <GLFrustum.h>
using namespace std;

#include "map.h"                                 //游戏界面
#include "display.h"
 
void display();                     
void init();
void timer(int);       
void key(unsigned char, int, int);              //游戏的判断是否终结函数
void keyup(unsigned char, int, int);
void reshape(int, int);



////设置mip贴图 部分
//void *gltReadTGABits(const char *FileName, GLint *iWidth, GLint *iHeight , GLint *iComponents ,GLenum *eFormat)
//{
//    FILE    *image;  //文件指针
//    TGAHEADER tgaHeader;
//    unsigned long lImageSize;
//    short sDepth;
//    GLbyte *pBits = NULL;
//
//
//    //设置默认的失败值
//    *iWidth = 0;
//    *iHeight = 0;
//    *eFormat = GL_RGB;
//    *iComponents = GL_RGB;
//
//
//    //尝试打开文件
//
//    image = fopen(FileName,"rb");
//    if(*image == NULL)
//        return NULL ;
//
//    //读入二进制文件头
//    fread(&tgaHeader , 18/* sizeof (TGAHEADER)*/, 1 , image);
//
//    //为大小字节存储顺序问题而进行字节交换
//
//#ifdef _Plane_
//    LITTLE_ENDIAN_WORD(&tgaHeader.colorMapStart);
//    LITTLE_ENDIAN_WORD(&tgaHeader.colorMapLength);
//    LITTLE_ENDIAN_WORD(&tgaHeader.xstart);
//    LITTLE_ENDIAN_WORD(&tgaHeader.width);
//    LITTLE_ENDIAN_WORD(&tgaHeader.height);
//#endif
//
//    *iWidth = tgaHeader.width;
//    *iHeight= tgaHeader.height;
//    sDepth  = tgaHeader.bits / 8;
//
//
//    //有效性检验  我们只关心8、24或32位的 targa
//
//    if(tgaHeader.bits!= 8 && tgaHeader.bits !=24 && tgaHeader.bits != 32)
//        return NULL;
//
//
//    //计算图像缓冲区的大小
//
//    lImageSize = tgaHeader.width * tgaHeader.height * sDepth;
//
//
//    //内存定位并进行成功检验
//
//    pBits - （GLbyte*）mallioc(lImageSize * sizeof(GLbyte));
//    if(pBits == NULL)
//        return NULL;
//
//
//    //读入位
//    //检查读取错误，这项操作应该发现RLE或者我们不想识别的奇怪格式
//
//    if(fread(pBits,lImageSize,1,image)!=1){
//        free(pBits);
//        return NULL;
//    }
//
//
//    switch(sDepth){
//        #ifndef OPENGL_ES
//            case 3: //最可能的情况
//                *eFormat = GL_BGR;
//                *iComponents = GL_RGB;
//                break;
//        #endif // OPENGL_ES
//
//        #ifndef WIN32
//            case 3: //最可能的情况
//                *eFormat = GL_BGR;
//                *iComponents = GL_RGB;
//                break;
//        #endif
//
//        #ifdef linux
//            case 3:
//                *eFormat = GL_BGR;
//                *iComponents = GL_RGBA;
//                break;
//        #endif
//
//            case 4:
//                *eFormat = GL_BGRA;
//                *iComponents = GL_RGBA;
//                break;
//            case 1:
//                *eFormat = GL_LUMINANCE;
//                *iComponents = GL_LUMINANCE;
//                break;
//            default:
//
//
//        #ifdef OPENGL_ES
//
//            for(int i =0; i<lImageSize; i+=3){
//                GLbyte temp = pBits[i];
//                pBits[i]    = pBits [i+2];
//                pBits[i+2]  = temp;
//            }//图像指针调整
//
//
//        #endif
//            break;
//    }
//
//    fclose(image);
//
//    return pBits;
//
//}
//
//


map m;
direction d = None;                             //键位的方向
interface i;

bool use = false;

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);                                  //图形界面初始化函数调用 glut界面 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);          //用颜色和不同模式的混合

                                                            //选用GLUT_Double 是避免计算机将图形绘制的过程显示出来 完整的动画或者图形一次显示出来
                                                            //选用GLUT_Depth  是采用深度缓存模式来完成打飞机的图形内存管理
    glutInitWindowPosition(500, 50);
    glutInitWindowSize(600, 600);                           //位置与确定窗口的大小
    
    glutCreateWindow("PlaneWar");                           //创建一个 名字叫做PlaneWar的一个窗口
    i.start_scene();
    glutDisplayFunc(display);                               //注册一个display 的场景
    glutReshapeFunc(reshape);                               //将图标不随窗口的变换而变换
    glutKeyboardFunc(key);                                  //处理按键消息的一个函数
    glutKeyboardUpFunc(keyup);                              //实现键盘对于按键的连续处理
    init();
    glutTimerFunc(10, timer, 1);                            //glut中内含的时间计时器
    glutTimerFunc(500, timer, 2);
    glutTimerFunc(150, timer, 3);
    
    glutMainLoop();
    return 0;
}

void reshape(int w, int h)                                  //对于模型进行重塑
{
    glViewport(0, 0, w, h);                                 //打开一个窗口系统 
    glMatrixMode(GL_PROJECTION);                            //告诉计算机对于接下来的对于场景的控制
                                                            /* 
                                                               GL_PROJECTION 规定对于透视的相关函数
                                                               GL_MODLEVIEW  规定对于模型视景的操作
                                                               GL_TEXTURE    规定对于文理的相关操作
                                                            */


    glLoadIdentity();                                       //规定当前矩阵为单位矩阵
    gluOrtho2D(0, 5, 0, 8);                                 //定义的剪裁面
    
    glMatrixMode(GL_MODELVIEW);                             //矩阵堆栈转移到模型视景进行堆栈   
    glLoadIdentity();                                       //重塑当前模型的样子
}

void init()
{
    glClearColor(0, 0, 0, 0);                               //将清除颜色设置为黑色 这个是清除函数 
    glEnable(GL_DEPTH_TEST);                                // 启动深度测试 根据坐标的远近自动隐藏被遮住的图形
}

void timer(int v)
{
    if (v == 1) //map update
    {
        //while (use)
        //    continue;
        //use = true;
        m.update(d);                                        //
        m.check();                                          //
        //system("cls");    //too slow
        std::cout << "score : " << m.getScore() << std::endl;
        if (m.isOvered())
        exit(0);
        glutPostRedisplay();                                //设置回调接口
        glutTimerFunc(10, timer, 1);
        //use = false;
    }
    if (v == 2)  //add new plane
    {
        //while (use)
        //    continue;
        //use =  true;
        //m.addPlane();
        //m.addPlane();
        //m.fire();
        int num = m.getScore() / 10 + 1;
        if (num > 10)
        num = 5;
        
        for (int a = 0; a < num; a++)   //add planes
        m.addPlane();
        
        glutPostRedisplay();
        glutTimerFunc(500, timer, 2);
        //use = false;
    }
    if (v == 3)
    {
        m.fire();
        glutTimerFunc(150, timer, 3);
    }
}

void key(unsigned char c, int mx, int my)   //设置键位函数
{
    if (c == 'w')
    d = Forward;
    if (c == 'a')
    d = Left;
    if (c == 's')
    d = Back;
    if (c == 'd')
    d = Right;
    //m.move(d);
}

void keyup(unsigned char c, int x, int y)   //预防冲键函数
{
    unsigned nc;
    if (d == None)
    return;
    if (d == Forward)
    nc = 'w';
    if (d == Back)
    nc = 's';
    if (d == Left)
    nc = 'a';
    if (d == Right)
    nc = 'd';
    if (nc == c)
    d = None;
}

void display()   
                                                  //draw              planes : 50 * 80 ; fires : 10 * 10
{
    
    
    glColor3f(1, 0., 0);                    //设置颜色 之后这部分要更改
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);   //清楚颜色缓冲区 之后 深度缓存区也要清除

    reveal p;
    p.aniplane_draw(m);
    
    glColor3f(0, 1, 0);
    for (auto x : m.fires)   //draw fires
    {
        if (x.visible)
        {
            glBegin(GL_QUADS);
            glVertex2f(x.getLeft() / 100, x.getTop() / 100);
            glVertex2f(x.getLeft() / 100, x.getBottom() / 100);
            glVertex2f(x.getRight() / 100, x.getTop() / 100);
            glVertex2f(x.getRight() / 100, x.getBottom() / 100);
            glEnd();
            glFlush();
        }
    }
    
    glColor3f(0, 0, 1);
    
    p.mainplane_draw(m);
    
    glutSwapBuffers();  //深度缓存函数
    
}




