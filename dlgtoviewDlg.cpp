
// dlgtoviewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "dlgtoview.h"
#include "dlgtoviewDlg.h"
#include "afxdialogex.h"
//#include"DlgDocument.h"
#include"zydview.h"
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


// CdlgtoviewDlg �Ի���




CdlgtoviewDlg::CdlgtoviewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdlgtoviewDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdlgtoviewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CdlgtoviewDlg, CDialogEx)
	//	ON_WM_SYSCOMMAND()
	//	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CdlgtoviewDlg ��Ϣ�������

BOOL CdlgtoviewDlg::OnInitDialog()
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
	/*CCreateContext pContext;
	CWnd* pFrameWnd = this;
	pContext.m_pCurrentDoc = new CDlgDocument;
	pContext.m_pNewViewClass = RUNTIME_CLASS(zydview);
	zydview *pView =(zydview *) ((CFrameWnd*)pFrameWnd)->CreateView(&pContext);
	ASSERT(pView);
	pView->m_nMapMode = MM_TEXT;

	pView->ShowWindow(SW_NORMAL);

	CRect rectWindow;
	GetWindowRect(rectWindow);
	rectWindow.right -= 5;
	rectWindow.bottom -= 70;
	pView->MoveWindow(rectWindow);*/
	CRect rect;
	GetClientRect(&rect);
	//��Ŀ��λ�ö�̬����CScrollView
	//CRuntimeClass *pViewRuntimeClass=RUNTIME_CLASS(zydview);

	//zydview *pview=(zydview*)pViewRuntimeClass->CreateObject();
	pview=new zydview;
	if (NULL==pview)
	{
		return FALSE;
	}


	pview->Create(NULL,NULL,WS_VISIBLE|WS_CHILD,
		rect,
		this,123,NULL);
	pview->ShowWindow(SW_SHOW);
	//pview->SetScrollSizes(MM_TEXT , CSize(10,10));
	pview->OnInitialUpdate();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//void CdlgtoviewDlg::OnSysCommand(UINT nID, LPARAM lParam)
//{
//	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
//	{
//		CAboutDlg dlgAbout;
//		dlgAbout.DoModal();
//	}
//	else
//	{
//		CDialogEx::OnSysCommand(nID, lParam);
//	}
//}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

//void CdlgtoviewDlg::OnPaint()
//{
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
//}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CdlgtoviewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

