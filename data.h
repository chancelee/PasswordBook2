#pragma once
#define CHM 50	//�涨ÿһ�������д50���ַ�
#define ENC 8	//�������ܳ�  

typedef struct _PWDBOOK {
	char cWeb[CHM];	//վ����
	char cUser[CHM];//�û���
	char cPwd[CHM];//����
	char cNote[CHM];//��ע
}PWDBOOK,*pPWDBOOK;

extern int gCount;//��ǰ�ж�������¼
extern int gMax;//�������
extern pPWDBOOK gPb;//�ṹ��ָ��
