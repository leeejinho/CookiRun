#pragma once
#include "Obj.h"
class CItem :
	public CObj
{
public:
	enum ITEM_TYPE { SMALL_HP, HP, JELLY, GIANT, SPEED, MAGNET, END };

public:
	CItem();
	~CItem();

public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Late_Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	const ITEM_TYPE& Get_ItemType() const { return m_eType; }

protected:
	int iNumber;
	DWORD dwTime;
	ITEM_TYPE m_eType;
};

