// Copyright 2000-2012, signotec GmbH, Ratingen, Germany, All Rights Reserved
// signotec GmbH
// Am Gierath 20b
// 40885 Ratingen
// Tel: +49 (2102) 5 35 75-10
// Fax: +49 (2102) 5 35 75-39
// E-Mail: <info@signotec.de>
//
//-----------------------------------------------------------------------------
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of the signotec GmbH nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// THIS SOFTWARE ONLY DEMONSTRATES HOW TO IMPLEMENT SIGNOTEC SOFTWARE COMPONENTS
// AND IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------
//
// Version: 1.0.28.0
// Date:    2012-06-21

#include "stdafx.h"
#include "STPadCapt Demo App.h"
#include "STPadCapt Demo AppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_EVENTSINK_MAP(CSTPadCaptDemoAppDlg, CDialog)
	ON_EVENT(CSTPadCaptDemoAppDlg, IDC_STPADCAPTCTRL1, 2, CSTPadCaptDemoAppDlg::DeviceDisconnectedSTPadCaptCtrl1, VTS_I4)
	ON_EVENT(CSTPadCaptDemoAppDlg, IDC_STPADCAPTCTRL1, 1, CSTPadCaptDemoAppDlg::SensorHotSpotPressedSTPadCaptCtrl1, VTS_I2)
	ON_EVENT(CSTPadCaptDemoAppDlg, IDC_STPADCAPTCTRL1, 4, CSTPadCaptDemoAppDlg::DisplayScrollPosChangedStpadcaptctrl1, VTS_I4 VTS_I4)
	ON_EVENT(CSTPadCaptDemoAppDlg, IDC_STPADCAPTCTRL1, 3, CSTPadCaptDemoAppDlg::SensorTimeoutOccuredStpadcaptctrl1, VTS_I4)
	ON_EVENT(CSTPadCaptDemoAppDlg, IDC_STPADCAPTCTRL1, 5, CSTPadCaptDemoAppDlg::SignatureDataReceivedStpadcaptctrl1, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
END_EVENTSINK_MAP()

CSTPadCaptDemoAppDlg::CSTPadCaptDemoAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSTPadCaptDemoAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAINFRAME);
	m_bOpenFlag = false;
	m_nPadType = 0;
	m_nStoreIdSigning = -1;
	m_nStoreIdOverlay = -1;
	m_nButtonCancelId = -1;
	m_nButtonConfirmId = -1;
	m_nButtonRetryId = -1;
}

void CSTPadCaptDemoAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTONDEVCOUNT, m_ButtonDevCount);
	DDX_Control(pDX, IDC_BUTTONOPENCLOSE, m_ButtonOpenClose);
	DDX_Control(pDX, IDC_BUTTONSTARTCANCEL, m_ButtonStartCancel);
	DDX_Control(pDX, IDC_STPADCAPTCTRL1, m_STPadCaptCtrl1);
	DDX_Control(pDX, IDC_LISTOFDEVICES, m_ListOfDevices);
	DDX_Control(pDX, IDC_BUTTONRETRY, m_ButtonRetry);
	DDX_Control(pDX, IDC_BUTTONCLEARDISPLAY, m_ButtonClearDisplay);
	DDX_Control(pDX, IDC_BUTTONOK, m_ButtonOK);
	DDX_Control(pDX, IDC_LABELTYPE, m_LabelType);
	DDX_Control(pDX, IDC_LABELFIRMWARE, m_LabelFirmware);
	DDX_Control(pDX, IDC_LABELSERIAL, m_LabelSerial);
	DDX_Control(pDX, IDC_LABELDISPLAY, m_LabelDisplay);
	DDX_Control(pDX, IDC_PICTUREBOXLCD, m_PictureBoxLcd);
	DDX_Control(pDX, IDC_LABELPORT, m_LabelPort);
	DDX_Control(pDX, IDC_CHECKSERIAL, m_CheckBoxSerial);
	DDX_Control(pDX, IDC_CHECKHID, m_CheckBoxHID);
}

