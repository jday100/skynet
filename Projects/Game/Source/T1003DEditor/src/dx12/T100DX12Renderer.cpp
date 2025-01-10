#include "T100DX12Renderer.h"

#include <d3dcompiler.h>
#include "T100DX12Tools.h"

T100DX12Renderer::T100DX12Renderer()
    :T100DX12Base()
{
    //ctor
}

T100DX12Renderer::~T100DX12Renderer()
{
    //dtor
}

T100VOID T100DX12Renderer::Append(T100Entity* entity)
{
    m_entities.push_back(entity);
}

T100VOID T100DX12Renderer::LoadAssets()
{
    WCHAR       assetsPath[512];
    GetAssetsPath(assetsPath, _countof(assetsPath));
    m_assetsPath    = assetsPath;

    m_aspectRatio   = static_cast<float>(m_width) / static_cast<float>(m_height);

    m_viewport      = CD3DX12_VIEWPORT(0.0f, 0.0f, static_cast<float>(m_width), static_cast<float>(m_height));
    m_scissorRect   = CD3DX12_RECT(0, 0, static_cast<LONG>(m_width), static_cast<LONG>(m_height));

    {
        CD3DX12_ROOT_SIGNATURE_DESC         rootSignatureDesc;
        rootSignatureDesc.Init(0, T100NULL, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

        ComPtr<ID3DBlob>            signature;
        ComPtr<ID3DBlob>            error;
        ThrowIfFailed(D3D12SerializeRootSignature(
                                                  &rootSignatureDesc,
                                                  D3D_ROOT_SIGNATURE_VERSION_1,
                                                  &signature,
                                                  &error
                                                  ));
        ThrowIfFailed(m_device->CreateRootSignature(
                                                    0,
                                                    signature->GetBufferPointer(),
                                                    signature->GetBufferSize(),
                                                    IID_PPV_ARGS(&m_rootSignature)
                                                    ));
    }

    {
        ComPtr<ID3DBlob>            vertexShader;
        ComPtr<ID3DBlob>            pixelShader;

        UINT        compileFlags    = 0;

        ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(L"shaders.hlsl").c_str(), T100NULL, T100NULL, "VSMain", "vs_5_0", compileFlags, 0, &vertexShader, T100NULL));
        ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(L"shaders.hlsl").c_str(), T100NULL, T100NULL, "PSMain", "ps_5_0", compileFlags, 0, &pixelShader, T100NULL));

        D3D12_INPUT_ELEMENT_DESC        inputElementDescs[] =
        {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
        };

        D3D12_GRAPHICS_PIPELINE_STATE_DESC      psoDesc = {};

        psoDesc.InputLayout         = { inputElementDescs, _countof(inputElementDescs) };
        psoDesc.pRootSignature      = m_rootSignature.Get();
        psoDesc.VS                  = CD3DX12_SHADER_BYTECODE(vertexShader.Get());
        psoDesc.PS                  = CD3DX12_SHADER_BYTECODE(pixelShader.Get());
        psoDesc.RasterizerState     = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
        psoDesc.BlendState          = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
        psoDesc.DepthStencilState.DepthEnable       = T100FALSE;
        psoDesc.DepthStencilState.StencilEnable     = T100FALSE;
        psoDesc.SampleMask          = UINT_MAX;
        psoDesc.PrimitiveTopologyType   = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        psoDesc.NumRenderTargets        = 1;
        psoDesc.RTVFormats[0]       = DXGI_FORMAT_R8G8B8A8_UNORM;
        psoDesc.SampleDesc.Count    = 1;

        ThrowIfFailed(m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_pipelineState)));


    }



    ThrowIfFailed(m_device->CreateCommandList(
                                              0,
                                              D3D12_COMMAND_LIST_TYPE_DIRECT,
                                              m_commandAllocator.Get(),
                                              m_pipelineState.Get(),
                                              IID_PPV_ARGS(&m_commandList)
                                              ));

    ThrowIfFailed(m_commandList->Close());

    {
        /*
        Vertex*     triangleVertices;

        Vertex      triangles[] =
        {
            { { 0.0f, 0.25f * m_aspectRatio, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
            { { 0.25f, -0.25f * m_aspectRatio, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
            { { -0.25f, -0.25f * m_aspectRatio, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } }
        };



        UINT vertexBufferSize     = sizeof(triangles);

        if(m_entities.size() == 1){
            triangleVertices    = m_entities[0]->vertex;
            vertexBufferSize    = sizeof(m_entities[0]->vertex);
        }else{
            triangleVertices    = triangles;
            vertexBufferSize    = sizeof(triangles);
        }
        */


    }

    {
        Vertex      triangleVertices[] =
        {
            { { 0.0f, 0.25f * m_aspectRatio, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
            { { 0.25f, -0.25f * m_aspectRatio, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
            { { -0.25f, -0.25f * m_aspectRatio, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } }
        };

        const UINT vertexBufferSize     = sizeof(triangleVertices);

        CD3DX12_HEAP_PROPERTIES         uploadHeap(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC           resourceDesc = CD3DX12_RESOURCE_DESC::Buffer(vertexBufferSize);

        ThrowIfFailed(m_device->CreateCommittedResource(
                                                        &uploadHeap,
                                                        D3D12_HEAP_FLAG_NONE,
                                                        &resourceDesc,
                                                        D3D12_RESOURCE_STATE_GENERIC_READ,
                                                        nullptr,
                                                        IID_PPV_ARGS(&m_vertexBuffer)
                                                        ));

        UINT8*          pVertexDataBegin;
        CD3DX12_RANGE   readRange(0, 0);

        ThrowIfFailed(m_vertexBuffer->Map(
                                          0,
                                          &readRange,
                                          reinterpret_cast<void**>(&pVertexDataBegin)
                                          ));
        memcpy(pVertexDataBegin, triangleVertices, sizeof(triangleVertices));
        m_vertexBuffer->Unmap(0, T100NULL);

        m_vertexBufferView.BufferLocation   = m_vertexBuffer->GetGPUVirtualAddress();
        m_vertexBufferView.StrideInBytes    = sizeof(Vertex);
        m_vertexBufferView.SizeInBytes      = vertexBufferSize;
    }

    {
        ThrowIfFailed(m_device->CreateFence(
                                            0,
                                            D3D12_FENCE_FLAG_NONE,
                                            IID_PPV_ARGS(&m_fence)
                                            ));
        m_fenceValue = 1;

        m_fenceEvent = CreateEvent(T100NULL, FALSE, FALSE, T100NULL);
        if (m_fenceEvent == T100NULL)
        {
            ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
        }

        WaitForPreviousFrame();
    }
}


T100VOID T100DX12Renderer::PopulateCommandList()
{
    ThrowIfFailed(m_commandAllocator->Reset());

    ThrowIfFailed(m_commandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());
    m_commandList->RSSetViewports(1, &m_viewport);
    m_commandList->RSSetScissorRects(1, &m_scissorRect);


    CD3DX12_RESOURCE_BARRIER    barrier1 = CD3DX12_RESOURCE_BARRIER::Transition(
                                                                                m_renderTargets[m_frameIndex].Get(),
                                                                                D3D12_RESOURCE_STATE_PRESENT,
                                                                                D3D12_RESOURCE_STATE_RENDER_TARGET
                                                                                );
    m_commandList->ResourceBarrier(1, &barrier1);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, m_rtvDescriptorSize);
    m_commandList->OMSetRenderTargets(1, &rtvHandle, T100FALSE, T100NULL);

    const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_commandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);
    m_commandList->DrawInstanced(3, 1, 0, 0);

    CD3DX12_RESOURCE_BARRIER    barrier2 = CD3DX12_RESOURCE_BARRIER::Transition(
                                                                                m_renderTargets[m_frameIndex].Get(),
                                                                                D3D12_RESOURCE_STATE_RENDER_TARGET,
                                                                                D3D12_RESOURCE_STATE_PRESENT
                                                                                );
    m_commandList->ResourceBarrier(1, &barrier2);

    ThrowIfFailed(m_commandList->Close());
}


std::wstring T100DX12Renderer::GetAssetFullPath(LPCWSTR assetName)
{
    return m_assetsPath + L"..\\..\\resources\\" + assetName;
}
