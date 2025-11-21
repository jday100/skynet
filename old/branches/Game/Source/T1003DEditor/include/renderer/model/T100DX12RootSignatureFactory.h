#ifndef T100DX12ROOTSIGNATUREFACTORY_H
#define T100DX12ROOTSIGNATUREFACTORY_H

#include "T100DX12Header.h"
#include "T100EntityCommon.h"

class T100DX12Model;
class T100DX12Studio;

class T100DX12RootSignatureFactory
{
    public:
        T100DX12RootSignatureFactory();
        virtual ~T100DX12RootSignatureFactory();

        static ComPtr<ID3D12RootSignature>      Create(T100DX12Studio*, T100DX12Model*);

    protected:
        static CD3DX12_DESCRIPTOR_RANGE1*       CreateRanges(T100ShaderParameters*);
        static CD3DX12_ROOT_PARAMETER1*         CreateParameters(T100ShaderParameters*, CD3DX12_DESCRIPTOR_RANGE1*);

        static T100VOID                         CreateRange(CD3DX12_DESCRIPTOR_RANGE1&, T100ShaderParameter&);
        static T100VOID                         CreateParameter(CD3DX12_ROOT_PARAMETER1&, CD3DX12_DESCRIPTOR_RANGE1&, T100ShaderParameter&);

    private:
        static D3D12_DESCRIPTOR_RANGE_TYPE      ConvertType(T100D3D12_DESCRIPTOR_RANGE_TYPE);
        static D3D12_DESCRIPTOR_RANGE_FLAGS     ConvertFlags(T100D3D12_DESCRIPTOR_RANGE_FLAGS);
        static D3D12_SHADER_VISIBILITY          Convert(T100D3D12_SHADER_VISIBILITY);
};

#endif // T100DX12ROOTSIGNATUREFACTORY_H
