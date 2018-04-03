#ifndef CLINUX_H
#define CLINUX_H


#include "AGuestOS.h"

/**
 * Class CLinux
 */
class CLinux : public AGuestOS
{
    /**
     * Public stuff
     */
public:
    /**
     * Constructors
     */
    /**
     * Empty Constructor
     */
    CLinux () { }
    /**
     *
     */
    ~CLinux ()
    {

    }
    /**
     * Operations
     */
    /**
     *
     */
    void InstallApp (const std::string &appName)
    {
        std::cout << "It would be install \"" << appName << "\" on Linux guest OS\n";

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
        std::cout << "Linux OS\n";
    }
    /**
     * Protected stuff
     */
protected:
    /**
     * Private stuff
     */
private:
    /**
     * Operations
     */
};
#endif //CLINUX_H

