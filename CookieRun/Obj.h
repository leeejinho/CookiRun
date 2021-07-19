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
	void Set_PosY(float _fY) { m_vPos.y = _fY; }
	void Set_PosX(float _fX) { m_vPos.y += _fX; }
	void Set_SizeX(float _SizeX) { m_vSize.x += _SizeX; }
	void Set_SizeY(float _SizeY) { m_vSize.y += _SizeY; }


public:
	const TEXINFO& Get_TexInfo() const { return m_TexInfo; }
	const RECT& Get_Rect() const { return m_tRect; }
	D3DXVECTOR3 Get_Pos() { return m_vPos; }
	D3DXVECTOR3 Get_Size() { return m_vSize; }
	


protected:
	bool		m_bDead;
	TEXINFO		m_TexInfo;
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vSize;
	RECT	m_tRect;

};

#endif // !__OBJ_H__

