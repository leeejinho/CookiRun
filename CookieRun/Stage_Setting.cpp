#include "stdafx.h"
#include "Stage_Setting.h"
#include "DjumpBlock.h"
#include "JumpBlock.h"
#include "SlideBlock.h"
#include "Jelly.h"
#include "Land.h"
#include "ObjMgr.h"
#include "Hpup.h"
#include "Giant.h"
#include "Score.h"
#include "Speed.h"


CStage_Setting::CStage_Setting()
{
}


CStage_Setting::~CStage_Setting()
{
}

void CStage_Setting::stage1_Setting()
{
	Block();
	Jelly();
	Item();
}



void CStage_Setting::Jelly()
{
	Jelly_Straight(500.f, 400.f, 10);
	Jelly_Straight2(1000.f, 425.f, 10);
	Jelly_Jump(2500.f, 420.f);
	Jelly_Straight(2650.f , 450.f, 11);
	Jelly_Jump(3300.f, 420.f);
	Jelly_Straight(3750.f, 450.f, 11);
	Jelly_Djump(4800.f, 440.f);
	Jelly_Seven(5500.f, 400.f);
	Jelly_Seven(6000.f, 200.f);
	Jelly_Straight4(6500.f, 300.f, 10);
	Jelly_Straight(9800.f, 450.f,7);
	Jelly_Jump(10250.f, 420.f);
	Jelly_Straight(10400.f, 450.f, 5);
	Jelly_Djump(10800.f, 480.f);
	Jelly_Straight(11000.f, 450.f, 7);
	Jelly_Straight(14000.f, 425.f, 10);
	Jelly_Djump(15000.f, 480.f);
	Jelly_Jump(15800.f, 420.f);
	Jelly_Straight(16400.f, 450.f, 11);
	Jelly_Jump(17200.f, 420.f);
	Jelly_Straight(17350.f, 420.f, 3);
	Jelly_Jump(17600.f, 420.f);
}

void CStage_Setting::Block()
{
	Land(150, 0.f);

	Jump(0, 2500.f);
	Jump(1, 3300.f);
	Slide(1, 3850.f);
	Slide(0, 4000.f);
	Slide(1, 4150.f);
	Djump(0, 4800.f);
	for (int i = 0; i < 10; ++i)
	{
		Djump((i * 3) % 6, 7500 + i*100.f);
	}
	Slide(1, 10000.f);
	Jump(1, 10250.f);
	Slide(0, 10500.f);
	Djump(0, 10800.f);
	Slide(1, 11100.f);
	Djump(0, 15000.f);
	Jump(1, 15800.f);
	Slide(1, 16500.f);
	Slide(0, 16650.f);
	Slide(1, 16800.f);
	Jump(0, 17200.f);
	Jump(1, 17600.f);
}

void CStage_Setting::Item()
{
	Giant(7300.f, 350.f);
}

void CStage_Setting::Land(int _inum , float _x, float _y/*= 545.f*/)
{
	CObj* pLand = nullptr;

	for (int i = 0; i < _inum; ++i)
	{
		if (i != 14 && i != 15 && i != 16 && i != 100 && i!= 105 && i != 106 && i != 107)
		{
			pLand = new CLand(124.f * i + 62.f + _x, _y);
			pLand->Initialize();

			CObjMgr::Get_Instance()->Add_Object(pLand, OBJID::LAND);
		}
	}
}

void CStage_Setting::Slide(DWORD _DrawID, float _x, float _y/*= 70.f*/)
{
	CObj* pobj = nullptr;
	pobj = new CSlideBlock(_x, _y, _DrawID);
	pobj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::BLOCK);
}

void CStage_Setting::Jump(DWORD _DrawID, float _x, float _y/*= 430.f*/)
{
	CObj* pobj = nullptr;
	pobj = new CJumpBlock(_x, _y, _DrawID);
	pobj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::BLOCK);
}

void CStage_Setting::Djump(DWORD _DrawID, float _x, float _y /*= 380.f*/)
{
	CObj* pobj = nullptr;
	pobj = new CDjumpBlock(_x, _y, _DrawID);
	pobj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::BLOCK);
}

