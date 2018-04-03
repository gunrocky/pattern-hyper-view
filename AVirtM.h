#ifndef AVIRTM_H
#define AVIRTM_H

#include <memory>
#include <string>
#include "CTaskEvent.h"
#include "AGuestOS.h"
#include "CLinux.h"
#include "CWindows.h"


enum OSIds
{
    LINUX = 0,
    WINDOWS
};

enum VirtMState
{
    OFF = 0,
    RUN
};

/**
 * Class AVirtM
 *
 */
class AVirtM
{
    /**
     * Public stuff
     */
public:
    /**
     * Constructors
     */
    /**
     *
     */
    AVirtM(CTaskEvent *ptaskEvent, const unsigned short cpuCounts, const unsigned long ramSize, const unsigned long hddSize, OSIds guestosId);
    AVirtM() {}
    virtual ~AVirtM ()
    {
        
    }
    /**
     * Accessor Methods
     */
    /**
     *
     */
    unsigned short getCpuCounts ( )
    {
        return m_cpuCounts;
    }

    unsigned long getRamSize ( )
    {
        return m_ramSize;
    }
    /**
     *
     */
    unsigned long getHddSize ( )
    {
        return m_hddSize;
    }
    
    OSIds getOsId ( )
    {
        return m_osid;
    }
    /**
     *
     */
    VirtMState getCurState ( )
    {
        return m_curState;
    }
    /**
     *
     */
    AVirtM (const AVirtM & virtm)
    {
        m_ramSize = virtm.m_ramSize;
        m_hddSize = virtm.m_hddSize;
        m_curState = virtm.m_curState;
        m_cpuCounts = virtm.m_cpuCounts;
        m_osid = virtm.m_osid;
        switch (m_osid)
        {
        case OSIds::LINUX:
            m_guestos.reset(new CLinux());
            break;
        case OSIds::WINDOWS:
            m_guestos.reset(new CWindows());
            break;
        }
    }


    virtual AVirtM &operator = (const AVirtM & virtm)
    {
        if (this == &virtm)
        {
            return *this;
        }
        m_ramSize = virtm.m_ramSize;
        m_hddSize = virtm.m_hddSize;
        m_curState = virtm.m_curState;
        m_cpuCounts = virtm.m_cpuCounts;
        m_osid = virtm.m_osid;
        switch (m_osid)
        {
        case OSIds::LINUX:
            m_guestos.reset(new CLinux());
            break;
        case OSIds::WINDOWS:
            m_guestos.reset(new CWindows());
            break;
        }
    }
    /**
     * Operations
     */
    /**
     *
     */
    virtual void Start () = 0;
    /**
     *
     */
    virtual void Stop () = 0;
    /**
     *
     */
    virtual std::unique_ptr<AVirtM> CloneVM (CTaskEvent *ptaskEvent) = 0;
    /**
     *
     */
    AGuestOS *GetOS ()
    {
        return m_guestos.get();
    }
    /**
     * Protected stuff
     */
protected:
    /**
     * Fields
     */
    unsigned long m_ramSize;
    unsigned long m_hddSize;
    VirtMState m_curState;
    std::unique_ptr<AGuestOS> m_guestos;
    OSIds m_osid;
    unsigned short m_cpuCounts;
};
#endif //AVIRTM_H

