#include <SimpleEngine/Gui/Menu.hpp>
namespace se
{
void Menu::scrollUp()
{
    if(myOptions.size()!=0)
    {
        myCurrentOption++;

        if(myCurrentOption == myOptions.end())
        {
            myCurrentOption = myOptions.begin();
        }
    }
}
void Menu::scrollDown()
{
    if(myOptions.size()!=0)
    {
        if(myCurrentOption==myOptions.begin())
        {
            myCurrentOption = myOptions.end();
        }
        myCurrentOption--;
    }
}
void Menu::addOption(std::shared_ptr<Option> option)
{
    myOptions.insert(option);
    if(myOptions.size() == 1)
        myCurrentOption = myOptions.begin();
}
void Menu::removeOption(std::shared_ptr<Option> option)
{
    if(option == getCurrentOption())
    {
        myCurrentOption = myOptions.begin();
    }
    myOptions.erase(option);
    if(myOptions.size()==0)
        myCurrentOption = myOptions.end();
}
void Menu::clearOptions()
{
    while(myOptions.size()>0)
    {
        removeOption(getCurrentOption());
    }
}
std::shared_ptr<Option> Menu::getCurrentOption()
{
    return *myCurrentOption;
}
}
