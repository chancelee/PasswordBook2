#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"ctrl.h"
#include "data.h"
//���ܣ���ɾ�Ĳ���ʾ���У�����д���ļ��������뱾Ҳ��Ҫ��������
int main(void)
{
	int nSec = 1;
	while (nSec)
	{
		char cKey[7] = { 0 };
		printf("����������:\n");
		scanf_s("%s", cKey, 7);
		if (!strcmp(cKey, "123456"))
			nSec = 0;
		else
			printf("�����������������\n");
		system("cls");
		getchar();
	}	
	MenuP();
	free(gPb);	//�����˳�֮ǰ�ͷŽṹ��ָ��
	gPb = NULL;	//�����ÿ�
	return 0;
}