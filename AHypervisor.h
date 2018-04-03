#ifndef AHYPERVISOR_H
#define AHYPERVISOR_H


#include <string>
#include <vector>
#include <memory>

#include "AVirtM.h"
#include "CTaskEvent.h"

#include "InonCopyable.h"

enum HypervisorState
{
    OFFHYPER = 0,
    RUNHYPER
};

enum HypervisorIds
{
    HYPERV = 0,
    QEMU,
    VBOX,
    VMWARE
};


/**
 * Class AHypervisor
 *
 */
class AHypervisor : public InonCopyable
{
    /**
     * Public stuff
     */
public:
    /**
     * Constructors
     */
    AHypervisor () { }
    
    virtual ~AHypervisor ()
    {

    }
    /**
     * Accessor Methods
     */
    HypervisorState getCurState ( )
    {
        return m_curState;
    }
    
    unsigned short getAvailableCpuCounts ( )
    {
        return m_availableCpuCounts;
    }
    
    unsigned long getAvailableRamSize ( )
    {
        return m_availableRamSize;
    }
    
    unsigned long getAvailableHddSize ( )
    {
        return m_availableHddSize;
    }
    /**
     * Operations
     */
    virtual bool CreateVM (const unsigned short cpuCounts, const unsigned long ramSize, const unsigned long hddSize, OSIds guestosId) = 0;
    
    virtual void RemoveVM (size_t indexVM) = 0;
    
    virtual size_t PrintListVM () = 0;
    
    virtual AVirtM *GetVM (size_t indexVM) = 0;
    /**
     * Protected stuff
     */
protected:
    /**
     * Fields
     */
    std::vector<std::unique_ptr<AVirtM>> m_vecVMs;
    HypervisorState m_curState;
    unsigned long m_availableRamSize = 17179869184;  // 1024×1024×1024×16
    unsigned long m_availableHddSize = 107374182400; // 1024×1024×1024×100
    CTaskEvent m_taskEvent;
    unsigned short m_availableCpuCounts = 8;
};
#endif //AHYPERVISOR_H

