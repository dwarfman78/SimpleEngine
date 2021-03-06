#ifndef Option_hpp
#define Option_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Interface representing an executable action on a menu.
    ////////////////////////////////////////////////////////////
    class SE_API Option
    {
        public:
        ////////////////////////////////////////////////////////////
        /// Execute action.
        ////////////////////////////////////////////////////////////
        virtual void execute() = 0;
    };
}
#endif
