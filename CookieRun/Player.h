#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	explicit CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	void Key_Check();

private:
	D3DXVECTOR3 m_vPos;
	D3DXVECTOR3 m_vSize;
	DWORD		m_dwDelay;
	WCHAR*		m_pStateKey;

	int			m_iDrawID;
	int			m_iMaxDrawID;
};

