#include "CHyperV.h"


#include <iostream>
#include <algorithm>
#include <exception>

/**
 * Constructors/Destructors
 */
/**
 * Methods
 */
bool CHyperV::CreateVM(const unsigned short cpuCounts, const unsigned long ramSize
                       , const unsigned long hddSize, OSIds guestosId)
{
    std::cout << m_currentClass << " create VM\n";
    if (AHypervisor::m_availableCpuCounts < cpuCounts)
    {
        std::cout << "Too many CPU counts are requested. Available CPU counts = "
                  << AHypervisor::m_availableCpuCounts << "\n";
        return false;
    }
    if (AHypervisor::m_availableRamSize < ramSize)
    {
        std::cout << "Too many RAM are requested. Available RAM = "
                  << AHypervisor::m_availableRamSize << "\n";
        return false;
    }
    if (AHypervisor::m_availableHddSize < hddSize)
    {
        std::cout << "Too many HDD size are requested. Available HDD size = "
                  << AHypervisor::m_availableHddSize << "\n";
        return false;
    }
    m_vecVMs.push_back(std::unique_ptr<AVirtM> (
        new CHyperVVirtM(m_taskEvent.get(), cpuCounts, ramSize
                         , hddSize, guestosId)));
    return true;
}

void CHyperV::RemoveVM (size_t indexVM)
{
    std::cout << m_currentClass << " remove VM\n";
    if (AHypervisor::m_vecVMs.size() <= indexVM)
    {
        std::cerr << "wrong input index. quantity of VMs = "
                  << AHypervisor::m_vecVMs.size() << "\n";
        throw std::runtime_error("wrong input index. quantity of VMs = "
                                 + std::to_string(AHypervisor::m_vecVMs.size()));
    }
    if (m_vecVMs.at(indexVM).get()->getCurState() != VirtMState::OFF)
    {
        std::cerr << "virtual machine must be shutdown\n";
        throw std::runtime_error("virtual machine must be shutdown");
    }
    unsigned short cpuCounts = AHypervisor::m_vecVMs.at(indexVM).get()->getCpuCounts();
    unsigned long ramSize = AHypervisor::m_vecVMs.at(indexVM).get()->getRamSize();
    unsigned long hddSize = AHypervisor::m_vecVMs.at(indexVM).get()->getHddSize();
    AHypervisor::m_vecVMs.erase(AHypervisor::m_vecVMs.begin()
                                + static_cast<std::_Bit_const_iterator::difference_type>(indexVM));
    AHypervisor::m_availableCpuCounts += cpuCounts;
    AHypervisor::m_availableRamSize += ramSize;
    AHypervisor::m_availableHddSize += hddSize;
}

size_t CHyperV::PrintListVM ()
{
    std::cout << m_currentClass << " print list of VMs\n";
    for (size_t i = 0; i < AHypervisor::m_vecVMs.size(); i++)
    {
        AHypervisor::m_vecVMs.at(i).get()->GetOS()->PrintInfo();
    }
    return m_vecVMs.size();
}

AVirtM *CHyperV::GetVM (size_t indexVM)
{
    std::cout << m_currentClass << " get VM\n";
    if (AHypervisor::m_vecVMs.size() < indexVM)
    {
        std::cerr << "wrong input index. quantity of VMs = "
                  << AHypervisor::m_vecVMs.size() << "\n";
        throw std::runtime_error("wrong input index. quantity of VMs = "
                                 + std::to_string(AHypervisor::m_vecVMs.size()));
    }

    return AHypervisor::m_vecVMs.at(indexVM).get();
}
