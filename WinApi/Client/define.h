#pragma once

/* 면접에서 매크로 관련된 문제가 나온다면 일단 모두 전처리 해놓고 생각.
#define Add(a, b) a+b
*/

// Singleton 매크로
#define SINGLE(type) public:\
						 static type* GetInst()\
						{\
							static type mgr;\
							return &mgr;\
						}\
					 private:\
						type();\
						~type();
#define fDT CTimeMgr::GetInst()->GetfDT()
#define DT CTimeMgr::GetInst()->GetDT()