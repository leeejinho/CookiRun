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
//}
