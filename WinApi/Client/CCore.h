#pragma once
#include "pch.h"

// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능



/* 싱글톤 패턴1
class CCore
{
private:
	static CCore* g_pInst;

public:
	// 정적 멤버함수
	static CCore* GetInstance()
	{
		// 최초 호출 된 경우 데이터 영역에 초기화.
		if (nullptr == g_pInst)
		{
			g_pInst = new CCore;
		}

		return g_pInst;
	}

	static void Release()
	{
		if (nullptr != g_pInst)
		{
			delete g_pInst;
			g_pInst = nullptr;
		}
	}

private:
	CCore();
	~CCore();
};
*/


class CCore
{
private:
	HWND	m_hWnd;         // 메인 윈도우 핸들
	POINT   m_ptResolution; // 메인 윈도우 해상도
	HDC     m_hDC;          // 메인 윈도우에 Draw할 DC

	HBITMAP m_hBit;
	HDC     m_memDC;
SINGLE(CCore);

public:
	int init(HWND hWnd, POINT _ptResolution);
	void progress();
private:
	void update();
	void render();
public:
	HWND GetMainHwnd() { return m_hWnd; }

};