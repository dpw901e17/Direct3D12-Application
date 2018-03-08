#pragma once
#include <vector>
#include <windows.h>
#include <DirectXMath.h>
#include <d3d12.h>
#include "d3dx12.h"
#include "../../scene-window-system/RenderObject.h"

class Cube {
public:
	Cube(int index, std::vector<ID3D12Resource*> uploadHeapResources, 
		const RenderObject& renderObject, const float scale);
	~Cube();

	UINT8* GetMappedGpuAddress(int frameBufferIndex) const;
	D3D12_GPU_VIRTUAL_ADDRESS GetVirtualGpuAddress(int frameBufferIndex) const;
	void UpdateWVPMatrix(int frameBufferIndex);


private:
	//Matrix data
	DirectX::XMFLOAT4X4 cubeWorldMat;
	DirectX::XMFLOAT4X4 cubeRotMat;
	DirectX::XMFLOAT4 cubePosition;

	//Memory Addresses
	std::vector<UINT8*> mappedGpuAddresses;
	std::vector<D3D12_GPU_VIRTUAL_ADDRESS> virtualGpuAdresses;

	int index;
	int constantBufferPerObjectAllignedSize = sizeof(DirectX::XMFLOAT4X4) + 255 & ~255;
	float m_Scale = 1.0;

};