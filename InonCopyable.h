#ifndef INONCOPYABLE_H
#define INONCOPYABLE_H

/**
 * Interface InonCopyable
 *
 */
class InonCopyable
{
public:
    /**
     * Constructors
     */
    /**
     *
     */
    InonCopyable ()
    {

    }
    /**
     *
     */
    virtual ~InonCopyable ()
    {

    }
private:
    /**
     * Constructors
     */
    /**
     *
     */
    InonCopyable (const InonCopyable &obj) {}
    /**
     * Operations
     */
    /**
     *
     */
    virtual InonCopyable operator= (const InonCopyable &obj) {}


};
#endif //INONCOPYABLE_H

