// _tourist.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car.h"
#include "_tourist.h"
#include "afxdialogex.h"


// _tourist �Ի���

IMPLEMENT_DYNAMIC(_tourist, CDialogEx)

_tourist::_tourist(CWnd* pParent /*=NULL*/)
	: CDialogEx(_tourist::IDD, pParent)
{

}

_tourist::~_tourist()
{
}

void _tourist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, _list);
}


BEGIN_MESSAGE_MAP(_tourist, CDialogEx)
END_MESSAGE_MAP()


// _tourist ��Ϣ�������


BOOL _tourist::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	_list.SetExtendedStyle(_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	_list.InsertColumn(0, _T("�������"), LVCFMT_LEFT, 100);
	_list.InsertColumn(1, _T("����Ʒ��"), LVCFMT_LEFT, 100);
	_list.InsertColumn(2, _T("�����ͺ�"), LVCFMT_LEFT, 120);
	_list.InsertColumn(3, _T("������ɫ"), LVCFMT_LEFT, 100);
	_list.InsertColumn(4, _T("��������"), LVCFMT_LEFT, 100);
	_list.InsertColumn(5, _T("�������"), LVCFMT_LEFT, 150);
	_list.InsertColumn(6, _T("��������"), LVCFMT_LEFT, 200);
	_list.InsertColumn(7, _T("���ۼ۸�"), LVCFMT_LEFT, 150);

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
		CString sql="select * from Car";
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


		   _list.InsertItem(count,pid);
		   _list.SetItemText(count,1,pbrand);
		   _list.SetItemText(count,2,ptype);
		   _list.SetItemText(count,3,pcolor);
		   _list.SetItemText(count,4,pcc);
		   _list.SetItemText(count,5,pyear);
	       _list.SetItemText(count,6,preason);
		   _list.SetItemText(count,7,pmoney);
		  
		   setconn->MoveNext();
		   count++;
		}
	}
	  catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	conn->Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
