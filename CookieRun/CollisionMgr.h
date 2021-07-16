#pragma once

#ifndef __COLLISIONMGR_H__
#define __COLLISIONMGR_H__

class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

//public:
//	static D3DXVECTOR3 GetPlayerRX(const CObj* _Player);	//플레이어 오른쪽 X좌표
//	static D3DXVECTOR3 GetItemLX(const CObj* _Item);		//아이템 왼쪽 X좌표
//	static D3DXVECTOR3 GetPlayerUY(const CObj* _Player);	//플레이어 위 Y좌표
//	static D3DXVECTOR3 GetItemBY(const CObj* _Item);		//아이템 아래 Y좌표
//
//
//public:
//	//아이템 먹기
//	static void Collision_HpUp(list<CObj*>& _Player, list<CObj*>& _Item);
//	static void Collision_Giant(list<CObj*>& _Player, list<CObj*>& _Item);
//	static void Collision_Score(list<CObj*>& _Player, list<CObj*>& _Item);
//	static void Collision_Speed(list<CObj*>& _Player, list<CObj*>& _Item);
};

#endif // !__COLLISIONMGR_H__
