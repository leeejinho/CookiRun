#include "stdafx.h"
#include "Stage.h"
#include "Texture_Manager.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"

#include "Stage_Setting.h"

CStage::CStage()
	:Stage_Set(nullptr)
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{

	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::SINGLE_TEX, L"../Image/Background/Background.png", L"Background")))
		return;
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::SINGLE_TEX, L"../Image/Land/Land.png", L"Land")))
		return;
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Image/Block/Djump/Djump00%d.png", L"Block", L"Djump", 6)))
		return;
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Image/Block/Slide/Slide00%d.png", L"Block", L"Slide", 2)))
		return;
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Image/Block/Jump/Jump00%d.png", L"Block", L"Jump", 2)))
		return;


	///////seokwon Test
	if (Stage_Set == nullptr)
		Stage_Set = new CStage_Setting;
	Stage_Set->stage1_Setting();

	//CScrollMgr::Get_Instance()->Set_ScrollX(-7000.f);
	///////seokwon Test

}

void CStage::Update()
{
	///////seokwon Test
	//if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	//	CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);
	//if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	//	CScrollMgr::Get_Instance()->Set_ScrollX(+5.f);
	//if (CKeyMgr::Get_Instance()->Key_Down('Q'))
	//	CObjMgr::Get_Instance()->Save_Land();
	//if (CKeyMgr::Get_Instance()->Key_Down('W'))
	//	CObjMgr::Get_Instance()->Save_Block();
	//if (CKeyMgr::Get_Instance()->Key_Down('E'))
	//	CObjMgr::Get_Instance()->Load();
	///////seokwon Test

	CObjMgr::Get_Instance()->Update();
}

void CStage::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage::Render()
{
	Render_Background();
	CObjMgr::Get_Instance()->Render();
}

void CStage::Release()
{
	SAFE_DELETE(Stage_Set);
}


void CStage::Render_Background()
{
	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Background");
	if (nullptr == pTexInfo)
		return;

	float fCenterX = pTexInfo->tImageInfo.Width >> 1;
	float fCenterY = pTexInfo->tImageInfo.Height >> 1;


	D3DXMATRIX matScale, matTrans, matWorld;
	D3DXMatrixScaling(&matScale, 2.f, 2.f, 0.f);
	D3DXMatrixTranslation(&matTrans, WINCX *0.5f, WINCY * 0.5f, 0.f);
	matWorld = matScale * matTrans;
	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}
