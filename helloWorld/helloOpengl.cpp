#include <GL/freeglut.h>
#include <box2d/box2d.h>

b2Vec2 boxOrigin(5.0f, 8.0f);

void drawGround()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glRects(0,0,10,1);
}

void drawBox()
{
    float x = boxOrigin.x;
    float y = boxOrigin.y;
    glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(x-1,y-1,x+1,y+1);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawGround();
    drawBox();

    glutSwapBuffers();
}

void initGl()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPointSize(20.0);
    glLineWidth(2.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(100,100); 
    glutInitWindowSize(800, 800);
    glutCreateWindow("Box2D");

    initGl();
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

