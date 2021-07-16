#pragma once
#ifndef __CHPUP_H__
#define __CHPUP_H__

#include "Obj.h"
class CHpup :	public CObj
{
public:
	CHpup();
	CHpup(float TexInfoX , float TexInfoY);
	virtual ~CHpup();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	int iNumber;
	DWORD dwTime;
};

#endif // !__CHPUP_H__
