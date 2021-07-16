#pragma once
#include "Block.h"
class CJumpBlock :
	public CBlock
{
public:
	CJumpBlock();
	CJumpBlock(float _fX, float _fY, DWORD _DrawId);
	~CJumpBlock();

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Late_Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

