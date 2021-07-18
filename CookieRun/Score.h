#pragma once
#ifndef __CSORE_H__
#define __CSORE_H__

#include "Obj.h"
class CScore :	public CObj
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
private:
	int iNumber;
	DWORD dwTime;
};

#endif // !__CSORE_H__