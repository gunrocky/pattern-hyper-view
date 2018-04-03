#ifndef CWINDOWS_H
#define CWINDOWS_H


#include <string>
#include "AGuestOS.h"

/**
 * Class CWindows
 *
 */
class CWindows : public AGuestOS
{
    /**
     * Public stuff
     */
public:
    /**
     * Constructors
     */
    CWindows () { }
    
    ~CWindows ()
    {

    }
    /**
     * Operations
     */
    void InstallApp (const std::string &appName)
    {
        std::cout << "It would be install \"" << appName << "\" on Windows guest OS\n";
        auto result = m_installedApps.insert(appName);
        if (result.second)
        {
            std::cout << "Application \"" << appName << "\" has been installed successfully\n";
        }
        else
        {
            std::cout << "Application \"" << appName << "\" has been already installed before\n";
        }
    }

    void PrintInfo ()
    {
        std::cout << "Windows OS\n";
    }
};
#endif //CWINDOWS_H

