#include <GL/freeglut.h>
#include <box2d/box2d.h>

b2World world(b2Vec2(0.0f, -10.0f));
b2Body *box;
bool play = false;

void drawGround()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glRects(0, 0, 10, 1);
}

void drawBox()
{
    float x = box->GetPosition().x;
    float y = box->GetPosition().y;
    glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(x - 1, y - 1, x + 1, y + 1);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGround();
    drawBox();

    if(play) world.Step(1.0f/30.0f, 6, 2);
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

void initBox2d()
{

    b2BodyDef groundDef;
    groundDef.position.Set(5.0f, 0.5f);
    b2Body *ground = world.CreateBody(&groundDef);
    b2PolygonShape groundShape;
    groundShape.SetAsBox(5.0f, 0.5f);
    ground->CreateFixture(&groundShape, 0.0f);

    b2BodyDef boxDef;
    boxDef.position.Set(5.0f, 8.0f);
    boxDef.type = b2_dynamicBody;
    box = world.CreateBody(&boxDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(1.0f, 1.0f);
    box->CreateFixture(&boxShape, 1.0f);
}

void onKeyPress(unsigned char key, int x, int y)
{
    if(key == 'p')
    {
        (play)? play = false : play = true;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Box2D");

    initGl();
    initBox2d();
    glutIdleFunc(display);
    glutKeyboardFunc(onKeyPress);

    glutMainLoop();

    return 0;
}