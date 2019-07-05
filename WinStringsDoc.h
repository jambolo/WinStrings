#if !defined( WINSTRINGSDOC_H_INCLUDED )
#define WINSTRINGSDOC_H_INCLUDED

#pragma once

/****************************************************************************

                               WinStringsDoc.h

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/WinStrings/WinStringsDoc.h#2 $

	$NoKeywords: $

****************************************************************************/



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CWinStringsDoc : public CDocument
{
protected: // create from serialization only
	CWinStringsDoc();
	DECLARE_DYNCREATE( CWinStringsDoc )

// Attributes
public:
	CString m_Data;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL( CWinStringsDoc )
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize( CArchive& ar );
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWinStringsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump( CDumpContext& dc ) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG( CWinStringsDoc )
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined( WINSTRINGSDOC_H_INCLUDED )