BEGIN_MESSAGE_MAP(CSTPadCaptDemoAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTONDEVCOUNT, &CSTPadCaptDemoAppDlg::OnBnClickedButtonDevCount)
	ON_BN_CLICKED(IDC_BUTTONOPENCLOSE, &CSTPadCaptDemoAppDlg::OnBnClickedButtonOpenClose)
	ON_BN_CLICKED(IDC_BUTTONSTARTCANCEL, &CSTPadCaptDemoAppDlg::OnBnClickedButtonStartCancel)
	ON_LBN_SELCHANGE(IDC_LISTOFDEVICES, &CSTPadCaptDemoAppDlg::OnLbnSelchangeListOfDevices)
	ON_BN_CLICKED(IDC_BUTTONRETRY, &CSTPadCaptDemoAppDlg::OnBnClickedButtonRetry)
	ON_BN_CLICKED(IDC_BUTTONCLEARDISPLAY, &CSTPadCaptDemoAppDlg::OnBnClickedButtonClearDisplay)
	ON_BN_CLICKED(IDC_BUTTONOK, &CSTPadCaptDemoAppDlg::OnBnClickedButtonOK)
	ON_BN_CLICKED(IDC_CHECKHID, &CSTPadCaptDemoAppDlg::OnBnClickedCheckhid)
	ON_BN_CLICKED(IDC_CHECKSERIAL, &CSTPadCaptDemoAppDlg::OnBnClickedCheckserial)
END_MESSAGE_MAP()


BOOL CSTPadCaptDemoAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	m_STPadCaptCtrl1.SetControlAppName("signoPAD-API Demo");
	bool m_bOpenFlag = false;
	m_ListOfDevices.AddString("No Devices");
	m_ListOfDevices.AddString("detected");
	m_CheckBoxHID.SetCheck(BST_CHECKED);

    // get connected devices and open first one if any
    OnBnClickedButtonDevCount();
	char szText[128];
    m_ListOfDevices.GetText(0, szText);
    if (strcmp(szText, "Device 1") == 0)
        OnBnClickedButtonOpenClose();

	return TRUE;
}

void CSTPadCaptDemoAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CSTPadCaptDemoAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSTPadCaptDemoAppDlg::OnBnClickedCheckhid()
{
	ConfigureSearch();
}

void CSTPadCaptDemoAppDlg::OnBnClickedCheckserial()
{
	ConfigureSearch();
}

void CSTPadCaptDemoAppDlg::ConfigureSearch()
{
	if (((m_CheckBoxHID.GetCheck() == BST_CHECKED) || (m_CheckBoxSerial.GetCheck() == BST_CHECKED)) && !m_bOpenFlag)
		m_ButtonDevCount.EnableWindow(true);
	else
	{
		m_ButtonDevCount.EnableWindow(false);
		return;
	}

	CString strList;
	long nCount = 0;
	if (m_CheckBoxHID.GetCheck() == BST_CHECKED)
	{	// enable search for HID devices
		strList.Append("HID;");
		nCount += 1;
	}
	if (m_CheckBoxSerial.GetCheck() == BST_CHECKED)
	{	// enable search for serial devices
		strList.Append("all");
		nCount += 256;
	}
	long nReturn = m_STPadCaptCtrl1.DeviceSetComPort(strList);
    if (nReturn < 0)
        // error
        GetError(nReturn);
	else if (nReturn != nCount)
	{	// return value not as expected
		CString strMsg;
		strMsg.Format("You've selected %d ports for the search but %d ports have been configured!", nCount, nReturn);
		AfxMessageBox(strMsg);
	}
}

