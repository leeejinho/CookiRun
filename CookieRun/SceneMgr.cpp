#include "stdafx.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Stage.h"
#include "Player.h"
#include "ObjMgr.h"
#include "KeyMgr.h"

CSceneMgr* CSceneMgr::m_Instance = nullptr;
CSceneMgr::CSceneMgr()
	: m_ePreScene(END), m_eCurScene(END), m_pScene(nullptr)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change(SCENEID _eID)
{
	m_eCurScene = _eID;

	if (m_ePreScene != m_eCurScene)
	{
		Release();

		switch (m_eCurScene)
		{
		case CSceneMgr::STAGE:
			m_pScene = new CStage;
			break;
		}
		m_pScene->Initialize();
		m_ePreScene = m_eCurScene;
	}
}

void CSceneMgr::Update()
{
	if (CObjMgr::Get_Instance()->Get_Player()->Get_Dead())
	{
		if (CKeyMgr::Get_Instance()->Key_Down('R'))
		{
			SAFE_DELETE(m_pScene);
			m_pScene = new CStage;
			m_pScene->Initialize();
		}
	}
	m_pScene->Update();
}

void CSceneMgr::Late_Update()
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render()
{
	m_pScene->Render();
}

void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
}
