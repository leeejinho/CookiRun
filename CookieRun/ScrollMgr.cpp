#include "stdafx.h"
#include "ScrollMgr.h"


CScrollMgr* CScrollMgr::m_pInstance = nullptr;
CScrollMgr::CScrollMgr()
	: m_fScrollX(0.f), m_fScrollY(0.f)
{
}


CScrollMgr::~CScrollMgr()
{
}

void CScrollMgr::Scroll_Lock()
{
	//if (0 < m_fScrollX)
	//	m_fScrollX = 0.f;

	////if ((-1920.f + WINCX) > m_fScrollX)
	////	m_fScrollX = (-1920.f + WINCX);

	//if (-(TILECX * TILEX) + WINCX > m_fScrollX)
	//	m_fScrollX = -(TILECX * TILEX) + WINCX;

}