void CStage_Setting::Jelly_Straight(float _x, float _y, int _inum)
{
	CObj* pobj = nullptr;

	for (int i = 0; i < _inum; ++i)
	{
		pobj = new CJelly(_x + i*50.f, _y);
		pobj->Initialize();
		CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::JELLY);
	}
}

void CStage_Setting::Jelly_Straight2(float _x, float _y, int _inum)
{
	CObj* pobj = nullptr;

	for (int i = 0; i < _inum; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			pobj = new CJelly(_x + i*50.f, _y - j * 50);
			pobj->Initialize();
			CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::JELLY);
		}
	}
}

void CStage_Setting::Jelly_Straight3(float _x, float _y, int _inum)
{
	CObj* pobj = nullptr;

	for (int i = 0; i < _inum; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			pobj = new CJelly(_x + i*50.f, _y - j * 50);
			pobj->Initialize();
			CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::JELLY);
		}
	}
}

void CStage_Setting::Jelly_Straight4(float _x, float _y, int _inum)
{
	CObj* pobj = nullptr;

	for (int i = 0; i < _inum; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			pobj = new CJelly(_x + i*50.f, _y - j * 50);
			pobj->Initialize();
			CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::JELLY);
		}
	}
}

void CStage_Setting::Jelly_Jump(float _x, float _y)
{
	CObj* pobj = nullptr;
	for (int i = 2; i < 7; ++i)
	{
		if (i == 3 || i == 5)
			pobj = new CJelly(_x - 200 + i*50.f, _y - 50);
		else if (i == 4)
			pobj = new CJelly(_x - 200 + i*50.f, _y - 75);
		else
			pobj = new CJelly(_x - 200 + i*50.f, _y);
		pobj->Initialize();
		CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::JELLY);
	}
}

void CStage_Setting::Jelly_Djump(float _x, float _y)
{
	CObj* pobj = nullptr;
	for (int i = 3; i < 10; ++i)
	{
		if (i == 3 || i == 9)
			pobj = new CJelly(_x - 300 + i*50.f, _y - 60);
		else if (i == 4 || i == 8)
			pobj = new CJelly(_x - 300 + i*50.f, _y - 120);
		else if (i == 5 || i == 7)
			pobj = new CJelly(_x - 300 + i*50.f, _y - 180);
		else if (i == 6)
			pobj = new CJelly(_x - 300 + i*50.f, _y - 240);
		else
			pobj = new CJelly(_x - 300 + i*50.f, _y);
		pobj->Initialize();
		CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::JELLY);
	}
}


void CStage_Setting::Jelly_Seven(float _x, float _y)
{
	CObj* pobj = nullptr;

	for (int i = 0; i < 2; ++i)
	{
		pobj = new CJelly(_x - 25 + i*50.f, _y - 50);
		pobj->Initialize();
		CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::JELLY);
	}
	for (int i = 0; i < 3; ++i)
	{
		pobj = new CJelly(_x - 50 + i*50.f, _y);
		pobj->Initialize();
		CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::JELLY);
	}
	for (int i = 0; i < 2; ++i)
	{
		pobj = new CJelly(_x - 25 + i*50.f, _y + 50);
		pobj->Initialize();
		CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::JELLY);
	}
}


void CStage_Setting::smallHp(float _x, float _y)
{
	CObj* pobj = nullptr;
	pobj = new CHpup(_x, _y);
	pobj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::BLOCK);
}

void CStage_Setting::Hp(float _x, float _y)
{
	CObj* pobj = nullptr;
	pobj = new CScore(_x, _y);
	pobj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::BLOCK);
}

void CStage_Setting::Giant(float _x, float _y)
{
	CObj* pobj = nullptr;
	pobj = new CGiant(_x, _y);
	pobj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::BLOCK);
}

void CStage_Setting::Speed(float _x, float _y)
{
	CObj* pobj = nullptr;
	pobj = new CSpeed(_x, _y);
	pobj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pobj, OBJID::BLOCK);
}
