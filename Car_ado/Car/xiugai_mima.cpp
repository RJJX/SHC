// xiugai_mima.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car.h"
#include "xiugai_mima.h"
#include "afxdialogex.h"
extern CString tid;


// xiugai_mima �Ի���

IMPLEMENT_DYNAMIC(xiugai_mima, CDialogEx)

xiugai_mima::xiugai_mima(CWnd* pParent /*=NULL*/)
	: CDialogEx(xiugai_mima::IDD, pParent)
{

}

xiugai_mima::~xiugai_mima()
{
}

void xiugai_mima::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(xiugai_mima, CDialogEx)
	ON_BN_CLICKED(IDOK, &xiugai_mima::OnBnClickedOk)
END_MESSAGE_MAP()


// xiugai_mima ��Ϣ�������


void xiugai_mima::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString _ps;
	GetDlgItem(txt_ps)->GetWindowTextW(_ps);

	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");
	
	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql="update [User] set u_password='"+ _ps +"' where u_id='"+ tid +"'";
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
	conn->Close();
}
