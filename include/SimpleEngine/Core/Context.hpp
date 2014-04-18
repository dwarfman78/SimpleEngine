#ifndef Context_hpp
#define Context_hpp
namespace se
{
    class SE_API Context
    {
        public:

        virtual bool isValid() const = 0;
    };
}
#endif
