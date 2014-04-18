#ifndef AnimationManager_hpp
#define AnimationManager_hpp
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/Singleton.hpp>
#include <SimpleEngine/Graphic/Animation.hpp>
#include <SimpleEngine/ToolBox/Logger.hpp>
#include <SimpleEngine/ToolBox/Utils.hpp>
namespace se
{
    class SE_API AnimationManager : public Singleton<AnimationManager>
    {
        friend class Singleton<AnimationManager>;

        public:
        ////////////////////////////////////////////////////////////
        /// Get the unique instance of the manager
        ////////////////////////////////////////////////////////////
        static AnimationManager* getInstance(){return Singleton<AnimationManager>::getInstance();}

        Animation& getAnimation(const std::string& name);

        private:
        AnimationManager();
        ////////////////////////////////////////////////////////////
        /// Private method for animation loading from xml file
        ////////////////////////////////////////////////////////////
        void loadAnimations(const pugi::xml_document& doc);

        std::map<std::string,Animation*> myAnimations;

        Animation defaultAnimation;

    };
}
#endif
