#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#pragma comment(lib,"winmm.lib")


void play();
void sang(int m);
void sing( char* mci);

	char c;
	char cmd[200];
	char music[200]="LONOL LONOL LONO OOMMLLONOL LQPPO LONOM MMOTS PPRRQQ QQNPOONO ONOR LSRQPPPRRQQ QQVUTUV VPOT TTSSSLSRQQRQ QRQ RQPOOQST TTSPPRQ OQST TTSPPRQRQPO PQMMOONO";
    char music1[200]="TVUTSTQ  TSTVUVUTUV VWXXXXW  VUTUS  TVUTST QSTXWVUV  VUTTTTSSTQ SSTXWVUVV  VUTTSUT";
	char music2[200]="STVTXXTW  WWVUVWXWSV VUTUVRRRVVWVSSS SYXWXX  STVTXXTW  WWVUVWXWSVV VUTUVRRRVVWVSSS  STUVVUVV";
	int i=0;
	unsigned int j=0;

int main()
{
  int opt;
  loop: system("cls");
  system("color f4");

  printf("\t\t\t��ӭʹ��!!!\n\n");
  printf("\t1.������\t2.���Ű���\t3.��������\t0.�˳�\n\n");
  while(1)
  {
  printf("��ѡ��");
 
  
  if(scanf("%d",&opt)==0)
  {
  while(getchar()!='\n');//��ջ�����
  opt=-1;
  
  }
  switch(opt){
  
  case 0:return 1;
  case 1:
	  {
		  system("cls");//����
		  printf("��ʱ���Ե��٣��س�������������");
		  play(); 
		  goto loop;
	  }break;
  case 2:
	  {
		   
		 while(1)
		 {
			 system("cls");
			 printf("��ѡ����ǲ��Ű���\n\n");
		     printf("\t1.ͯ��\t2.������Ը \t3. �������ʹ \t0.����");
             printf("��ѡ��");
 
         if(scanf("%d",&opt)==0)
	   {
      while(getchar()!='\n');//��ջ�����
	  opt=-1;}
	   switch(opt)
	   {
  
       case 0:goto loop;
       case 1:
		   {printf("���� ͯ��");
		   sing(music);}break;

	   case 2:
		  {printf("���� ������Ը");
		 sing(music1); }break;

	   case 3:
		   {printf("���� �������ʹ");
		 sing(music2); }break;
	   
	   }
	    default:
			{
	  printf("����������뷵��");
	  Sleep(3000);

  
		 }
	  }
	  
	  }
  }break;
  case 3:
	  {

		     
		 while(1)
		 {
			 system("cls");
			 printf("��ѡ����ǲ�������\n\n");
		     printf("\t1.ͯ��\t2.������Ը \t3. �������ʹ \t0.����");
             printf("��ѡ��");
 
             if(scanf("%d",&opt)==0)
			{
				while(getchar()!='\n');//��ջ�����
				opt=-1;
			 }
			   switch(opt)
			   {
  
			   case 0:goto loop;
			   case 1:
				   {printf("���� ��İ���");
				   sang(1); 
				   }break;

			   case 2:
				  {printf("����");
				 sang(2); }break;

			   case 3:
				   {printf("���� �������");
				 sang(3); }break;
			   
			   }
			   
		 
  
	}
  
  }
  }


	return 0;
}
void play(){

	while(1){
		c=getche();
		if(c=='\r')break;
		sprintf(cmd,"open sound//%c.mp3 alias s%d",c,i);
		mciSendString(cmd,NULL,0,NULL);

		sprintf(cmd,"play s%d",i);
		mciSendString(cmd,NULL,0,NULL);
		i++;

		}
}
void sang(int m){
	while(1){
			
    sprintf(cmd,"play singsang//%d.mp3",m);
    mciSendString(cmd,NULL,0,NULL);
	
	Sleep(240000);

	}
	
}
void sing( char* mci){

for(j=0;j<strlen(music);j++){
		sprintf(cmd,"open sound//%c.mp3 alias s%d",mci[j],i);
		mciSendString(cmd,NULL,0,NULL);
		sprintf(cmd,"play s%d",i);
		mciSendString(cmd,NULL,0,NULL);
		i++;
		Sleep(500);}
}