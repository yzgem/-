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

  printf("\t\t\t欢迎使用!!!\n\n");
  printf("\t1.弹钢琴\t2.播放伴奏\t3.播放音乐\t0.退出\n\n");
  while(1)
  {
  printf("请选择");
 
  
  if(scanf("%d",&opt)==0)
  {
  while(getchar()!='\n');//清空缓存区
  opt=-1;
  
  }
  switch(opt){
  
  case 0:return 1;
  case 1:
	  {
		  system("cls");//清屏
		  printf("此时可以弹琴（回车键结束）！！");
		  play(); 
		  goto loop;
	  }break;
  case 2:
	  {
		   
		 while(1)
		 {
			 system("cls");
			 printf("你选择的是播放伴奏\n\n");
		     printf("\t1.童话\t2.星语心愿 \t3. 会呼吸的痛 \t0.返回");
             printf("请选择");
 
         if(scanf("%d",&opt)==0)
	   {
      while(getchar()!='\n');//清空缓存区
	  opt=-1;}
	   switch(opt)
	   {
  
       case 0:goto loop;
       case 1:
		   {printf("播放 童话");
		   sing(music);}break;

	   case 2:
		  {printf("播放 星语心愿");
		 sing(music1); }break;

	   case 3:
		   {printf("播放 会呼吸的痛");
		 sing(music2); }break;
	   
	   }
	    default:
			{
	  printf("输入错误，三秒返回");
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
			 printf("你选择的是播放音乐\n\n");
		     printf("\t1.童话\t2.星语心愿 \t3. 会呼吸的痛 \t0.返回");
             printf("请选择");
 
             if(scanf("%d",&opt)==0)
			{
				while(getchar()!='\n');//清空缓存区
				opt=-1;
			 }
			   switch(opt)
			   {
  
			   case 0:goto loop;
			   case 1:
				   {printf("播放 真的爱你");
				   sang(1); 
				   }break;

			   case 2:
				  {printf("播放");
				 sang(2); }break;

			   case 3:
				   {printf("播放 单身情歌");
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