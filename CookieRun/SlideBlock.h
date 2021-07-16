#pragma once
#include "Block.h"
class CSlideBlock :
	public CBlock
{
public:
	CSlideBlock();
	CSlideBlock(float _fX, float _fY, DWORD _DrawId);
	~CSlideBlock();

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Late_Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

