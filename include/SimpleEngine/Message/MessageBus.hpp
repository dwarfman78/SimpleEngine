#ifndef MessageBus_hpp
#define MessageBus_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/Singleton.hpp>
#include <SimpleEngine/Message/Listener.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    
    ////////////////////////////////////////////////////////////
    /// Message bus for messaging system.
    /// Use this singleton class to both register listener 
    /// and publish messages.
    ////////////////////////////////////////////////////////////
    class SE_API MessageBus : public Singleton<MessageBus>
    {
        friend class Singleton<MessageBus>;

        public:
        static MessageBus* getInstance(){return Singleton<MessageBus>::getInstance();};
        
        ////////////////////////////////////////////////////////////
        /// Register a listener to the specified type of message.
        /// When a message of the specified type occurs, the notify 
        /// method of the listener is called with the current message
        /// provided as argument.
        ////////////////////////////////////////////////////////////
        template <class MessageType>
        void listen(std::shared_ptr<Listener<MessageType> > listener);
        
        ////////////////////////////////////////////////////////////
        /// Notify a message to listeners if any. Listeners are resolved
        /// using the declared message type from template argument.
        ////////////////////////////////////////////////////////////
        template <class MessageType>
        void notify(const MessageType& message);

        private:
        /**
         * Inner data structur
         * 
         */
        std::unordered_map<std::type_index, std::set<std::shared_ptr<ListenerBase> > > myBus;
    };
    #include <SimpleEngine/Message/MessageBus.inl>
}
#endif
