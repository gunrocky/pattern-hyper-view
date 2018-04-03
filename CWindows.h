#ifndef CWINDOWS_H
#define CWINDOWS_H


#include <string>
#include "AGuestOS.h"

/**
 * Namespace
 */
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
     * Fields
     */
    /**
     *
     */
    /**
     * Constructors
     */
    /**
     * Empty Constructor
     */
    CWindows () { }
    /**
     *
     */
    ~CWindows ()
    {

    }
    /**
     * Accessor Methods
     */
    /**
     * Operations
     */
    /**
     *
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
    /**
     * Protected stuff
     */
protected:
    /**
     * Fields
     */
    /**
     *
     */
    /**
     * Constructors
     */
    /**
     * Accessor Methods
     */
    /**
     * Operations
     */
    /**
     * Private stuff
     */
private:
    /**
     * Fields
     */
    /**
     *
     */
    /**
     * Constructors
     */
    /**
     * Accessor Methods
     */
    /**
     * Operations
     */
};
#endif //CWINDOWS_H

