﻿#pragma once


//==========================================
//	## 윈도우 사이즈 ##
//==========================================
#define WIN_SIZE_X 540
#define WIN_SIZE_Y 909

#ifdef _ACADEMY_
#define WIN_START_X 2000
#else
#define WIN_START_X 0
#endif

#define WIN_START_Y 0


//==========================================
//	## 싱글톤 선언 ##
//==========================================
#define DECLARE_SINGLE(ClassName)			\
private:									\
	ClassName() {}							\
	~ClassName() {}							\
public:										\
	static ClassName* GetInstance()			\
	{										\
		static ClassName instance;			\
		return &instance;					\
	}

#define GET_SINGLE(ClassName)	ClassName::GetInstance()

#define SAFE_DELETE(p) {if(p) delete (p); (p) = NULL;}
#define SAFE_DELETE_ARRAY(o) {if(p) delete [] (p); (p) = NULL;}

// (0.000001)
#define EPSILON 1e-6f

#define Rad2Deg(x) (57.2957 * x)
#define Deg2Rad(x) (0.017453 * x)
#define EQUALS(a, b) (abs(a - b) < EPSILON)


#define DECLARE_CHILD(ClassName, ParentName)	\
	using Super = ParentName;					\
public:											\
	ClassName() {}								\
	virtual ~ClassName() {}


#define Alert(title, message) MessageBox(_hWnd, message, title, NULL)
#define CurrentScene (GET_SINGLE(SceneManager)->GetCurrentScene())
