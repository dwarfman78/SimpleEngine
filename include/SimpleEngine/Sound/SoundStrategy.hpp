#ifndef SoundStrategy_hpp
#define SoundStrategy_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/Core/RenderingStrategy.hpp>
#include <SimpleEngine/Graphic/GraphicEngine.hpp>
////////////////////////////////////////////////////////////
namespace se
{
////////////////////////////////////////////////////////////
/// Drawing strategy, this class defines rendering strategy
/// for sound entities.
////////////////////////////////////////////////////////////
class SE_API SoundStrategy : public RenderingStrategy
{
public:

    /** \brief see RenderingStrategy
     *
     */
    virtual void render(RenderingContext& rc);
};
}
#endif // SoundStrategy_hpp
