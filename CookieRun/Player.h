#pragma once
#include "Obj.h"
#include "Item.h"

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
	const bool Get_Magnet_Item() const { return m_bMagnet; }
	bool Get_Hit() { return m_bHit; }
private:
	void Move_Player();
	void Key_Check();
	void Jumping();
	void Update_Rect();
	void Hit_Check();
	void Speed_Item();
	void Giant_Item();
	void Magnet_Item();
	void Update_Hp();
	
public:
	void Item_Use(CItem::ITEM_TYPE _Type);
	void Set_Hp(int _iHp) { m_iHp += _iHp; }
	void Set_Hit() { m_bHit = true; }
	void Set_HitTime() { m_dwHitTime = GetTickCount(); }
	void Set_Speed() { m_fSpeed = 1.f; }

private:
	DWORD		m_dwTexDelay;
	WCHAR*		m_pStateKey;
	DWORD		dwTime;

	bool		m_bGiant;
	DWORD		m_dwGiantTime;
	bool		m_bSpeed;
	DWORD		m_dwSpeedTime;
	bool		m_bHit;
	DWORD		m_dwHitTime;
	int			m_iBlink;
	DWORD		m_dwBlinkTime;


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
	bool		m_bMagnet;

	int			m_iDrawID;
	int			m_iMaxDrawID;

	float			m_Up;

	DWORD		m_dwMagnetTime;
	DWORD		m_dwHpDelay;
	int			m_iHp;

};

