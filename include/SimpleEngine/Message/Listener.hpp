#ifndef Listener_hpp
#define Listener_hpp
#include <SimpleEngine/myImports.hpp>
namespace se
{
    class SE_API ListenerBase
    {
    };

    template <class MessageType>
    class SE_API Listener : public ListenerBase
    {
        public:

        virtual void notify(const MessageType& message) = 0;

    };
}
#endif
