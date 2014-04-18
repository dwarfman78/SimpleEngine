#ifndef DrawingStrategy_hpp
#define DrawingStrategy_hpp
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
    /// for drawn entities.
    ////////////////////////////////////////////////////////////
    class SE_API DrawingStrategy : public RenderingStrategy
    {
      public:

      /** \brief see RenderingStrategy
       *
       */
      virtual void render(RenderingContext& rc);
    };
}
#endif
