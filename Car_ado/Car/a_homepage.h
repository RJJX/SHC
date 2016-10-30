#pragma once
#include "afxcmn.h"


// a_homepage 对话框

class a_homepage : public CDialogEx
{
	DECLARE_DYNAMIC(a_homepage)

public:
	a_homepage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~a_homepage();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl a_list;
	virtual BOOL OnInitDialog();

	CDatabase m_db;
	CRecordset rs;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
};
