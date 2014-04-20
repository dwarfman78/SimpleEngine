#ifndef Option_hpp
#define Option_hpp
#include <SimpleEngine/myImports.hpp>
namespace se
{
    class SE_API Option
    {
        public:
        virtual void execute() = 0;
    };
}
#endif
