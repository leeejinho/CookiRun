#include "stdafx.h"
#include "JumpBlock.h"
#include "Texture_Manager.h"
#include "ScrollMgr.h"

CJumpBlock::CJumpBlock()
{
}

CJumpBlock::CJumpBlock(float _fX, float _fY, DWORD _DrawId)
{
	m_vPos.x = _fX;
	m_vPos.y = _fY;
	DrawId = _DrawId;
	m_eType = JUMP;

	m_vSize.x = 159;
	m_vSize.y = 124;
}


CJumpBlock::~CJumpBlock()
{
	Release();
}

void CJumpBlock::Initialize()
{
	m_tRect.left = (LONG)(m_vPos.x - m_vSize.x * 0.5f);
	m_tRect.top = (LONG)(m_vPos.y - m_vSize.y * 0.5f);
	m_tRect.right = (LONG)(m_vPos.x + m_vSize.x * 0.5f);
	m_tRect.bottom = (LONG)(m_vPos.y + m_vSize.y * 0.5f);
}

int CJumpBlock::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (m_bDestory)
		Destory();

	return OBJ_NOENVENT;
}

void CJumpBlock::Late_Update()
{
}

void CJumpBlock::Render()
{
	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Block", L"Jump", DrawId);
	if (nullptr == pTexInfo)
		return;

	float fCenterX = float(pTexInfo->tImageInfo.Width >> 1);
	float fCenterY = float(pTexInfo->tImageInfo.Height >> 1);

	float ScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();

	D3DXMATRIX matScale, matTrans, matRotate, matWorld;
	D3DXMatrixScaling(&matScale, 0.8f*m_fDestory_Scale, 0.8f*m_fDestory_Scale, 0.f);
	D3DXMatrixTranslation(&matTrans, m_vPos.x + ScrollX + m_fDestory_Trans, m_vPos.y - (m_fDestory_Trans *0.5f), 0.f);
	D3DXMatrixRotationZ(&matRotate, D3DXToRadian(m_fDestory_Angle));
	matWorld = matScale * matRotate * matTrans;
	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CJumpBlock::Release()
{
}
