#pragma once
class CObj;
class CMainGame final
{
private:
	CMainGame();
public:
	~CMainGame();

public:
	HRESULT Initialize();
	void Update();
	void Render();
	void Release();
public:
	static CMainGame* Create();
private:
	CObj* m_pPlayer;
};

