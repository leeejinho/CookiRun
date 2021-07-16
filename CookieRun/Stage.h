#pragma once
#include "Scene.h"
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

public:
	void Stage1_Test();

private:
	void Render_Background();
};