void CSTPadCaptDemoAppDlg::OnBnClickedButtonDevCount()
{
	if ((m_CheckBoxHID.GetCheck() != BST_CHECKED) && (m_CheckBoxSerial.GetCheck() != BST_CHECKED))
	{
		AfxMessageBox("Please enable at least one model type to search for!");
		return;
	}

	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);

	// erase all entries
    m_ListOfDevices.ResetContent();

    // get number of connected devices
    long nDeviceCount = m_STPadCaptCtrl1.DeviceGetCount();
    if (nDeviceCount < 0)
        // error
        GetError(nDeviceCount);

    // build list
    if (nDeviceCount <= 0)
    {   // no devices detected
        m_ListOfDevices.AddString("No Devices");
        m_ListOfDevices.AddString("detected");
		m_ListOfDevices.EnableWindow(false);
        m_ButtonOpenClose.EnableWindow(false);
		m_ButtonOpenClose.SetWindowText("Open");
        m_ButtonClearDisplay.EnableWindow(false);
        m_ButtonStartCancel.EnableWindow(false);
        m_ButtonRetry.EnableWindow(false);
        m_ButtonOK.EnableWindow(false);
        ShowLogo(SW_SHOW);
        m_STPadCaptCtrl1.ShowWindow(SW_HIDE);
        m_LabelType.SetWindowText("Type: -");
        m_LabelPort.SetWindowText("Port: -");
        m_LabelFirmware.SetWindowText("Firmware: -");
        m_LabelSerial.SetWindowText("Serial: -");
        m_LabelDisplay.SetWindowText("Display: -");
    }
    else
    {   // build device list
        long nCount = 0;
        while (nCount < nDeviceCount)
        {
			char szText[256];
			sprintf_s(szText, 256, "Device %d", nCount + 1);
            m_ListOfDevices.AddString(szText);
            nCount++;
        }
        m_ListOfDevices.EnableWindow(true);

        // select first element of list
        if (nDeviceCount > 0)
		{
            m_ListOfDevices.SetCurSel(0);
			OnLbnSelchangeListOfDevices();
		}
	}

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::OnLbnSelchangeListOfDevices()
{
	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);

	// get serial and type of selected device
	BSTR bstrSerial;
	long nResult = m_STPadCaptCtrl1.DeviceGetInfo(&bstrSerial, &m_nPadType, m_ListOfDevices.GetCurSel());
    if (nResult < 0)
    {   // error
        GetError(nResult);
        return;
    }

    // print type
	char szText[32];
	HBITMAP hBmLogo = NULL;
    switch(m_nPadType)
    {
        case 1:
            m_LabelType.SetWindowText("Type: Sigma HID");
			hBmLogo = LoadBitmap((HINSTANCE)GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGO_SIGMA));
            break;
        case 2:
            m_LabelType.SetWindowText("Type: Sigma FTDI");
			hBmLogo = LoadBitmap((HINSTANCE)GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGO_SIGMA));
            break;
        case 11:
            m_LabelType.SetWindowText("Type: Omega HID");
			hBmLogo = LoadBitmap((HINSTANCE)GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGO_OMEGA));
            break;
        case 12:
            m_LabelType.SetWindowText("Type: Omega FTDI");
			hBmLogo = LoadBitmap((HINSTANCE)GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGO_OMEGA));
            break;
        default:
			sprintf_s(szText, 32, "Type: %d", m_nPadType);
            m_LabelType.SetWindowText(szText);
			hBmLogo = LoadBitmap((HINSTANCE)GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGO_SIGMA));
            break;
    }
	if (hBmLogo)
	{
		m_PictureBoxLcd.SetBitmap(hBmLogo);
		DeleteObject(hBmLogo);
	}
    m_STPadCaptCtrl1.ShowWindow(SW_HIDE);
    ShowLogo(SW_SHOW);
	m_PictureBoxLcd.SetWindowPos(&wndTop, 0 ,0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);

    // print serial
	_bstr_t cbstrSerial(bstrSerial);
	sprintf_s(szText, 32, "Serial: %s", (char*)cbstrSerial);
    m_LabelSerial.SetWindowText(szText);

	// get port number
	switch (m_nPadType)
	{
		case 1:
		case 11:
			m_LabelPort.SetWindowText("Port: USB");
			break;
		default:
			nResult = m_STPadCaptCtrl1.DeviceGetComPort(m_ListOfDevices.GetCurSel());
			if (nResult < 0)
			{   // error
				GetError(nResult);
				return;
			}
			else
			{
				sprintf_s(szText, 32, "Port: COM%d", nResult);
				m_LabelPort.SetWindowText(szText);
			}
	}

    // get firmware version
    BSTR bstrVersion = 0;
    nResult = m_STPadCaptCtrl1.DeviceGetVersion(&bstrVersion, m_ListOfDevices.GetCurSel());
    if (nResult < 0)
    {   // error
        GetError(nResult);
        return;
    }

    // print firmware version
	_bstr_t cbstrVersion(bstrVersion);
	sprintf_s(szText, 32, "Firmware: %s", (char*)cbstrVersion);
    m_LabelFirmware.SetWindowText(szText);

    // enable "Open" button for selected device
    m_ButtonOpenClose.EnableWindow(true);
	sprintf_s(szText, 32, "Open Device %d", m_ListOfDevices.GetCurSel() + 1);
	m_ButtonOpenClose.SetWindowText(szText);

	m_LabelDisplay.SetWindowText("Display: -");

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::OnBnClickedButtonOpenClose()
{
	CString strWindowText;
	m_ButtonOpenClose.GetWindowText(strWindowText);
	char szText[128];
	sprintf_s(szText, 128, "Open Device %d", m_ListOfDevices.GetCurSel() + 1);
	if (strWindowText.Compare(szText) == 0)
		OpenDevice();
	else
	    CloseDevice();
}

