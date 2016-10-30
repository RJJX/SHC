// Signin.cpp : 实现文件
//

#include "stdafx.h"
#include "Car.h"
#include "CarDlg.h"
#include "Signin.h"
#include "afxdialogex.h"
#include "u_homepage.h"
#include "a_homepage.h"
CString tid;
CString tpassword;
// Signin 对话框

IMPLEMENT_DYNAMIC(Signin, CDialogEx)

Signin::Signin(CWnd* pParent /*=NULL*/)
	: CDialogEx(Signin::IDD, pParent)
{
	/*	tid=_T("");
	    tpassword=_T("");*/
}

Signin::~Signin()
{
}

void Signin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Signin, CDialogEx)
	ON_BN_CLICKED(IDOK, &Signin::OnBnClickedOk)
//	ON_BN_CLICKED(IDCANCEL, &Signin::OnBnClickedCancel)
ON_BN_CLICKED(IDCANCEL, &Signin::OnBnClickedCancel)
END_MESSAGE_MAP()


// Signin 消息处理程序


void Signin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString tid,tpassword;
	int u=0,a=0;
	GetDlgItem(txt_id)->GetWindowTextW(tid);
	GetDlgItem(txt_ps)->GetWindowTextW(tpassword);


	/////////////链接数据源////////////
	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn_u;
	setconn_u.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");
	
	try{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql_u="select * from [User],Admin where u_id='"+ tid +"' or a_id='"+ tid +"'";
		setconn_u=conn->Execute(_bstr_t(sql_u),NULL,adCmdText);
		CString uid,ups,aid,aps;
		setconn_u->MoveFirst();
		while(!setconn_u->adoEOF)
		{
			uid=setconn_u->GetCollect("u_id");
			ups=setconn_u->GetCollect("u_password");
			if(uid.Trim()==tid.Trim() && ups.Trim()==tpassword.Trim())
				u++;
			aid=setconn_u->GetCollect("a_id");
			aps=setconn_u->GetCollect("a_password");
			if(aid.Trim()==tid.Trim() && aps.Trim()==tpassword.Trim())
				a++;
			setconn_u->MoveNext();
		}

			if(u>0)
			{
				SendMessage(WM_CLOSE);
				u_homepage dlg;
				dlg.DoModal();
			}
			  if(a>0)
			 {
				 SendMessage(WM_CLOSE);
				 a_homepage dlg;
				 dlg.DoModal();
			 }
			else if(u==0 && a==0)
				MessageBox(_T("账号或密码不正确!"));
    }
    catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	conn->Close();

}


void Signin::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
