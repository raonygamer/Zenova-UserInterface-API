#include "Zenova.h"
#include "generated/initcpp.h"
#include "mod/D3DHook.h"
#include <dxgi1_5.h>

typedef HRESULT(STDMETHODCALLTYPE* PFN_IDXGISwapChain_Present)(
	IDXGISwapChain* This,
	/* [in] */ UINT SyncInterval,
	/* [in] */ UINT Flags);

typedef HRESULT(STDMETHODCALLTYPE* PFN_IDXGISwapChain_Present1)(
	IDXGISwapChain1* This,
	/* [in] */ UINT SyncInterval,
	/* [in] */ UINT Flags,
	const DXGI_PRESENT_PARAMETERS* pPresentParameters);

PFN_IDXGISwapChain_Present1 Original_IDXGISwapChain_Present1 = nullptr;
HRESULT STDMETHODCALLTYPE IDXGISwapChain_Present1_Hook(IDXGISwapChain1* This, UINT SyncInterval, UINT Flags, const DXGI_PRESENT_PARAMETERS* pPresentParameters) {
	Zenova_Info("Present1");
	return Original_IDXGISwapChain_Present1(This, SyncInterval, Flags, pPresentParameters);
}

//0x68DC0

MOD_FUNCTION void ModLoad(ModContext& ctx) {
	
}

MOD_FUNCTION void ModStart() {
	D3DHook::Initialize();
}

MOD_FUNCTION void ModTick() {
	
}

MOD_FUNCTION void ModStop() {
	
}