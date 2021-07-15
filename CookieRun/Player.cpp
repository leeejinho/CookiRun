#include "stdafx.h"
#include "Player.h"
#include "Texture_Manager.h"
#include "KeyMgr.h"

CPlayer::CPlayer()
	: m_dwDelay(0), m_iDrawID(0), m_iMaxDrawID(0), m_pStateKey(L"")
{
	ZeroMemory(&m_vPos, sizeof(D3DXVECTOR3));
	ZeroMemory(&m_vSize, sizeof(D3DXVECTOR3));
}	  


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Run/cookie0001_run0%d.png", L"Player", L"Run", 4);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Jump/cookie0001_jump0%d.png", L"Player", L"Jump", 8);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Slide/cookie0001_slide0%d.png", L"Player", L"Slide", 2);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Hit/cookie0001_hit0%d.png", L"Player", L"Hit", 3);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Dead/cookie0001_dead0%d.png", L"Player", L"Dead", 5);

	m_vPos = { WINCX * 0.5f, WINCY * 0.5f, 0.f };
	m_vSize = { 1.f, 1.f, 0.f };
	m_iDrawID = 0;
	m_pStateKey = L"Run";
}

int CPlayer::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	Key_Check();

	return OBJ_NOENVENT;
}

void CPlayer::Late_Update()
{
}

void CPlayer::Render()
{
	if (m_dwDelay + 50 < GetTickCount())
	{
		++m_iDrawID;
		if (m_iDrawID > m_iMaxDrawID)
			m_iDrawID = 0;
		m_dwDelay = GetTickCount();
	}

	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Player", m_pStateKey, m_iDrawID);
	

	D3DXMATRIX matScale, matTrans, matWord;
	D3DXMatrixScaling(&matScale, m_vSize.x, m_vSize.y, 0.f);
	D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, 0.f);
	matWord = matScale * matTrans;

	float fCenterX = (float)(pTexInfo->tImageInfo.Width >> 1);
	float fCenterY = (float)(pTexInfo->tImageInfo.Height >> 1);
	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWord);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CPlayer::Release()
{
	CTexture_Manager::Destroy_Instance();
}

void CPlayer::Key_Check()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	{
		m_pStateKey = L"Slide";
		m_iMaxDrawID = 1;
	}
	else
	{
		m_pStateKey = L"Run";
		m_iMaxDrawID = 3;

	}
}
