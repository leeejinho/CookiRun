#include "stdafx.h"
#include "MainGame.h"
#include "SceneMgr.h"
#include "Graphic_Device.h"
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
	CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::STAGE);


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
