#ifndef Logger_h
#define Logger_h
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SimpleEngine/myImports.hpp>
#include "NonCopyable.hpp"
////////////////////////////////////////////////////////////
/// Class for basic logging.
/// This class behavior is to log data into a buffer.
/// When the buffer is full, its content is flushed by calling
/// the append method.
///
/// The append method call appendTo method with 'out' parameter
/// set to an ofstream defined in LOGGER_CONF_FILE.
/// You can define your own append method or your own
/// appendTo method (to log into std::cout for example)
///
/// Logger can be enabled or disabled, you can also define
/// a buffer size in number of chars stored.
///
/// ex :
///<logger enabled="true" buffer_size="1000000">
///<output value="out.txt"/>
///</logger>
////////////////////////////////////////////////////////////
namespace se
{
    class SE_API Logger : public NonCopyable
    {
        public:
        ////////////////////////////////////////////////////////////
        /// Constructor
        /// \param loggerName : name
        ////////////////////////////////////////////////////////////
        explicit Logger(std::string loggerName);

        ////////////////////////////////////////////////////////////
        /// Append logger to output file defined in LOGGER_CONF_FILE
        /// defined in myConsts.hpp. This method closes default file
        /// output stream so it should be called once at the end of
        /// your program's main.
        ////////////////////////////////////////////////////////////
        virtual void append();

        ////////////////////////////////////////////////////////////
        /// Operators for eye candy logging
        ////////////////////////////////////////////////////////////
        template <typename T>
        Logger& operator <<(const T& data);

        protected:
        ////////////////////////////////////////////////////////////
        /// Append to stream in param
        /// \param target output
        ////////////////////////////////////////////////////////////
        virtual void appendTo(std::ostream& out);

        private:

        // return timestamp without \n at the end
        const std::string getTimestampString() const;

        // return true if buffer is full after adding data to it
        const bool needFlush(std::string& data) const;

        ////////////////////////////////////////////////////////////
        /// Private data members.
        ////////////////////////////////////////////////////////////
        static          std::stringstream logStream;
        static          std::ofstream outputStream;
        static          bool enabled;
        static unsigned int BUFFER_SIZE;
        static const    std::string FATAL_ERROR;
    };
    #include <SimpleEngine/ToolBox/Logger.inl>
}
#endif
