#ifndef Utils_h
#define Utils_h
namespace se
{
class SE_API Utils
{
private:
    Utils();

public:

    template <typename T>
    static std::string toString(const T& in)
    {
        // utiliser un flux de sortie pour cr�er la cha�ne
        std::ostringstream oss;
        // �crire la valeur dans le flux
        oss << in;
        // renvoyer une string
        return oss.str();
    }
    static bool equals(const std::string& s1, const std::string& s2)
    {
        return (s1.compare(s2)==0);
    }
    static float norm(const sf::Vector2f& v)
    {
        return sqrt(v.x * v.x + v.y * v.y);
    }
    static float det(const sf::Vector2f v1, const sf::Vector2f& v2)
    {
        return v1.x*v2.y-v1.y*v2.x;
    }
    static float radsToDeg(float rads)
    {
        return rads * RADS_TO_DEG_RATIO;
    }
    static float degToRads(float deg)
    {
        return deg * 1/RADS_TO_DEG_RATIO;
    }
    static float getOrientedAngle(const sf::Vector2f& v1, const sf::Vector2f& v2)
    {
        double nV1 = se::Utils::norm(v1);
        double nV2 = se::Utils::norm(v2);

        return (acos((v1.x*v2.x+v1.y*v2.y)/(nV1*nV2)));
    }
    static sf::Vector2f createFromPolar(float teta, float norm)
    {
        return sf::Vector2f(norm*cos(teta),norm*sin(teta));
    }
    static float metersToPixels(float meters)
    {
        return meters*15.0f;
    }
    static float pixelsToMeters(float pixels)
    {
        return pixels/15.0f;
    }
    static void applyBlastImpulse(b2Body* body, b2Vec2 blastCenter, b2Vec2 applyPoint, float blastPower)
    {
        //ignore the grenade itself, and any non-dynamic bodies
        if ( body->GetType() != b2_dynamicBody )
            return;
        b2Vec2 blastDir = applyPoint - blastCenter;
        float distance = blastDir.Normalize();
        //ignore bodies exactly at the blast point - blast direction is undefined
        if ( distance == 0 )
            return;
        float invDistance = 1 / distance;
        float impulseMag = blastPower * invDistance * invDistance;
        impulseMag = b2Min( impulseMag, 500.0f );
        body->SetGravityScale(1);
        body->ApplyLinearImpulse( impulseMag * blastDir, applyPoint, true );
    }
};
}
#endif
