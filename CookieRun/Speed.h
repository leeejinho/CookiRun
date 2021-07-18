#pragma once
#ifndef __CSPEED_H__
#define __CSPEED_H__
#include "Item.h"
class CSpeed : 	public CItem
{
public:
	explicit CSpeed();
	explicit CSpeed(float TexInfoX, float TexInfoY);
	virtual ~CSpeed();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

#endif // !__CSPEED_H__