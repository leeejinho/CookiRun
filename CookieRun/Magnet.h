#pragma once
#include "Item.h"
class CMagnet :
	public CItem
{
public:
	CMagnet();
	CMagnet(float _x, float _y);
	~CMagnet();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;


};

