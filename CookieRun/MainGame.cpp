#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Texture_Manager.h"
#include "Graphic_Device.h"
#include "Hpup.h"
#include "Giant.h"
#include "Score.h"
#include "Speed.h"
#include "Jelly.h"


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

	m_pHpup = new CHpup(500.f,100.f);		//여기서 위치 정해주기
	m_pHpup->Initialize();

	m_pGiant = new CGiant(300.f,200.f);		//여기서 위치 정해주기
	m_pGiant->Initialize();

	m_pScore = new CScore(500.f,300.f);		//여기서 위치 정해주기
	m_pScore->Initialize();

	m_pSpeed = new CSpeed(100.f,500.f);	//여기서 위치 정해주기
	m_pSpeed->Initialize();

	m_pJelly = new CJelly(400.f,200.f);
	m_pJelly->Initialize();

	return S_OK;
}

void CMainGame::Update()
{
	m_pPlayer->Update();
	m_pHpup->Update();
	m_pGiant->Update();
	m_pScore->Update();
	m_pSpeed->Update();
	m_pJelly->Update();
}

void CMainGame::Render()
{
	CGraphic_Device::Get_Instance()->Render_Begin();
  
	m_pPlayer->Render();	//쿠키 사이즈 364*364

	m_pHpup->Render();		//아이템 사이즈 90*90

	m_pGiant->Render();		//아이템 사이즈 90*90

	m_pScore->Render();		//아이템 사이즈 90*90

	m_pSpeed->Render();		//아이템 사이즈 90*90

	m_pJelly->Render();		//아이템 사이즈 40*53
  
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
