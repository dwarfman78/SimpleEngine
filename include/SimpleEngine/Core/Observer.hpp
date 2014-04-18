#ifndef Observer_h
#define Observer_h

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/Core/Event.hpp>
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Abstract class for notifiable elements
    ////////////////////////////////////////////////////////////
    class SE_API Observer
    {
        public:

        ////////////////////////////////////////////////////////////
        /// User defined method for event handling
        ////////////////////////////////////////////////////////////
        virtual void notify(const Event& e) = 0;
    };
}
#endif