void CSTPadCaptDemoAppDlg::OpenDevice()
{
	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);

	// open device
	long nResult = m_STPadCaptCtrl1.DeviceOpen(m_ListOfDevices.GetCurSel());
	if (nResult < 0)
	{   // error
		GetError(nResult);
		return;
	}
	m_bOpenFlag = true;
	m_nStoreIdSigning = -1;
	m_nStoreIdOverlay = -1;
	ShowLogo(SW_HIDE);
	m_STPadCaptCtrl1.ShowWindow(SW_SHOW);
	char szText[128];
	sprintf_s (szText, 128, "Close Device %d", m_ListOfDevices.GetCurSel() + 1);
	m_ButtonOpenClose.SetWindowText(szText);
	m_CheckBoxHID.EnableWindow(false);
	m_CheckBoxSerial.EnableWindow(false);
	m_ButtonDevCount.EnableWindow(false);
	m_ButtonClearDisplay.EnableWindow(true);
	m_ButtonStartCancel.EnableWindow(true);
	m_ButtonRetry.EnableWindow(false);
	m_ButtonOK.EnableWindow(false);
	m_ListOfDevices.EnableWindow(false);

	// get display size of selected device
	long nWidth = m_STPadCaptCtrl1.GetDisplayWidth();
	if (nWidth < 0)
	{   // error
		GetError(nWidth);
		return;
	}
	long nHeight = m_STPadCaptCtrl1.GetDisplayHeight();
	if (nHeight < 0)
	{   // error
		GetError(nHeight);
		return;
	}

	// print display size
	sprintf_s (szText, 128, "Display: %d x %d Pixel", nWidth, nHeight);
	m_LabelDisplay.SetWindowText(szText);

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::CloseDevice()
{
	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);

    // close device
	long nResult = m_STPadCaptCtrl1.DeviceClose(m_ListOfDevices.GetCurSel());
	if (nResult < 0)
	{   // error
		GetError(nResult);
		return;
	}
	m_bOpenFlag = false;
	char szText[128];
	sprintf_s(szText, 128, "Open Device %d", m_ListOfDevices.GetCurSel() + 1);
	m_ButtonOpenClose.SetWindowText(szText);
	m_CheckBoxHID.EnableWindow(true);
	m_CheckBoxSerial.EnableWindow(true);
	m_ButtonDevCount.EnableWindow(true);
	m_ListOfDevices.EnableWindow(true);
	m_ButtonStartCancel.SetWindowText("Start");
	m_ButtonClearDisplay.EnableWindow(false);
	m_ButtonStartCancel.EnableWindow(false);
	m_ButtonRetry.EnableWindow(false);
	m_ButtonOK.EnableWindow(false);
	m_STPadCaptCtrl1.ShowWindow(SW_HIDE);
	ShowLogo(SW_SHOW);

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::OnBnClickedButtonClearDisplay()
{
	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);

    // erase LCD
    int nResult = m_STPadCaptCtrl1.DisplayErase();

    if (nResult < 0)
        // error
        GetError(nResult);
    else
    {
        ShowLogo(SW_HIDE);
        m_STPadCaptCtrl1.ShowWindow(SW_SHOW);
    }

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::OnBnClickedButtonStartCancel()
{
	CString strWindowText;
	m_ButtonStartCancel.GetWindowText(strWindowText);
    if (strWindowText.Compare("Start") == 0)
        // display general terms and two buttons "OK" & "Cancel"
		ShowDisclaimer();
	else
		Cancel();
}

