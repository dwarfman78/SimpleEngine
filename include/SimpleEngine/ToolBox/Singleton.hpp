#ifndef Singleton_h
#define Singleton_h
#include <SimpleEngine/ToolBox/NonCopyable.hpp>
namespace se
{
    template <class T>
    class Singleton : public NonCopyable
    {
        private:
        static T* myInstance;

        protected:
        Singleton() {}
        ~Singleton() {}

        public:
        static T* getInstance()
        {
            if(!myInstance)
                myInstance = new T;

            return myInstance;
        }

        static void destroy() {}

    };

    template <class T>
    T* Singleton<T>::myInstance = NULL;
}
#endif

