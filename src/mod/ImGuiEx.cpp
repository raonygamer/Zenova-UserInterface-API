#include "ImGuiEx.h"

bool ImGuiEx::Initialized = false;
IDXGISwapChain* ImGuiEx::SwapChain = nullptr;
ID3D11Device* ImGuiEx::Device = nullptr;
ID3D11DeviceContext* ImGuiEx::DeviceContext = nullptr;
ID3D11RenderTargetView* ImGuiEx::RenderTargetView = nullptr;
WNDPROC ImGuiEx::OriginalWndProcHandler = nullptr;

IUnknown* ImGuiEx::CoreWindow = nullptr;
HWND ImGuiEx::Window = nullptr;
HWND ImGuiEx::InputSinkWindow = nullptr;
HWND ImGuiEx::FrameWindow = nullptr;

void ImGuiEx::InitializeImGui(IDXGISwapChain* SwapChain)
{
	if (!Initialized) {
		ImGuiEx::SwapChain = SwapChain;
		if (GetDeviceAndContext(SwapChain, &Device, &DeviceContext)) {
			DXGI_SWAP_CHAIN_DESC desc;
			SwapChain->GetDesc(&desc);

			if (SwapChain)
			{
				reinterpret_cast<IDXGISwapChain1*>(SwapChain)->GetCoreWindow(__uuidof(IUnknown), (void**)&CoreWindow);
				Zenova_Info("Is CoreWindow nullptr: {}", CoreWindow == nullptr);
			}

			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO(); (void)io;
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

			if (!TryFindCoreWindow())
				return;

			//OriginalWndProcHandler = (WNDPROC)SetWindowLongPtr(Window, GWLP_WNDPROC, (LONG_PTR)ImGuiEx::WndProc);

			ImGui_ImplWinRT_Init(CoreWindow);
			ImGui_ImplDX11_Init(Device, DeviceContext);

			ReleaseRenderTarget();
			CreateRenderTarget(SwapChain);

			Initialized = true;
		}
	}
}

bool ImGuiEx::GetDeviceAndContext(IDXGISwapChain* pSwapChain, ID3D11Device** outDevice, ID3D11DeviceContext** outDeviceContext)
{
	if (pSwapChain) {
		if (SUCCEEDED(pSwapChain->GetDevice(IID_ID3D11Device, (void**)outDevice))) {
			if (outDeviceContext)
			{
				(*outDevice)->GetImmediateContext(outDeviceContext);
				return true;
			}
		}
	}
	return false;
}

void ImGuiEx::Render(IDXGISwapChain* SwapChain)
{
	if (!Initialized) return;
	ImGui_ImplWinRT_NewFrame();
	ImGui_ImplDX11_NewFrame();

	ImGui::NewFrame();

	Draw(SwapChain);

	ImGui::EndFrame();

	ImGui::Render();

	DeviceContext->OMSetRenderTargets(1, &RenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

inline bool showWindow = false;
void ImGuiEx::Draw(IDXGISwapChain* SwapChain)
{
	if (ImGui::IsKeyReleased(ImGuiKey_Insert))
		showWindow = !showWindow;

	if (showWindow) {
		ImGui::ShowDemoWindow(&showWindow);
	}
}

void ImGuiEx::CreateRenderTarget(IDXGISwapChain* SwapChain)
{
	ID3D11Texture2D* pBackBuffer;

	SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	if (pBackBuffer)
		Device->CreateRenderTargetView(pBackBuffer, NULL, &RenderTargetView);
	pBackBuffer->Release();
}

void ImGuiEx::ReleaseRenderTarget()
{
	if (RenderTargetView)
		RenderTargetView->Release();
}

LRESULT CALLBACK ImGuiEx::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	return CallWindowProc(ImGuiEx::OriginalWndProcHandler, hWnd, uMsg, wParam, lParam);
}