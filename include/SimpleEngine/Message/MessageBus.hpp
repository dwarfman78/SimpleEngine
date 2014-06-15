#ifndef MessageBus_hpp
#define MessageBus_hpp
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/Singleton.hpp>
#include <SimpleEngine/Message/Listener.hpp>
namespace se
{
    class SE_API MessageBus : public Singleton<MessageBus>
    {
        friend class Singleton<MessageBus>;

        public:
        static MessageBus* getInstance(){return Singleton<MessageBus>::getInstance();};

        template <class MessageType>
        void listen(std::shared_ptr<Listener<MessageType> > listener);

        template <class MessageType>
        void notify(const MessageType& message);

        private:
        std::unordered_map<std::type_index, std::set<std::shared_ptr<ListenerBase> > > myBus;
    };
    #include <SimpleEngine/Message/MessageBus.inl>
}
#endif
