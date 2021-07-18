#pragma once
#include "Obj.h"
class CHpbar final:
	public CObj
{
public:
	CHpbar();
	virtual ~CHpbar();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	int m_iCurHp;
};

