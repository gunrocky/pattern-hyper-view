#ifndef AGUESTOS_H
#define AGUESTOS_H


#include <string>
#include <set>
#include <iostream>

/**
 * Class AGuestOS
 *
 *
 */
class AGuestOS
{
    /**
     * Public stuff
     */
public:
    /**
     *
     */
    virtual ~AGuestOS ()
    {

    }
    /**
     * Operations
     */
    /**
     *
     */
    virtual void InstallApp (const std::string &appName) = 0;

    virtual void PrintInfo () = 0;
    /**
     * Protected stuff
     */
protected:
    /**
     * Fields
     */
    std::set<std::string> m_installedApps;
};
#endif //AGUESTOS_H

