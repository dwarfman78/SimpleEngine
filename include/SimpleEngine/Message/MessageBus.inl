template <class MessageType>
void MessageBus::listen(std::shared_ptr<Listener<MessageType> > listener)
{
    std::type_index type = std::type_index(typeid(MessageType));
    myBus[type].insert(listener);
}
template <class MessageType>
void MessageBus::notify(const MessageType& message)
{
    try
    {
        auto listListener = myBus.at(std::type_index(typeid(MessageType)));

        for(auto& listener : listListener)
        {
            (std::static_pointer_cast<Listener<MessageType> >(listener))->notify(message);
        }
    }
    catch (const std::out_of_range& oor)
    {
    }
}
