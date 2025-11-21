#ifndef T1003DEDITORDESCRIPTIONFILE_H
#define T1003DEDITORDESCRIPTIONFILE_H

#include <fstream>
#include <wx/wx.h>
#include "game/file/T100JSON.h"
#include "T1003DEditorDescriptionReferenceData.h"

    static const wxChar* enumFormatLabels[] = {
        wxT("T100DXGI_FORMAT_UNKNOWN"),
        wxT("T100DXGI_FORMAT_R32G32B32A32_TYPELESS"),
        wxT("T100DXGI_FORMAT_R32G32B32A32_FLOAT"),
        wxT("T100DXGI_FORMAT_R32G32B32A32_UINT"),

        wxT("T100DXGI_FORMAT_R32G32B32A32_SINT"),
        wxT("T100DXGI_FORMAT_R32G32B32_TYPELESS"),
        wxT("T100DXGI_FORMAT_R32G32B32_FLOAT"),
        wxT("T100DXGI_FORMAT_R32G32B32_UINT"),

        wxT("T100DXGI_FORMAT_R32G32B32_SINT"),
        wxT("T100DXGI_FORMAT_R16G16B16A16_TYPELESS"),
        wxT("T100DXGI_FORMAT_R16G16B16A16_FLOAT"),
        wxT("T100DXGI_FORMAT_R16G16B16A16_UNORM"),

        wxT("T100DXGI_FORMAT_R16G16B16A16_UINT"),
        wxT("T100DXGI_FORMAT_R16G16B16A16_SNORM"),
        wxT("T100DXGI_FORMAT_R16G16B16A16_SINT"),
        wxT("T100DXGI_FORMAT_R32G32_TYPELESS"),

        wxT("T100DXGI_FORMAT_R32G32_FLOAT"),
        wxT("T100DXGI_FORMAT_R32G32_UINT"),
        wxT("T100DXGI_FORMAT_R32G32_SINT"),
        wxT("T100DXGI_FORMAT_R32G8X24_TYPELESS"),

        wxT("T100DXGI_FORMAT_D32_FLOAT_S8X24_UINT"),
        wxT("T100DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS"),
        wxT("T100DXGI_FORMAT_X32_TYPELESS_G8X24_UINT"),
        wxT("T100DXGI_FORMAT_R10G10B10A2_TYPELESS"),

        wxT("T100DXGI_FORMAT_R10G10B10A2_UNORM"),
        wxT("T100DXGI_FORMAT_R10G10B10A2_UINT"),
        wxT("T100DXGI_FORMAT_R11G11B10_FLOAT"),
        wxT("T100DXGI_FORMAT_R8G8B8A8_TYPELESS"),

        wxT("T100DXGI_FORMAT_R8G8B8A8_UNORM"),
        wxT("T100DXGI_FORMAT_R8G8B8A8_UNORM_SRGB"),
        wxT("T100DXGI_FORMAT_R8G8B8A8_UINT"),
        wxT("T100DXGI_FORMAT_R8G8B8A8_SNORM"),

        wxT("T100DXGI_FORMAT_R8G8B8A8_SINT"),
        wxT("T100DXGI_FORMAT_R16G16_TYPELESS"),
        wxT("T100DXGI_FORMAT_R16G16_FLOAT"),
        wxT("T100DXGI_FORMAT_R16G16_UNORM"),

        wxT("T100DXGI_FORMAT_R16G16_UINT"),
        wxT("T100DXGI_FORMAT_R16G16_SNORM"),
        wxT("T100DXGI_FORMAT_R16G16_SINT"),
        wxT("T100DXGI_FORMAT_R32_TYPELESS"),

        wxT("T100DXGI_FORMAT_D32_FLOAT"),
        wxT("T100DXGI_FORMAT_R32_FLOAT"),
        wxT("T100DXGI_FORMAT_R32_UINT"),
        wxT("T100DXGI_FORMAT_R32_SINT"),

        wxT("T100DXGI_FORMAT_R24G8_TYPELESS"),
        wxT("T100DXGI_FORMAT_D24_UNORM_S8_UINT"),
        wxT("T100DXGI_FORMAT_R24_UNORM_X8_TYPELESS"),
        wxT("T100DXGI_FORMAT_X24_TYPELESS_G8_UINT"),

        wxT("T100DXGI_FORMAT_R8G8_TYPELESS"),
        wxT("T100DXGI_FORMAT_R8G8_UNORM"),
        wxT("T100DXGI_FORMAT_R8G8_UINT"),
        wxT("T100DXGI_FORMAT_R8G8_SNORM"),

        wxT("T100DXGI_FORMAT_R8G8_SINT"),
        wxT("T100DXGI_FORMAT_R16_TYPELESS"),
        wxT("T100DXGI_FORMAT_R16_FLOAT"),
        wxT("T100DXGI_FORMAT_D16_UNORM"),

        wxT("T100DXGI_FORMAT_R16_UNORM"),
        wxT("T100DXGI_FORMAT_R16_UINT"),
        wxT("T100DXGI_FORMAT_R16_SNORM"),
        wxT("T100DXGI_FORMAT_R16_SINT"),

        wxT("T100DXGI_FORMAT_R8_TYPELESS"),
        wxT("T100DXGI_FORMAT_R8_UNORM"),
        wxT("T100DXGI_FORMAT_R8_UINT"),
        wxT("T100DXGI_FORMAT_R8_SNORM"),

        wxT("T100DXGI_FORMAT_R8_SINT"),
        wxT("T100DXGI_FORMAT_A8_UNORM"),
        wxT("T100DXGI_FORMAT_R1_UNORM"),
        wxT("T100DXGI_FORMAT_R9G9B9E5_SHAREDEXP"),

        wxT("T100DXGI_FORMAT_R8G8_B8G8_UNORM"),
        wxT("T100DXGI_FORMAT_G8R8_G8B8_UNORM"),
        wxT("T100DXGI_FORMAT_BC1_TYPELESS"),
        wxT("T100DXGI_FORMAT_BC1_UNORM"),

        wxT("T100DXGI_FORMAT_BC1_UNORM_SRGB"),
        wxT("T100DXGI_FORMAT_BC2_TYPELESS"),
        wxT("T100DXGI_FORMAT_BC2_UNORM"),
        wxT("T100DXGI_FORMAT_BC2_UNORM_SRGB"),

        wxT("T100DXGI_FORMAT_BC3_TYPELESS"),
        wxT("T100DXGI_FORMAT_BC3_UNORM"),
        wxT("T100DXGI_FORMAT_BC3_UNORM_SRGB"),
        wxT("T100DXGI_FORMAT_BC4_TYPELESS"),

        wxT("T100DXGI_FORMAT_BC4_UNORM"),
        wxT("T100DXGI_FORMAT_BC4_SNORM"),
        wxT("T100DXGI_FORMAT_BC5_TYPELESS"),
        wxT("T100DXGI_FORMAT_BC5_UNORM"),

        wxT("T100DXGI_FORMAT_BC5_SNORM"),
        wxT("T100DXGI_FORMAT_B5G6R5_UNORM"),
        wxT("T100DXGI_FORMAT_B5G5R5A1_UNORM"),
        wxT("T100DXGI_FORMAT_B8G8R8A8_UNORM"),

        wxT("T100DXGI_FORMAT_B8G8R8X8_UNORM"),
        wxT("T100DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM"),
        wxT("T100DXGI_FORMAT_B8G8R8A8_TYPELESS"),
        wxT("T100DXGI_FORMAT_B8G8R8A8_UNORM_SRGB"),

        wxT("T100DXGI_FORMAT_B8G8R8X8_TYPELESS"),
        wxT("T100DXGI_FORMAT_B8G8R8X8_UNORM_SRGB"),
        wxT("T100DXGI_FORMAT_BC6H_TYPELESS"),
        wxT("T100DXGI_FORMAT_BC6H_UF16"),

        wxT("T100DXGI_FORMAT_BC6H_SF16"),
        wxT("T100DXGI_FORMAT_BC7_TYPELESS"),
        wxT("T100DXGI_FORMAT_BC7_UNORM"),
        wxT("T100DXGI_FORMAT_BC7_UNORM_SRGB"),

        wxT("T100DXGI_FORMAT_AYUV"),
        wxT("T100DXGI_FORMAT_Y410"),
        wxT("T100DXGI_FORMAT_Y416"),
        wxT("T100DXGI_FORMAT_NV12"),

        wxT("T100DXGI_FORMAT_P010"),
        wxT("T100DXGI_FORMAT_P016"),
        wxT("T100DXGI_FORMAT_420_OPAQUE"),
        wxT("T100DXGI_FORMAT_YUY2"),

        wxT("T100DXGI_FORMAT_Y210"),
        wxT("T100DXGI_FORMAT_Y216"),
        wxT("T100DXGI_FORMAT_NV11"),
        wxT("T100DXGI_FORMAT_AI44"),

        wxT("T100DXGI_FORMAT_IA44"),
        wxT("T100DXGI_FORMAT_P8"),
        wxT("T100DXGI_FORMAT_A8P8"),
        wxT("T100DXGI_FORMAT_B4G4R4A4_UNORM"),

        wxT("T100DXGI_FORMAT_P208"),
        wxT("T100DXGI_FORMAT_V208"),
        wxT("T100DXGI_FORMAT_V408"),
        wxT("T100DXGI_FORMAT_FORCE_UINT"),
        T100NULL
    };

    static long enumFormatValues[] = {
        0x0,
        0x1,
        0x2,
        0x3,

        0x4,
        0x5,
        0x6,
        0x7,

        0x8,
        0x9,
        0xa,
        0xb,

        0xc,
        0xd,
        0xe,
        0xf,

        0x10,
        0x11,
        0x12,
        0x13,

        0x14,
        0x15,
        0x16,
        0x17,

        0x18,
        0x19,
        0x1a,
        0x1b,

        0x1c,
        0x1d,
        0x1e,
        0x1f,

        0x20,
        0x21,
        0x22,
        0x23,

        0x24,
        0x25,
        0x26,
        0x27,

        0x28,
        0x29,
        0x2a,
        0x2b,

        0x2c,
        0x2d,
        0x2e,
        0x2f,

        0x30,
        0x31,
        0x32,
        0x33,

        0x34,
        0x35,
        0x36,
        0x37,

        0x38,
        0x39,
        0x3a,
        0x3b,

        0x3c,
        0x3d,
        0x3e,
        0x3f,

        0x40,
        0x41,
        0x42,
        0x43,

        0x44,
        0x45,
        0x46,
        0x47,

        0x48,
        0x49,
        0x4a,
        0x4b,

        0x4c,
        0x4d,
        0x4e,
        0x4f,

        0x50,
        0x51,
        0x52,
        0x53,

        0x54,
        0x55,
        0x56,
        0x57,

        0x58,
        0x59,
        0x5a,
        0x5b,

        0x5c,
        0x5d,
        0x5e,
        0x5f,

        0x60,
        0x61,
        0x62,
        0x63,

        0x64,
        0x65,
        0x66,
        0x67,

        0x68,
        0x69,
        0x6a,
        0x6b,

        0x6c,
        0x6d,
        0x6e,
        0x6f,

        0x70,
        0x71,
        0x72,
        0x73,

        0x82,
        0x83,
        0x84,
        -1
    };

    static const wxChar* enumClassificationLabels[] = {
        wxT("T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA"),
        wxT("T100D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA"),
        T100NULL
    };

    static long enumClassificationValues[] = {
        0, 1
    };


class T1003DEditorDescriptionFile
{
    public:
        T1003DEditorDescriptionFile(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&);
        virtual ~T1003DEditorDescriptionFile();

        T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&     GetDescriptions();

        static T100DXGI_FORMAT                      ConvertFormat(T100UINT);
        static T100D3D12_INPUT_CLASSIFICATION       ConvertClassification(T100UINT);

        friend std::ifstream& operator>>(std::ifstream&, T1003DEditorDescriptionFile&);
        friend std::ofstream& operator<<(std::ofstream&, T1003DEditorDescriptionFile&);

    protected:
        JSON                                        m_json;

    private:
        T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&     m_descs;

        T100VOID                                    encode();
        T100VOID                                    EncodeDesc(T100D3D12_INPUT_ELEMENT_DESC*, JSON&);

        T100VOID                                    decode();
        T100VOID                                    DecodeDesc(JSON&);
};

#endif // T1003DEDITORDESCRIPTIONFILE_H