void CSTPadCaptDemoAppDlg::ShowDisclaimer()
{	// display disclaimer and two buttons "Cancel" and "Confirm"
	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);
    long nResult = 0;

    // clear all hot spots
	nResult = ClearHotSpots();
    if (nResult < 0)
    {   // error
        GetError(nResult);
        return;
    }

    // clear signature window
    nResult = m_STPadCaptCtrl1.SensorClearSignRect();
    if (nResult < 0)
    {   // error
        GetError(nResult);
        return;
    }

    // erase LCD and background buffer
    nResult = m_STPadCaptCtrl1.DisplayErase();
    if (nResult < 0)
    {   // error
        GetError(nResult);
        return;
    }

	LPCTSTR szDisclaimer = "With my signature, I certify that I'm excited about the signotec LCD Signature Pad and the signotec Pad Capture Control. This demo application has blown me away and I can't wait to integrate all these great features in my own application.";

    if ((m_nPadType == 11) || (m_nPadType == 12))
    {
        // do all the following drawing operations in the permanent memory
        nResult = m_STPadCaptCtrl1.DisplaySetTarget(m_nStoreIdOverlay);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }
        m_nStoreIdOverlay = nResult;

        // load button bitmaps and set hot spots for toolbar
        // "Cancel" button
		HBITMAP hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTCANCEL_OMEGA));
        nResult = m_STPadCaptCtrl1.DisplaySetImage(24, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 80, HandleToLong(hBitmap));
        DeleteObject(hBitmap);
		hBitmap = NULL;
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }
        nResult = m_STPadCaptCtrl1.SensorAddHotSpot(24, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 80, 170, 66);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }
        m_nButtonCancelId = nResult;
        // "Confirm" button
		hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTOK_OMEGA));
        nResult = m_STPadCaptCtrl1.DisplaySetImage(234, 400, HandleToLong(hBitmap));
        DeleteObject(hBitmap);
		hBitmap = NULL;
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }
        nResult = m_STPadCaptCtrl1.SensorAddHotSpot(234, 400, 170, 66);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }
        m_nButtonConfirmId = nResult;
        // Scroll buttons
		hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTSCROLL_OMEGA));
        nResult = m_STPadCaptCtrl1.DisplaySetImage(444, 400, HandleToLong(hBitmap));
        DeleteObject(hBitmap);
		hBitmap = NULL;
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }
        nResult = m_STPadCaptCtrl1.SensorAddScrollHotSpot(444, 400, 66, 66, 0);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }
        nResult = m_STPadCaptCtrl1.SensorAddScrollHotSpot(548, 400, 66, 66, 1);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }

        // do all the following drawing operations in the overlay buffer
        nResult = m_STPadCaptCtrl1.DisplaySetTarget(2);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }

        // copy stored image to overlay buffer
        nResult = m_STPadCaptCtrl1.DisplaySetImageFromStore((short)m_nStoreIdOverlay);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }

        // do all the following drawing operations in the background buffer
        nResult = m_STPadCaptCtrl1.DisplaySetTarget(1);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }

        // draw disclaimer
        nResult = m_STPadCaptCtrl1.DisplaySetTextInRect(10, 10, (short)m_STPadCaptCtrl1.GetDisplayWidth() - 20, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 80, 0, szDisclaimer);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }

        // use font size of the disclaimer text
        if (nResult != 40)
        {
            nResult = m_STPadCaptCtrl1.DisplaySetFont("Arial", (short)nResult, 0);
            if (nResult < 0)
            {
                GetError(nResult);
                return;
            }
        }

        // set scroll text
        nResult = m_STPadCaptCtrl1.DisplaySetTextInRect(10, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 80, (short)m_STPadCaptCtrl1.GetDisplayWidth() - 20, 100, 0, "Congratulations! If you can read this text you have found the scroll buttons!");
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }

        // set end text
        nResult = m_STPadCaptCtrl1.DisplaySetTextInRect(10, (short)m_STPadCaptCtrl1.GetDisplayTargetHeight() - 120, (short)m_STPadCaptCtrl1.GetDisplayWidth() - 20, 80, 0, "You have scrolled to the end of this text!");
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }

        // set overlay rect
        nResult = m_STPadCaptCtrl1.DisplaySetOverlayRect(0, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 80, (short)m_STPadCaptCtrl1.GetDisplayWidth(), 80);
        if (nResult < 0)
        {
            GetError(nResult);
            return;
        }
    }
    else
    {
		// do all drawing operations in the background buffer
		m_STPadCaptCtrl1.DisplaySetTarget(1);

		// load button bitmaps and set hot spots
		HBITMAP hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTCANCEL_SIGMA));
		nResult = m_STPadCaptCtrl1.DisplaySetImage(20, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 40, HandleToLong(hBitmap));
		DeleteObject(hBitmap);
		hBitmap = NULL;
		if (nResult < 0)
		{   // error
			GetError(nResult);
			return;
		}

		nResult = m_STPadCaptCtrl1.SensorAddHotSpot(20, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 40, 85, 33);
		if (nResult < 0)
		{   // error
			GetError(nResult);
			return;
		}
		m_nButtonCancelId = nResult;

		hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTOK_SIGMA));
		nResult = m_STPadCaptCtrl1.DisplaySetImage((short)m_STPadCaptCtrl1.GetDisplayWidth() - 105, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 40, HandleToLong(hBitmap));
		DeleteObject(hBitmap);
		hBitmap = NULL;
		if (nResult < 0)
		{   // error
			GetError(nResult);
			return;
		}

		nResult = m_STPadCaptCtrl1.SensorAddHotSpot((short)m_STPadCaptCtrl1.GetDisplayWidth() - 105, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 40, 85, 33);
		if (nResult < 0)
		{   // error
			GetError(nResult);
			return;
		}
		m_nButtonConfirmId = nResult;

		// display general terms
		nResult = m_STPadCaptCtrl1.DisplaySetTextInRect(10, 10, (short)m_STPadCaptCtrl1.GetDisplayWidth() - 20, (short)m_STPadCaptCtrl1.GetDisplayHeight() - 60, 0, szDisclaimer);
		if (nResult < 0)
		{   // error
			GetError(nResult);
			return;
		}
	}

	// do all drawing operations on the LCD
	m_STPadCaptCtrl1.DisplaySetTarget(0);

	// draw buffered image
	nResult = m_STPadCaptCtrl1.DisplaySetImageFromStore(1);
	if (nResult < 0)
	{
		GetError(nResult);
		return;
	}

	m_ButtonRetry.EnableWindow(false);
    m_ButtonStartCancel.SetWindowText("Cancel");
    m_ButtonOK.EnableWindow(true);
    m_ButtonClearDisplay.EnableWindow(false);
    ShowLogo(SW_HIDE);
    m_STPadCaptCtrl1.ShowWindow(SW_SHOW);

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::Cancel()
{   
	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);

	long nResult = 0;
	if (m_STPadCaptCtrl1.GetSignatureState())
        // cancel capturing (this clears the LCD, too)
        nResult = m_STPadCaptCtrl1.SignatureCancel();
	else
		// erase LCD
        nResult = m_STPadCaptCtrl1.DisplayErase();

    if (nResult < 0)
    {   // error
        GetError(nResult);
        return;
    }

    // clear all hot spots
    nResult = ClearHotSpots();
    if (nResult < 0)
        // error
        GetError(nResult);
    
    m_ButtonStartCancel.SetWindowText("Start");
    m_ButtonStartCancel.EnableWindow(true);
    m_ButtonRetry.EnableWindow(false);
    m_ButtonOK.EnableWindow(false);
    m_ButtonClearDisplay.EnableWindow(true);

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::OnBnClickedButtonRetry()
{
	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);

	long nResult = m_STPadCaptCtrl1.SignatureRetry();
	if (nResult < 0)
		// error
		GetError(nResult);

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::OnBnClickedButtonOK()
{
    // clear hot spots
    int nResult = ClearHotSpots();
    if (nResult < 0)
    {   // error
        GetError(nResult);
        return;
    }
    if (!m_STPadCaptCtrl1.GetSignatureState())
    {   // accept disclaimer and start capturing
        nResult = m_STPadCaptCtrl1.DisplayErase();
        if (nResult < 0)
        {   // error
            GetError(nResult);
            return;
        }
		StartCapturing();
	}
	else
		ConfirmCapturing();
}

