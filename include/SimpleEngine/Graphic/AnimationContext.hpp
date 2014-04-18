#ifndef AnimationContext_hpp
#define AnimationContext_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Graphic/Animation.hpp>
#include <SimpleEngine/Graphic/AnimationManager.hpp>
#include <SimpleEngine/Core/Context.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Animation context, this class contains a reference to
    /// a managed animation (from ANIMATIONS_CONF_FILE).
    ////////////////////////////////////////////////////////////
    class SE_API AnimationContext : public NonCopyable, public Context
    {
        public:

        ////////////////////////////////////////////////////////////
        /// Default Constructor.
        ////////////////////////////////////////////////////////////
        AnimationContext();

        ////////////////////////////////////////////////////////////
        /// Constructor.
        /// \param animationName: animation's name according to ANIMATIONS_CONF_FILE
        ////////////////////////////////////////////////////////////
        AnimationContext(const std::string& animationName);

        ////////////////////////////////////////////////////////////
        /// Gettor settors
        ////////////////////////////////////////////////////////////
        const Animation& getAnimation() const;
        sf::Int32 getFrameTime() const;
        sf::Int32 getCurrentTime() const;
        sf::Clock& getClock();
        const sf::FloatRect& getFrame() const;
        std::vector<sf::FloatRect>::const_iterator& getFrameIterator();
        AnimationContext& setAnimation(const Animation& animation);
        ////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////
        /// Animation manipulation methods
        ////////////////////////////////////////////////////////////
        void initAnimation();
        void addToCurrentTime(sf::Int32 delta);
        void setCurrentTime(sf::Int32 time);
        ////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////
        /// \return false if the animation is the default animation (no frame)
        ////////////////////////////////////////////////////////////
        bool isValid() const;

        private:

        /** Reference to an animation, this could be
        the default animation leading to an invalid context **/
        const Animation* myAnimation;

        /** time duration of one frame **/
        sf::Int32 myFrameTime;

        /** Internal clock **/
        sf::Clock myClock;

        /** Current frame time **/
        sf::Int32 myCurrentTime;

        /** Current frame **/
        std::vector<sf::FloatRect>::const_iterator myFrame;

        /** Tells if context is initialized and ready or not **/
        bool valid;

    };
}
#endif
