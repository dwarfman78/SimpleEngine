#include <SimpleEngine/ToolBox/Config.hpp>
using namespace std;
namespace se
{
    Config::Config()
    {
        Logger log("Config::Config");

        log << "Trying to load config file : " + GENERAL_CONF_FILE;

        pugi::xml_document doc;

        if(doc.load_file(GENERAL_CONF_FILE.c_str()))
        {
            log << "Config file successfully loaded, parsing vars ...";

            //load variables from xml file
            loadVars(doc);
        }
        else
        {
            log << "Error, couldnt open config file : " + GENERAL_CONF_FILE;
        }
    }
    void Config::loadVars(const pugi::xml_document& doc)
    {
        Logger log("Config::loadVars");

        log << "parsing vars : ";

        pugi::xml_node config = doc.child("config");

        for (pugi::xml_node aValue = config.child("var"); aValue; aValue = aValue.next_sibling("var"))
        {// foreach <var ..

            // name = ""
            string name = aValue.attribute("name").value();

            // value = ""
            string value = aValue.attribute("value").value();

            // store value
            myVars[name] = value;

            // .. />

            // do some logging
            log << "\t found : " + name + " == " + aValue.attribute("value").value();
        }
    }
}
