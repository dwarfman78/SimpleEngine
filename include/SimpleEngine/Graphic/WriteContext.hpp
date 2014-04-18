#ifndef WriteContext_hpp
#define WriteContext_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Core/Manager.hpp>
#include <SimpleEngine/Core/Context.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Write context, this class contains a text and a font.
    ////////////////////////////////////////////////////////////
    class SE_API WriteContext : public NonCopyable, public Context
    {
    public:
        /** \brief Constructor.
         *
         *
         */
        WriteContext();
        /** \brief Constructor.
         *
         * \param text const std::string& text content.
         * \param font const std::string& text font.
         *
         */
        WriteContext(const std::string& text, const std::string& font);

        ////////////////////////////////////////////////////////////
        /// Gettor settors
        ////////////////////////////////////////////////////////////
        sf::Text& getText();
        void setText(const std::string& text);
        void setFont(const std::string& font);
        bool isValid() const;
    private:
        /** Text **/
        sf::Text myText;

        /** Font **/
        sf::Font myFont;

        bool valid;

    };
}

#endif // WriteContext_hpp
