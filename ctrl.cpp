#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "data.h"
#include "ctrl.h"
#include "EncryIO.h"


void ShowAll()
{
	InitP();
	printf("��%d����¼\n------------------------------------------\n", gCount);
	for (int i = 0; i < gCount; i++)
	{
		printf("��%d����¼��\n-------------------------------------------\n", i + 1);
		printf("վ������%s\n�û�����%s\n��  �룺%s\n��  ע��%s\n", gPb[i].cWeb, gPb[i].cUser, gPb[i].cPwd, gPb[i].cNote);
		printf("-------------------------------------------\n");
	}


	system("pause");
}
void AddP()
{
	InitP();
	printf("������Ŀ��վ�㡢�û��������롢��ע��Ϣ\n");
	if (gCount>gMax)
	{
		pPWDBOOK pNew = (pPWDBOOK)malloc((gCount +1) * sizeof(PWDBOOK));
		memcpy(pNew, gPb, gCount * sizeof(PWDBOOK));
		free(gPb);
		gPb = pNew;
	}
	scanf_s("%s %s %s %s", gPb[gCount].cWeb, CHM, gPb[gCount].cUser, CHM, gPb[gCount].cPwd, CHM, gPb[gCount].cNote, CHM);
	gCount++;
	SaveP();
	printf("��ӳɹ�\n");
}
int FindP()
{
	InitP();
	printf("������վ������\n");
	char cKey[CHM];//�ؼ���
	scanf_s("%s", cKey, CHM);
	int nFd = -1;
	for (int i = 0; i < gCount; i++)
	{
		if (!strcmp(cKey, gPb[i].cWeb))
		{
			nFd = i;
			break;
		}
	}
	if (nFd == -1)
		printf("û���ҵ�\n");
	else
	{
		printf("��%d�����ϣ�\n", nFd + 1);
		printf("-------------------------------------------\n");
		printf("վ������%s\n�û�����%s\n��  �룺%s\n��  ע��%s\n", gPb[nFd].cWeb, gPb[nFd].cUser, gPb[nFd].cPwd, gPb[nFd].cNote);
	}
	return nFd;
}
void DeleteP()
{
	int nIdx = FindP();
	if (nIdx == -1)
		printf("�޷�ɾ��\n");
	else
	{
		for (int i = nIdx; i < gCount - 1; i++)
		{
			strcpy_s(gPb[i].cWeb, CHM, gPb[i + 1].cWeb);
			strcpy_s(gPb[i].cUser, CHM, gPb[i + 1].cUser);
			strcpy_s(gPb[i].cPwd, CHM, gPb[i + 1].cPwd);
			strcpy_s(gPb[i].cNote, CHM, gPb[i + 1].cNote);
		}
		gCount--;

		SaveP();
		printf("ɾ���ɹ�\n");
	}
	system("pause");
}
void AlertP()
{
	int nIdx = FindP();
	if (nIdx == -1)
		printf("�޷�ɾ��\n");
	else
	{
		printf("-------------------------------------------\n");
		printf("�������µ��û��������롢��ע\n");
		scanf_s("%s %s %s", gPb[nIdx].cUser, CHM, gPb[nIdx].cPwd, CHM, gPb[nIdx].cNote, CHM);
		SaveP();
		printf("�޸ĳɹ�\n");
	}
	system("pause");
}