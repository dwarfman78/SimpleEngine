#ifndef Listener_hpp
#define Listener_hpp
////////////////////////////////////////////////////////////
/// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    class SE_API ListenerBase
    {
    };

    ////////////////////////////////////////////////////////////
    /// Listener interface for messaging system.
    ////////////////////////////////////////////////////////////
    template <class MessageType>
    class SE_API Listener : public ListenerBase
    {
        public:
        ////////////////////////////////////////////////////////////
        /// Method for message handling.
        ////////////////////////////////////////////////////////////
        virtual void notify(const MessageType& message) = 0;

    };
}
#endif
