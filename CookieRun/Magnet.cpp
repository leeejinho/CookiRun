#include "stdafx.h"
#include "Magnet.h"
#include "Texture_Manager.h"
#include "ScrollMgr.h"	

CMagnet::CMagnet()
{
}

CMagnet::CMagnet(float _x, float _y)
{
	m_vPos.x = _x;
	m_vPos.y = _y;
}


CMagnet::~CMagnet()
{
}

void CMagnet::Initialize()
{
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Image/Item/Hp/item08_energy_%d.png", L"Item", L"HpUp", 4)))
		return;

	dwTime = GetTickCount();
}

int CMagnet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	return OBJ_NOENVENT;
}

void CMagnet::Late_Update()
{
}

void CMagnet::Render()
{
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	if (dwTime + 122 < GetTickCount())
	{
		++iNumber;

		if (iNumber > 3)
			iNumber = 0;

		dwTime = GetTickCount();
	}

	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Item", L"HpUp", iNumber);

	if (pTexInfo == nullptr)
		return;
	float fCenterX = pTexInfo->tImageInfo.Width >> 1;	//이미지 가로 길이 / 2 => 이미지 중앙
	float fCenterY = pTexInfo->tImageInfo.Height >> 1;	//이미지 세로 길이 / 2 -> 이미지 중앙


	D3DXMATRIX matScale, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 0.5f, 0.5f, 0.f);										//아이템 크기
	D3DXMatrixTranslation(&matTrans, m_vPos.x + iScrollX, m_vPos.y + iScrollY, 0.f);	//아이템 위치
	matWorld = matScale * matTrans;

	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	//						  왼쪽						 위						  오른쪽				 아래
	RECT Hpup = { fCenterX - 20 , fCenterY - 20 , fCenterX + 20 ,fCenterY + 20 };
	//	left , top , right , bottom
}

void CMagnet::Release()
{
}
