#include <SimpleEngine/ToolBox/Logger.hpp>
using namespace std;
namespace se
{
    ////////////////////////////////////////////////////////////////
    // init static stuff
    ////////////////////////////////////////////////////////////////

    // we assume that debug is enabled
    bool Logger::enabled = true;

    // the buffer
    stringstream Logger::logStream;

    // the output stream to log file
    ofstream Logger::outputStream;

    // buffer size
    unsigned int Logger::BUFFER_SIZE = 10000;

    const string Logger::FATAL_ERROR = "LOGGER FATAL ERROR";
    ////////////////////////////////////////////////////////////////

    Logger::Logger(string loggerName)
    {
        if(Logger::enabled)
        {//if debug is disabled we do nothing

            //log name
            *this << "[ "+loggerName+" ]";

            if(!Logger::outputStream.is_open())
            {//if logger output is close we have to open it

                pugi::xml_document doc;

                if(doc.load_file(LOGGER_CONF_FILE.c_str()))
                {// LOGGER_CONF_FILE contains information about how we want to log and if we want to log

                    // do we want to log ?
                    Logger::enabled = doc.child("logger").attribute("enabled").as_bool();

                    if(Logger::enabled)
                    {// yes we do

                        cout << "Opening log config file : " + LOGGER_CONF_FILE << endl;

                        //ok where do we want to log ?
                        string where = doc.child("logger").child("output").attribute("value").value();
                        //set buffer size, when buffer is full we flush to log file
                        Logger::BUFFER_SIZE = doc.child("logger").attribute("buffer_size").as_int();

                        //open the stream
                        //Logger::outputStream.open(where.c_str() ,ios::out | ios::app);
                        Logger::outputStream.open(where.c_str() ,ios::out | ios::trunc);

                        cout << "log file : " + where << endl;

                        cout << "buffer size " << Logger::BUFFER_SIZE << endl;

                    }
                }
                else
                {
                    cerr << "Error, couldnt open or parse logger config file : " + LOGGER_CONF_FILE;
                }
            }
        }
    }

    void Logger::appendTo(ostream& out)
    {
        out << Logger::logStream.str() << endl;
        Logger::logStream.flush();
        Logger::logStream.str("");
    }

    void Logger::append()
    {
        if(Logger::enabled)
        {
            appendTo(Logger::outputStream);

            if(Logger::outputStream.is_open())
            {
                cout << "closing log file. " << endl;
                Logger::outputStream.close();
            }
        }
    }

    const string Logger::getTimestampString() const
    {
        const time_t now = time(NULL); //timestamp with \n at the end
        const string timestampString(ctime(&now));

        return timestampString.substr(0,timestampString.size()-1); //timestamp without \n at the end
    }

    const bool Logger::needFlush(string& data) const
    {
        return Logger::logStream.str().size() + data.size() + 27 >= Logger::BUFFER_SIZE; //27 is timestamp
    }
}
