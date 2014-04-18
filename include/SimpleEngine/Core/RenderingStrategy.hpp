#ifndef RenderingStrategy_hpp
#define RenderingStrategy_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/Core/RenderingContext.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Rendering Strategy, interface that define an rendition algorithm
    /// for entities.
    ////////////////////////////////////////////////////////////
    class SE_API RenderingStrategy : public NonCopyable
    {
        public:

        /** \brief Abstract method for entities rendition.
         *
         * \param rc RenderingContext& current context.
         * \return virtual void
         *
         */
        virtual void render(RenderingContext& rc) = 0;
    };
}
#endif
