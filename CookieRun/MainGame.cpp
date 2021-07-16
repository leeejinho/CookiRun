#include "stdafx.h"
#include "MainGame.h"
#include "Graphic_Device.h"
#include "Hpup.h"
#include "Giant.h"
#include "Score.h"
#include "Speed.h"

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
	m_pHpup = new CHpup;
	m_pHpup->Initialize();

	m_pGiant = new CGiant;
	m_pGiant->Initialize();

	m_pScore = new CScore;
	m_pScore->Initialize();

	m_pSpeed = new CSpeed;
	m_pSpeed->Initialize();


	return S_OK;
}

void CMainGame::Update()
{
}

void CMainGame::Render()
{
	CGraphic_Device::Get_Instance()->Render_Begin();

	m_pHpup->Render();

	m_pGiant->Render();

	m_pScore->Render();

	m_pSpeed->Render();

	CGraphic_Device::Get_Instance()->Render_End();
}

void CMainGame::Release()
{
	CGraphic_Device::Get_Instance()->Release_Graphic_Device();
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
