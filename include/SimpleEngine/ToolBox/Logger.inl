template <typename T>
Logger& Logger::operator <<(const T& data)
{
    // convert data to a string
    std::ostringstream oss;
    oss << data;

    std::string newLogEntry(oss.str());

    if(Logger::enabled)
    {
        // test if the buffer is full
        // and need to be flushed
        if(needFlush(newLogEntry))
            appendTo(Logger::outputStream);

        try
        {
            //could lead to bad alloc because string buffer size may increase dynamically
            Logger::logStream << "[" << getTimestampString() << "] " << newLogEntry << std::endl;

        }
        catch (const std::bad_alloc& e)
        {
            std::cout << Logger::FATAL_ERROR << std::endl;
        }
    }

    return *this;
}

/* template <>
inline Logger& Logger::operator <<(const std::string& data)
{
    return *this;
}*/
