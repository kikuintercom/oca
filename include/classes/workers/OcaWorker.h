#ifndef OCAWORKER_H
#define OCAWORKER_H

#include "OcaTypes.h"
#include "OcaRoot.h"

class OcaWorker : OcaRoot
{
public:
    OcaStatus GetEnabled(OcaBoolean);
    OcaStatus SetEnabled(OcaBoolean);
    OcaStatus AddPort(OcaString, OcaPortMode, OcaPortID);
    OcaStatus DeletePort(OcaPortID);
    OcaStatus GetPorts(OcaList<OcaPort>);
    OcaStatus GetPortName(OcaPortID, OcaString);
    OcaStatus SetPortName(OcaPortID, OcaString);
    OcaStatus GetLabel(OcaString);
    OcaStatus SetLabel(OcaString);
    OcaStatus GetOwner(OcaONo);
    OcaStatus GetLatency(OcaTimeInterval);
    OcaStatus SetLatency(OcaTimeInterval);

private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   VersionNumber;
    OcaBoolean              Enabled;
    OcaList<OcaPort>        Ports;
    OcaString               Label;
    OcaONo                  Owner;
    OcaTimeInterval         Latency;
};

#endif // OCAWORKER_H=
