#pragma once
#include "Item.h"
class CJelly :	public CItem
{
public:
	CJelly();
	CJelly(float TexInfoX, float TexInfoY);
	virtual ~CJelly();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	void Update_Rect();

public:
	void Magnet();
private:
	int		Magnet_Speed;
};

