#pragma once
class CStage_Setting
{
public:
	CStage_Setting();
	~CStage_Setting();

public:
	void stage1_Setting();

public:
	void Jelly();
	void Block();
	void Item();

	void Land( int _inum, float _x, float _y = 545.f);
	void Slide(DWORD _DrawID,float _x, float _y = 70.f);
	void Jump(DWORD _DrawID, float _x, float _y = 430.f);
	void Djump(DWORD _DrawID, float _x, float _y = 380.f);

	void Jelly_Straight(float _x, float _y, int _inum);
	void Jelly_Straight2(float _x, float _y, int _inum);
	void Jelly_Straight3(float _x, float _y, int _inum);
	void Jelly_Straight4(float _x, float _y, int _inum);
	void Jelly_Jump(float _x, float _y);
	void Jelly_Djump(float _x, float _y);
	void Jelly_Seven(float _x, float _y);


	void smallHp(float _x, float _y);
	void Hp(float _x, float _y);
	void Giant(float _x, float _y);
	void Speed(float _x, float _y);

};

