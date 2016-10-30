// update.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car.h"
#include "update.h"
#include "afxdialogex.h"
extern CString aid;


// update �Ի���

IMPLEMENT_DYNAMIC(update, CDialogEx)

update::update(CWnd* pParent /*=NULL*/)
	: CDialogEx(update::IDD, pParent)
{

}

update::~update()
{
}

void update::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(update, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &update::OnBnClickedOk)
END_MESSAGE_MAP()


// update ��Ϣ�������


void update::OnPaint()
{
	CPaintDC dc(this); // device context for painting


	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");

	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql="select * from Car where c_id='"+ aid +"'";
		CString _brand,_type,_color,_cc,_year,_reason,_money;
		setconn=conn->Execute(_bstr_t(sql),NULL,adCmdText);

		_brand=setconn->GetCollect("c_brand");
		_type=setconn->GetCollect("c_type");
		_color=setconn->GetCollect("c_color");
		_cc=setconn->GetCollect("c_cc");
		_year=setconn->GetCollect("c_year");
		_reason=setconn->GetCollect("c_reason");
		_money=setconn->GetCollect("c_money");
		
		SetDlgItemText(txt_brand,_brand);
		SetDlgItemText(txt_type,_type);
		SetDlgItemText(txt_color,_color);
		SetDlgItemText(txt_cc,_cc);
		SetDlgItemText(txt_year,_year);
		SetDlgItemText(txt_reason,_reason);
		SetDlgItemText(txt_money,_money);
	}
	  catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	  conn->Close();
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}


void update::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CString _brand,_type,_color,_cc,_year,_reason,_money;

//	MessageBox(aid);

	GetDlgItem(txt_brand)->GetWindowTextW(_brand);
	GetDlgItem(txt_type)->GetWindowTextW(_type);
	GetDlgItem(txt_color)->GetWindowTextW(_color);
	GetDlgItem(txt_cc)->GetWindowTextW(_cc);
	GetDlgItem(txt_year)->GetWindowTextW(_year);
	GetDlgItem(txt_reason)->GetWindowTextW(_reason);
	GetDlgItem(txt_money)->GetWindowTextW(_money);

	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");
	int count=0;
	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql = (_T("update Car set c_brand='"+ _brand +"',c_type='"+ _type +"',c_color='"+ _color +"',c_cc='"+ _cc +"',c_year='"+ _year +"',c_reason='"+ _reason +"',c_money='"+ _money +"' where c_id='"+ aid +"'"));
		setconn=conn->Execute(_bstr_t(sql),&result,adCmdText);
		if(int(result)!=0)
			MessageBox(_T("�޸ĳɹ�!"));
	}
	  catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	conn->Close();
}
