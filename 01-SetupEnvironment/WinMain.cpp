
#include "Window.h"
#include <d3d11.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <sstream>

#define MAX_LOADSTRING 100

ID3D11Device* g_Device;
IDXGISwapChain* g_Swapchain;
ID3D11DeviceContext* g_DeviceContext;
ID3D11RenderTargetView* g_RenderTargetView;
D3D11_VIEWPORT g_viewport;
float g_aspectRatio;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    Window wnd(800, 300, "MyWindow");


    MSG msg;

    // Main message loop:
    while (true)
    {
        PeekMessage(&msg, nullptr, 0,0,PM_REMOVE);

        TranslateMessage(&msg);
        DispatchMessage(&msg);
        
        if (msg.message == WM_QUIT)
            break;
        if (GetAsyncKeyState(VK_ESCAPE))
            break;

        // Rendering Code
        //ID3D11RenderTargetView* tempRTV[] = { g_RenderTargetView };
        //g_DeviceContext->OMSetRenderTargets(1, tempRTV, nullptr);

        //float color[4] = { 1, 0, 0, 1 };
        //g_DeviceContext->ClearRenderTargetView(g_RenderTargetView, color);

        //g_DeviceContext->RSSetViewports(1, &g_viewport);

        //g_Swapchain->Present(0, 0);
    }

    //g_Device->Release();
    //g_DeviceContext->Release();
    //g_RenderTargetView->Release();
    //g_Swapchain->Release();

    return (int) msg.wParam;
}


//
//   // D3d11 code here
//   RECT rect;
//   GetClientRect(hWnd, &rect);
//
//   // Attach d3d to the window
//   D3D_FEATURE_LEVEL DX11 = D3D_FEATURE_LEVEL_11_0;
//   DXGI_SWAP_CHAIN_DESC swap;
//   ZeroMemory(&swap, sizeof(DXGI_SWAP_CHAIN_DESC));
//   swap.BufferCount = 1;
//   swap.OutputWindow = hWnd;
//   swap.Windowed = true;
//   swap.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
//   swap.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//   swap.BufferDesc.Width = rect.right - rect.left;
//   swap.BufferDesc.Height = rect.bottom - rect.top;
//   swap.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//   swap.SampleDesc.Count = 1;
//
//   g_aspectRatio = swap.BufferDesc.Width / (float)swap.BufferDesc.Height;
//
//   HRESULT result;
//
//   result = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG, &DX11, 1, D3D11_SDK_VERSION, &swap, &g_Swapchain, &g_Device, 0, &g_DeviceContext);
//   assert(!FAILED(result));
//
//   ID3D11Resource* backbuffer;
//   result = g_Swapchain->GetBuffer(0, __uuidof(backbuffer), (void**)&backbuffer);
//   result = g_Device->CreateRenderTargetView(backbuffer, NULL, &g_RenderTargetView);
//   assert(!FAILED(result));
//
//   // Release the resource to decrement the counter by one
//   // This is necessary to keep the buffer from leaking memory
//   backbuffer->Release();
//
//   // Setup viewport
//   g_viewport.Width = swap.BufferDesc.Width;
//   g_viewport.Height = swap.BufferDesc.Height;
//   g_viewport.TopLeftY = g_viewport.TopLeftX = 0;
//   g_viewport.MinDepth = 0;
//   g_viewport.MaxDepth = 1;
//   // D3d11 code here