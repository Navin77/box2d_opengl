#include <iostream>
#include <box2d/box2d.h>

int main()
{
    b2World world(b2Vec2(0.0f, -10.0f));

    b2BodyDef groundDef;
    groundDef.position.Set(5.0f, 0.5f);
    b2Body* ground = world.CreateBody(&groundDef);
    b2PolygonShape groundShape;
    groundShape.SetAsBox(5.0f, 0.5f);
    ground->CreateFixture(&groundShape, 0.0f);

    b2BodyDef boxDef;
    boxDef.position.Set(5.0f, 8.0f);
    boxDef.type = b2_dynamicBody;
    b2Body* box = world.CreateBody(&boxDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(1.0f, 1.0f);
    box->CreateFixture(&boxShape, 1.0f);

    b2Vec2 pos;
    float angle;


    std::cout << "Box position and rotation\n";

    for (size_t i = 0; i < 5; i++)
    {
        world.Step(1.0f, 6, 2);

        pos = box->GetPosition();
        angle = box->GetAngle();

        printf("%4.3f %4.3f %4.3f\n", pos.x, pos.y, angle);
    }
    
    return 0;

}