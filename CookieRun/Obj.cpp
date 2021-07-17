#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	:m_bDead(false)
{
	ZeroMemory(&m_vPos, sizeof(D3DXVECTOR3));
	ZeroMemory(&m_vSize, sizeof(D3DXVECTOR3));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{
}