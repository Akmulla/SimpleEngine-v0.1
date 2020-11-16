#pragma once
#include <DirectXMath.h>
#include "Geometry.h"
#include <memory>
#include <vector>

class Component;

class GameObject
{
public:
	GameObject(DirectX::XMFLOAT3*,int);
	~GameObject();
	void AddComponent(Component&);

	template<typename T>
	T* GetComponent()
	{
		for (auto it = m_components.begin(); it != m_components.end(); ++it)
		{
			T* component = dynamic_cast<T*>(it);
			if (component)
				return component;
		}

		return nullptr;
	}


	DirectX::XMFLOAT3 position;
	//DirectX::XMFLOAT3* dxVertices;
	int size;

	DirectX::XMFLOAT3 dxCoord;
	DirectX::XMFLOAT3* dxVertices;
private:
	std::vector<Component*> m_components;
};