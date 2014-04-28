#ifndef Menu_hpp
#define Menu_hpp
#include <SimpleEngine/Gui/Option.hpp>
namespace se
{
    class SE_API Menu
    {
        public:
            void scrollUp();
            void scrollDown();
            void addOption(std::shared_ptr<Option> option);
            void removeOption(std::shared_ptr<Option> option);
            std::shared_ptr<Option> getCurrentOption();
            void clearOptions();
        private:
            std::set<std::shared_ptr<Option> > myOptions;
            std::set<std::shared_ptr<Option> >::iterator myCurrentOption;
    };
}
#endif
