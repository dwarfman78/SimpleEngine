#ifndef Config_h
#define Config_h

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/Singleton.hpp>
#include <SimpleEngine/ToolBox/Logger.hpp>
////////////////////////////////////////////////////////////
/// Class for GENERAL_CONF_FILE parsing and access
/// ex:
/// <config>
///	<var name="float1" value="355.2"/>
///	<var name="bool1" value="1"/>
///	<var name="string1" value="test string"/>
///	<var name="bool2" value="0"/>
/// </config>
////////////////////////////////////////////////////////////
namespace se
{
    class SE_API Config : public Singleton<Config>
    {
        friend class Singleton<Config>;

        private:

        ////////////////////////////////////////////////////////////
        /// Constructor
        /// \brief Load data from GENERAL_CONFIG_FILE xml file.
        ////////////////////////////////////////////////////////////
        Config();

        public:

        ////////////////////////////////////////////////////////////
        /// Retrieve a var by its name
        /// \param  name    var name
        /// \param  out     var value
        /// \return         True if var is found and type is correct
        ////////////////////////////////////////////////////////////
        template <typename T>
        bool     get(const std::string& name, T& out)    const;

        private:
        ////////////////////////////////////////////////////////////
        /// Private datas
        ////////////////////////////////////////////////////////////
        std::map<std::string, std::string>  myVars;

        ////////////////////////////////////////////////////////////
        /// Private methods for data loading
        ////////////////////////////////////////////////////////////
        void    loadVars(const pugi::xml_document& result);
    };
    #include <SimpleEngine/ToolBox/Config.inl>
}
#endif
