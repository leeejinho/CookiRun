#include "stdafx.h"
#include "Block.h"


CBlock::CBlock()
	:m_eType(END), m_bDestory(false) , m_dwDestory(NULL)
	, m_fDestory_Angle(0.f), m_fDestory_Scale(1.f), m_fDestory_Trans(0.f)
{
	ZeroMemory(m_vPos,sizeof(D3DXVECTOR3));
	ZeroMemory(m_vSize, sizeof(D3DXVECTOR3));
}


CBlock::~CBlock()
{
}

void CBlock::Destory()
{
	if (!m_bDestory)
	{
		m_bDestory = true;
		m_dwDestory = GetTickCount();
	}
	else
	{
		if (GetTickCount() - m_dwDestory > 2000)
			m_bDead = true;
		m_fDestory_Angle += 10.f;
		m_fDestory_Scale -= 0.01f;
		m_fDestory_Trans += 10.f;
	}

}
