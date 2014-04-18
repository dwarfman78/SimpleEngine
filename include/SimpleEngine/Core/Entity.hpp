#ifndef Entity_hpp
#define Entity_hpp

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Core/RenderingContext.hpp>
#include <SimpleEngine/Core/Renderable.hpp>
#include <SimpleEngine/Graphic/DrawingStrategy.hpp>
#include <SimpleEngine/Graphic/WriteStrategy.hpp>
#include <SimpleEngine/Graphic/AnimationStrategy.hpp>
#include <SimpleEngine/Graphic/ParticleContext.hpp>
#include <SimpleEngine/Graphic/ParticleStrategy.hpp>
#include <SimpleEngine/Sound/SoundStrategy.hpp>
#include <SimpleEngine/Core/Manager.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Base Renderable class for rendering objects.
    /// This class is divided in two part :
    /// - Contextual part, which represents the object's current state
    /// - Strategy part, which defines how the object behave
    /// It provides method to enable behaviors (eg. makeDrawable)
    /// and to manipulate contexts indirectly.
    ////////////////////////////////////////////////////////////
    class SE_API Entity : public NonCopyable, public Renderable
    {
        friend class RenderingStrategy;

        public:

        Entity();

        virtual ~Entity();
        ////////////////////////////////////////////////////////////
        /// This method defines the drawing context's sprite according
        /// to its name.
        /// \param img : managed image to draw
        ////////////////////////////////////////////////////////////
        Entity& makeDrawable(const std::string& img);

        ////////////////////////////////////////////////////////////
        /// This method defines the animation's context according to
        /// its name.
        /// \param animationName : animation to start
        ////////////////////////////////////////////////////////////
        Entity& makeAnimable(const std::string& animationName);

        ////////////////////////////////////////////////////////////
        /// This method defines the write context according to
        /// a text.
        /// \param text : text to be displayed
        ////////////////////////////////////////////////////////////
        Entity& makeWritable(const std::string& text);

        ////////////////////////////////////////////////////////////
        /// This method defines the particle context and behavior
        ////////////////////////////////////////////////////////////
        Entity& makeParticle(std::function<void(RenderingContext&)> born, std::function<void(RenderingContext&)> live, std::function<void(RenderingContext&)> die);

        Entity& makeSound(const std::string& soundName);

        ////////////////////////////////////////////////////////////
        /// Defines the entity's position
        /// this method modifies the geometrical context.
        /// \param x : abs
        /// \param y : ord
        ////////////////////////////////////////////////////////////
        Entity& setPosition(float x, float y);

        ////////////////////////////////////////////////////////////
        /// Get the entity's position
        /// \return current position vector
        ////////////////////////////////////////////////////////////
        const sf::Vector3f& getPosition();

        ////////////////////////////////////////////////////////////
        /// Get the entity's sprite
        /// \return current sprite
        ////////////////////////////////////////////////////////////
        const sf::Sprite& getSprite();

        ////////////////////////////////////////////////////////////
        /// Get the entity's animation
        /// \return current animation
        ////////////////////////////////////////////////////////////
        const Animation& getAnimation();

        ////////////////////////////////////////////////////////////
        /// Set rotation
        /// \param rotation rotation angle in degrees.
        ////////////////////////////////////////////////////////////
        Entity& setRotation(float rotation);

        ////////////////////////////////////////////////////////////
        /// Set origin
        /// \param x : abs
        /// \param y : ord
        ////////////////////////////////////////////////////////////
        Entity& setOrigin(float x, float y);

        ////////////////////////////////////////////////////////////
        /// Set scale
        /// \param x : abs
        /// \param y : ord
        ////////////////////////////////////////////////////////////
        Entity& setScale(float x, float y);

        ////////////////////////////////////////////////////////////
        /// Set color
        /// \param color : color to set.
        ////////////////////////////////////////////////////////////
        Entity& setColor(const sf::Color& color);

        ////////////////////////////////////////////////////////////
        /// Get the object's current context
        /// This context can be modified (non const)
        ////////////////////////////////////////////////////////////
        RenderingContext& getContext();


        bool unregistered;

        protected:

        ////////////////////////////////////////////////////////////
        /// Render method implementation, because this object is a renderable
        /// it must implement the render method, basically this method calls
        /// each strategy's render method.
        ////////////////////////////////////////////////////////////
        virtual void render();

        ////////////////////////////////////////////////////////////
        /// Abstract method for game logic implementation
        ////////////////////////////////////////////////////////////
        virtual void renderLogic();

        ////////////////////////////////////////////////////////////
        /// Treat interpolation by defining this method
        ////////////////////////////////////////////////////////////
        virtual void interpolate(const float interpolation);

        virtual bool unregister() const;

        private:

        ////////////////////////////////////////////////////////////
        /// Rendering context, contains all the data needed for rendering
        /// this object.
        ////////////////////////////////////////////////////////////
        RenderingContext myContext;

        ////////////////////////////////////////////////////////////
        /// Rendering Strategies ...
        ////////////////////////////////////////////////////////////
        DrawingStrategy myDrawingStrategy;

        AnimationStrategy myAnimationStrategy;

        WriteStrategy myWriteStrategy;

        SoundStrategy mySoundStrategy;

        /////////////////////////////////////////////////////////////
        /// Particles
        /////////////////////////////////////////////////////////////
       // std::function<void(RenderingContext&)>& born;
        std::function<void(RenderingContext&)> live;
        std::function<void(RenderingContext&)> die;

        bool registered;

    };
}
#endif
