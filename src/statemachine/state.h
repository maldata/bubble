#ifndef STATE_H
#define STATE_H

namespace bubble
{
    class State
    {
    public:
        State();
        virtual ~State();

        virtual void initialize();
        virtual void uninitialize();
        virtual void iterate();
    };
}

#endif // STATE_H
