#pragma once

#include <d3d11.h>

class ViewPort
{
public:
	D3D11_VIEWPORT* m_D3DViewPort;
	float minDepth = 0.0f;
	float maxDepth = 1.0f;

	ViewPort();
	~ViewPort();
	void Create(float x = 0.0f, float y = 0.0f, float width = 1.0f, float height = 0.0f);
};
