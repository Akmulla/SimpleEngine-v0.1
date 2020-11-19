#pragma once
#include <DirectXMath.h>
#include "Geometry.h"
#include <memory>
#include <vector>
#include "Component.h"
#include "Mesh.h"
#include "Transform.h"
#include "Scene.h"

class GameObject
{
public:
	GameObject(Scene& scene);
	~GameObject();
	void AddComponent(Component&);
	Scene& scene;

	template<typename T>
	T* GetComponent() const
	{
		for (auto it = m_components.begin(); it != m_components.end(); ++it)
		{
			T* component = dynamic_cast<T*>(*it);
			if (component)
				return component;
		}

		return nullptr;
	}

	void UpdateAllComponents(double);
private:
	std::vector<Component*> m_components;
};