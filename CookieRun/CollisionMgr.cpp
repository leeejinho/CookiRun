#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"
#include "Hpup.h"
#include "Giant.h"
#include "Score.h"
#include "Speed.h"
#include "Player.h"

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
				static_cast<CPlayer*>(Player)->Player_Item(Item->Get_Number());
			}
		}
	}
}

void CCollisionMgr::Collision_Tile(list<CObj*>& _Player, list<CObj*>& _Tile)
{
	float fX = 0.f, fY = 0.f;

	for (auto& Player: _Player)
	{
		for (auto& Tile : _Tile)
		{
			if (Check_Rect(Player, Tile, &fX, &fY))
			{
				if (fX < fY)
				{
					if (Player->Get_Pos().x < Tile->Get_Pos().x)
						Tile->Set_PosX(fX);
					else
						Tile->Set_PosX(-fX);
				}
				else
				{
					if (Player->Get_Pos().y < Tile->Get_Pos().y)
						Tile->Set_PosY(fY);
					else
						Tile->Set_PosY(-fY);
				}
			}
		}
	}
}

bool CCollisionMgr::Check_Rect(CObj * _Player, CObj * _Tile, float * _x, float * _y)
{
	float	fCenterDisX = abs(_Player->Get_Pos().x - _Tile->Get_Pos().x);
	float	fCenterDisY = abs(_Player->Get_Pos().y - _Tile->Get_Pos().y);

	float	fRSumX = (float)((70 + 124) >> 1);
	float	fRSumY = (float)((70 + 140) >> 1);

	if (fCenterDisX < fRSumX && fCenterDisY < fRSumY)
	{
		*_x = fRSumX - fCenterDisX;
		*_y = fRSumY - fCenterDisY;

		return true;
	}
	return false;
}

//void CCollisionMgr::Collision_Tile(list<CObj*>& _Player, list<CObj*>& _Tile)
//{
//	RECT rc = {};
//
//	for (auto& Player : _Player)
//	{
//		for (auto& Tile : _Tile)
//		{
//			if (IntersectRect(&rc, &Player->Get_Rect(), &Tile->Get_Rect()))
//			{
//				Player->Set_PosY(Tile->Get_Rect().top - 182);
//			}
//		}
//	}
//}
