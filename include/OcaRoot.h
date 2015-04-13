#ifndef OCAROOT_H
#define OCAROOT_H

#include "OcaTypes.h"

class OcaRoot
{
    public:
        OcaRoot();
        virtual ~OcaRoot();

        void PropertyChanged(OcaPropertyChangedEventData);
        OcaStatus GetClassIdentification(OcaClassIdentification);

    protected:
    private:
};

#endif // OCAROOT_H
