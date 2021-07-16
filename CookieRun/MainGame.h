#pragma once

class CObj;
class CHpup;
class CGiant;
class CScore;
class CSpeed;
class CJelly;

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
	
};

