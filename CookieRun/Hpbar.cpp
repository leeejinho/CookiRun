#include "stdafx.h"
#include "Hpbar.h"
#include "Texture_Manager.h"
#include "ObjMgr.h"
#include "Player.h"

CHpbar::CHpbar()
	: m_iCurHp(0)
{
}


CHpbar::~CHpbar()
{
	Release();
}

void CHpbar::Initialize()
{
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::SINGLE_TEX, L"../Texture/UI/HpBarbg.png", L"HpBarbg");
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::SINGLE_TEX, L"../Texture/UI/HpBar.png", L"HpBar");
	CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::SINGLE_TEX, L"../Texture/UI/icon_hp.png", L"icon_hp");

	m_vPos = { WINCX * 0.5f, 30.f, 0.f };
	m_vSize = { 0.5f, 0.5f, 0.f };
}

int CHpbar::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	return OBJ_NOENVENT;
}

void CHpbar::Late_Update()
{
}

void CHpbar::Render()
{
	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"HpBarbg");
	float fCenterX = (float)(pTexInfo->tImageInfo.Width >> 1);
	float fCenterY = (float)(pTexInfo->tImageInfo.Height >> 1);

	D3DXMATRIX matScale, matTrans;
	D3DXMatrixScaling(&matScale, m_vSize.x, m_vSize.y, 0.f);
	D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, 0.f);

	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&D3DXMATRIX(matScale * matTrans));
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
	
	pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"icon_hp");
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), &D3DXVECTOR3(-50.f, -5.f, 0.f), D3DCOLOR_ARGB(255, 255, 255, 255));

	pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"HpBar");

	if (!CObjMgr::Get_Instance()->Get_List(OBJID::PLAYER).empty())
		m_iCurHp = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_Player())->Get_Hp() * (pTexInfo->tImageInfo.Width * 0.01f);
	else
		m_iCurHp = 0;
	RECT rc = { 0, 0, (LONG)(m_iCurHp), (LONG)(pTexInfo->tImageInfo.Height) };
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, &rc, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CHpbar::Release()
{
}
