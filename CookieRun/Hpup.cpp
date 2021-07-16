#include "stdafx.h"
#include "Hpup.h"
#include "Texture_Manager.h"
#include "Graphic_Device.h"
#include "ScrollMgr.h"


CHpup::CHpup()
	:iNumber(0)
{
}

CHpup::CHpup(float TexInfoX, float TexInfoY)
	:iNumber(0)
{
	m_vPos.x = TexInfoX;
	m_vPos.y = TexInfoY;
}


CHpup::~CHpup()
{
	Release();
}

void CHpup::Initialize()
{
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Image/Item/Hp/item08_energy_%d.png", L"Item", L"HpUp",4)))
		return;

	dwTime = GetTickCount();
}

int CHpup::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	return OBJ_NOENVENT;
}

void CHpup::Late_Update()
{

}

void CHpup::Render()
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
		float fCenterX = pTexInfo->tImageInfo.Width >> 1;	//�̹��� ���� ���� / 2 => �̹��� �߾�
		float fCenterY = pTexInfo->tImageInfo.Height >> 1;	//�̹��� ���� ���� / 2 -> �̹��� �߾�


		D3DXMATRIX matScale, matTrans, matWorld;
		D3DXMatrixScaling(&matScale, 0.5f, 0.5f, 0.f);										//������ ũ��
		D3DXMatrixTranslation(&matTrans, m_vPos.x + iScrollX, m_vPos.y + iScrollY, 0.f);	//������ ��ġ
		matWorld = matScale * matTrans;

		CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
		CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));

	//						  ����						 ��						  ������				 �Ʒ�
		RECT Hpup = { fCenterX - 20 , fCenterY - 20 , fCenterX + 20 ,fCenterY + 20 };
	//	left , top , right , bottom
}

void CHpup::Release()
{
	
}
