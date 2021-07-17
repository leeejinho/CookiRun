#pragma once
#include "Scene.h"

class CStage_Setting;
class CStage :
	public CScene
{
public:
	CStage();
	~CStage();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render() override;
	virtual void Release() override;


private:
	void Render_Background();
	CStage_Setting* Stage_Set;
};

