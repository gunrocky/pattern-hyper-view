#ifndef CTASKEVENT_H
#define CTASKEVENT_H


#include <iostream>
#include <string>

/**
 * Class CTaskEvent
 *
 */
class CTaskEvent
{
    /**
     * Public stuff
     */
public:
    /**
     * Empty Constructor
     */
    CTaskEvent () { }
    ~CTaskEvent() { }
    /**
     * Operations
     */
    void OnTaskProgress (std::string taskDescription, short percent)
    {
        if (percent <= 100 && percent >= 0)
        {
            std::cout << "Task - " << taskDescription << " :: percent - " << percent << "%\n";
        }
        else
        {
            std::cerr << "got wrong percent\n";
        }
    }
};
#endif //CTASKEVENT_H

