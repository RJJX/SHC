// u_homepage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car.h"
#include "u_homepage.h"
#include "afxdialogex.h"
#include "b_car.h"
#include "sell_car.h"
#include "xiugai_xinxi.h"
#include "xiugai_mima.h"
#include<cstring>
b_car *b;
sell_car *s;
xiugai_xinxi *x;
xiugai_mima *m;

// u_homepage �Ի���

IMPLEMENT_DYNAMIC(u_homepage, CDialogEx)

u_homepage::u_homepage(CWnd* pParent /*=NULL*/)
	: CDialogEx(u_homepage::IDD, pParent)
{
}

u_homepage::~u_homepage()
{
}

void u_homepage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(u_homepage, CDialogEx)
	ON_COMMAND(ID_32779, &u_homepage::On32779)
	ON_COMMAND(ID_32778, &u_homepage::On32778)
	ON_COMMAND(ID_32776, &u_homepage::On32776)
	ON_COMMAND(ID_32777, &u_homepage::On32777)
END_MESSAGE_MAP()


// u_homepage ��Ϣ�������



///////////��Ҫ�򳵲˵���ť/////////
void u_homepage::jx()
{
	if(b)
	{
		b->DestroyWindow();
		b=NULL;
	}
	if(s)
	{
		s->DestroyWindow();
		s=NULL;
	}
	if(x)
	{
		x->DestroyWindow();
		x=NULL;
	}
	if(m)
	{
		m->DestroyWindow();
		m=NULL;
	}

}



void u_homepage::On32779()
{
	// TODO: �ڴ���������������
	jx();
	b=new b_car;
	b->Create(buycar,this);
    b->ShowWindow(SW_SHOW);
}

///////////��Ҫ�����˵���ť/////////
void u_homepage::On32778()
{
	// TODO: �ڴ���������������
	jx();
    s=new sell_car;
	s->Create(sellcar,this);
    s->ShowWindow(SW_SHOW);
}

/////////////�޸ĸ�����Ϣ/////////////
void u_homepage::On32776()
{
	// TODO: �ڴ���������������
	jx();
	x=new xiugai_xinxi;
	x->Create(xinxi,this);
	x->ShowWindow(SW_SHOW);
}


void u_homepage::On32777()
{
	// TODO: �ڴ���������������
	jx();
	m=new xiugai_mima;
	m->Create(IDD_DIALOG3,this);
	m->ShowWindow(SW_SHOW);
}
