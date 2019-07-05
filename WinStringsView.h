#if !defined( WINSTRINGSVIEW_H_INCLUDED )
#define WINSTRINGSVIEW_H_INCLUDED

#pragma once

/****************************************************************************

                               WinStringsView.h

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/WinStrings/WinStringsView.h#2 $

	$NoKeywords: $

****************************************************************************/

#include "resource.h"
#include "LogCtrl.h"

class CWinStringsDoc;

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CWinStringsView : public CFormView
{
protected: // create from serialization only
	CWinStringsView();
	DECLARE_DYNCREATE( CWinStringsView )

public:
	//{{AFX_DATA( CWinStringsView )
	enum { IDD = IDD_WINSTRINGS_FORM };
	LogCtrl	m_Display;
	int		m_MinStringSize;
	//}}AFX_DATA

// Attributes
public:
	CWinStringsDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL( CWinStringsView )
	public:
	virtual BOOL PreCreateWindow( CREATESTRUCT& cs );
	protected:
	virtual void DoDataExchange( CDataExchange* pDX );    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting( CPrintInfo* pInfo );
	virtual void OnBeginPrinting( CDC* pDC, CPrintInfo* pInfo );
	virtual void OnEndPrinting( CDC* pDC, CPrintInfo* pInfo );
	virtual void OnPrint( CDC* pDC, CPrintInfo* pInfo );
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWinStringsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump( CDumpContext& dc ) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG( CWinStringsView )
	afx_msg void OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );
	afx_msg void OnScan();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DisplayEndOfScan( int count );
	void DisplayString( LPCTSTR string, int length );
	void ScanForStrings();
};

#ifndef _DEBUG  // debug version in WinStringsView.cpp
inline CWinStringsDoc* CWinStringsView::GetDocument()
   { return ( CWinStringsDoc* )m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined( WINSTRINGSVIEW_H_INCLUDED )
