#pragma once
#ifndef __CHPUP_H__
#define __CHPUP_H__

#include "Item.h"
class CHpup :	public CItem
{
public:
	explicit CHpup();
	explicit CHpup(float TexInfoX , float TexInfoY);
	virtual ~CHpup();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;


};

#endif // !__CHPUP_H__
