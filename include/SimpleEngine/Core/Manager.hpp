#ifndef Manager_h
#define Manager_h

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/Singleton.hpp>
#include <SimpleEngine/ToolBox/Logger.hpp>
#include <SimpleEngine/Graphic/GraphicEngine.hpp>
////////////////////////////////////////////////////////////

namespace se
{
    namespace xmlTags
    {
        enum xmlTag
        {
            IMAGE,
            SOUND,
            FONT,
        };
    }
    ////////////////////////////////////////////////////////////
    /// Class Manager.
    /// Template class for loading resources from MEDIAS_CONF_FILE
    /// M is the managed resource (eg:sf::Texture)
    /// R is the utility resource used by clients (eg:sf::Sprite)
    /// xmlTag is the appropriate tag in MEDIAS_CONF_FILE (eg:image)
    ////////////////////////////////////////////////////////////
    template <class M, class R, const xmlTags::xmlTag xmlTag>
    class SE_API Manager : public Singleton< Manager<M,R,xmlTag> >
    {
        friend class Singleton< Manager<M,R,xmlTag> >;

        public:

        ////////////////////////////////////////////////////////////
        /// Get the unique instance of the manager given these templates parameters
        ////////////////////////////////////////////////////////////
        static Manager<M,R,xmlTag>* getInstance(){return Singleton< Manager<M,R,xmlTag> >::getInstance();}

        ////////////////////////////////////////////////////////////
        /// Return a new instance of a light resource, given the name
        /// of the managed (heavy) resource.
        /// \param resourceName : name of the managed resource according to MEDIAS_CONF_FILE
        ////////////////////////////////////////////////////////////
        R getResource(const std::string& resourceName) const;

        ////////////////////////////////////////////////////////////
        /// Return the number of loaded resources from xml file.
        ////////////////////////////////////////////////////////////
        unsigned int getNbLoadedResources() const;

        private:

        Manager();

        ////////////////////////////////////////////////////////////
        /// Map that store managed resources
        ////////////////////////////////////////////////////////////
        std::map<std::string,M> myResources;

        ////////////////////////////////////////////////////////////
        /// Private method for resource loading from xml file
        ////////////////////////////////////////////////////////////
        void loadResources(const pugi::xml_document& doc);

        ////////////////////////////////////////////////////////////
        /// Stored xml enum value that identify the xml tag loaded (eg <image>)
        ////////////////////////////////////////////////////////////
        const xmlTags::xmlTag myXmlTag;
    };
    #include <SimpleEngine/Core/Manager.inl>
}
#endif
