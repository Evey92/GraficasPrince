#include "stdafx.h"
#include "ViewPort.h"


ViewPort::ViewPort()
{
}


ViewPort::~ViewPort()
{
}

void ViewPort::Create(float x, float y, float width, float height)
{
	m_D3DViewPort->TopLeftX = x;
	m_D3DViewPort->TopLeftY = y;
	m_D3DViewPort->Width = width;
	m_D3DViewPort->Height = height;
}
