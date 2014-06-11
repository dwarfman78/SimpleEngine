#ifndef PhysicBodyManager_hpp
#define PhysicBodyManager_hpp
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/Singleton.hpp>
#include <SimpleEngine/ToolBox/Logger.hpp>
#include <SimpleEngine/ToolBox/Utils.hpp>
namespace se
{
    class SE_API PhysicBodyManager : public Singleton<PhysicBodyManager>
    {
        friend class Singleton<PhysicBodyManager>;

        public:
        ////////////////////////////////////////////////////////////
        /// Get the unique instance of the manager
        ////////////////////////////////////////////////////////////
        static PhysicBodyManager* getInstance(){return Singleton<PhysicBodyManager>::getInstance();}

        ////////////////////////////////////////////////////////////
        /// Create a b2Body from a named body definition and adds it to the world.
        /// Might return nullptr if body definition does not exist.
        ////////////////////////////////////////////////////////////
        b2Body* addBodyToWorld(const std::string& name, b2World& world, float x, float y);

        ////////////////////////////////////////////////////////////
        /// Return gravity as configured in physics.xml world.
        ////////////////////////////////////////////////////////////
        float getGravity() const {return myGravity;};

        private:
        PhysicBodyManager();

        void loadDefinitions(const pugi::xml_document& doc);

        float myGravity;

        std::map<std::string, std::tuple<b2BodyDef,b2FixtureDef,b2Shape* > > myBodyDef;

    };
}
#endif
