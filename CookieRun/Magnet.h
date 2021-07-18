#pragma once
#include "Obj.h"
class CMagnet :
	public CObj
{
public:
	CMagnet();
	CMagnet(float _x, float _y);
	~CMagnet();

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

