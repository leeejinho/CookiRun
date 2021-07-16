#pragma once
#ifndef __CSPEED_H__
#define __CSPEED_H__

#include "Obj.h"
class CSpeed : 	public CObj
{
public:
	CSpeed();
	virtual ~CSpeed();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;
private:
	int iNumber;
};

#endif // !__CSPEED_H__