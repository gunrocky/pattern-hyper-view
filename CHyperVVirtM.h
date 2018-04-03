#ifndef CHYPERVVIRTM_H
#define CHYPERVVIRTM_H


#include <string>

#include "AVirtM.h"
#include "CTaskEvent.h"

/**
 * Class CHyperVVirtM
 *
 */
class CHyperVVirtM : public AVirtM
{
    /**
     * Public stuff
     */
public:
    /**
     * Constructors
     */
    CHyperVVirtM (ITaskEvent *ptaskEvent, const unsigned short cpuCounts, const unsigned long ramSize, const unsigned long hddSize, OSIds guestosId)
    {
        std::string taskDesc("HyperV virt machine creation");
        short perc = 0;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        AVirtM::m_curState = VirtMState::OFF;
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        AVirtM::m_cpuCounts = cpuCounts;
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        AVirtM::m_ramSize = ramSize;
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        AVirtM::m_hddSize = hddSize;
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        switch (guestosId)
        {
        case OSIds::LINUX:
            AVirtM::m_guestos.reset(new CLinux());
            break;
        case OSIds::WINDOWS:
            AVirtM::m_guestos.reset(new CWindows());
            break;
        }
        AVirtM::m_osid = guestosId;
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);
    }
    
    CHyperVVirtM (ITaskEvent *ptaskEvent, CHyperVVirtM &hyperVirt)
    {
        std::string taskDesc("HyperV virt machine cloning");
        short perc = 0;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        AVirtM::m_curState = VirtMState::OFF;
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        AVirtM::m_cpuCounts = hyperVirt.getCpuCounts();
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        AVirtM::m_ramSize = hyperVirt.getRamSize();
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        AVirtM::m_hddSize = hyperVirt.getHddSize();
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);

        switch (hyperVirt.getOsId())
        {
        case OSIds::LINUX:
            AVirtM::m_guestos.reset(new CLinux());
            break;
        case OSIds::WINDOWS:
            AVirtM::m_guestos.reset(new CWindows());
            break;
        }
        AVirtM::m_osid = hyperVirt.getOsId();
        perc += 20;
        ptaskEvent->OnTaskProgress(taskDesc, perc);
    }
    
    ~CHyperVVirtM ()
    {

    }
    /**
     * Operations
     */
    void Start ()
    {
        AVirtM::m_curState = VirtMState::RUN;
    }
    
    void Stop ()
    {
        AVirtM::m_curState = VirtMState::OFF;
    }
    
    std::unique_ptr<AVirtM> CloneVM (ITaskEvent *ptaskEvent)
    {
        return std::unique_ptr<AVirtM> (new CHyperVVirtM(ptaskEvent, *this));
    }
private:
    /**
     * Constructors
     */
    CHyperVVirtM ()
    {

    }
};
#endif //CHYPERVVIRTM_H

