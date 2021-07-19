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
private:
	void Move_Player();
	void Key_Check();
	void Jumping();
	void Update_Rect();

	void Speed_Item();
	void Giant_Item();

	void Magnet_Item();
	
public:
	void Item_Use(CItem::ITEM_TYPE _Type);

	void Update_Hp();


private:
	DWORD		m_dwTexDelay;
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
	bool		m_bMagnet;

	int			m_iDrawID;
	int			m_iMaxDrawID;

	float			m_Up;

	DWORD		m_dwMagnetTime;
	DWORD		m_dwHpDelay;
	int			m_iHp;

};

