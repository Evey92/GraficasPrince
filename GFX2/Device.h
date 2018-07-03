#pragma once
#include <d3d11.h>
#include <vector>

#define MAX_LOADSTRING 100
using std::vector;

class Device
{
public:
	HWND g_hWnd;
	ID3D11Device* g_pd3dDevice = nullptr;
	ID3D11DeviceContext* g_pImmediateContext = nullptr;
	IDXGISwapChain* g_SwapChain = nullptr;
	ID3D11RenderTargetView* g_pRenderTargetView = nullptr;
	ID3D11Texture2D* g_pDepthStencil = nullptr;
	ID3D11DepthStencilView* g_pDepthStencilView = nullptr;
	HINSTANCE hInst;

	Device();
	~Device();
	HRESULT initDevice();
};

