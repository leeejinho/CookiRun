#pragma once
#ifndef __CSORE_H__
#define __CSORE_H__

#include "Item.h"
class CScore :	public CItem
{
public:
	explicit CScore();
	explicit CScore(float TexInfoX, float TexInfoY);
	virtual ~CScore();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

#endif // !__CSORE_H__