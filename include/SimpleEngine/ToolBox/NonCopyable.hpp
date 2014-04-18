#ifndef NonCopyable_h
#define NonCopyable_h
#include <SimpleEngine/myImports.hpp>
namespace se
{
    class SE_API NonCopyable
    {
        protected :

        NonCopyable() {}

        private :

        NonCopyable(const NonCopyable&);
        NonCopyable& operator =(const NonCopyable&);
    };

}
#endif
