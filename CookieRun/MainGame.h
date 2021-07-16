#pragma once

class CObj;
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
	CObj* m_pPlayer;
	CMainGame* m_pPlayer;
	CHpup*		m_pHpup;
	CGiant*		m_pGiant;
	CScore*		m_pScore;
	CSpeed*		m_pSpeed;
};

