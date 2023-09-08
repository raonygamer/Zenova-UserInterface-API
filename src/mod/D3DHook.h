#pragma once
#include "Zenova.h"
#include "ImGuiEx.h"
#include <dxgi.h>
#include <d3d11.h>

typedef HRESULT (*__stdcall FPTR_IDXGISwapChain_Present)(
    IDXGISwapChain* SwapChain,
    UINT SyncInterval,
    UINT PresentFlags);

struct D3DHook {
    static FPTR_IDXGISwapChain_Present IDXGISwapChain_Present_Trampoline;
    static HRESULT __stdcall IDXGISwapChain_Present_Hook(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT PresentFlags);

    static bool CreateDummySwapChain(IDXGISwapChain** ppSwapChain);
    static void GetFunctionPointers(FPTR_IDXGISwapChain_Present* pPresentTarget);
    static void InitializeHooks();
	static void Initialize();
};