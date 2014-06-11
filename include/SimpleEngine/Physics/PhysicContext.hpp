#ifndef PhysicContext_hpp
#define PhysicContext_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Core/Context.hpp>
#include <SimpleEngine/Physics/PhysicBodyManager.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    class SE_API PhysicContext : public NonCopyable, public Context
    {
        public:
            PhysicContext();
            virtual ~PhysicContext();
            void addBodyToWorld(const std::string& bodyName, b2World& world, float x, float y);

            bool isValid() const;

            b2Body* getBody();

        private:
            b2Body* myBody;
            b2World* myWorld;
            bool valid;
    };
}
#endif // PhysicContext_hpp
