#ifndef RaycastNearCallback_hpp
#define RaycastNearCallback_hpp
#include <SimpleEngine/myImports.hpp>
namespace se
{
class RaycastNearestCallback : public b2RayCastCallback
{
public:
    RaycastNearestCallback();

    float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction);

    b2Body* myBody;
    b2Vec2 myPoint;
};
}
#endif // RaycastNearCallback_hpp
