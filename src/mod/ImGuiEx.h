#pragma once

#include <basetsd.h>
#include <dxgi.h>
#include <dxgi1_5.h>
#include <tchar.h>
#include <d3d11.h>
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_winrt.h"
#include <CoreWindow.h>
#include <Windows.h>
#include "Zenova.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
struct ImGuiEx {
	static bool Initialized;

	static IDXGISwapChain* SwapChain;
	static ID3D11Device* Device;
	static ID3D11DeviceContext* DeviceContext;
	static ID3D11RenderTargetView* RenderTargetView;
    static IUnknown* CoreWindow;
    static HWND Window;
	static HWND InputSinkWindow;
	static HWND FrameWindow;
	static WNDPROC OriginalWndProcHandler;

	static void InitializeImGui(IDXGISwapChain* SwapChain);
	static bool GetDeviceAndContext(IDXGISwapChain* pSwapChain, ID3D11Device** outDevice, ID3D11DeviceContext** outDeviceContext);
	static void Render(IDXGISwapChain* SwapChain);
	static void Draw(IDXGISwapChain* SwapChain);
    static void CreateRenderTarget(IDXGISwapChain* SwapChain);
    static void ReleaseRenderTarget();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    static BOOL CALLBACK EnumChildProc(
        _In_ HWND   hwnd,
        _In_ LPARAM lParam
    )
    {
        wchar_t buf[256];
        GetClassNameW(hwnd, buf, 256);

        if (wcscmp(buf, L"Windows.UI.Core.CoreWindow") == 0)
        {
            Window = hwnd;
        }

        return true;
    };

    static bool TryFindCoreWindow()
    {
        if (FrameWindow == nullptr)
        {
            FrameWindow = FindWindowW(L"ApplicationFrameWindow", L"Minecraft");
        }
        EnumChildWindows(FrameWindow, EnumChildProc, 0);
        return Window != nullptr;
    }
};