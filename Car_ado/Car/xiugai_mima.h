#pragma once



// xiugai_mima �Ի���

class xiugai_mima : public CDialogEx
{
	DECLARE_DYNAMIC(xiugai_mima)

public:
	xiugai_mima(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~xiugai_mima();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	CDatabase m_db;
	CRecordset rs;

	_variant_t result;
};
