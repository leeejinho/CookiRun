#pragma once

#ifndef __SCENE_H__
#define __SCENE_H__


class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Late_Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};


#endif // !__SCENE_H__
