#ifndef SimpleFunctorOption_hpp
#define SimpleFunctorOption_hpp
#include <SimpleEngine/Gui/Option.hpp>
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
namespace se
{

template <typename F>
class SE_API SimpleFunctorOption : public Option, public NonCopyable
{
public:
    SimpleFunctorOption(F f) : myFunction(f)
    {
    }
    void execute()
    {
        myFunction();
    }
private:

    F myFunction;


};
}
#endif
