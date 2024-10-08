// Written by syri.
//
#include <EnginePCH.h>
#include "Application.h"

#include <Application/Window.h>
#include <Application/WindowData.h>


namespace Engine
{
	CApplication::CApplication()
		: m_bRunning(true)
    {}

    CApplication::~CApplication()
    {
		for (CWindow* WindowReference : Windows)
		{
			WindowReference = nullptr;
			delete WindowReference;
		}
    }

    void CApplication::Run()
    {
        while (m_bRunning)
        {
			for (CWindow* WindowReference : Windows)
			{
				if (!WindowReference->Update()) m_bRunning = false;
				else WindowReference->Render();
			}
        }
    }

	void CApplication::CreateNewWindow(SWindowDescriptor& InWindowDescriptor, const ERendererType InRendererType)
	{
		bool bFoundExistingWindow = true;
		uint32_t ID;		

		if (Windows.size() > 0)
		{
			while (bFoundExistingWindow)
			{
				ID = rand() % 1000;

				for (CWindow* WindowReference : Windows)
				{
					bFoundExistingWindow = WindowReference->ID == ID;
				}
			}
		}
		else ID = rand() % 1000;

		Windows.push_back(new CWindow(ID, InWindowDescriptor, InRendererType));
	}
}
