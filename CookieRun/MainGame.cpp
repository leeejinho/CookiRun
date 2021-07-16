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
  
	CObj* pObj = new CPlayer;
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::PLAYER);

	pObj = new CHpup(500.f,100.f);
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::SP);

	pObj = new CGiant(300.f,200.f);
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::GIANT);

	pObj = new CScore(500.f,300.f);
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::HP);

	pObj = new CSpeed(100.f,500.f);
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::SPEED);

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

