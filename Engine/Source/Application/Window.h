// Written by syri.
//
#pragma once
#include <API.h>
#include <Application/Application.h>
#include <Application/WindowData.h>
#include <Math/Colour.h>


namespace Engine
{
	class UMA_API CWindow
	{
	public:
		const uint32_t ID;

		SWindowDescriptor& WindowDescriptor;
		
		MSG Message;

		ERendererType RHIRendererType;
		IRenderer* Renderer;

	private:
		HINSTANCE m_InstanceHandle;

	public:
		CWindow(uint32_t InID, SWindowDescriptor& InWindowDescriptor, const ERendererType InRHIRendererType);
		~CWindow();

		bool Update();
		void Render();
		
		static LRESULT CALLBACK MessageHandler(HWND WindowHandle, UINT Message, WPARAM WParam, LPARAM LParam);

	};
}
