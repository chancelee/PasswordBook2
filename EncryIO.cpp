#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "data.h"
#include "EncryIO.h"
//���������ܣ�ÿ���ַ������ENC
//���ļ��е����ݶ������ڴ沢����
void InitP()
{
	FILE *pFile = nullptr;

	//1.��
	if (fopen_s(&pFile, "pwd.txt", "ab+"))	//rb+���ܶ�Ҳ��д����w�ᱻ���ǣ���r���ܴ�0��ʼ��
		printf("���ļ�ʧ��\n");
	//��ȡ������
	fseek(pFile, 0, SEEK_END);
	gCount = ftell(pFile) / 200;
	fseek(pFile, 0, SEEK_SET);
	if (gCount>gMax)
	{
		gPb = (pPWDBOOK)malloc(gCount * sizeof(PWDBOOK));
		memset(gPb, 0, gCount * sizeof(PWDBOOK));
		for (int i = 0; i < gCount; i++)
		{
			fread(gPb[i].cWeb, CHM, 1, pFile);
			fread(gPb[i].cUser, CHM, 1, pFile);
			fread(gPb[i].cPwd, CHM, 1, pFile);
			fread(gPb[i].cNote, CHM, 1, pFile);
			for (int j = 0; j < CHM;j++)
			{
				gPb[i].cWeb[j] ^= ENC;
				gPb[i].cUser[j] ^= ENC;
				gPb[i].cPwd[j] ^= ENC;
				gPb[i].cNote[j] ^= ENC;
			}
		}
	}
	else
	{
		gPb = (pPWDBOOK)malloc(gMax * sizeof(PWDBOOK));
		memset(gPb, 0, gMax * sizeof(PWDBOOK));
	}
	
	//3.�ر�
	fclose(pFile);
}
//���ڴ��е����ݼ��ܲ�д���ļ�
void SaveP()
{
	FILE *pFile = nullptr;
	//1.��
	if (fopen_s(&pFile, "pwd.txt", "wb+"))
		printf("ʧ��\n");
	//2.����д��
	for (int i = 0; i < gCount; i++)
	{
		for (int j = 0; j < CHM;j++)
		{
			gPb[i].cWeb[j] ^= ENC;
			gPb[i].cUser[j] ^= ENC;
			gPb[i].cPwd[j] ^= ENC;
			gPb[i].cNote[j] ^= ENC;
		}
		fwrite(gPb[i].cWeb, CHM, 1, pFile);
		fwrite(gPb[i].cUser, CHM, 1, pFile);
		fwrite(gPb[i].cPwd, CHM, 1, pFile);
		fwrite(gPb[i].cNote, CHM, 1, pFile);
	}
	//3.�ر�
	fclose(pFile);
}