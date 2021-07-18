#include "stdafx.h"
#include "Jelly.h"
#include "Texture_Manager.h"
#include "Graphic_Device.h"
#include "ScrollMgr.h"
#include "ObjMgr.h"

CJelly::CJelly()
{
}

CJelly::CJelly(float TexInfoX, float TexInfoY)
	:Magnet_Speed(0)
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
	
}

void CJelly::Render()
{

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	//if (iScrollX + m_vPos.x > -100 && iScrollX + m_vPos.x < 900)
	//{
		const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Jelly");

		if (pTexInfo == nullptr)
			return;
		float fCenterX = float(pTexInfo->tImageInfo.Width >> 1);
		float fCenterY = float(pTexInfo->tImageInfo.Height >> 1);

		D3DXMATRIX matScale, matTrans, matWorld;											//아이템 크기
		D3DXMatrixTranslation(&matTrans, m_vPos.x + iScrollX, m_vPos.y, 0.f);		//아이템 위치


		CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matTrans);
		CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

		//						  왼쪽						 위						  오른쪽				 아래
		RECT Hpup = { fCenterX - 20, fCenterY - 20 , fCenterX + 20, fCenterY + 20 };
		//	left , top , right , bottom
	//}
}

void CJelly::Release()
{
}

//void CJelly::Magnet()
//{
//	if (Magnet_Speed < 3)
//		++Magnet_Speed;
//
//	D3DXVECTOR3 PlayerPos = CObjMgr::Get_Instance()->Get_Player()->getvpos();
//
//	PlayerPos = PlayerPos - m_vPos;
//
//	D3DXVec3Normalize(&PlayerPos, &PlayerPos);
//
//	m_vPos += PlayerPos*Magnet_Speed;
//
//}
