#ifndef Message_hpp
#define Message_hpp
namespace se
{
    class SE_API MessageBase
    {
    };

    template <class Type, typename... Datas>
    class SE_API Message : public MessageBase
    {
        public:
        std::tuple<Datas ...> myDatas;
    };
}
#endif
