#ifndef NETWORKING_H
#define NETWORKING_H

class OcaNetworkSignalChannel : OcaWorker
{
private:
    OcaClassID                                  ClassID;
    OcaClassVersionNumber                       ClassVersion;
    OcaMap<OcaONo, OcaStreamConnectorPinIndex>  ConnectorPins;
    OcaNetworkSignalChannelID                   IDAdvertised;
    OcaONo                                      Network;
    OcaNetworkSignalChannelID                   RemoteChannelID;
    OcaNetworkMediaSourceOrSink                 SourceOrSink;
    OcaNetworkSignalChannelStatus               Status;

public:
    OcaStatus AddToConnector(OcaONo, OcaStreamConnectorPinIndex);
    OcaStatus GetConnectorPins(OcaMap<OcaONo, OcaStreamConnectorPinIndex>);
    OcaStatus GetIDAdvertised(OcaNetworkSignalChannelID);
    OcaStatus GetNetwork(OcaONo);
    OcaStatus GetRemoteChannelID(OcaNetworkSignalChannelID);
    OcaStatus GetSourceOrSink(OcaNetworkMediaSourceOrSink);
    OcaStatus GetStatus(OcaNetworkSignalChannelStatus);
    OcaStatus RemoveFromConnector(OcaONo);
    OcaStatus SetIDAdvertised(OcaNetworkSignalChannelID);
    OcaStatus SetNetwork(OcaONo);
    OcaStatus SetRemoteChannelID(OcaNetworkSignalChannelID);
};



#endif // NETWORKING_H
