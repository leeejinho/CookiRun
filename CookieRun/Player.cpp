#include "stdafx.h"
#include "Player.h"
#include "Texture_Manager.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"

CPlayer::CPlayer()
	: m_dwTexDelay(0), m_iDrawID(0), m_iMaxDrawID(0), m_pStateKey(L""), m_bSlide(false),
	m_fJumpPower(0.f), m_fJumpTime(0.f), m_fJumpY(0.f), m_bJump(false), m_bDoubleJump(false), m_iMaxJump(0),
	m_fSpeed(0.f), m_iHp(0), m_dwHpDelay(GetTickCount()),
	m_bGiant(false), m_bSpeed(false), m_bHit(false)
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
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/DoubleJump/cookie0001_doublejump0%d.png", L"Player", L"DoubleJump", 10);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Slide/cookie0001_slide0%d.png", L"Player", L"Slide", 2);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Hit/cookie0001_hit0%d.png", L"Player", L"Hit", 3);
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Player/Dead/cookie0001_dead0%d.png", L"Player", L"Dead", 5);

	// seokwon test
	//m_vPos = { 7200.f,WINCY*0.5f , 0.f };
	// seokwon test
	
	m_vPos = { 200.f, WINCY * 0.5f, 0.f };
	m_vSize = { 1.f, 1.f, 0.f };
	m_iDrawID = 0;

	m_pStateKey = L"Run";
	m_fJumpPower = 50.f;
	m_iMaxJump = 2;
	m_fSpeed = 5.f;
	m_iHp = 100;
}

int CPlayer::Update()
{
	if (!m_bDead)
	{
		//if (m_iDrawID == 4)
			//return OBJ_DEAD;
		Move_Player();
		Key_Check();
		Jumping();
		Speed_Item();
		Giant_Item();
		Update_Hp();
		Update_Rect();
	}
	return OBJ_NOENVENT;
}

void CPlayer::Late_Update()
{
}

void CPlayer::Render()
{
	if (m_dwTexDelay + 60 < GetTickCount())
	{
		++m_iDrawID;
		if (m_iDrawID > m_iMaxDrawID)
		{
			m_iDrawID = 0;
			if (m_pStateKey == L"DoubleJump")
				m_iDrawID = 9;
			else if (m_bDead)
				m_iDrawID = 4;
			if (m_pStateKey == L"Hit")
			{
				m_pStateKey = L"Run";
				m_iMaxDrawID = 3;
			}
		}
		m_dwTexDelay = GetTickCount();
	}
	float fScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Player", m_pStateKey, m_iDrawID);	

	D3DXMATRIX matScale, matTrans, matWord;
	D3DXMatrixScaling(&matScale, m_vSize.x, m_vSize.y, 0.f);
	D3DXMatrixTranslation(&matTrans, m_vPos.x + fScrollX, m_vPos.y, 0.f);
	matWord = matScale * matTrans;

	float fCenterX = (float)(pTexInfo->tImageInfo.Width >> 1);
	float fCenterY = (float)(pTexInfo->tImageInfo.Height);
	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWord);
	
	if (m_bHit)
	{
		if (m_dwBlinkTime + 500 < GetTickCount())
		{
			if (m_iBlink == 100)
				m_iBlink = 200;
			else
				m_iBlink = 100;
		}
		CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(m_iBlink, 255, 255, 255));
	}
	else
		CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CPlayer::Release()
{
}

void CPlayer::Move_Player()
{
	m_vPos.x += m_fSpeed;
	CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);
	
	//seokwon test
	//if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	//	m_vPos.x += 5.f;
	//if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	//	m_vPos.x -= 5.f;
	//seokwon test
}

void CPlayer::Key_Check()
{
	//if (CKeyMgr::Get_Instance()->Key_Pressing('Z') && !m_bJump)		//////////////////////seokwon test
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT) && !m_bJump)
	{
		if (!m_bSlide)
			m_iDrawID = 0;
		m_bSlide = true;
		m_pStateKey = L"Slide";
		m_iMaxDrawID = 1;
	}
	//else if (CKeyMgr::Get_Instance()->Key_Down('X') && !m_bSlide && m_iMaxJump > 0)     //////////////////////seokwon test
	else if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT) && !m_bSlide && m_iMaxJump > 0)
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
	else if (!m_bJump && !m_bDoubleJump && !m_bDead)
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

		if (m_vPos.y > 480.f)
		{
			m_vPos.y = 480.f;
			m_bJump = false;
			m_bDoubleJump = false;
			m_iDrawID = 0;
			m_fJumpTime = 0.f;
			m_iMaxJump = 2;
		}
	}
	else
	{
		m_vPos.y += m_fSpeed;
	}
}

void CPlayer::Update_Rect()
{
	m_tRect.left = (LONG)(m_vPos.x - 35);
	m_tRect.right = (LONG)(m_vPos.x + 35);
	m_tRect.bottom = (LONG)(m_vPos.y);
	m_tRect.top = (LONG)(m_tRect.bottom - 120);

	if (m_bGiant)
	{
		m_tRect.left = (LONG)(m_vPos.x - 70);
		m_tRect.right = (LONG)(m_vPos.x + 70);
		m_tRect.bottom = (LONG)(m_vPos.y);
		m_tRect.top = (LONG)(m_tRect.bottom - 240);
	}
}

void CPlayer::Hit_Check()
{
	if (m_bHit)
	{
		m_fSpeed += 1.f;
		if (m_fSpeed > 5.f)
			m_fSpeed = 5.f;

		if (m_dwHitTime + 3000 < GetTickCount())
			m_bHit = false;
	}
}

void CPlayer::Speed_Item()
{

	if (m_dwSpeedTime + 2000 < GetTickCount())
	{
		m_bSpeed = false;
		m_fSpeed = 5.f;
	}
}

void CPlayer::Giant_Item()
{
	if (m_bGiant)
	{
		if (m_dwGiantTime + 3000 > GetTickCount())
		{
			m_vSize += D3DXVECTOR3{ 0.02f, 0.02f, 0.f };
			if (m_vSize.x >= 2.f)
			{
				m_vSize = { 2.f, 2.f, 0.f };
			}
		}

		else if (m_dwGiantTime + 3000 < GetTickCount())
		{
			m_vSize -= D3DXVECTOR3{ 0.02f, 0.02f, 0.f };
			if (m_vSize.x <= 1.f)
			{
				m_vSize = { 1.f, 1.f, 0.f };
				m_bGiant = false;
			}
		}
	}

	
}

void CPlayer::Item_Use(CItem::ITEM_TYPE _Type)
{
	switch (_Type)
	{
	case CItem::SMALL_HP:
		m_iHp += 10;
		break;
	case CItem::HP:
		m_iHp += 30;
		break;
	case CItem::JELLY:

		break;
	case CItem::GIANT:
		m_dwGiantTime = GetTickCount();
		m_bGiant = true;
		break;
	case CItem::SPEED:
		m_dwSpeedTime = GetTickCount();
		m_bSpeed = true;
		m_fSpeed = 10.f;
		break;
	case CItem::MAGNET:

		break;
	}
}

void CPlayer::Update_Hp()
{
	if (m_iHp <= 0)
	{
		if (!m_bDead)
		{
			m_iDrawID = 0;
			m_iHp = 0;
		}

		m_bDead = true;
		m_pStateKey = L"Dead";
		m_iMaxDrawID = 4;
	}
	else if (m_iHp > 100)
	{
		m_iHp = 100;
	}
	else
	{
		if (m_dwHpDelay + 500 < GetTickCount())
		{
			--m_iHp;
			m_dwHpDelay = GetTickCount();
		}
	}
}
