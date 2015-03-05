#include <SimpleEngine/Physics/PhysicStrategy.hpp>
namespace se
{
void PhysicStrategy::render(RenderingContext& rc)
{
    GeometricalContext& gc = rc.getGeometricalContext();
    PhysicContext& pc = rc.getPhysicContext();

    if(gc.isValid()&&pc.isValid())
    {
        b2Body *pBody = pc.getBody();
        b2Vec2 const &bodyPos = pBody->GetPosition();

        gc.getPosition().x = Utils::metersToPixels(bodyPos.x);
        gc.getPosition().y = Utils::metersToPixels(bodyPos.y);
        gc.setRotation(Utils::radsToDeg(pBody->GetAngle()));
    }
}

}
