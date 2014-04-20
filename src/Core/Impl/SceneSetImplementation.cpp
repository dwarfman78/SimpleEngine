#include <SimpleEngine/Core/Impl/SceneSetImplementation.hpp>
namespace se
{
SceneSetImplementation::SceneSetImplementation()
{
}
SceneSetImplementation::~SceneSetImplementation()
{
}
void SceneSetImplementation::registerRenderable(std::shared_ptr<Renderable> renderable)
{
    // Add a reference to a renderable
    myRenderables.insert(renderable);

}
void SceneSetImplementation::unregisterRenderable(std::shared_ptr<Renderable> renderable)
{
    myRenderables.erase(renderable);
}
void SceneSetImplementation::render()
{
    for(auto i : myRenderables)
    {
        // Render it
        if(!(i)->unregister())
            (i)->render();
    }
}
void SceneSetImplementation::cleanRenderables()
{
    for(std::set<std::shared_ptr<Renderable> >::iterator i = myRenderables.begin(); i!=myRenderables.end();)
    {
        if((*i)->unregister())
        {
            myRenderables.erase(*(i++));
        }
        else
        {
            ++i;
        }
    }
}
void SceneSetImplementation::renderLogic()
{
    for(auto i : myRenderables)
    {
        if(!(i)->unregister())
            (i)->renderLogic();
    }
}
void SceneSetImplementation::interpolate(const float interpolation)
{
    for(auto i : myRenderables)
    {
        if(!(i)->unregister())
            (i)->interpolate(interpolation);
    }
}
bool SceneSetImplementation::unregister() const
{
    return false;
}
}
