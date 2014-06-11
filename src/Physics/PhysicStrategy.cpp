#include <SimpleEngine/Physics/PhysicStrategy.hpp>
namespace se
{
void PhysicStrategy::render(RenderingContext& rc)
{
    GeometricalContext& gc = rc.getGeometricalContext();
    PhysicContext& pc = rc.getPhysicContext();

    if(gc.isValid()&&pc.isValid())
    {
        gc.getPosition().x = Utils::metersToPixels(pc.getBody()->GetPosition().x);
        gc.getPosition().y = Utils::metersToPixels(pc.getBody()->GetPosition().y);
        gc.setRotation(Utils::radsToDeg(pc.getBody()->GetAngle()));
    }
}

}
