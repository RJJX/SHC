
// CarDlg.h : ͷ�ļ�
//

#pragma once


// CCarDlg �Ի���
class CCarDlg : public CDialogEx
{
// ����
public:
	CCarDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CAR_DIALOG };
	

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtnsign();
	afx_msg void OnBnClickedbtnregister();

	afx_msg void OnBnClickedbtntourist();
};
