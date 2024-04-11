#include "CHyperV.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{

    try
    {
        CHyperV hypervisor;
        srand(static_cast<unsigned int>(time(NULL)));

        for (int i = 0; i < 10; i++)
        {
            int randomNum = rand() % 2;
            unsigned short cpuCount = static_cast<unsigned short>(rand()) % 2 + 1;
            unsigned long ramSize = static_cast<unsigned long>(rand()) % (1024 * 1024 * 1024) * 2;
            unsigned long hddSize = static_cast<unsigned long>(rand()) % (1024 * 1024 * 1024) * 13;
            if (randomNum)
            {
                hypervisor.CreateVM(cpuCount, ramSize, hddSize, OSIds::WINDOWS);
            }
            else
            {
                hypervisor.CreateVM(cpuCount, ramSize, hddSize, OSIds::LINUX);
            }
        }

        size_t quantityVM = hypervisor.PrintListVM();
        
        std::cout << "\n" << "quantity of virt machines = " << quantityVM << "\n";
        
        size_t pos = static_cast<size_t>(rand()) % quantityVM;
        std::cout << "\n" << "position for app installation = " << pos << "\n";
        AVirtM *ptr;
        
        ptr = hypervisor.GetVM(pos);
        
        ptr->GetOS()->InstallApp("super application");
        
        pos = static_cast<size_t>(rand()) % quantityVM;
        std::cout << "\n" << "position for removing virt machine = " << pos << "\n";
        hypervisor.RemoveVM(pos);
        
        quantityVM = hypervisor.PrintListVM();
        
        std::cout << "\n" << "quantity of virt machines = " << quantityVM << "\n";
    }
    catch (const std::exception &exp)
    {
        std::cout << "error: " << exp.what() << "\n";
    }

    return 0;
}
