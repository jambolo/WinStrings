/****************************************************************************

                              WinStringsView.cpp

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/WinStrings/WinStringsView.cpp#2 $

	$NoKeywords: $

****************************************************************************/

#include "stdafx.h"

#include "WinStringsView.h"

#include "WinStringsDoc.h"

#include <locale>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinStringsView

IMPLEMENT_DYNCREATE( CWinStringsView, CFormView )

BEGIN_MESSAGE_MAP( CWinStringsView, CFormView )
	//{{AFX_MSG_MAP( CWinStringsView )
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_SCAN, OnScan)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND( ID_FILE_PRINT, CFormView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinStringsView construction/destruction

CWinStringsView::CWinStringsView()
	: CFormView( CWinStringsView::IDD )
{
	//{{AFX_DATA_INIT( CWinStringsView )
	m_MinStringSize = 10;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CWinStringsView::~CWinStringsView()
{
}

void CWinStringsView::DoDataExchange( CDataExchange* pDX )
{
	CFormView::DoDataExchange( pDX );
	//{{AFX_DATA_MAP( CWinStringsView )
	DDX_Control(pDX, IDC_DISPLAY, m_Display);
	DDX_Slider( pDX, IDC_STRINGSIZE, m_MinStringSize );
	//}}AFX_DATA_MAP
}

BOOL CWinStringsView::PreCreateWindow( CREATESTRUCT& cs )
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow( cs );
}

void CWinStringsView::OnInitialUpdate()
{
	CSliderCtrl * pslider = static_cast< CSliderCtrl * >( GetDlgItem( IDC_STRINGSIZE ) );
	pslider->SetRange( 1, 32 );
	pslider->SetPos( m_MinStringSize );

	CString text;
	text.Format( "%d", pslider->GetPos() );
	SetDlgItemText( IDC_STRINGSIZEDISPLAY, text );

	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_Display.ClearAll();
	ScanForStrings();
}

/////////////////////////////////////////////////////////////////////////////
// CWinStringsView printing

BOOL CWinStringsView::OnPreparePrinting( CPrintInfo* pInfo )
{
	// default preparation
	return DoPreparePrinting( pInfo );
}

void CWinStringsView::OnBeginPrinting( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ )
{
	// TODO: add extra initialization before printing
}

void CWinStringsView::OnEndPrinting( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ )
{
	// TODO: add cleanup after printing
}

void CWinStringsView::OnPrint( CDC* pDC, CPrintInfo* /*pInfo*/ )
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CWinStringsView diagnostics

#ifdef _DEBUG
void CWinStringsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CWinStringsView::Dump( CDumpContext& dc ) const
{
	CFormView::Dump( dc );
}

CWinStringsDoc* CWinStringsView::GetDocument() // non-debug version is inline
{
	ASSERT( m_pDocument->IsKindOf( RUNTIME_CLASS( CWinStringsDoc ) ) );
	return static_cast< CWinStringsDoc * >( m_pDocument );
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinStringsView message handlers



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CWinStringsView::OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar ) 
{
	CSliderCtrl * pslider = reinterpret_cast< CSliderCtrl * >( pScrollBar );
	CString text;
	text.Format( "%d", pslider->GetPos() );
	SetDlgItemText( IDC_STRINGSIZEDISPLAY, text );
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CWinStringsView::OnScan() 
{
	m_Display.ClearAll();
	UpdateData();
	ScanForStrings();
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CWinStringsView::ScanForStrings()
{
	CWaitCursor	wait_cursor;

	int string_count = 0;
	char const * data = LPCTSTR( GetDocument()->m_Data );
	int const length = GetDocument()->m_Data.GetLength();

	for ( int i = 0; i < length; i++ )
	{
		if ( std::isprint( data[i], std::locale::classic() ) )
		{
			for ( int j = i+1; j < length; j++ )
			{
				if ( !std::isprint( data[j], std::locale::classic() ) )
					break;
			}

			int const string_length = j - i;

			if ( string_length >= m_MinStringSize )
			{
				DisplayString( &data[i], string_length );
				++string_count;
			}

			i = j;
		}
	}

	DisplayEndOfScan( string_count );
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CWinStringsView::DisplayString( char const * string, int length )
{
	m_Display.AppendLine( CString( string, length ) );
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CWinStringsView::DisplayEndOfScan( int count )
{
	CString end_string;
	end_string.Format( "%d strings found.\r\n", count );
	m_Display.Append( end_string, CFE_ITALIC, RGB( 0, 128, 0 ) );
}
