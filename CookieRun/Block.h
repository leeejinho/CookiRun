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

public:
	void Destory();

protected:

	DWORD	DrawId;
	DWORD	m_dwDestory;

	bool	m_bDestory;

	float	m_fDestory_Scale;
	float	m_fDestory_Angle;
	float	m_fDestory_Trans;

	BLOCK_TYPE m_eType;
	HDC	hdc;
};

