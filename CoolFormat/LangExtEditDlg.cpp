// LangExtEditDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CoolFormat3.h"
#include "LangExtEditDlg.h"


// CLangExtEditDlg �Ի���

IMPLEMENT_DYNAMIC(CLangExtEditDlg, CBCGPDialog)

CLangExtEditDlg::CLangExtEditDlg(const CString &strLang, const CString &strExt, CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CLangExtEditDlg::IDD, pParent)
	, m_strLang(strLang)
	, m_strExt(strExt)
{

}

CLangExtEditDlg::~CLangExtEditDlg()
{
}

void CLangExtEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LANG, m_strLang);
	DDX_Text(pDX, IDC_EDIT_EXT, m_strExt);
}


BEGIN_MESSAGE_MAP(CLangExtEditDlg, CBCGPDialog)
END_MESSAGE_MAP()


// CLangExtEditDlg ��Ϣ�������

void CLangExtEditDlg::OnOK()
{
	UpdateData();

	CBCGPDialog::OnOK();
}

BOOL CLangExtEditDlg::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();

    SendMessageToDescendants(WM_SETFONT, (WPARAM)globalData.fontRegular.m_hObject, MAKELPARAM(FALSE, 0), FALSE);
    InitLang();

	if (!IsVisualManagerStyle())
	{
		EnableVisualManagerStyle(TRUE, TRUE);
	}

	GetDlgItem(IDCANCEL)->SetFocus();
	return FALSE;
}

void CLangExtEditDlg::InitLang()
{
	CString strTemp;
	BOOL bNameVaild = strTemp.LoadString(IDOK);
	ASSERT(bNameVaild);
	SetDlgItemText(IDOK, strTemp);

	bNameVaild = strTemp.LoadString(IDCANCEL);
	ASSERT(bNameVaild);
	SetDlgItemText(IDCANCEL, strTemp);

	bNameVaild = strTemp.LoadString(IDS_LANGUAGE_EX);
	ASSERT(bNameVaild);
	SetDlgItemText(IDC_STATIC_LANG, strTemp);
	SetDlgItemSizeToContent(GetDlgItem(IDC_STATIC_LANG));

	bNameVaild = strTemp.LoadString(IDS_LANGUAGEEXT_EX);
	ASSERT(bNameVaild);
	SetDlgItemText(IDC_STATIC_EXT, strTemp);
	SetDlgItemSizeToContent(GetDlgItem(IDC_STATIC_EXT));

	bNameVaild = strTemp.LoadString(IDS_LANGEXT_EDIT_DLG);
	ASSERT(bNameVaild);
	SetWindowText(strTemp);
}