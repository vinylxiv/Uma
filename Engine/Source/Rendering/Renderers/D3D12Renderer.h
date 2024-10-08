// Written by syri.
//
#pragma once
#include <API.h>
#include <Rendering/IRenderer.h>


namespace Engine
{
	class CD3D12Renderer : public IRenderer
	{
	private:
		static const uint32_t s_FrameCount = 2;

		uint32_t m_renderTargetViewDescriptorSize;
		uint32_t m_FrameIndex;
		HANDLE m_FenceEvent;
		uint64_t m_FenceValue;
		bool m_bUseWarpDevice;

		Microsoft::WRL::ComPtr<IDXGISwapChain3> m_SwapChain;
		Microsoft::WRL::ComPtr<ID3D12Device> m_Device;
		Microsoft::WRL::ComPtr<ID3D12Resource> m_renderTargets[s_FrameCount];
		Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_CommandAllocator;
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_CommandQueue;
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_RenderTargetViewHeap;
		Microsoft::WRL::ComPtr<ID3D12PipelineState> m_PipelineState;
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_CommandList;
		Microsoft::WRL::ComPtr<ID3D12Fence> m_Fence;

	public:
		UMA_API CD3D12Renderer(SWindowDescriptor& InWindowDescriptor);

		UMA_API void Initialise();
		UMA_API void Update();
		UMA_API void Render();
		UMA_API void Destroy();

		UMA_API void GetHardwareAdapter(IDXGIFactory2* FactoryPointer, IDXGIAdapter1** AdapterPointer);

	private:
		UMA_API void LoadPipeline();
		UMA_API void LoadAssets();
		UMA_API void PopulateCommandList();
		UMA_API void WaitForPreviousFrame();

	};
}
