#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"
#include "Hpup.h"
#include "Giant.h"
#include "Score.h"
#include "Speed.h"
#include "Player.h"
#include "Item.h"
#include "Jelly.h"
#include "ObjMgr.h"

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}


//void CCollisionMgr::Collision_Magnet_Jelly(CObj *& _Player, list<CObj*>& _Jelly)
//{
//	//RECT rc = {};
//	//for (auto& Jelly : _Jelly)
//	//{
//	//	if (IntersectRect(&rc, &_Player->Get_vpos, &Jelly->Get_vpos()))
//	//	{
//	//		D3DXVECTOR3 vDis;
//	//		vDis = _Player->getvpos - jelly->getvpos;
//	//		if (vDis < 100)
//	//			jelly->magnet
//	//	}
//	//}

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
				//static_cast<CPlayer*>(Player)->Player_Item(Item->Get_Number());
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








void CCollisionMgr::Collision_Player_Item(CObj *& _Player, list<CObj*>& _Item)
{
	RECT rc = {};

	for (auto& Item : _Item)
	{
		if (IntersectRect(&rc, &_Player->Get_Rect(), &Item->Get_Rect()))
		{
			static_cast<CPlayer*>(_Player)->Item_Use(static_cast<CItem*>(Item)->Get_ItemType());
			Item->Set_Dead();
		}
	}
	
}

void CCollisionMgr::Collision_Player_Jelly(CObj *& _Player, list<CObj*>& _Jelly)
{
	RECT rc = {};

	for (auto& Jelly : _Jelly)
	{
		if (IntersectRect(&rc, &_Player->Get_Rect(), &Jelly->Get_Rect()))
		{
			static_cast<CPlayer*>(_Player)->Item_Use(static_cast<CItem*>(Jelly)->Get_ItemType());
			Jelly->Set_Dead();
		}
	}

}

void CCollisionMgr::Collision_Player_Block(CObj *& _Player, list<CObj*>& _Block)
{
	RECT rc = {};

	for (auto& Block : _Block)
	{
		if (IntersectRect(&rc, &_Player->Get_Rect(), &Block->Get_Rect()))
		{
			if (!static_cast<CPlayer*>(_Player)->Get_Hit())
			{
				static_cast<CPlayer*>(_Player)->Set_Hit();
				static_cast<CPlayer*>(_Player)->Set_HitTime();
				static_cast<CPlayer*>(_Player)->Set_Speed();
				static_cast<CPlayer*>(_Player)->Set_Hp(-10);
			}
		}
	}

}

void CCollisionMgr::Collision_Player_Tile(CObj *& _Player, list<CObj*>& _Tile)
{
	RECT rc = {};

	for (auto& Tile : _Tile)
	{
		if (IntersectRect(&rc, &_Player->Get_Rect(), &Tile->Get_Rect()))
		{
			_Player->Set_PosY(Tile->Get_Rect().top);
		}
	}

}

void CCollisionMgr::Magnet_Jelly(CObj *& _Player, list<CObj*>& _Jelly)
{
	RECT PlayerRect = CObjMgr::Get_Instance()->Get_Player()->Get_Rect();

	D3DXVECTOR3 PlayerPos = { (PlayerRect.right + PlayerRect.left)*0.5f,(PlayerRect.top + PlayerRect.bottom)*0.5f , 0.f };

	
	for (auto& Jelly : _Jelly)
	{
		if (200 > D3DXVec3Length(&(PlayerPos - Jelly->Get_Pos())))
			static_cast<CJelly*>(Jelly)->Magnet();
	}
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