void CSTPadCaptDemoAppDlg::StartCapturing()
{
	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);

	HBITMAP hBitmap = NULL;
	int nResult = 0;

	switch (m_nPadType)
	{
		case 11:
		case 12:
            // Omega: do all drawing operations in the memory
            nResult = m_STPadCaptCtrl1.DisplaySetTarget(m_nStoreIdSigning);
            if (nResult < 0)
            {
                GetError(nResult);
                return;
            }
            m_nStoreIdSigning = nResult;

            // load the bitmaps
			hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTCANCEL_OMEGA));
            nResult = m_STPadCaptCtrl1.DisplaySetImage(24, 18, HandleToLong(hBitmap));
            DeleteObject(hBitmap);
			hBitmap = NULL;
            if (nResult < 0)
            {
                GetError(nResult);
                return;
            }
			hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTRETRY_OMEGA));
            nResult = m_STPadCaptCtrl1.DisplaySetImage(234, 18, HandleToLong(hBitmap));
            DeleteObject(hBitmap);
			hBitmap = NULL;
            if (nResult < 0)
            {
                GetError(nResult);
                return;
            }
			hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTOK_OMEGA));
            nResult = m_STPadCaptCtrl1.DisplaySetImage(444, 18, HandleToLong(hBitmap));
            DeleteObject(hBitmap);
			hBitmap = NULL;
            if (nResult < 0)
            {
                GetError(nResult);
                return;
            }
			hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTBITMAP_OMEGA));
            nResult = m_STPadCaptCtrl1.DisplaySetImage(25, 150, HandleToLong(hBitmap));
            DeleteObject(hBitmap);
			hBitmap = NULL;
            if (nResult < 0)
            {
                GetError(nResult);
                return;
            }
           // do all drawing operations in the background buffer
            m_STPadCaptCtrl1.DisplaySetTarget(1);

            // draw stored image
            nResult = m_STPadCaptCtrl1.DisplaySetImageFromStore((short)m_nStoreIdSigning);
            if (nResult < 0)
            {
                GetError(nResult);
                return;
            }

            // do all drawing operations on the  LCD directly
            m_STPadCaptCtrl1.DisplaySetTarget(0);

            // draw buffered image
            nResult = m_STPadCaptCtrl1.DisplaySetImageFromStore(1);
            if (nResult < 0)
            {
                GetError(nResult);
                return;
            }
            break;
		default:
            // Sigma: draw on the LCD directly
			hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DEFAULTBITMAP_SIGMA));
			nResult = m_STPadCaptCtrl1.DisplaySetImage(0, 0, HandleToLong(hBitmap));
            DeleteObject(hBitmap);
			hBitmap = NULL;
			if (nResult < 0)
			{   // error
				GetError(nResult);
				return;
			}
	}

    // get scaling factor
	int nScale = ((m_nPadType >= 11) && (m_nPadType <= 12)) ? 2 : 1;

    // set default signature window
    nResult = m_STPadCaptCtrl1.SensorSetSignRect(0, 50 * nScale, 0, 0);
    if (nResult < 0)
    {
        GetError(nResult);
        return;
    }

    // add default hotspots
    nResult = m_STPadCaptCtrl1.SensorAddHotSpot(12 * nScale, 9 * nScale, 85 * nScale, 33 * nScale);
    if (nResult < 0)
    {
        GetError(nResult);
        return;
    }
    m_nButtonCancelId = nResult;

    nResult = m_STPadCaptCtrl1.SensorAddHotSpot((short)m_STPadCaptCtrl1.GetDisplayWidth() - 203 * nScale, 9 * nScale, 85 * nScale, 33 * nScale);
    if (nResult < 0)
    {
        GetError(nResult);
        return;
    }
    m_nButtonRetryId = nResult;

    nResult = m_STPadCaptCtrl1.SensorAddHotSpot((short)m_STPadCaptCtrl1.GetDisplayWidth() - 98 * nScale, 9 * nScale, 85 * nScale, 33 * nScale);
    if (nResult < 0)
    {
        GetError(nResult);
        return;
    }
    m_nButtonConfirmId = nResult;

	// start capturing
    nResult = m_STPadCaptCtrl1.SignatureStart();
    if (nResult < 0)
    {   // error
        GetError(nResult);
        return;
    }
    m_ButtonRetry.EnableWindow(true);
    ShowLogo(SW_HIDE);

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::ConfirmCapturing()
{
	HCURSOR hCursWait = LoadCursor(NULL, IDC_WAIT);
	HCURSOR hCursPrev = NULL;
	if (hCursWait)
		hCursPrev = SetCursor(hCursWait);

    // confirm capturing
    long nResult = m_STPadCaptCtrl1.SignatureConfirm();
    if (nResult < 0)
    {   // error
        GetError(nResult);
        return;
    }

    m_ButtonStartCancel.SetWindowText("Start");
    m_ButtonRetry.EnableWindow(false);
    m_ButtonOK.EnableWindow(false);
    m_ButtonClearDisplay.EnableWindow(true);

	if (hCursPrev)
		SetCursor(hCursPrev);
	if (hCursWait)
		DeleteObject(hCursWait);
}

