#pragma once
#include "afxcmn.h"


// _tourist 对话框

class _tourist : public CDialogEx
{
	DECLARE_DYNAMIC(_tourist)

public:
	_tourist(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~_tourist();

// 对话框数据
	enum { IDD = tourist };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CDatabase m_db;
	CRecordset rs;
	CListCtrl _list;
};
