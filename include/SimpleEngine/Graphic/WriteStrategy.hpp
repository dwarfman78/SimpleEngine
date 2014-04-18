#ifndef WriteStrategy_hpp
#define WriteStrategy_hpp
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/Core/RenderingStrategy.hpp>
#include <SimpleEngine/Graphic/GraphicEngine.hpp>
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Write strategy, this class defines rendering strategy
    /// for text entities.
    ////////////////////////////////////////////////////////////
    class WriteStrategy : public RenderingStrategy
    {
        public:
        /** @brief see RenderingStrategy
          *
          */
        void render(RenderingContext& rc);

    };
}
#endif // WriteStrategy