void CSTPadCaptDemoAppDlg::SensorHotSpotPressedSTPadCaptCtrl1(short nHotSpotId)
{
	if (nHotSpotId == m_nButtonCancelId)
		OnBnClickedButtonStartCancel();
	else if (nHotSpotId == m_nButtonRetryId)
		OnBnClickedButtonRetry();
	else if (nHotSpotId == m_nButtonConfirmId)
		OnBnClickedButtonOK();
}

void CSTPadCaptDemoAppDlg::DeviceDisconnectedSTPadCaptCtrl1(long nIndex)
{   // reset form and search for still connected devices
    m_bOpenFlag = false;
    m_ListOfDevices.AddString("No Devices");
    m_ListOfDevices.AddString("detected");
    m_ListOfDevices.EnableWindow(false);
    m_ButtonClearDisplay.EnableWindow(false);
    m_ButtonStartCancel.EnableWindow(false);
    m_ButtonRetry.EnableWindow(false);
    m_ButtonOK.EnableWindow(false);
    m_STPadCaptCtrl1.ControlErase();
    ShowLogo(SW_SHOW);
	m_CheckBoxHID.EnableWindow(true);
	m_CheckBoxSerial.EnableWindow(true);
    m_ButtonDevCount.EnableWindow(true);
    m_ButtonStartCancel.SetWindowText("Start");
	OnBnClickedButtonDevCount();
}

