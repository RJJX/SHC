#pragma once
#include "afxcmn.h"


// b_car 对话框

class b_car : public CDialogEx
{
	DECLARE_DYNAMIC(b_car)

public:
	b_car(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~b_car();



// 对话框数据
	enum { IDD = buycar };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持


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
