#pragma once
#ifndef __CGIANT_H__
#define __CGIANT_H__

#include "Obj.h"
class CGiant :	public CObj
{
public:
	CGiant();
	virtual ~CGiant();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;
private:
	int iNumber;
};

#endif // !__CGIANT_H__