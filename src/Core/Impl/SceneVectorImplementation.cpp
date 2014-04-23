#include <SimpleEngine/Core/Impl/SceneVectorImplementation.hpp>
namespace se
{
SceneVectorImplementation::SceneVectorImplementation()
{
}
SceneVectorImplementation::~SceneVectorImplementation()
{
}
void SceneVectorImplementation::registerRenderable(std::shared_ptr<Renderable> renderable)
{
    // Add a reference to a renderable
    myRenderables.push_back(renderable);

}
void SceneVectorImplementation::unregisterRenderable(std::shared_ptr<Renderable> renderable)
{
}
void SceneVectorImplementation::render()
{
    for(auto i : myRenderables)
    {
        // Render it
        if(!(i)->unregister())
            (i)->render();
    }
}
void SceneVectorImplementation::cleanRenderables()
{
    for(std::vector<std::shared_ptr<Renderable> >::iterator i = myRenderables.begin(); i!=myRenderables.end();)
    {
        if((*i)->unregister())
        {
            myRenderables.erase((i++));
        }
        else
        {
            ++i;
        }
    }
}
void SceneVectorImplementation::renderLogic()
{
    for(auto i : myRenderables)
    {
        if(!(i)->unregister())
            (i)->renderLogic();
    }
}
void SceneVectorImplementation::interpolate(const float interpolation)
{
    for(auto i : myRenderables)
    {
        if(!(i)->unregister())
            (i)->interpolate(interpolation);
    }
}
bool SceneVectorImplementation::unregister() const
{
    return false;
}
}

