#include "Graphics.h"
#include <assert.h>

#pragma comment(lib, "d3d11.lib")

Graphics::Graphics(HWND hWnd)
{
	// Feature Level
	D3D_FEATURE_LEVEL DX11 = D3D_FEATURE_LEVEL_11_0;

	//SwapChainDescription
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapChainDesc.BufferCount = 1; // 1 means double buffer, one back buffer(and one front buffer).
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.Windowed = true;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.Width = 0;
	swapChainDesc.BufferDesc.Height = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.SampleDesc.Count = 1;

	HRESULT result;
	result = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG, &DX11, 1, D3D11_SDK_VERSION, &swapChainDesc, &pSwapchain, &pDevice, 0, &pDeviceContext);
	assert(!FAILED(result));

	// gain access to texture subresource in swap chain (back buffer)
	ID3D11Resource* pBackBuffer = nullptr;
	pSwapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&pBackBuffer));

	// Create Render Target View
	pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pTargetView);
	pBackBuffer->Release();

}

Graphics::~Graphics()
{
	if(pTargetView)
	{
		pTargetView->Release();
	}
	if (pSwapchain)
	{
		pSwapchain->Release();
	}
	if (pDeviceContext)
	{
		pDeviceContext->Release();
	}

	if (pDevice)
	{
		pDevice->Release();
	}
}

void Graphics::EndFrame()
{
	pSwapchain->Present(0, 0);
}

void Graphics::ClearBuffer(float red, float green, float blue)
{
	const float color[] = { red,green,blue,1.0f };
	pDeviceContext->ClearRenderTargetView(pTargetView, color);
}
