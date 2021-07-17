#pragma once
#include "Obj.h"
class CPlayer final:
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

public:
	int	Get_Hp() { return m_iHp; }

private:
	void Move_Player();
	void Key_Check();
	void Jumping();
	void Update_Rect();
	void Update_Hp();

private:
	DWORD		m_dwTexDelay;
	WCHAR*		m_pStateKey;
	RECT		m_Rect;

	bool		m_bSlide;

	bool		m_bJump;
	bool		m_bDoubleJump;
	int			m_iMaxJump;
	float		m_fJumpPower;
	float		m_fJumpTime;
	float		m_fJumpY;

	float		m_fSpeed;

	int			m_iDrawID;
	int			m_iMaxDrawID;
	
	DWORD		m_dwHpDelay;
	int			m_iHp;
};

