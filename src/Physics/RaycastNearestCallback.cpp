#include <SimpleEngine/Physics/RaycastNearestCallback.hpp>
namespace se
{
    RaycastNearestCallback::RaycastNearestCallback() : myBody(nullptr)
    {
    ;
    }

    float32 RaycastNearestCallback::ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction)
    {
        myBody = fixture->GetBody();
        myPoint = point;
        return fraction;
    }
}
