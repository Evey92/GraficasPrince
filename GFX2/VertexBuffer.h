#pragma once
#include <d3d11.h>
#include <vector>

using std::vector;

template<typename TVERTEX>
class VertexBuffer
{

public:

	VertexBuffer() = default;
	~VertexBuffer() {}

	void reserve(size_t numObjects)
	{
		m_vertexData.reserve(numObjects);
	}

	void add(const TVERTEX& vertex)
	{
		m_vertexData.push_back(vertex);
	}

	void add(const vector<TVERTEX>& vertices)
	{
		m_vertexData.insert(m_vertexData.end(), vertices.begin(), vertices.end())
	}

	void add(const TVERTEX* pVertices, size_t numVertices)
	{
		m_vertexData.insert(m_vertexData.end(), pVertices, pVertices + numVertices)
	}

	void clear()
	{
		m_vertexData.clear();
	}

	void createHardwareBuffer(ID3D11Device* pd3dDevice, unsigned int usage = D3D11_USAGE_DEFAULT)
	{
		D3D11_BUFFER_DESC bd;
		memset(&bd, 0, sizeof(bd));

		bd.Usage = usage;
		bd.ByteWidth = static_cast<uint32>(sizeof(TVERTEX)* m_vertexData.size());
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA InitData;
		memset(&InitData, 0, sizeof(InitData));
		InitData.pSysMem = &m_vertexData[0];

		HRESULT hr = g_pd3dDevice->CreateBuffer(&bd, &InitData, &m_pBuffer);
		if (FAILED(hr))
		{
			throew exception("Failed to create Vertex Buffer).");
		}
	}

private:
	
	vector<TVERTEX> m_indexData;
};