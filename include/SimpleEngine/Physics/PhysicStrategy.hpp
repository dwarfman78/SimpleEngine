#ifndef PhysicStrategy_hpp
#define PhysicStrategy_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/Core/RenderingStrategy.hpp>
////////////////////////////////////////////////////////////
namespace se
{
class SE_API PhysicStrategy : public RenderingStrategy
{
public:
    /** \brief see RenderingStrategy
    *
    */
    virtual void render(RenderingContext& rc);
};
}
#endif // PhysicStrategy_hpp
