#pragma once
#ifndef __CGIANT_H__
#define __CGIANT_H__

#include "Obj.h"
class CGiant :	public CObj
{
public:
	explicit CGiant();
	explicit CGiant(float TexInfoX, float TexInfoY);
	virtual ~CGiant();

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

#endif // !__CGIANT_H__