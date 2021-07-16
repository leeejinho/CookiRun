#pragma once
#include "Block.h"
class CLand :
	public CBlock
{
public:
	CLand();
	CLand(float _fX,float _fY);
	~CLand();

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Late_Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

