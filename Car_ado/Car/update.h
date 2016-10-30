#pragma once


// update 对话框

class update : public CDialogEx
{
	DECLARE_DYNAMIC(update)

public:
	update(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~update();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CDatabase m_db;
	CRecordset rs;
	afx_msg void OnBnClickedOk();

	_variant_t result;
};
