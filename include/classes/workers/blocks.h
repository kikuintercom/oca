#ifndef BLOCKS_H
#define BLOCKS_H

class OcaBlock : OcaWorker
{
private:
    OcaClassID                          ClassID;
    OcaClassVersionNumber               ClassVersion;
    OcaONo                              Type;
    OcaList<OcaObjectIdentification>    Members[];
    OcaMap<OcaUint16, OcaSignalPath>    SignalPaths[];
    OcaLibVolIdentifier                 MostRecentParamSetIdentifier;

public:
    OcaStatus GetType(OcaONo);

    /*FIXME: Not sure about the second parameter! The OCA documentation
    specifies that is should be:
    ConstructionParameters variant[0..n] «optional» Zero or more construction
    parameters, as defined by the abstract method "Constructor" in the
    class being instantiated.*/
    OcaStatus ConstructMember(OcaClassID, OcaList<OcaProperty>, OcaONo);
    OcaStatus ConstructMemberUsingFactory(OcaONo, OcaONo);
    OcaStatus DeleteMember(OcaONo);
    OcaStatus GetMembers(OcaList<OcaObjectIdentification>);
    OcaStatus GetMembersRecursive(OcaList<OcaBlockMember>);
    OcaStatus AddSignalPath(OcaSignalPath, OcaUint16);
    OcaStatus DeleteSignalPath(OcaUint16);
    OcaStatus GetSignalPaths(OcaList<OcaSignalPath>);
    OcaStatus GetSignalPathsRecursive(OcaList<OcaSignalPath>);
    OcaStatus GetMostRecentParamSetIdentifier(OcaLibVolIdentifier);
    OcaStatus ApplyParamSet(OcaLibVolIdentifier);
    OcaStatus GetCurrentParamSetData(OcaLibVolData_ParamSet);
    OcaStatus StoreCurrentParamSetData(OcaLibVolIdentifier);
};

class OcaBlockFactory : OcaWorker
{
private:
    OcaClassID                              ClassID;
    OcaClassVersionNumber                   ClassVersion;
    OcaList<OcaProtoPort>                   ProtoPorts[];
    OcaList<OcaProtoObjectIdentification>   ProtoMembers[];
    OcaMap<OcaUint16, OcaProtoSignalPath>   ProtoSignalPaths[];

public:
    OcaStatus DefineProtoPort(OcaString, OcaPortMode, OcaProtoPortID);
    OcaStatus UndefineProtoPort(OcaProtoPortID);
    OcaStatus GetProtoPorts(OcaList<OcaProtoPort>);

    /*FIXME: Not sure about the second parameter! The OCA documentation
    specifies that is should be:
    ConstructionParameters variant[0..n] «optional» Zero or more construction
    parameters, as defined by the abstract method "Constructor" in the
    class being instantiated.*/
    OcaStatus DefineProtoMember(OcaClassID, OcaList<OcaProperty>, OcaProtoONo);
    OcaStatus DefineProtoMemberUsingFactory(OcaONo, OcaProtoONo);
    OcaStatus UndefineProtoMember(OcaProtoONo);

    /*FIXME: The template parameter according to the documentation
    should be 'OcaBlockProtoObjectIdentification'.
    However, this doesn't exist and isn't specified as an OCA Datatype,
    so I've subbed in OcaProtoObjectIdentification for now.
    This could well be *another* inconsistency in the docs, though.*/
    OcaStatus GetProtoMembers(OcaList<OcaProtoObjectIdentification>);
    OcaStatus DefineProtoSignalPath(OcaProtoSignalPath, OcaUint16);
    OcaStatus UndefineProtoSignalPath(OcaUint16);
    OcaStatus GetProtoSignalPaths(OcaMap<OcaUint16, OcaProtoSignalPath>);

};

class OcaMatrix : OcaWorker
{
private:
    OcaClassID              ClassID;
    OcaClassVersionNumber   ClassVersion;
    OcaMatrixCoordinate     X;
    OcaMatrixCoordinate     Y;
    OcaMatrixCoordinate     xSize;
    OcaMatrixCoordinate     ySize;
    OcaList2D<OcaONo>       Members;
    OcaONo                  Proxy;
    OcaUint8                PortsPerRow;
    OcaUint8                PortsPerColumn;

public:
    OcaStatus GetCurrentXY(OcaMatrixCoordinate, OcaMatrixCoordinate);
    OcaStatus SetCurrentXY(OcaMatrixCoordinate, OcaMatrixCoordinate);
    OcaStatus GetSize(OcaMatrixCoordinate, OcaMatrixCoordinate,
                      OcaMatrixCoordinate, OcaMatrixCoordinate,
                      OcaMatrixCoordinate, OcaMatrixCoordinate);
    OcaStatus SetSize(OcaMatrixCoordinate, OcaMatrixCoordinate);
    OcaStatus GetMembers(OcaList2D<OcaONo>);
    OcaStatus SetMembers(OcaList2D<OcaONo>);
    OcaStatus GetMember(OcaMatrixCoordinate, OcaMatrixCoordinate, OcaONo);
    OcaStatus SetMember(OcaMatrixCoordinate, OcaMatrixCoordinate, OcaONo);
    OcaStatus GetProxy(OcaONo);
    OcaStatus SetProxy(OcaONo);
    OcaStatus GetPortsPerRow(OcaUint8);
    OcaStatus SetPortsPerRow(OcaUint8);
    OcaStatus GetPortsPerColumn(OcaUint8);
    OcaStatus SetPortsPerColumn(OcaUint8);
    OcaStatus SetCurrentXYLock(OcaMatrixCoordinate, OcaMatrixCoordinate);
    OcaStatus UnlockCurrent();
};

#endif // BLOCKS_H
