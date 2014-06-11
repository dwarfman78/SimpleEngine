#include <SimpleEngine/Physics/PhysicBodyManager.hpp>
namespace se
{
PhysicBodyManager::PhysicBodyManager()
{
    Logger log("PhysicBodyManager::PhysicBodyManager");

    log << "Trying to load physics config file : " + PHYSICS_CONF_FILE;

    pugi::xml_document doc;

    if(doc.load_file(PHYSICS_CONF_FILE.c_str()))
    {
        log << "Medias file successfully loaded, loading resources";

        // load resources from conf
        loadDefinitions(doc);
    }
    else
    {
        log << "Error, couldnt open physics config file : " + PHYSICS_CONF_FILE;
    }
}

void PhysicBodyManager::loadDefinitions(const pugi::xml_document& doc)
{
    Logger log("PhysicBodyManager::loadDefinitions");

    pugi::xml_node config = doc.child("physics").child("world");

    myGravity = config.attribute("gravity").as_float();

    log << "gravity : "<< myGravity;

    for (pugi::xml_node body = doc.child("physics").child("body"); body; body = body.next_sibling("body"))
    {
        //<body...

        log << "\t new body found ...";

        b2BodyDef bodyDef;

        std::string type = body.attribute("type").value();
        std::string name = body.attribute("name").value();

        log << "\t attributes : name -> " << name << " type -> " << type;

        if(type.compare("dynamic") == 0)
        {
            bodyDef.type = b2_dynamicBody;
        }

        //for(pugi::xml_node fixture = body.child("fixture"); fixture; fixture = body.next_sibling("fixture"))
        {
            pugi::xml_node fixture = body.child("fixture");

            b2FixtureDef fixtureDef;

            float density, friction, restitution = 0.0f;

            density = fixture.attribute("density").as_float();
            friction = fixture.attribute("friction").as_float();
            restitution = fixture.attribute("restitution").as_float();

            fixtureDef.density = density;
            fixtureDef.friction = friction;
            fixtureDef.restitution = restitution;

            log << "\t\t Fixture : density ->" << density << " friction -> " << friction << " restitution -> " << restitution;

            pugi::xml_node shape = fixture.child("shape");

            std::string shapeType = shape.attribute("type").value();

            if(shapeType.compare("box") == 0)
            {
                b2PolygonShape* boxShape = new b2PolygonShape();
                pugi::xml_node point = shape.child("point");

                float pX, pY = 0.0f;

                pX = Utils::pixelsToMeters(point.attribute("x").as_float())/2;
                pY = Utils::pixelsToMeters(point.attribute("y").as_float())/2;

                log << "\t\t\t Box : x -> " << pX << " y -> " << pY;

                boxShape->SetAsBox(pX,pY);

                fixtureDef.shape = boxShape;


                myBodyDef[name] = std::make_tuple(bodyDef,fixtureDef,boxShape);
            }

        }
    }
}
b2Body* PhysicBodyManager::addBodyToWorld(const std::string& name, b2World& world, float x, float y)
{
    b2Body* returnValue = nullptr;
    try
    {
        auto b2Tuple = myBodyDef.at(name);

        b2BodyDef bodyDef;
        b2FixtureDef fixtureDef;
        b2Shape* shapePtr;

        std::tie(bodyDef,fixtureDef,shapePtr) = b2Tuple;

        bodyDef.position = b2Vec2(x,y);

        returnValue = world.CreateBody(&bodyDef);

        returnValue->CreateFixture(&fixtureDef);
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }

    return returnValue;

}
}
