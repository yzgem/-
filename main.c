//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )不显示控制台

#include<stdio.h>
#include<windows.h>
#include"itmojun.h"
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"itmojun.lib")//连接静态库

int iShowText=0;//用于控制显示字幕为零隐藏字幕非零就显示字幕

int iMessageBox=0;//用于控制消息框的显示0不显示
DWORD WINAPI ShowTextThr(LPVOID IpPara);//函数的声明

DWORD WINAPI MessageBoxThr(LPVOID IpPara);
int main()
	{
	   HANDLE hTextThr=NULL;
	   HANDLE hMessageThr=NULL;

	   char msg[20];//存放微信端发送给电脑的数据
	    system("color f4");
		//AutoRun();程序自启

		//创建线程执行显示字幕
	   hTextThr=CreateThread( NULL,0,ShowTextThr,NULL,0,NULL);
	   //关闭句柄
	   CloseHandle(hTextThr);
	   //创建线程控制消息框的显示
	   hMessageThr=CreateThread( NULL,0,MessageBoxThr,NULL,0,NULL);
	   CloseHandle(hMessageThr);


	   while(1)
	   {
		 GetPCCmd("xyyy",msg);//接收微信端发送给id为xxy的数据
		 printf("%s",msg);
		 if(strstr(msg,"播放"))
		 {
			 mciSendString("play bg.mp3",NULL,0,NULL);
		 }
		 else if(strstr(msg,"停止"))
		 {
			 mciSendString("stop bg.mp3",NULL,0,NULL);
		 }
		 else if(strstr(msg,"暂停"))
		 {
			 mciSendString("pause bg.mp3",NULL,0,NULL);
		 }
		 else if(strstr(msg,"关机"))//让电脑关机
		 {
		     WinExec("shutdown -s -t 0",0);
		 }
		 else if(strstr(msg,"重启"))
		 {
		     WinExec("shutdown -r -t 0",0);
		 }
		 else if(strstr(msg,"关掉xx软件"))
		 {
		     WinExec("cmd /C taskkill /f /im Dreamweaver.exe",0);
		 }
		 else if(strstr(msg,"结束桌面"))
		 {
		     WinExec("cmd /C taskkill /f /im explorer.exe",0);//win10时不适用 ：
			 
			/* HWND desktop,taskker;
			 desktop=FindWindow("ProgMan",NULL);
			 taskker=FindWindow("Shell_TrayWnd",NULL);

	  	     ShowWindow(desktop,SW_HIDE);
             ShowWindow(taskker,SW_HIDE);*/
			 
		 }
		 else if(strstr(msg,"还原桌面"))
		 {
		     WinExec("C:\\Windows\\explorer.exe",1);
			 
			/* HWND desktop,taskker;
			 desktop=FindWindow("ProgMan",NULL);
			 taskker=FindWindow("Shell_TrayWnd",NULL);

	  	     ShowWindow(desktop,SW_SHOW);
             ShowWindow(taskker,SW_SHOW);*/
			 
		 }
		  else if(strstr(msg,"打开网页"))
		 {
		     WinExec("explorer https://www.baidu.com",1);
		 }
		  else if(strstr(msg,"显示字幕"))
		  {
		   //直接在桌面上显示一句话
	      	iShowText=1;
		  }
		  else if(strstr(msg,"关闭字幕"))
		  {
		  
			iShowText=0;
		  }
		   else if(strstr(msg,"弹出消息框"))
		  {
		   //直接在桌面上显示一句话
	      	iMessageBox=1;
		  }
		  else if(strstr(msg,"隐藏消息框"))
		  {
		  
			iMessageBox=0;
		  }
		 Sleep(3000);//延时3秒

	   }
	 

		return 0;
	}

  DWORD WINAPI ShowTextThr(LPVOID IpPara)

	 {
	  HFONT hFont=CreateFont(100,50,0,0,FW_THIN,0,0,0,ANSI_CHARSET,
		  OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
		  DEFAULT_PITCH | FF_SWISS,"宋体");

	  HFONT hOldFont;
	  HDC hdc;
	  const char* ShowText="dzq";

		 while(1)
		 {
		    if(iShowText!=0)
			{
			hdc=GetDC(NULL);

			SetBkMode(hdc,TRANSPARENT);
			SetTextColor(hdc,RGB(0,255,0));//显示字幕
            
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
				MessageBox(NULL,"电脑被控制","温馨提示",MB_OKCANCEL | MB_ICONWARNING);
			}else
			{
				Sleep(1000);
			}
	  }  
  
  }




