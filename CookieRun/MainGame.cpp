#include "stdafx.h"
#include "MainGame.h"

#include "Player.h"
#include "Texture_Manager.h"
#include "Graphic_Device.h"
#include "Hpup.h"
#include "Giant.h"
#include "Score.h"
#include "Speed.h"
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
	m_pPlayer->Update();
  
  CSceneMgr::Get_Instance()->Update();
	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	CGraphic_Device::Get_Instance()->Render_Begin();
  
	CSceneMgr::Get_Instance()->Render();
	m_pPlayer->Render();

	m_pHpup->Render();

	m_pGiant->Render();

	m_pScore->Render();

	m_pSpeed->Render();
  


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

