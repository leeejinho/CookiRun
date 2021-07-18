#include "stdafx.h"
#include "Giant.h"
#include "Texture_Manager.h"
#include "Graphic_Device.h"
#include "ScrollMgr.h"



CGiant::CGiant()

{
}

CGiant::CGiant(float TexInfoX, float TexInfoY)

{
	m_vPos.x = TexInfoX;
	m_vPos.y = TexInfoY;

	m_eType = GIANT;
}


CGiant::~CGiant()
{
}

void CGiant::Initialize()
{
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Image/Item/Giant/item04_biggest_%d.png", L"Item", L"Giant", 4)))
		return;

	dwTime = GetTickCount();
}

int CGiant::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	return OBJ_NOENVENT;
}

void CGiant::Late_Update()
{
}

void CGiant::Render()
{
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();


	if (dwTime + 122 < GetTickCount())
	{
		++iNumber;

		if (iNumber > 3)
			iNumber = 0;

		dwTime = GetTickCount();
	}

	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Item", L"Giant", iNumber);

	if (pTexInfo == nullptr)
		return;
	float fCenterX = float(pTexInfo->tImageInfo.Width >> 1);
	float fCenterY = float(pTexInfo->tImageInfo.Height >> 1);

	D3DXMATRIX matScale, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 0.5f, 0.5f, 0.f);										//아이템 크기
	D3DXMatrixTranslation(&matTrans, m_vPos.x + iScrollX, m_vPos.y, 0.f);				//아이템 위치	
	matWorld = matScale * matTrans;

	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	//						  왼쪽						 위						  오른쪽				 아래
	m_tRect = { LONG(m_vPos.x - 20) ,LONG(m_vPos.y - 20) , LONG(m_vPos.x + 20) , LONG(m_vPos.y + 20) };
	//	left , top , right , bottom
}

void CGiant::Release()
{
}
