// sell_car.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car.h"
#include "sell_car.h"
#include "afxdialogex.h"
#include "Signin.h"
#include<cstring>
extern CString tid;
extern CString tpassword;

// sell_car �Ի���

IMPLEMENT_DYNAMIC(sell_car, CDialogEx)

sell_car::sell_car(CWnd* pParent /*=NULL*/)
	: CDialogEx(sell_car::IDD, pParent)
{

}

sell_car::~sell_car()
{
}

void sell_car::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(sell_car, CDialogEx)
	ON_BN_CLICKED(IDOK, &sell_car::OnBnClickedOk)
END_MESSAGE_MAP()


// sell_car ��Ϣ�������


void sell_car::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/////////////////��������Դ///////////////
	CString cid,cbrand,ctype,ccolor,ccc,cyear,creason,cmoney;

	GetDlgItem(txt_brand)->GetWindowTextW(cbrand);
	GetDlgItem(txt_type)->GetWindowTextW(ctype);
	GetDlgItem(txt_color)->GetWindowTextW(ccolor);
	GetDlgItem(txt_cc)->GetWindowTextW(ccc);
	GetDlgItem(txt_year)->GetWindowTextW(cyear);
	GetDlgItem(txt_reason)->GetWindowTextW(creason);
	GetDlgItem(txt_money)->GetWindowTextW(cmoney);



	CoInitialize(NULL);
	_ConnectionPtr conn;
	conn.CreateInstance(__uuidof(Connection));
	_RecordsetPtr setconn;
	setconn.CreateInstance(__uuidof(_RecordsetPtr));
	CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");


	try
	{
		conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
		CString sql = "insert Car values('"+tid+"','"+cbrand+"','"+ctype+"','"+ccolor+"','"+ccc+"','"+cyear+"','"+creason+"','"+cmoney+"')";

		setconn=conn->Execute(_bstr_t(sql),&result,adCmdText);

		if(int(result)==0)
		{
			MessageBox(_T("�ϴ�ʧ��!"));
		}
		else
		{
			MessageBox(_T("�ϴ��ɹ�!"));
		}
	}
	catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
        exit(0);
    }
	conn->Close();

}
