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
#include "ObjMgr.h"
#include "Hpbar.h"

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
  


	/*m_pJelly = new CJelly(400.f,200.f);
	m_pJelly->Initialize();*/

	return S_OK;
}

void CMainGame::Update()
{
	CSceneMgr::Get_Instance()->Update();
	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	CGraphic_Device::Get_Instance()->Render_Begin();
  
	CSceneMgr::Get_Instance()->Render();

  CGraphic_Device::Get_Instance()->Render_End();
}

void CMainGame::Release()
{
	CKeyMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();
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

