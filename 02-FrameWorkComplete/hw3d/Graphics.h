#pragma once
#include "ChiliWin.h"
#include <d3d11.h>

class Graphics
{
public:
	Graphics(HWND hWnd);
	Graphics(const Graphics& ) = delete;
	Graphics& operator=(const Graphics& ) = delete;
	~Graphics();
	void EndFrame();
	void ClearBuffer(float red, float green, float blue);
private:
	ID3D11Device* pDevice;
	IDXGISwapChain* pSwapchain;
	ID3D11DeviceContext* pDeviceContext;
	ID3D11RenderTargetView* pTargetView;
};

