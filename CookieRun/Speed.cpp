#include "stdafx.h"
#include "Speed.h"
#include "Texture_Manager.h"
#include "Graphic_Device.h"
#include "ScrollMgr.h"


CSpeed::CSpeed()
{
}


CSpeed::~CSpeed()
{
}

void CSpeed::Initialize()
{
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Image/Item/Speed/item03_invincible_%d.png", L"Item", L"Speed",4)))
		return;
}

int CSpeed::Update()
{
	return 0;
}

void CSpeed::Late_Update()
{
}

void CSpeed::Render()
{
	DWORD dwTime = GetTickCount();





	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Item", L"Speed");

	if (pTexInfo == nullptr)
		return;
	float fCenterX = pTexInfo->tImageInfo.Width >> 1;
	float fCenterY = pTexInfo->tImageInfo.Height >> 1;

	D3DXMATRIX matScale, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 0.5f, 0.5f, 0.f);			//해당하는 인덱스에 접근해서 X,Y 크기 설정
	D3DXMatrixTranslation(&matTrans, 100.f, 400.f, 0.f);		//해당하는 인덱스에 접근해서 X,Y으로 인해서 이동하겠다
	matWorld = matScale * matTrans;

	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

}

void CSpeed::Release()
{
}
