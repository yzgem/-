//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )����ʾ����̨

#include<stdio.h>
#include<windows.h>
#include"itmojun.h"
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"itmojun.lib")//���Ӿ�̬��

int iShowText=0;//���ڿ�����ʾ��ĻΪ��������Ļ�������ʾ��Ļ

int iMessageBox=0;//���ڿ�����Ϣ�����ʾ0����ʾ
DWORD WINAPI ShowTextThr(LPVOID IpPara);//����������

DWORD WINAPI MessageBoxThr(LPVOID IpPara);
int main()
	{
	   HANDLE hTextThr=NULL;
	   HANDLE hMessageThr=NULL;

	   char msg[20];//���΢�Ŷ˷��͸����Ե�����
	    system("color f4");
		//AutoRun();��������

		//�����߳�ִ����ʾ��Ļ
	   hTextThr=CreateThread( NULL,0,ShowTextThr,NULL,0,NULL);
	   //�رվ��
	   CloseHandle(hTextThr);
	   //�����߳̿�����Ϣ�����ʾ
	   hMessageThr=CreateThread( NULL,0,MessageBoxThr,NULL,0,NULL);
	   CloseHandle(hMessageThr);


	   while(1)
	   {
		 GetPCCmd("xyyy",msg);//����΢�Ŷ˷��͸�idΪxxy������
		 printf("%s",msg);
		 if(strstr(msg,"����"))
		 {
			 mciSendString("play bg.mp3",NULL,0,NULL);
		 }
		 else if(strstr(msg,"ֹͣ"))
		 {
			 mciSendString("stop bg.mp3",NULL,0,NULL);
		 }
		 else if(strstr(msg,"��ͣ"))
		 {
			 mciSendString("pause bg.mp3",NULL,0,NULL);
		 }
		 else if(strstr(msg,"�ػ�"))//�õ��Թػ�
		 {
		     WinExec("shutdown -s -t 0",0);
		 }
		 else if(strstr(msg,"����"))
		 {
		     WinExec("shutdown -r -t 0",0);
		 }
		 else if(strstr(msg,"�ص�xx���"))
		 {
		     WinExec("cmd /C taskkill /f /im Dreamweaver.exe",0);
		 }
		 else if(strstr(msg,"��������"))
		 {
		     WinExec("cmd /C taskkill /f /im explorer.exe",0);//win10ʱ������ ��
			 
			/* HWND desktop,taskker;
			 desktop=FindWindow("ProgMan",NULL);
			 taskker=FindWindow("Shell_TrayWnd",NULL);

	  	     ShowWindow(desktop,SW_HIDE);
             ShowWindow(taskker,SW_HIDE);*/
			 
		 }
		 else if(strstr(msg,"��ԭ����"))
		 {
		     WinExec("C:\\Windows\\explorer.exe",1);
			 
			/* HWND desktop,taskker;
			 desktop=FindWindow("ProgMan",NULL);
			 taskker=FindWindow("Shell_TrayWnd",NULL);

	  	     ShowWindow(desktop,SW_SHOW);
             ShowWindow(taskker,SW_SHOW);*/
			 
		 }
		  else if(strstr(msg,"����ҳ"))
		 {
		     WinExec("explorer https://www.baidu.com",1);
		 }
		  else if(strstr(msg,"��ʾ��Ļ"))
		  {
		   //ֱ������������ʾһ�仰
	      	iShowText=1;
		  }
		  else if(strstr(msg,"�ر���Ļ"))
		  {
		  
			iShowText=0;
		  }
		   else if(strstr(msg,"������Ϣ��"))
		  {
		   //ֱ������������ʾһ�仰
	      	iMessageBox=1;
		  }
		  else if(strstr(msg,"������Ϣ��"))
		  {
		  
			iMessageBox=0;
		  }
		 Sleep(3000);//��ʱ3��

	   }
	 

		return 0;
	}

  DWORD WINAPI ShowTextThr(LPVOID IpPara)

	 {
	  HFONT hFont=CreateFont(100,50,0,0,FW_THIN,0,0,0,ANSI_CHARSET,
		  OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
		  DEFAULT_PITCH | FF_SWISS,"����");

	  HFONT hOldFont;
	  HDC hdc;
	  const char* ShowText="dzq";

		 while(1)
		 {
		    if(iShowText!=0)
			{
			hdc=GetDC(NULL);

			SetBkMode(hdc,TRANSPARENT);
			SetTextColor(hdc,RGB(0,255,0));//��ʾ��Ļ
            
			hOldFont=(HFONT)SelectObject(hdc,hFont);
			TextOut(hdc,50,50,ShowText,strlen(ShowText));
			SelectObject(hdc,hOldFont);
			ReleaseDC(NULL,hdc);

			}
			Sleep(1000);
		 }
	 }

  DWORD WINAPI MessageBoxThr(LPVOID IpPara)
  {
  
	  while(1)
	  {
			if(iMessageBox==1)
			{
				MessageBox(NULL,"���Ա�����","��ܰ��ʾ",MB_OKCANCEL | MB_ICONWARNING);
			}else
			{
				Sleep(1000);
			}
	  }  
  
  }




