#if !defined( WINSTRINGS_H_INCLUDED )
#define WINSTRINGS_H_INCLUDED

#pragma once

/****************************************************************************

                                 WinStrings.h

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/WinStrings/WinStrings.h#2 $

	$NoKeywords: $

****************************************************************************/

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CWinStringsApp : public CWinApp
{
public:
	CWinStringsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL( CWinStringsApp )
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG( CWinStringsApp )
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined( WINSTRINGS_H_INCLUDED )
