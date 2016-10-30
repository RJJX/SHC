// a_homepage.cpp : 实现文件
//

#include "stdafx.h"
#include "Car.h"
#include "a_homepage.h"
#include "afxdialogex.h"
#include "update.h"
CString aid;


// a_homepage 对话框

IMPLEMENT_DYNAMIC(a_homepage, CDialogEx)

a_homepage::a_homepage(CWnd* pParent /*=NULL*/)
	: CDialogEx(a_homepage::IDD, pParent)
{

}

a_homepage::~a_homepage()
{
}

void a_homepage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, a_list);
}


BEGIN_MESSAGE_MAP(a_homepage, CDialogEx)
	ON_BN_CLICKED(IDOK, &a_homepage::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &a_homepage::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &a_homepage::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &a_homepage::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &a_homepage::OnBnClickedButton4)
END_MESSAGE_MAP()


// a_homepage 消息处理程序


BOOL a_homepage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

/////////////判断选中行数并修改////////////
void a_homepage::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int i=0; i<a_list.GetItemCount(); i++ )
      {
           if( a_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
           {
				aid=a_list.GetItemText(i,0);
				update dlg;
				dlg.DoModal();
		   }
	  }
}

///////////////删除///////////////////
void a_homepage::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");
	
	for(int i=0; i<a_list.GetItemCount(); i++ )
      {
           if( a_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
           {
				aid=a_list.GetItemText(i,0);
		   }
	  }

	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql="delete from Car where c_id='"+ aid.Trim() +"'";
		setconn=conn->Execute(_bstr_t(sql),NULL,adCmdText);
		MessageBox(_T("删除成功!"));
	}
	 catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	conn->Close();
}

/////////////////////刷新///////////////////
void a_homepage::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	a_list.DeleteAllItems();
	int count=0;

	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");
	
	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql="SELECT * FROM Car";
		setconn=conn->Execute(_bstr_t(sql),NULL,adCmdText);
		setconn->MoveFirst();
		CString pid,pbrand,ptype,pcolor,pcc,pyear,preason,pmoney; 
		setconn=conn->Execute(_bstr_t(sql),NULL,adCmdText);
		setconn->MoveFirst();
		while(!setconn->adoEOF)
		{
			pid=setconn->GetCollect("c_id");
			pbrand=setconn->GetCollect("c_brand");
			ptype=setconn->GetCollect("c_type");
			pcolor=setconn->GetCollect("c_color");
			pcc=setconn->GetCollect("c_cc");
			pyear=setconn->GetCollect("c_year");
			preason=setconn->GetCollect("c_reason");
			pmoney=setconn->GetCollect("c_money");


		   a_list.InsertItem(count,pid);
		   a_list.SetItemText(count,1,pbrand);
		   a_list.SetItemText(count,2,ptype);
		   a_list.SetItemText(count,3,pcolor);
		   a_list.SetItemText(count,4,pcc);
		   a_list.SetItemText(count,5,pyear);
	       a_list.SetItemText(count,6,preason);
		   a_list.SetItemText(count,7,pmoney);
		  
		   setconn->MoveNext();
		   count++;
		}
	}
	catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	conn->Close();

}

///////////////未售车辆////////////////
void a_homepage::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	a_list.DeleteAllItems();
	for(int i=0;i<7;i++)
	{
		a_list.DeleteColumn(0);
	}
	int count=0;

	a_list.SetExtendedStyle(a_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	a_list.InsertColumn(0, _T("车辆编号"), LVCFMT_LEFT, 100);
	a_list.InsertColumn(1, _T("车辆品牌"), LVCFMT_LEFT, 100);
	a_list.InsertColumn(2, _T("车辆型号"), LVCFMT_LEFT, 120);
	a_list.InsertColumn(3, _T("车辆颜色"), LVCFMT_LEFT, 100);
	a_list.InsertColumn(4, _T("车辆排量"), LVCFMT_LEFT, 100);
	a_list.InsertColumn(5, _T("车辆年份"), LVCFMT_LEFT, 150);
	a_list.InsertColumn(6, _T("出售理由"), LVCFMT_LEFT, 200);
	a_list.InsertColumn(7, _T("出售价格"), LVCFMT_LEFT, 150);

	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");
	
	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql="SELECT * FROM Car";
		setconn=conn->Execute(_bstr_t(sql),NULL,adCmdText);
		setconn->MoveFirst();
		CString pid,pbrand,ptype,pcolor,pcc,pyear,preason,pmoney; 
		setconn=conn->Execute(_bstr_t(sql),NULL,adCmdText);
		setconn->MoveFirst();
		while(!setconn->adoEOF)
		{
			pid=setconn->GetCollect("c_id");
			pbrand=setconn->GetCollect("c_brand");
			ptype=setconn->GetCollect("c_type");
			pcolor=setconn->GetCollect("c_color");
			pcc=setconn->GetCollect("c_cc");
			pyear=setconn->GetCollect("c_year");
			preason=setconn->GetCollect("c_reason");
			pmoney=setconn->GetCollect("c_money");


		   a_list.InsertItem(count,pid);
		   a_list.SetItemText(count,1,pbrand);
		   a_list.SetItemText(count,2,ptype);
		   a_list.SetItemText(count,3,pcolor);
		   a_list.SetItemText(count,4,pcc);
		   a_list.SetItemText(count,5,pyear);
	       a_list.SetItemText(count,6,preason);
		   a_list.SetItemText(count,7,pmoney);
		  
		   setconn->MoveNext();
		   count++;
		}
	}
	catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	conn->Close();

}

/////////////已售车辆////////////
void a_homepage::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	a_list.DeleteAllItems();
	for(int i=0;i<8;i++)
	{
		a_list.DeleteColumn(0);
	}
	int count=0;

	a_list.SetExtendedStyle(a_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	a_list.InsertColumn(0, _T("卖家账号"), LVCFMT_LEFT, 100);
	a_list.InsertColumn(1, _T("买家账号"), LVCFMT_LEFT, 100);
	a_list.InsertColumn(2, _T("车辆编号"), LVCFMT_LEFT, 120);
	a_list.InsertColumn(3, _T("车辆品牌"), LVCFMT_LEFT, 100);
	a_list.InsertColumn(4, _T("车辆型号"), LVCFMT_LEFT, 100);
	a_list.InsertColumn(5, _T("车辆年份"), LVCFMT_LEFT, 150);
	a_list.InsertColumn(6, _T("出售价格"), LVCFMT_LEFT, 150);


	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");
	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql="SELECT * FROM Sale";
		CString sid,bid,cid,cbrand,ctype,cyear,money;  
		setconn=conn->Execute(_bstr_t(sql),NULL,adCmdText);
		setconn->MoveFirst();

		while(!(setconn->adoEOF))
	   {
		   sid=setconn->GetCollect("s_seller");
		   bid=setconn->GetCollect("s_buyer");
		   cid=setconn->GetCollect("c_id");
		   cbrand=setconn->GetCollect("c_brand");
		   ctype=setconn->GetCollect("c_type");
		   cyear=setconn->GetCollect("s_year");
		   money=setconn->GetCollect("s_money");


		   a_list.InsertItem(count,sid);
		   a_list.SetItemText(count,1,bid);
		   a_list.SetItemText(count,2,cid);
		   a_list.SetItemText(count,3,cbrand);
		   a_list.SetItemText(count,4,ctype);
		   a_list.SetItemText(count,5,cyear);
	       a_list.SetItemText(count,6,money);
		  
		   setconn->MoveNext();
		   count++;
	   }
	}
	catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	conn->Close();

}
