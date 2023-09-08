#include "D3DHook.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxguid.lib")

void D3DHook::Initialize()
{
	D3DHook::InitializeHooks();
}

bool D3DHook::CreateDummySwapChain(IDXGISwapChain** ppSwapChain)
{
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = FindWindow("ApplicationFrameWindow", "Minecraft");
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    const UINT createDeviceFlags = 0;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };

    ID3D11Device* pDevice;
    ID3D11DeviceContext* pDeviceCtx;

    HRESULT res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, ppSwapChain, &pDevice, &featureLevel, &pDeviceCtx);
    if (res == DXGI_ERROR_UNSUPPORTED)
        res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, ppSwapChain, &pDevice, &featureLevel, &pDeviceCtx);
    if (res != S_OK)
    {
        Zenova_Info("Failed to create dummy SwapChain, err: {:x}", res);
        return false;
    }
    return true;
}

void D3DHook::GetFunctionPointers(FPTR_IDXGISwapChain_Present* pPresentTarget)
{
    IDXGISwapChain* pSwapChain = nullptr;
    if (CreateDummySwapChain(&pSwapChain)) {
        if (pPresentTarget)
            (*pPresentTarget) = (FPTR_IDXGISwapChain_Present)(*reinterpret_cast<void***>(pSwapChain))[8];
    }
}

void D3DHook::InitializeHooks()
{
    IDXGISwapChain* pSwapChain = nullptr;
    if (CreateDummySwapChain(&pSwapChain)) {
        Zenova_Info("Vtable replacement in IDXGISwapChain::Present is {}", Zenova::Platform::CreateHook((*reinterpret_cast<void***>(pSwapChain))[8], &IDXGISwapChain_Present_Hook, &IDXGISwapChain_Present_Trampoline));
        Zenova_Info("IDXGISwapChain::Present hook address: 0x{:x}", (intptr_t)&IDXGISwapChain_Present_Hook);
        Zenova_Info("IDXGISwapChain::Present trampoline address: 0x{:x}", (intptr_t)IDXGISwapChain_Present_Trampoline);
    }
    else {
        Zenova_Info("Failed to hook IDXGISwapChain::Present");
    }
}

#define RetOriginalCall \
if (IDXGISwapChain_Present_Trampoline) \
return IDXGISwapChain_Present_Trampoline(SwapChain, SyncInterval, PresentFlags);

FPTR_IDXGISwapChain_Present D3DHook::IDXGISwapChain_Present_Trampoline = nullptr;
HRESULT __stdcall D3DHook::IDXGISwapChain_Present_Hook(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT PresentFlags)
{
    ImGuiEx::InitializeImGui(SwapChain);
    ImGuiEx::Render(SwapChain);
    
    RetOriginalCall
    else
    {
        Zenova_Info("Invalid IDXGISwapChain::Present trampoline.");
        return 0;
    }
}


