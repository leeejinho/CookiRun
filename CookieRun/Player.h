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
	void Jumping();

private:
	D3DXVECTOR3 m_vPos;
	D3DXVECTOR3 m_vSize;
	DWORD		m_dwDelay;
	WCHAR*		m_pStateKey;

	bool		m_bSlide;

	bool		m_bJump;
	bool		m_bDoubleJump;
	int			m_iMaxJump;
	float		m_fJumpPower;
	float		m_fJumpTime;
	float		m_fJumpY;

	int			m_iDrawID;
	int			m_iMaxDrawID;
};

