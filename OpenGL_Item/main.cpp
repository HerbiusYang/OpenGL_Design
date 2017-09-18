//
//  main.cpp
//  OpenGL_Item
//
//  Created by 李磊 杨清宇 on 2017/9/7.
//  Copyright © 2017年 Herbius. All rights reserved.
//

//#include <iostream>
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//void Render(void)
//{
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_TRIANGLES);
//    {
//        glColor3f(1.0,0.0,0.0);
//        glVertex2f(0, .5);
//        glColor3f(0.0,1.0,0.0);
//        glVertex2f(-.5,-.5);
//        glColor3f(0.0, 0.0, 1.0);
//        glVertex2f(.5, -.5);
//    }
//    glEnd();
//}
//
//int main(int argc, const char * argv[]) {
//    GLFWwindow* win;
//    if(!glfwInit()){
//        return -1;
//    }
//    win = glfwCreateWindow(640, 480, "OpenGL Base Project", NULL, NULL);
//    if(!win)
//    {
//        glfwTerminate();
//        exit(EXIT_FAILURE);
//    }
//    if(!glewInit())
//    {
//        return -1;
//    }
//    glfwMakeContextCurrent(win);
//    while(!glfwWindowShouldClose(win)){
//        Render();
//        glfwSwapBuffers(win);
//        glfwPollEvents();
//    }
//    glfwTerminate();
//    exit(EXIT_SUCCESS);
//    return 0;
//}


#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUT/GLUT.h>
#include <math.h>
#include <time.h>


void myInit(){                           //初始化坐标系函数

    glClearColor(1.0, 1.0, 1.0, 0);      //设置背景颜色为亮白
    glColor3f(0.0f, 0.0f ,0.0f);         //设置绘图颜色为黑色
    glPointSize(4.0);                    //设置点的大小为4*4像素px
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);  //设置初始坐标系  大小为 640*480
}

//void display(void){
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_POINTS);
//        glVertex2i(100, 50);
//        glVertex2i(100, 130);
//        glVertex2i(150, 130);
//    glEnd();
//    glFlush();                           //送出所有输出到设备
//}

void sierpinski_render(void){

    glClear(GL_COLOR_BUFFER_BIT);         //清屏
    GlintPoint T[3]={{10,10},{600,10},{600,600}};
    












}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("my first demo");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}





