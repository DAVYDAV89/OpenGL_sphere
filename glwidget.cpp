#include "glwidget.h"
#include <QDebug>
#include <GL/glut.h>

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    R = 1;
    X = 0;
    Y = 0;
    Z = 0;
    wired = false;

    ang = 0.5;

    connect(&timer, SIGNAL (timeout()), this, SLOT (updateGL()));
    timer.start(10);
}

void GLWidget::initializeGL()
{
//    qDebug() << __PRETTY_FUNCTION__;

    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
//    qDebug() << __PRETTY_FUNCTION__;

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5, 0,0,0, 0,1,0);

    ang += 0.5;

    glRotated(ang, X, Y, Z);

    glColor3f(1,0,0);
    if (wired)
        glutWireSphere(R,20,20);
    else
        glutSolidSphere(R,20,20);
}

void GLWidget::resizeGL(int w, int h)
{
//    qDebug() << __PRETTY_FUNCTION__;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w/h, 0.01, 100.0);

    updateGL();
}
