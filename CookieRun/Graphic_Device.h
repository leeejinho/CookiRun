#pragma once
class CGraphic_Device final 
{
	//DECLARE_SINGLETON(CGraphic_Device)
private:
	CGraphic_Device();
	~CGraphic_Device();
public:
	LPDIRECT3DDEVICE9 Get_Device() { return m_pDevice; }
	LPD3DXSPRITE Get_Sprite() { return m_pSprite;  }
	LPD3DXFONT Get_Font() { return m_pFont; }
public:
	HRESULT Ready_Graphic_Device(); 
	void Release_Graphic_Device(); 
	void Render_Begin(); 
	void Render_End(); 

public:												
	static CGraphic_Device* Get_Instance()
	{													
		if (!m_pInstance)									
			m_pInstance = new CGraphic_Device;
		return m_pInstance;									
	}													
	static void Destroy_Instance()						
	{													
		if (m_pInstance)									
		{													
			delete m_pInstance;									
			m_pInstance = nullptr;								
		}													
	}																								
	
private:
	//��ġ�� �ʱ�ȭ �ϴ� ����. 
	//1.��ġ�� ������ ���´�. 
	//2.��ġ�� �ʱⰪ�� �־��ش�. 
	//3. �� �������� ���� ��ġ(�׷��� ī��)�� �����ϱ� ���� �İ�ü�� �����Ѵ�. 
	LPDIRECT3D9  m_pSDK; // ��ġ�� ������ �����ϱ� ���� �İ�ü. 
	LPDIRECT3DDEVICE9 m_pDevice; // ��ġ�� �����ϴ� �İ�ü. 
	LPD3DXSPRITE	m_pSprite; 
	LPD3DXFONT		m_pFont; 

	static CGraphic_Device* m_pInstance;
};

