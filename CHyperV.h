#ifndef CHYPERV_H
#define CHYPERV_H

#include "CHyperVVirtM.h"
#include "AHypervisor.h"

/**
 * Class CHyperV
 *
 */
class CHyperV : public AHypervisor
{
    /**
     * Public stuff
     */
public:
    /**
     * Constructors
     */
    CHyperV ()
    {
        m_currentClass.assign("CHyperV");
    }
    
    ~CHyperV ()
    {

    }
    /**
     * Operations
     */
    bool CreateVM (const unsigned short cpuCounts, const unsigned long ramSize, const unsigned long hddSize, OSIds guestosId);
    
    void RemoveVM (size_t indexVM);
    
    size_t PrintListVM ();
    
    AVirtM *GetVM (size_t indexVM);
private:
    
    std::string m_currentClass;
};
#endif //CHYPERV_H

