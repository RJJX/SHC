#pragma once



// xiugai_mima 对话框

class xiugai_mima : public CDialogEx
{
	DECLARE_DYNAMIC(xiugai_mima)

public:
	xiugai_mima(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~xiugai_mima();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	CDatabase m_db;
	CRecordset rs;

	_variant_t result;
};
