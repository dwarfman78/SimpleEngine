#ifndef Config_inl
#define Config_inl
template <typename T>
bool Config::get(const std::string& name, T& out) const
{
    // seek the internal map for key and value
    std::map<std::string, std::string>::const_iterator it = myVars.find(name);

    if(it != myVars.end())
    {   // if found
        // create stream for universal casting
        std::istringstream iss(it->second);

        T tmp;

        if((iss >> tmp) && (iss.eof()))
        {// try to convert

            // if conversion is succesfull
            // we erase out with tmp's value
            // otherwise out is not erased
            out = tmp;
            return true;
        }
    }

    // return false in case of conversion problem
    // or key not found.
    return false;
}

// specialization for std::string
template<> inline
bool Config::get<std::string>(const std::string& name, std::string& out) const
{
    // seek the internal map for key and value
    std::map<std::string, std::string>::const_iterator it = myVars.find(name);

    if(it != myVars.end())
    {   // if found
        // we erase out with the value
        out = it->second;
        return true;
    }

    return false;
}
#endif // Config_inl
