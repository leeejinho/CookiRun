#include "stdafx.h"
#include "Land.h"
#include "Texture_Manager.h"
#include "ScrollMgr.h"

CLand::CLand()
{
}

CLand::CLand(float _fX, float _fY)
{
	m_vPos.x = _fX;
	m_vPos.y = _fY;
}


CLand::~CLand()
{
}

void CLand::Initialize()
{
	m_tRect.left=m_vPos.x-62;
	m_tRect.top = m_vPos.y - 70;
	m_tRect.right = m_vPos.x + 62;
	m_tRect.bottom = m_vPos.y + 70;
}

int CLand::Update()
{




	return OBJ_NOENVENT;
}

void CLand::Late_Update()
{
}

void CLand::Render()
{
	

	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Land");
	if (nullptr == pTexInfo)
		return;

	float fCenterX = pTexInfo->tImageInfo.Width >> 1;
	float fCenterY = pTexInfo->tImageInfo.Height >> 1;

	float ScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();

	D3DXMATRIX matScale, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);
	D3DXMatrixTranslation(&matTrans, m_vPos.x - ScrollX, m_vPos.y, 0.f);
	matWorld = matScale * matTrans;
	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

}

void CLand::Release()
{
}
