#include "GameObject.h"

GameObject::GameObject(DirectX::XMFLOAT3* vertices, int size)
{
	this->dxVertices = vertices;
	this->size = size;
}

GameObject::~GameObject()
{

}