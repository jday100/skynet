#ifndef T100DX12PIPELINESTATEFACTORY_H
#define T100DX12PIPELINESTATEFACTORY_H

#include "T100DX12Header.h"
#include "common/T100EntityCommon.h"

class T100DX12Model;
class T100DX12Studio;

class T100DX12PipelineStateFactory
{
    public:
        T100DX12PipelineStateFactory();
        virtual ~T100DX12PipelineStateFactory();

        static ComPtr<ID3D12PipelineState>      Create(T100DX12Studio*, T100DX12Model*);

    protected:
        static D3D12_INPUT_ELEMENT_DESC*        CreateDescriptions(T100DX12Model*);

    private:
        static T100VOID                         CreateElement(D3D12_INPUT_ELEMENT_DESC&, T100D3D12_INPUT_ELEMENT_DESC&);

        static DXGI_FORMAT                      ConvertFormat(T100DXGI_FORMAT);
        static D3D12_INPUT_CLASSIFICATION       Convert(T100D3D12_INPUT_CLASSIFICATION);

};

#endif // T100DX12PIPELINESTATEFACTORY_H
