#ifndef GeometricalContext_hpp
#define GeometricalContext_hpp
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
#include <SimpleEngine/Core/Context.hpp>
////////////////////////////////////////////////////////////
namespace se
{
    ////////////////////////////////////////////////////////////
    /// Geometrical context, this class contains information about the entity's geometric (position, scale ..)
    ////////////////////////////////////////////////////////////
    class SE_API GeometricalContext : public NonCopyable, public Context
    {
        public:

        /** \brief Constructor.
         *
         *
         */
        GeometricalContext();

        /** \brief Constructor
         *
         * \param pos const sf::Vector3f& position.
         * \param rotation const float rotation.
         *
         */
        GeometricalContext(const sf::Vector3f& pos, const float rotation);

        ////////////////////////////////////////////////////////////
        /// Gettors/Settors
        ////////////////////////////////////////////////////////////
        GeometricalContext& setRotation(const float rotation);
        float getRotation();
        GeometricalContext& setPosition(const sf::Vector3f& pos);
        sf::Vector3f& getPosition();
        sf::Vector2f& getScale();
        sf::Vector2f& getOrigin();
        GeometricalContext& setOrigin(float x, float y);
        ////////////////////////////////////////////////////////////

        bool isValid() const;

        private:

        /** Position **/
        sf::Vector3f myPosition;

        /** Rotation in degrees **/
        float myRotation;

        /** Scale **/
        sf::Vector2f myScale;

        /** Origine **/
        sf::Vector2f origin;

        /** Context validity **/
        bool valid;
    };
}
#endif
