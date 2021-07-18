#include "stdafx.h"
#include "ObjMgr.h"
#include "Obj.h"
#include "Block.h"
#include "Land.h"
#include "JumpBlock.h"
#include "DjumpBlock.h"
#include "SlideBlock.h"
#include "CollisionMgr.h"


CObjMgr* CObjMgr::m_pInstance = nullptr;
CObjMgr::CObjMgr() : m_iStairMax(0)
{
}


CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::Update()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		auto iter = m_listObj[i].begin();
		for (; iter != m_listObj[i].end(); )
		{
			int iEvent = (*iter)->Update();
			if (OBJ_DEAD == iEvent)
			{
				SAFE_DELETE(*iter);
				iter = m_listObj[i].erase(iter);
			}
			else
				++iter;
		}
	}
	//CCollisionMgr::Collision_Tile(m_listObj[OBJID::LAND], m_listObj[OBJID::PLAYER]);
	//CCollisionMgr::Collision_Rect(m_listObj[OBJID::PLAYER], m_listObj[OBJID::SP]);
	//CCollisionMgr::Collision_Rect(m_listObj[OBJID::PLAYER], m_listObj[OBJID::HP]);
	//CCollisionMgr::Collision_Rect(m_listObj[OBJID::PLAYER], m_listObj[OBJID::GIANT]);
	//CCollisionMgr::Collision_Rect(m_listObj[OBJID::PLAYER], m_listObj[OBJID::SPEED]);
	//CCollisionMgr::Collision_Rect(m_listObj[OBJID::PLAYER], m_listObj[OBJID::JELLY]);

	CCollisionMgr::Collision_Player_Item(m_listObj[OBJID::PLAYER].front(), m_listObj[OBJID::ITEM]);
	CCollisionMgr::Collision_Player_Jelly(m_listObj[OBJID::PLAYER].front(), m_listObj[OBJID::JELLY]);
	CCollisionMgr::Collision_Player_Block(m_listObj[OBJID::PLAYER].front(), m_listObj[OBJID::BLOCK]);
	CCollisionMgr::Collision_Player_Tile(m_listObj[OBJID::PLAYER].front(), m_listObj[OBJID::LAND]);
	
	/*
	CCollisionMgr::Magnet_Jelly();
	*/

}

void CObjMgr::Late_Update()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (auto& pObj : m_listObj[i])
		{
			pObj->Late_Update();

			if (m_listObj[i].empty())
				break;
		}
	}
}

void CObjMgr::Render()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (auto& pObj : m_listObj[i])
			pObj->Render();
	}
}

void CObjMgr::Release()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for_each(m_listObj[i].begin(), m_listObj[i].end(), Safe_Delete<CObj*>);
		m_listObj[i].clear();
	}
}

void CObjMgr::Delete_ID(OBJID::ID _eID)
{
	for_each(m_listObj[_eID].begin(), m_listObj[_eID].end(), Safe_Delete<CObj*>);
	m_listObj[_eID].clear();
}

void CObjMgr::Save_Land()
{
	HANDLE hFile = CreateFile(L"../Data/Land.dat", GENERIC_WRITE
		, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;


	DWORD	dwByte = 0;
	for (auto& pObj : m_listObj[OBJID::LAND])
	{
		WriteFile(hFile, &static_cast<CBlock*>(pObj)->Get_Pos(), sizeof(D3DXVECTOR3), &dwByte, NULL);
	}

	CloseHandle(hFile);
}

void CObjMgr::Save_Block()
{
	HANDLE hFile = CreateFile(L"../Data/Block.dat", GENERIC_WRITE
		, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;


	DWORD	dwByte = 0;
	for (auto& pObj : m_listObj[OBJID::BLOCK])
	{
		WriteFile(hFile, &static_cast<CBlock*>(pObj)->Get_Pos(), sizeof(D3DXVECTOR3), &dwByte, NULL);
		WriteFile(hFile, &static_cast<CBlock*>(pObj)->Get_DrawId(), sizeof(DWORD), &dwByte, NULL);
		WriteFile(hFile, &static_cast<CBlock*>(pObj)->Get_Type(), sizeof(CBlock::BLOCK_TYPE), &dwByte, NULL);
	}

	CloseHandle(hFile);
}

void CObjMgr::Load()
{
	CObj* pobj = nullptr;

	HANDLE hFile = CreateFile(L"../Data/Land.dat", GENERIC_READ
		, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return;
	
	Delete_ID(OBJID::LAND);

	DWORD dwByte = 0;
	D3DXVECTOR3 vPos= {};
	while (true)
	{
		ReadFile(hFile, &vPos, sizeof(D3DXVECTOR3), &dwByte, NULL);

		if (dwByte == 0)
			break;

		pobj = new CLand(vPos.x, vPos.y);
		pobj->Initialize();
		m_listObj[OBJID::LAND].emplace_back(pobj);
	}

	CloseHandle(hFile);

	HANDLE hFile2 = CreateFile(L"../Data/Block.dat", GENERIC_READ
		, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);


	if (hFile == INVALID_HANDLE_VALUE)
		return;

	Delete_ID(OBJID::BLOCK);

	DWORD DrawID = 0;

	CBlock::BLOCK_TYPE Type = CBlock::END;
	while (true)
	{
		ReadFile(hFile2, &vPos, sizeof(D3DXVECTOR3), &dwByte, NULL);
		ReadFile(hFile2, &DrawID, sizeof(DWORD), &dwByte, NULL);
		ReadFile(hFile2, &Type, sizeof(CBlock::BLOCK_TYPE), &dwByte, NULL);
		if (dwByte == 0)
			break;

		switch (Type)
		{
		case CBlock::JUMP:
			pobj = new CJumpBlock(vPos.x, vPos.y, DrawID);
			pobj->Initialize();
			m_listObj[OBJID::BLOCK].emplace_back(pobj);
			break;
		case CBlock::DJUMP:
			pobj = new CDjumpBlock(vPos.x, vPos.y, DrawID);
			pobj->Initialize();
			m_listObj[OBJID::BLOCK].emplace_back(pobj);
			break;
		case CBlock::SLIDE:
			pobj = new CSlideBlock(vPos.x, vPos.y, DrawID);
			pobj->Initialize();
			m_listObj[OBJID::BLOCK].emplace_back(pobj);
			break;
		}
	}

	CloseHandle(hFile2);
}

