// b_car.cpp : 实现文件
//

#include "stdafx.h"
#include "Car.h"
#include "CarDlg.h"
#include "b_car.h"
#include "afxdialogex.h"
#include "Signin.h"
extern CString tid;


// b_car 对话框

IMPLEMENT_DYNAMIC(b_car, CDialogEx)

b_car::b_car(CWnd* pParent /*=NULL*/)
	: CDialogEx(b_car::IDD, pParent)
{

}

b_car::~b_car()
{
}

void b_car::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, mylist, m_list);
}


BEGIN_MESSAGE_MAP(b_car, CDialogEx)
	ON_BN_CLICKED(btnback, &b_car::OnBnClickedbtnback)
	ON_BN_CLICKED(btnbuy, &b_car::OnBnClickedbtnbuy)
END_MESSAGE_MAP()


// b_car 消息处理程序




BOOL b_car::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("车辆编号"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("车辆品牌"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, _T("车辆型号"), LVCFMT_LEFT, 120);
	m_list.InsertColumn(3, _T("车辆颜色"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, _T("车辆排量"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(5, _T("车辆年份"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(6, _T("出售理由"), LVCFMT_LEFT, 200);
	m_list.InsertColumn(7, _T("出售价格"), LVCFMT_LEFT, 150);

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


		   m_list.InsertItem(count,pid);
		   m_list.SetItemText(count,1,pbrand);
		   m_list.SetItemText(count,2,ptype);
		   m_list.SetItemText(count,3,pcolor);
		   m_list.SetItemText(count,4,pcc);
		   m_list.SetItemText(count,5,pyear);
	       m_list.SetItemText(count,6,preason);
		   m_list.SetItemText(count,7,pmoney);
		  
		   setconn->MoveNext();
		   count++;
		}
	}
	  catch (_com_error &e)
    {
        AfxMessageBox(e.Description());
    }
	// TODO:  在此添加额外的初始化
	conn->Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void b_car::OnBnClickedbtnback()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void b_car::OnBnClickedbtnbuy()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	CString cid,cbrand,ctype,ccolor,ccc,cyear,creason,cmoney;
	for(int i=0; i<m_list.GetItemCount(); i++ )
      {
           if( m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
           {
                //添加是否购买代码
//			   CString pid,pbrand,ptype,pcolor,pcc,pyear,preason,pmoney;
			   cid=m_list.GetItemText(i,0);
			   ctype=m_list.GetItemText(i,2);
			   cbrand=m_list.GetItemText(i,1);
			   cyear=m_list.GetItemText(i,5);
			   cmoney=m_list.GetItemText(i,7);
			   

			   	CoInitialize(NULL);
	            _ConnectionPtr conn;
	            conn.CreateInstance(__uuidof(Connection));
	            _RecordsetPtr setconn;
	            setconn.CreateInstance(__uuidof(_RecordsetPtr));
	            CString strsql=("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Second hand car;Data Source=.");

				try
				{
					conn->Open(_bstr_t(strsql),"","",adConnectUnspecified);
					CString sql="delete from Car where c_id ='"+ cid +"'";
//					CString sql1="insert into Sale values('"+ cid +"','"+ tid +"','"+cid+"','"+ctype+"','"+cbrand+"','"+cyear+"','"+cmoney+"')";
					setconn=conn->Execute(_bstr_t(sql),&result,adCmdText);
					if(int(result)!=0)
					{
						CString sql1="insert into Sale values('"+ cid +"','"+ tid +"','"+cid+"','"+ctype+"','"+cbrand+"','"+cyear+"','"+cmoney+"')";
						setconn=conn->Execute(_bstr_t(sql1),&result,adCmdText);
						if(int(result)!=0)
							MessageBox(_T("购买成功!"));
					}
				}
				 catch (_com_error &e)
                 {
                      AfxMessageBox(e.Description());
                 }
        }
	}
}
