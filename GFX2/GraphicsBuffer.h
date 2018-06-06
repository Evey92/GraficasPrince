#pragma once

#include <d3d11.h>
#include <vector>
#include <exception>

using std::vector;
using std::exception;

class GraphicsBuffer
{
public:
	GraphicsBuffer() = default;
	virtual	~GraphicsBuffer() 
	{
		if (m_pBuffer)
			m_pBuffer->Release();
	}

public:
	///

public:
	ID3D11Buffer* m_pBuffer = nullptr;
};

template<typename TVERTEX>

class VertexBuffer final : public GraphicsBuffer
{
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

///INDEX
template<typename ITYPE>

class IndexexBuffer final : public GraphicsBuffer
{
	IndexexBuffer() = default;
	~IndexexBuffer() {}

	void reserve(size_t numObjects)
	{
		m_indexData.reserve(numObjects);
	}

	void add(const ITYPE& vertex)
	{
		m_indexData.push_back(vertex);
	}

	void add(const vector<ITYPE>& vertices)
	{
		m_indexData.insert(m_indexData.end(), vertices.begin(), vertices.end())
	}

	void add(const ITYPE* pVertices, size_t numVertices)
	{
		m_indexData.insert(m_indexData.end(), pVertices, pVertices + numVertices)
	}

	void clear()
	{
		m_indexData.clear();
	}

	void createHardwareBuffer(ID3D11Device* pd3dDevice, unsigned int usage = D3D11_USAGE_DEFAULT)
	{
		D3D11_BUFFER_DESC bd;
		memset(&bd, 0, sizeof(bd));

		bd.Usage = usage;
		bd.ByteWidth = static_cast<uint32>(sizeof(ITYPE)* m_indexData.size());
		bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bd.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA InitData;
		memset(&InitData, 0, sizeof(InitData));
		InitData.pSysMem = &m_indexData[0];

		HRESULT hr = g_pd3dDevice->CreateBuffer(&bd, &InitData, &m_pBuffer);
		if (FAILED(hr))
		{
			throew exception("Failed to create Vertex Buffer).");
		}
	}

	void write(ID3D11DeviceContext* pDeviceContext, void* pData, size_t numBytes)
	{
		D3D11_MAPPED_SUBRESOURCE subRes;
		memset(&subRes, 0, sizeof(subRes));

		pDeviceContext->Map(m_pBuffer, nullptr, D3D11_MAP_WRITE_DISCARD, &subRes);

		pDeviceContext->Unmap(m_pBuffer, 0);
	}

private:
	vector<ITYPE> m_indexData;
};

template<typename ConsVERTEX>

class ConstantBuffer final : public GraphicsBuffer
{
	ConstantBuffer() = default;
	~ConstantBuffer() {}

	void reserve(size_t numObjects)
	{
		m_indexData.reserve(numObjects);
	}

	void add(const ConsVERTEX& vertex)
	{
		m_indexData.push_back(vertex);
	}

	void add(const vector<ConsVERTEX>& vertices)
	{
		m_indexData.insert(m_indexData.end(), vertices.begin(), vertices.end())
	}

	void add(const ConsVERTEX* pVertices, size_t numVertices)
	{
		m_indexData.insert(m_indexData.end(), pVertices, pVertices + numVertices)
	}

	void clear()
	{
		m_indexData.clear();
	}

	void createHardwareBuffer(ID3D11Device* pd3dDevice, unsigned int usage = D3D11_USAGE_DEFAULT)
	{
		D3D11_BUFFER_DESC bd;
		memset(&bd, 0, sizeof(bd));

		bd.Usage = usage;
		bd.ByteWidth = static_cast<uint32>(sizeof(ITYPE)* m_indexData.size());
		bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bd.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA InitData;
		memset(&InitData, 0, sizeof(InitData));
		InitData.pSysMem = &m_indexData[0];

		HRESULT hr = g_pd3dDevice->CreateBuffer(&bd, &InitData, &m_pBuffer);
		if (FAILED(hr))
		{
			throew exception("Failed to create Vertex Buffer).");
		}
	}

	void write(ID3D11DeviceContext* pDeviceContext, void* pData, size_t numBytes)
	{
		D3D11_MAPPED_SUBRESOURCE subRes;
		memset(&subRes, 0, sizeof(subRes));

		pDeviceContext->Map(m_pBuffer, nullptr, D3D11_MAP_WRITE_DISCARD, &subRes);

		pDeviceContext->Unmap(m_pBuffer, 0);
	}

private:
	vector<ConsVERTEX> m_indexData;
};