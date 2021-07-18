#pragma once

#ifndef __COLLISIONMGR_H__
#define __COLLISIONMGR_H__

class CObj;
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();


//public:
//	static D3DXVECTOR3 GetPlayerRX(const CObj* _Player);	//�÷��̾� ����� X��ǥ
//	static D3DXVECTOR3 GetItemLX(const CObj* _Item);		//������ ���� X��ǥ
//	static D3DXVECTOR3 GetPlayerUY(const CObj* _Player);	//�÷��̾� � Y��ǥ
//	static D3DXVECTOR3 GetItemBY(const CObj* _Item);		//������ �Ʒ� Y��ǥ
//
//
//public:
//	//������ �Ա�
//	static void Collision_HpUp(list<CObj*>& _Player, list<CObj*>& _Item);
//	static void Collision_Giant(list<CObj*>& _Player, list<CObj*>& _Item);
//	static void Collision_Score(list<CObj*>& _Player, list<CObj*>& _Item);
//	static void Collision_Speed(list<CObj*>& _Player, list<CObj*>& _Item);

//public:
//	static void Collision_Magnet_Jelly(CObj*& _Player, list<CObj*>& _Jelly);

public:
	static void Collision_Rect(list<CObj*>& _Player, list<CObj*>& _Item);
	static void CCollisionMgr::Collision_Tile(list<CObj*>& _Player, list<CObj*>& _Tile);
	static bool CCollisionMgr::Check_Rect(CObj* _Player, CObj* _Item, float* _x, float* _y);


	static void Collision_Player_Item(CObj*& _Player, list<CObj*>& _Item);
	static void Collision_Player_Jelly(CObj*& _Player, list<CObj*>& _Jelly);
	static void Collision_Player_Block(CObj*& _Player, list<CObj*>& _Block);
	static void Collision_Player_Tile(CObj*& _Player, list<CObj*>& _Tile);
	static void Magnet_Jelly(CObj*& _Player, list<CObj*>& _Jelly);

};

#endif // !__COLLISIONMGR_H__
