#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Texture_Manager.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
	Release();
}

HRESULT CMainGame::Initialize()
{
	CGraphic_Device::Get_Instance()->Ready_Graphic_Device();

	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();
	return S_OK;
}

void CMainGame::Update()
{
	m_pPlayer->Update();
}

void CMainGame::Render()
{
	CGraphic_Device::Get_Instance()->Render_Begin();
	m_pPlayer->Render();
	CGraphic_Device::Get_Instance()->Render_End();
}

void CMainGame::Release()
{
	CGraphic_Device::Destroy_Instance();
}

CMainGame * CMainGame::Create()
{
	CMainGame* pInstance = new CMainGame;
	/*if (0x80000000 & pInstance->Ready_MainApp())*/
	if (FAILED(pInstance->Initialize()))
	{
		delete pInstance;
		pInstance = nullptr;
		return pInstance;
	}
	return pInstance;
}
