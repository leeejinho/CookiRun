#pragma once

class CHpup;
class CGiant;
class CScore;
class CSpeed;
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
	CHpup*		m_pHpup;
	CGiant*		m_pGiant;
	CScore*		m_pScore;
	CSpeed*		m_pSpeed;
};

