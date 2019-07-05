/****************************************************************************

                              WinStringsDoc.cpp

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/WinStrings/WinStringsDoc.cpp#2 $

	$NoKeywords: $

****************************************************************************/

#include "stdafx.h"

#include "WinStringsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinStringsDoc

IMPLEMENT_DYNCREATE( CWinStringsDoc, CDocument )

BEGIN_MESSAGE_MAP( CWinStringsDoc, CDocument )
	//{{AFX_MSG_MAP( CWinStringsDoc )
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinStringsDoc construction/destruction

CWinStringsDoc::CWinStringsDoc()
{
}

CWinStringsDoc::~CWinStringsDoc()
{
}

BOOL CWinStringsDoc::OnNewDocument()
{
	if ( !CDocument::OnNewDocument() )
		return FALSE;

	// TODO: add reinitialization code here
	// ( SDI documents will reuse this document )

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWinStringsDoc serialization

void CWinStringsDoc::Serialize( CArchive& ar )
{
	if ( ar.IsStoring() )
		return;

	// Get the file and the length of the data
	CFile * pfile = ar.GetFile();
	DWORD length = pfile->GetLength();

	// Allocate enough space for the data and read it from the file
	LPTSTR buffer = m_Data.GetBufferSetLength( length );
	pfile->Read( buffer, length );
	m_Data.ReleaseBuffer( length );
}

/////////////////////////////////////////////////////////////////////////////
// CWinStringsDoc diagnostics

#ifdef _DEBUG
void CWinStringsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinStringsDoc::Dump( CDumpContext& dc ) const
{
	CDocument::Dump( dc );
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinStringsDoc commands

void CWinStringsDoc::DeleteContents() 
{
	m_Data.Empty();
	
	CDocument ::DeleteContents();
}
