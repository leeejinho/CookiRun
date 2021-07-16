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
#include "SceneMgr.h"
#include "KeyMgr.h"

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

 	CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::STAGE);
  
	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();

	m_pHpup = new CHpup(500.f,100.f);		//���⼭ �ġ ����ֱ�
	m_pHpup->Initialize();

	m_pGiant = new CGiant(300.f,200.f);		//���⼭ �ġ ����ֱ�
	m_pGiant->Initialize();

	m_pScore = new CScore(500.f,300.f);		//���⼭ �ġ ����ֱ�
	m_pScore->Initialize();

	m_pSpeed = new CSpeed(100.f,500.f);	//���⼭ �ġ ����ֱ�
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

	CSceneMgr::Get_Instance()->Update();
	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	CGraphic_Device::Get_Instance()->Render_Begin();
  
	m_pPlayer->Render();	// 364*364

	m_pHpup->Render();		// 90*90

	m_pGiant->Render();		// 90*90

	m_pScore->Render();		// 90*90

	m_pSpeed->Render();		// 90*90

	m_pJelly->Render();		// 40*53

	CSceneMgr::Get_Instance()->Render();

  CGraphic_Device::Get_Instance()->Render_End();
}

void CMainGame::Release()
{
	CGraphic_Device::Destroy_Instance();
  CSceneMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
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

