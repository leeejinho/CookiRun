#pragma once

#ifndef __COLLISIONMGR_H__
#define __COLLISIONMGR_H__

class CObj;
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static void Collision_Rect(list<CObj*>& _Player, list<CObj*>& _Item);
	static void CCollisionMgr::Collision_Tile(list<CObj*>& _Player, list<CObj*>& _Tile);
	static bool CCollisionMgr::Check_Rect(CObj* _Player, CObj* _Item, float* _x, float* _y);

};

#endif // !__COLLISIONMGR_H__
