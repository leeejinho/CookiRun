#pragma once
#include "Obj.h"
class CBlock : public CObj
{
public:
	enum BLOCK_TYPE { JUMP, DJUMP, SLIDE, END };
public:
	CBlock();
	~CBlock();

public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Late_Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	const D3DXVECTOR3& Get_Pos() const { return m_vPos; }
	const DWORD& Get_DrawId() const { return DrawId; }
	const BLOCK_TYPE& Get_Type() const { return m_eType; }

public:
	void Set_Pos(float _fx, float _fy) { m_vPos.x = _fx; m_vPos.y = _fy; }


protected:
	D3DXVECTOR3	m_vPos;
	D3DXVECTOR3	m_vSize;
	DWORD	DrawId;

	BLOCK_TYPE m_eType;
	HDC	hdc;
};

