#pragma once


// sell_car �Ի���

class sell_car : public CDialogEx
{
	DECLARE_DYNAMIC(sell_car)

public:
	sell_car(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~sell_car();

// �Ի�������
	enum { IDD = sellcar };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();

	CDatabase m_db;
	CRecordset rs;

	_variant_t result;
};
