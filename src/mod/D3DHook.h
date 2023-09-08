#pragma once
#include "Zenova.h"
#include "ImGuiEx.h"
#include <dxgi.h>
#include <d3d11.h>

typedef HRESULT (*__stdcall FPTR_IDXGISwapChain_Present)(
    IDXGISwapChain* SwapChain,
    UINT SyncInterval,
    UINT PresentFlags);

typedef HRESULT(STDMETHODCALLTYPE* PFN_IDXGISwapChain_ResizeBuffers)(
    IDXGISwapChain* This,
    /* [in] */ UINT BufferCount,
    /* [in] */ UINT Width,
    /* [in] */ UINT Height,
    /* [in] */ DXGI_FORMAT NewFormat,
    /* [in] */ UINT SwapChainFlags);

struct D3DHook {
    static FPTR_IDXGISwapChain_Present IDXGISwapChain_Present_Trampoline;
    static HRESULT __stdcall IDXGISwapChain_Present_Hook(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT PresentFlags);
    static PFN_IDXGISwapChain_ResizeBuffers IDXGISwapChain_ResizeBuffers_Trampoline;
    static HRESULT STDMETHODCALLTYPE IDXGISwapChain_ResizeBuffers_Hook(IDXGISwapChain* This, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);

    static bool CreateDummySwapChain(IDXGISwapChain** ppSwapChain);
    static void GetFunctionPointers(FPTR_IDXGISwapChain_Present* pPresentTarget);
    static void InitializeHooks();
	static void Initialize();
};