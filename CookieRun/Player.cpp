#include "stdafx.h"
#include "Player.h"
#include "Texture_Manager.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"

CPlayer::CPlayer()
	: m_dwDelay(0), m_iDrawID(0), m_iMaxDrawID(0), m_pStateKey(L""), m_bSlide(false),
	m_fJumpPower(0.f), m_fJumpTime(0.f), m_fJumpY(0.f), m_bJump(false), m_bDoubleJump(false), m_iMaxJump(0),
	m_fSpeed(0.f)
{
	ZeroMemory(&m_vPos, sizeof(D3DXVECTOR3));
	ZeroMemory(&m_vSize, sizeof(D3DXVECTOR3));
	ZeroMemory(&m_Rect, sizeof(RECT));
}	  


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Run/cookie0001_run0%d.png", L"Player", L"Run", 4);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Jump/cookie0001_jump0%d.png", L"Player", L"Jump", 8);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/DoubleJump/cookie0001_doublejump0%d.png", L"Player", L"DoubleJump", 10);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Slide/cookie0001_slide0%d.png", L"Player", L"Slide", 2);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Hit/cookie0001_hit0%d.png", L"Player", L"Hit", 3);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Dead/cookie0001_dead0%d.png", L"Player", L"Dead", 5);

	// seokwon test
	m_vPos = { 7200.f,WINCY*0.5f , 0.f };
	// seokwon test
	
	//m_vPos = { 200.f, WINCY * 0.5f, 0.f };
	m_vSize = { 1.f, 1.f, 0.f };
	m_iDrawID = 0;

	m_pStateKey = L"Run";
	m_fJumpPower = 50.f;
	m_iMaxJump = 2;
	m_fSpeed = 5.f;

}

int CPlayer::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	Move_Player();
	Key_Check();
	Jumping();

	return OBJ_NOENVENT;
}

void CPlayer::Late_Update()
{
}

void CPlayer::Render()
{
	if (m_dwDelay + 60 < GetTickCount())
	{
		++m_iDrawID;
		if (m_iDrawID > m_iMaxDrawID)
		{
			m_iDrawID = 0;
			if (m_pStateKey == L"DoubleJump")
				m_iDrawID = 9;
		}
		m_dwDelay = GetTickCount();
	}
	float fScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Player", m_pStateKey, m_iDrawID);	

	D3DXMATRIX matScale, matTrans, matWord;
	D3DXMatrixScaling(&matScale, m_vSize.x, m_vSize.y, 0.f);
	D3DXMatrixTranslation(&matTrans, m_vPos.x + fScrollX, m_vPos.y, 0.f);
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

void CPlayer::Move_Player()
{
	//m_vPos.x += m_fSpeed;
	//CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);
	
	//seokwon test
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		m_vPos.x += 5.f;
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		m_vPos.x -= 5.f;
	//seokwon test
}

void CPlayer::Key_Check()
{
	//if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT) && !m_bJump)
	if (CKeyMgr::Get_Instance()->Key_Pressing('Z') && !m_bJump)		//////////////////////seokwon test
	{
		if (!m_bSlide)
			m_iDrawID = 0;
		m_bSlide = true;
		m_pStateKey = L"Slide";
		m_iMaxDrawID = 1;
	}
	//else if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT) && !m_bSlide && m_iMaxJump > 0)
	else if (CKeyMgr::Get_Instance()->Key_Down('X') && !m_bSlide && m_iMaxJump > 0)     //////////////////////seokwon test
	{
		if (!m_bJump)
		{
			--m_iMaxJump;
			m_iDrawID = 0;
			m_fJumpY = m_vPos.y;
		}
		else if (m_bJump && m_iMaxJump > 0)
		{
			if (!m_bDoubleJump)
			{
				--m_iMaxJump;
				m_iDrawID = 0;
				m_fJumpY = m_vPos.y;
				m_fJumpTime = 0.f;
			}
		}

		if (m_iMaxJump == 1)
		{
			m_bJump = true;
			m_pStateKey = L"Jump";
			m_iMaxDrawID = 1;
		}
		else if (m_iMaxJump == 0)
		{
			m_bDoubleJump = true;
			m_pStateKey = L"DoubleJump";
			m_iMaxDrawID = 9;
		}
	}
	else if (!m_bJump && !m_bDoubleJump)
	{
		m_bSlide = false;
		m_pStateKey = L"Run";
		m_iMaxDrawID = 3;

	}

	
}

void CPlayer::Jumping()
{
	float fY = WINCY * 0.5f;
	
	if (m_bJump || m_bDoubleJump)
	{
		m_vPos.y = m_fJumpY - (m_fJumpPower * m_fJumpTime - 0.5f * 9.8f * m_fJumpTime * m_fJumpTime);
		m_fJumpTime += 0.2f;

		if (m_vPos.y > fY)
		{
			m_vPos.y = fY;
			m_bJump = false;
			m_bDoubleJump = false;
			m_iDrawID = 0;
			m_fJumpTime = 0.f;
			m_iMaxJump = 2;
		}
	}
}

void CPlayer::Update_Rect()
{
	m_Rect.left = (LONG)(m_vPos.x - 35);
	m_Rect.right = (LONG)(m_vPos.x + 35);
	m_Rect.bottom = (LONG)(m_vPos.y + (364 / 2));
	m_Rect.top = (LONG)(m_Rect.bottom - 140);
}
