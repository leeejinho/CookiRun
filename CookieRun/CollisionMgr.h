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
	static void Collision_Tile(list<CObj*>& _Player, list<CObj*>& _Tile);

};

#endif // !__COLLISIONMGR_H__
