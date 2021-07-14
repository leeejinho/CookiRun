#pragma once
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
	CMainGame* m_pPlayer;
};

