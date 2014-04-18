#include <SimpleEngine/Core/Event.hpp>
namespace se
{
    Event::Event(EventCode code) : myCode(code)
    {
        ;
    }
    Event::Event(const sf::Event& sfevent) : mySfEvent(sfevent), myCode(SF_EVENT)
    {
        ;
    }
    const sf::Event& Event::getSfEvent() const
    {
        return mySfEvent;
    }
    bool Event::isSfEvent() const
    {
        return myCode == SF_EVENT;
    }
}
