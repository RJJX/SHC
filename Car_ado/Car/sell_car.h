#pragma once


// sell_car 对话框

class sell_car : public CDialogEx
{
	DECLARE_DYNAMIC(sell_car)

public:
	sell_car(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~sell_car();

// 对话框数据
	enum { IDD = sellcar };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();

	CDatabase m_db;
	CRecordset rs;

	_variant_t result;
};
