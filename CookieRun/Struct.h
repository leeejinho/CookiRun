#pragma once
typedef struct tagTexInfo
{
	LPDIRECT3DTEXTURE9 pTexture; 
	D3DXIMAGE_INFO tImageInfo;
}TEXINFO;

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vDir;
	D3DXVECTOR3 vSize;
}INFO;