void CSTPadCaptDemoAppDlg::DisplayScrollPosChangedStpadcaptctrl1(long nXPos, long nYPos)
{
	// Not implemented in this sample
}

void CSTPadCaptDemoAppDlg::SensorTimeoutOccuredStpadcaptctrl1(long nPointsCount)
{
	// Not implemented in this sample
}

void CSTPadCaptDemoAppDlg::SignatureDataReceivedStpadcaptctrl1(long nXPos, long nYPos, long nPressure, long nTimestamp)
{
	// Not implemented in this sample
}

long CSTPadCaptDemoAppDlg::ClearHotSpots()
{
	long nResult = m_STPadCaptCtrl1.SensorClearHotSpots();
    if (nResult == 0)
    {
		m_nButtonCancelId = -1;
		m_nButtonConfirmId = -1;
		m_nButtonRetryId = -1;
    }
	return nResult;
}

void CSTPadCaptDemoAppDlg::ShowLogo(int nCmdShow)
{
	HBITMAP hBmLogo = NULL;
    switch(m_nPadType)
    {
        case 11:
        case 12:
			hBmLogo = LoadBitmap((HINSTANCE)GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGO_OMEGA));
            break;
        default:
			hBmLogo = LoadBitmap((HINSTANCE)GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGO_SIGMA));
            break;
    }
	if (hBmLogo)
	{
		m_PictureBoxLcd.ShowWindow(nCmdShow);
		m_PictureBoxLcd.SetBitmap(hBmLogo);
		DeleteObject(hBmLogo);
	}
}

void CSTPadCaptDemoAppDlg::GetError(long nError)
{
	HCURSOR hCursDefault = LoadCursor(NULL, IDC_ARROW);
	SetCursor(hCursDefault);

	BSTR bstrError;
	if (m_STPadCaptCtrl1.ControlGetErrorString(&bstrError, nError) == 0)
	{
		_bstr_t cbstrError(bstrError);
		AfxMessageBox(cbstrError);
	}
}
