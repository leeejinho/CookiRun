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
	void Move_Player();
	void Key_Check();
	void Jumping();
	void Update_Rect();
	void Speed_Item();
	void Giant_Item();
	
public:
	void Player_Item(int _ItemNumber);

private:
	D3DXVECTOR3 m_vPos;
	D3DXVECTOR3 m_vSize;
	DWORD		m_dwDelay;
	WCHAR*		m_pStateKey;
	DWORD		dwTime;

	bool		m_bSlide;

	bool		m_bJump;
	bool		m_bDoubleJump;
	int			m_iMaxJump;
	float		m_fJumpPower;
	float		m_fJumpTime;
	float		m_fJumpY;

	float		m_fSpeed;
	float		MaxSize;
	float		LeastSize;
	float		Plus;
	bool		Speed;
	bool		Giant;

	int			m_iDrawID;
	int			m_iMaxDrawID;
	float			m_Up;
};

