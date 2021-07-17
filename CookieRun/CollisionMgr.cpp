#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"
#include "Hpup.h"
#include "Giant.h"
#include "Score.h"
#include "Speed.h"

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::Collision_Rect(list<CObj*>& _Player, list<CObj*>& _Item)
{
	RECT rc = {};

	for (auto& Player : _Player)
	{
		for (auto& Item : _Item)
		{
			if (IntersectRect(&rc, &Player->Get_Rect(), &Item->Get_Rect()))
			{
				Item->Set_Dead();
			}
		}
	}
}

void CCollisionMgr::Collision_Tile(list<CObj*>& _Player, list<CObj*>& _Tile)
{
	RECT rc = {};

	for (auto& Player : _Player)
	{
		for (auto& Tile : _Tile)
		{
			if (IntersectRect(&rc, &Player->Get_Rect(), &Tile->Get_Rect()))
			{
				Player->Set_PosY(Tile->Get_Rect().top - 182);
			}
		}
	}
}
