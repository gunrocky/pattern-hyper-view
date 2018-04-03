#ifndef CTASKEVENT_H
#define CTASKEVENT_H


#include <iostream>
#include <string>



class ITaskEvent
{
public:
    ~ITaskEvent() {}
    virtual void OnTaskProgress(const std::string &taskDescription, short percent) = 0;
};

/**
 * Class CTaskEvent
 *
 */
class CTaskEvent : public ITaskEvent
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
    void OnTaskProgress (const std::string &taskDescription, short percent)
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

