#include <SimpleEngine/Graphic/WriteContext.hpp>
namespace se
{
    WriteContext::WriteContext() : valid(false)
    {
        ;
    }
    WriteContext::WriteContext(const std::string& text, const std::string& font) : valid(true)
    {
        myFont.loadFromFile(font);
        myText.setFont(myFont);
        setText(text);
    }

    sf::Text& WriteContext::getText()
    {
        return myText;
    }

    void WriteContext::setText(const std::string& text)
    {
        if(!valid)
        {
            myFont.loadFromFile("arial.ttf");
        }
        myText.setString(text);
        valid=true;
    }

    void WriteContext::setFont(const std::string& font)
    {
        myFont.loadFromFile(font);
        myText.setFont(myFont);
    }

    bool WriteContext::isValid() const
    {
        return valid;
    }
}
