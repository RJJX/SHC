#pragma once


// xiugai_xinxi �Ի���

class xiugai_xinxi : public CDialogEx
{
	DECLARE_DYNAMIC(xiugai_xinxi)

public:
	xiugai_xinxi(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~xiugai_xinxi();

// �Ի�������
	enum { IDD = xinxi };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtnsee();

	CDatabase m_db;
	CRecordset rs;
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();

	_variant_t result;
};
