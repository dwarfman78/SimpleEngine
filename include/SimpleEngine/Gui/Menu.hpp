#ifndef Menu_hpp
#define Menu_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/Gui/Option.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Class that represents a logical continuous (circular) menu.
    ////////////////////////////////////////////////////////////
    class SE_API Menu
    {
        public:
            ////////////////////////////////////////////////////////////
            /// Set the current selected option to the next in the list.
            /// if the current option is the last one before the call of scrollUp,
            /// the selected option after the call of the scrollUp method will be the
            /// first option of the menu.
            ////////////////////////////////////////////////////////////
            void scrollUp();
            ////////////////////////////////////////////////////////////
            /// Set the current selected option to the previous in the list.
            /// if the current option is the first before the call of scrollDown,
            /// the selected option after the call of the scrollDown method will be the
            /// last option of the menu.
            ////////////////////////////////////////////////////////////
            void scrollDown();
            ////////////////////////////////////////////////////////////
            /// Append an option at the end of the menu.
            ////////////////////////////////////////////////////////////
            void addOption(std::shared_ptr<Option> option);
            ////////////////////////////////////////////////////////////
            /// Remove an option from the menu.
            ////////////////////////////////////////////////////////////
            void removeOption(std::shared_ptr<Option> option);
            ////////////////////////////////////////////////////////////
            /// Get the current selected option of the menu.
            ////////////////////////////////////////////////////////////
            std::shared_ptr<Option> getCurrentOption();
            ////////////////////////////////////////////////////////////
            /// Remove all options from the menu.
            ////////////////////////////////////////////////////////////
            void clearOptions();
        private:
            std::set<std::shared_ptr<Option> > myOptions;
            std::set<std::shared_ptr<Option> >::iterator myCurrentOption;
    };
}
#endif
