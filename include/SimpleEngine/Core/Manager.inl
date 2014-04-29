template <class M, class R, const xmlTags::xmlTag xmlTag>
Manager<M,R,xmlTag>::Manager() : myXmlTag(xmlTag)
{
    Logger log("Manager::Manager");

    //log << "Trying to load medias config file : " + MEDIAS_CONF_FILE;

    pugi::xml_document doc;

    if(doc.load_file(MEDIAS_CONF_FILE.c_str()))
    {
        //log << "Medias file successfully loaded, loading resources";

        // load resources from conf
        loadResources(doc);
    }
    else
    {
        log << "Error, couldnt open medias config file : " + MEDIAS_CONF_FILE;
    }
}
template <class M, class R, const xmlTags::xmlTag xmlTag>
R Manager<M,R,xmlTag>::getResource(const std::string& resourceName) const
{
    //Logger log("Manager::getResource");

    //log << "trying to get resource : " + resourceName;

    R returnValue;
    // seek the internal map for key and value
    if(myResources.find(resourceName) != myResources.end())
    {
        //log << "resource found !";

        return R(myResources.find(resourceName)->second);
    }

    return returnValue;
}
template <class M, class R, const xmlTags::xmlTag xmlTag>
void Manager<M,R,xmlTag>::loadResources(const pugi::xml_document& doc)
{
        Logger log("Manager::loadResources");

        pugi::xml_node config = doc.child("medias");

        std::string xmlStringTag;

        switch(myXmlTag)
        {
            case xmlTags::IMAGE : xmlStringTag = "image"; break;
            case xmlTags::SOUND : xmlStringTag = "sound"; break;
            case xmlTags::FONT : xmlStringTag = "font"; break;
            default : xmlStringTag = "";
        }

        log << "loading xml tag : " + std::string(xmlStringTag);

        for (pugi::xml_node aValue = config.child(xmlStringTag.c_str()); aValue; aValue = aValue.next_sibling(xmlStringTag.c_str()))
        {// foreach <var ..

            M managed;
            // name = ""
            std::string name = aValue.attribute("name").value();

            // value = ""
            std::string value = aValue.attribute("value").value();

            log << "\t found : " + name + " == " + value;

            if(managed.loadFromFile(value))
            {
                log << "\t managed object successfully loaded";

                // store value
                myResources[name] = managed;
            }
            else
            {
                log << "\t cannot load managed object from file";
            }

            // .. />

        }
}

