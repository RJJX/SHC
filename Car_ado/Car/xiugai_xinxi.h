#pragma once


// xiugai_xinxi 对话框

class xiugai_xinxi : public CDialogEx
{
	DECLARE_DYNAMIC(xiugai_xinxi)

public:
	xiugai_xinxi(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~xiugai_xinxi();

// 对话框数据
	enum { IDD = xinxi };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtnsee();

	CDatabase m_db;
	CRecordset rs;
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();

	_variant_t result;
};
