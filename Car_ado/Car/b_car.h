#pragma once
#include "afxcmn.h"


// b_car �Ի���

class b_car : public CDialogEx
{
	DECLARE_DYNAMIC(b_car)

public:
	b_car(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~b_car();



// �Ի�������
	enum { IDD = buycar };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��


	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	CDatabase m_db;
	CRecordset rs;
	afx_msg void OnBnClickedbtnback();
	afx_msg void OnBnClickedbtnbuy();

	_variant_t result;
};
