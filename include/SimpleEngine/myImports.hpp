#ifndef myImports_hpp
#define myImports_hpp
////////////////////////////////////////////////////////////
// Define portable import / export macros
////////////////////////////////////////////////////////////
#if !defined(SE_STATIC)

    #if defined(SYSTEM_WINDOWS)

        // Windows compilers need specific (and different) keywords for export and import
        #if defined(SE_EXPORTS)
            define SE_API __declspec(dllexport)
        #else
            define SE_API __declspec(dllimport)
        #endif // defined

    #else // Linux, FreeBSD, Mac OS X

        #if __GNUC__ >= 4

            // GCC 4 has special keywords for showing/hidding symbols,
            // the same keyword is used for both importing and exporting
            #define SE_API __attribute__ ((__visibility__ ("default")))

        #else

            // GCC < 4 has no mechanism to explicitely hide symbols, everything's exported
            #define SE_API

        #endif

    #endif

#else

    // Static build doesn't need import/export macros
    #define SE_API

#endif
///////////////////
// System headers
///////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <math.h>
#include <map>
#include <vector>
#include <string>
#include <unordered_set>
#include <functional>
#include <memory>

///////////////////
// Consts
///////////////////
#include <SimpleEngine/myConsts.hpp>

///////////////////
// Xml parser
///////////////////
#include <pugixml.hpp>

///////////////////
// SFML
///////////////////
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

/////////////////
// BOX2D Header
/////////////////
//#include <Box2D/Box2D.h>
#endif
