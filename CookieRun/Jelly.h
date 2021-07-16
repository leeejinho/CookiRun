#pragma once
#include "Obj.h"
class CJelly :	public CObj
{
public:
	CJelly();
	CJelly(float TexInfoX, float TexInfoY);
	virtual ~CJelly();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

