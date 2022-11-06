#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>

class GLWidget : public QGLWidget
{
    Q_OBJECT
    QTimer timer;

public:
    GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    int X, Y, Z, R;
    bool wired;
    float ang;

};

#endif // GLWIDGET_H
