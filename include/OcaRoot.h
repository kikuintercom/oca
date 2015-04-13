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
        OcaStatus GetLockable(OcaBoolean);
        OcaStatus Lock();
        OcaStatus Unlock;
        OcaStatus GetRole(OcaString);


    protected:
    private:
        OcaClassID              ClassID;
        OcaClassVersionNumber   ClassVersion;
        OcaONo                  ObjectNumber;
        OcaBoolean              Lockable;
        OcaString               Role;
};

#endif // OCAROOT_H
