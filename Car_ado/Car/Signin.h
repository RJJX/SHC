#pragma once


// Signin 对话框

class Signin : public CDialogEx
{
	DECLARE_DYNAMIC(Signin)

public:
	Signin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Signin();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };
	CDatabase m_db;
	CRecordset rs;
	CRecordset ra;

	CString uid;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	public:
	

};

