
// CarDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car.h"
#include "CarDlg.h"
#include "afxdialogex.h"
#include "Signin.h"
#include "Register.h"
#include "_tourist.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCarDlg �Ի���




CCarDlg::CCarDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCarDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCarDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btnSign, &CCarDlg::OnBnClickedbtnsign)
	ON_BN_CLICKED(btnRegister, &CCarDlg::OnBnClickedbtnregister)
	ON_BN_CLICKED(btntourist, &CCarDlg::OnBnClickedbtntourist)
END_MESSAGE_MAP()


// CCarDlg ��Ϣ�������

BOOL CCarDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCarDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCarDlg::OnPaint()
{
//	if (IsIconic())
//	{
//		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
//
//		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
//
//		// ʹͼ���ڹ����������о���
//		int cxIcon = GetSystemMetrics(SM_CXICON);
//		int cyIcon = GetSystemMetrics(SM_CYICON);
//		CRect rect;
//		GetClientRect(&rect);
//		int x = (rect.Width() - cxIcon + 1) / 2;
//		int y = (rect.Height() - cyIcon + 1) / 2;
//
//		// ����ͼ��
//		dc.DrawIcon(x, y, m_hIcon);
//	}
//	else
//	{
//		CDialogEx::OnPaint();
//	}

	//�ڶԻ�����ӱ���
	CPaintDC dc(this); //DC
	CRect rect;         //���λ��
	GetClientRect(&rect);//��ȡ�ͻ�����С
	CFont font;// ����
	font.CreatePointFont(200,_T("�����п�")); //�����С������
	CFont *pOldFont; //ԭDC�е�����
	pOldFont=dc.SelectObject(&font);

	CString strTemp;
	strTemp="�� �� �� �� �� ϵ ͳ";
	dc.SetBkMode(TRANSPARENT);  //����Ϊ͸��
	dc.TextOutW((rect.Width()*1)/4,rect.Height()*1/5,strTemp);  //����λ��

	dc.SelectObject(pOldFont);   //�ָ�֮ǰ������
	font.DeleteObject();     //�ͷ�����
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù�� 
//��ʾ��
HCURSOR CCarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCarDlg::OnBnClickedbtnsign()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Signin dlg;
	dlg.DoModal();
}


void CCarDlg::OnBnClickedbtnregister()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Register dlg;
	dlg.DoModal();
}


void CCarDlg::OnBnClickedbtntourist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_tourist dlg;
	dlg.DoModal();
}
