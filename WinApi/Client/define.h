#pragma once

/* �������� ��ũ�� ���õ� ������ ���´ٸ� �ϴ� ��� ��ó�� �س��� ����.
#define Add(a, b) a+b
*/

// Singleton ��ũ��
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