// xiugai_xinxi.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car.h"
#include "xiugai_xinxi.h"
#include "afxdialogex.h"
extern CString tid;


// xiugai_xinxi �Ի���

IMPLEMENT_DYNAMIC(xiugai_xinxi, CDialogEx)

xiugai_xinxi::xiugai_xinxi(CWnd* pParent /*=NULL*/)
	: CDialogEx(xiugai_xinxi::IDD, pParent)
{

}

xiugai_xinxi::~xiugai_xinxi()
{
}

void xiugai_xinxi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(xiugai_xinxi, CDialogEx)
	ON_BN_CLICKED(IDOK, &xiugai_xinxi::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// xiugai_xinxi ��Ϣ�������


void xiugai_xinxi::OnBnClickedbtnsee()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void xiugai_xinxi::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString pname,pphone;
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
		CString sql = (_T("update [User] set u_name='"+ pname +"',u_phone='"+ pphone +"' where u_id='"+ tid +"'"));
	    setconn=conn->Execute(_bstr_t(sql),&result,adCmdText);
		if(int(result)!=0)
		{
			 MessageBox(_T("�޸ĳɹ�!"));
		}
	}
	 catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	
}


void xiugai_xinxi::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CString _id;
	CString _name ;
	CString _phone ;


	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");


	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql="select * from [User] where u_id='"+ tid +"'";
		setconn=conn->Execute(_bstr_t(sql),NULL,adCmdText);

		_name=setconn->GetCollect("u_name");
		_phone=setconn->GetCollect("u_phone");
	}
	  catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }

	SetDlgItemText(txt_id,tid);
	SetDlgItemText(txt_name,_name);
	SetDlgItemText(txt_phone,_phone);

	conn->Close();
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
