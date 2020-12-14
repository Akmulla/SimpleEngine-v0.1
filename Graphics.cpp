#include "Graphics.h"

Graphics::Graphics(HWND hwnd)
{
	DXGI_SWAP_CHAIN_DESC sd;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = hwnd;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;

	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&sd,
		&pSwap,
		&pDevice,
		nullptr,
		&pContext
	);

	ID3D11Resource* pBackBuffer = nullptr;
	pSwap->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&pBackBuffer));
	pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pTarget);
	pBackBuffer->Release();
}

Graphics::~Graphics()
{

}

void Graphics::ClearBackground(ColorRGBA colorRGBA)
{
	const float color[] = { colorRGBA.r,colorRGBA.g,colorRGBA.b,colorRGBA.a };
	pContext->ClearRenderTargetView(pTarget, color);
}

void Graphics::EndFrame()
{
	pSwap->Present(1u, 0u);
}

void Graphics::RenderGameObject(const GameObject& gameObject)
{
	
	//using namespace Microsoft::WRL;
	Mesh* mesh = gameObject.GetComponent<Mesh>();
	Transform* transform = gameObject.GetComponent<Transform>();

	if (!mesh || !transform)
		return;

	DirectX::XMFLOAT3* baseVertices = mesh->dxVertices;
	int size = mesh->size;
	DirectX::XMFLOAT3* dxVertices = new DirectX::XMFLOAT3[size];
	DirectX::XMFLOAT3 dxPosition(transform->position.x, transform->position.y, 0.0f);

	for (int i = 0; i < size; i++)
	{
		//DirectX::XMVECTOR v1 = DirectX::XMLoadFloat3(&baseVertices[i]);
		//DirectX::XMVECTOR v2 = DirectX::XMLoadFloat3(&dxPosition);
		//DirectX::XMStoreFloat3(&dxVertices[i],DirectX::XMVectorAdd (v1 , v2));
		dxVertices[i] = baseVertices[i];
	}

	
	//vertex buffer
	Microsoft::WRL::ComPtr<ID3D11Buffer> pVertexBuffer;
	D3D11_BUFFER_DESC bd = {};
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.CPUAccessFlags = 0u;
	bd.MiscFlags = 0u;
	bd.ByteWidth = sizeof(DirectX::XMFLOAT3) * size;
	bd.StructureByteStride = sizeof(Vertex);
	D3D11_SUBRESOURCE_DATA sd = {};
	sd.pSysMem = dxVertices;
	pDevice->CreateBuffer(&bd, &sd, &pVertexBuffer);

	const UINT stride = sizeof(Vertex);
	const UINT offset = 0u;
	pContext->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &stride, &offset);

	Microsoft::WRL::ComPtr<ID3DBlob> pBlob;

	//PixelShader
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pPixelShader;
	D3DReadFileToBlob(L"PixelShader.cso", &pBlob);
	pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader);
	
	pContext->PSSetShader(pPixelShader.Get(), nullptr, 0u);
	////

	//Vertex shader
	Microsoft::WRL::ComPtr<ID3D11VertexShader> pVertexShader;

	D3DReadFileToBlob(L"VertexShader.cso", &pBlob);
	pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader);

	pContext->VSSetShader(pVertexShader.Get(), 0, 0);

	//Constant buffer for transformation matrix
	struct ConstantBuffer
	{
		DirectX::XMMATRIX transformation;
	};

	const ConstantBuffer cb =
	{
		{
			DirectX::XMMatrixTranspose( 
				DirectX::XMMatrixTranslation(transform->position.x, transform->position.y, 0.0f) * 
				DirectX::XMMatrixRotationZ(transform->rotation)
			)
		}
	};

	Microsoft::WRL::ComPtr<ID3D11Buffer> pConstantBuffer;
	CD3D11_BUFFER_DESC cb_desc;
	cb_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb_desc.Usage = D3D11_USAGE_DYNAMIC;
	cb_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb_desc.MiscFlags = 0u;
	cb_desc.ByteWidth = sizeof(cb);
	cb_desc.StructureByteStride = 0u;
	D3D11_SUBRESOURCE_DATA subresource = {};
	subresource.pSysMem = &cb;
	pDevice->CreateBuffer(&cb_desc, &subresource, &pConstantBuffer);
	pContext->VSSetConstantBuffers(0u, 1u, pConstantBuffer.GetAddressOf());


	//////
	Microsoft::WRL::ComPtr<ID3D11InputLayout> pInputLayout;
	const D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{"Position",0,DXGI_FORMAT_R32G32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
	};

	pDevice->CreateInputLayout(ied,
		(UINT)std::size(ied),
		pBlob->GetBufferPointer(),
		pBlob->GetBufferSize(),
		&pInputLayout);

	//Set input layout
	pContext->IASetInputLayout(pInputLayout.Get());

	//Set render targets
	pContext->OMSetRenderTargets(1u, &pTarget, nullptr);

	//Set primitive topology
	pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	//configure viewport
	CD3D11_VIEWPORT vp;
	vp.Width = 1024;
	vp.Height = 768;
	vp.MinDepth = 0;
	vp.MaxDepth = 1;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	pContext->RSSetViewports(1u, &vp);

	pContext->Draw(sizeof(DirectX::XMFLOAT3)*size, 0u);
	
}

