#ifndef AnimationStrategy_hpp
#define AnimationStrategy_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/Core/RenderingStrategy.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Animation strategy, this class defines rendering strategy
    /// for animated entities.
    ////////////////////////////////////////////////////////////
    class SE_API AnimationStrategy : public RenderingStrategy
    {
        public:

        /** \brief see RenderingStrategy
         *
         */
        virtual void render(RenderingContext& rc);
    };
}
#endif
