#pragma once
#ifndef __OBJ_H__
#define __OBJ_H__
class CObj abstract
{
public:
	CObj();
	virtual ~CObj();
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Late_Update()PURE;
	virtual void Render(HDC _DC)PURE;
	virtual void Release()PURE;
};

#endif // !__OBJ_H__
