#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"ctrl.h"


void MenuP()
{
	char cOp = 0;	//�û�������
	int nOver = 1;	//�ж��Ƿ��˳�����

	while (nOver)
	{
		printf("��ӭʹ�����뱾\n");
		printf("1.Add\n2.Delete\n3.Alert\n4.Find\n5.ShowAll\n6.Quit\n");
		scanf_s("%c", &cOp, 1);
		switch (cOp)
		{
		case '1':AddP(); break;
		case '2':DeleteP(); break;
		case '3':AlertP(); break;
		case '4':
		{
			FindP();
			system("pause");
		}break;
		case '5':ShowAll(); break;
		case '6':nOver = 0; break;
		default:
			printf("�����������������\n");
			break;
		}
		getchar();
		system("cls");
	}
	
}