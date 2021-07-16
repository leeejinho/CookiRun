#include "stdafx.h"
#include "Jelly.h"
#include "Texture_Manager.h"
#include "Graphic_Device.h"
#include "ScrollMgr.h"

CJelly::CJelly()
{
}

CJelly::CJelly(float TexInfoX, float TexInfoY)
{
	m_vPos.x = TexInfoX;
	m_vPos.y = TexInfoY;
}


CJelly::~CJelly()
{
}

void CJelly::Initialize()
{
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::SINGLE_TEX, L"../Image/Item/Jelly/jellybean_20.png", L"Jelly")))
		return;
}

int CJelly::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	return OBJ_NOENVENT;
}

void CJelly::Late_Update()
{
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Jelly");

	if (pTexInfo == nullptr)
		return;
	float fCenterX = float(pTexInfo->tImageInfo.Width >> 1);
	float fCenterY = float(pTexInfo->tImageInfo.Height >> 1);

	D3DXMATRIX matScale, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 0.5f, 0.5f, 0.f);											//아이템 크기
	D3DXMatrixTranslation(&matTrans, m_vPos.x + iScrollX, m_vPos.x + iScrollY, 0.f);		//아이템 위치
	matWorld = matScale * matTrans;

	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	//						  왼쪽						 위						  오른쪽				 아래
	RECT Hpup = { fCenterX - 20, fCenterY - 20 , fCenterX + 20, fCenterY + 20};
	//	left , top , right , bottom
}

void CJelly::Render()
{
}

void CJelly::Release()
{
}
