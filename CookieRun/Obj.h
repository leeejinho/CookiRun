#pragma once
#ifndef __OBJ_H__
#define __OBJ_H__
class CObj abstract
{
public:
	CObj();
	virtual ~CObj();
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Late_Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void Set_Dead() { m_bDead = true; }

public:
	const TEXINFO& Get_TexInfo() const { return m_TexInfo; }
protected:
	bool		m_bDead;
	TEXINFO		m_TexInfo;
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vSize;
};

#endif // !__OBJ_H__
