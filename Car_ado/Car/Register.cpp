// Register.cpp : 实现文件
//

#include "stdafx.h"
#include "Car.h"
#include "Register.h"
#include "afxdialogex.h"


// Register 对话框

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=NULL*/)
	: CDialogEx(Register::IDD, pParent)
{

}

Register::~Register()
{
}

void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Register, CDialogEx)
	ON_BN_CLICKED(IDOK, &Register::OnBnClickedOk)
END_MESSAGE_MAP()


// Register 消息处理程序


void Register::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString pid,ppassword,pname,pphone;
	GetDlgItem(txt_id)->GetWindowTextW(pid);
	GetDlgItem(txt_ps)->GetWindowTextW(ppassword);
	GetDlgItem(txt_name)->GetWindowTextW(pname);
	GetDlgItem(txt_phone)->GetWindowTextW(pphone);


	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");

	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql="select * from [User]";
		CString sql1="insert into [User] values ('"+ pid +"','"+ ppassword +"','"+ pname +"','"+ pphone +"')";
		setconn=conn->Execute(_bstr_t(sql),NULL,adCmdText);
		CString _id;
		int i=0;
		setconn->MoveFirst();
		while(!setconn->adoEOF)
		{
			_id=setconn->GetCollect("u_id");
			if(_id.Trim()==pid.Trim())
				i++;
			setconn->MoveNext();
		}
		if(i>0)
		{
			MessageBox(_T("该账号已被占用!"));
			conn->Close();
		}
		else
		{
			///////注册////////
			setconn=conn->Execute(_bstr_t(sql1),NULL,adCmdText);
			MessageBox(_T("注册成功!"));
			conn->Close();
		    CDialogEx::OnOK();
		}
	}
	 catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
        exit(0);
    }
}