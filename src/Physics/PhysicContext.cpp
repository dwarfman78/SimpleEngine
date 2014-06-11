#include <SimpleEngine/Physics/PhysicContext.hpp>
namespace se
{
PhysicContext::PhysicContext() : valid(false), myWorld(nullptr), myBody(nullptr)
{
}
PhysicContext::~PhysicContext()
{
    if(myWorld!=nullptr&&myBody!=nullptr)
        myWorld->DestroyBody(myBody);
}

void PhysicContext::addBodyToWorld(const std::string& bodyName, b2World& world,float x, float y)
{
    myBody = PhysicBodyManager::getInstance()->addBodyToWorld(bodyName,world,Utils::pixelsToMeters(x),Utils::pixelsToMeters(y));

    myWorld = &world;

    valid = (myBody!=nullptr);
}

bool PhysicContext::isValid() const
{
    return valid;
}

b2Body* PhysicContext::getBody()
{
    return myBody;
}

}
