#include "stdafx.h"
#include "Block.h"


CBlock::CBlock()
	:m_eType(END)
{
	ZeroMemory(m_vPos,sizeof(D3DXVECTOR3));
	ZeroMemory(m_vSize, sizeof(D3DXVECTOR3));
}


CBlock::~CBlock()
{
}
