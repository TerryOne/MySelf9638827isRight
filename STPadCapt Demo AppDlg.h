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
// Version: 1.0.25.0
// Date:    2012-01-01

#pragma once
#include "afxwin.h"
#include "comutil.h"
#include "STPadCaptCtrl.h"


class CSTPadCaptDemoAppDlg : public CDialog
{
public:
	CSTPadCaptDemoAppDlg(CWnd* pParent = NULL);
	enum { IDD = IDD_STPADCAPTDEMOAPP_DIALOG };

protected:
	virtual	void	DoDataExchange(CDataExchange* pDX);

protected:
			HICON			m_hIcon;

	virtual	BOOL			OnInitDialog();
	afx_msg	void			OnPaint();
	afx_msg	HCURSOR			OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()

			bool			m_bOpenFlag;
			long			m_nPadType;
			long			m_nStoreIdSigning;
			long			m_nStoreIdOverlay;
			long			m_nButtonCancelId;
			long			m_nButtonConfirmId;
			long			m_nButtonRetryId;
			void			GetError(long nError);
			void			ConfigureSearch();
			void			OpenDevice();
			void			CloseDevice();
			void			ShowDisclaimer();
			void			Cancel();
			void			StartCapturing();
			void			ConfirmCapturing();
			void			ShowLogo(int nCmdShow);
			long			ClearHotSpots();
public:
			CButton			m_CheckBoxSerial;
			CButton			m_CheckBoxHID;
			CButton			m_ButtonDevCount;
			CButton			m_ButtonOpenClose;
			CSTPadCaptCtrl1	m_STPadCaptCtrl1;
			CListBox		m_ListOfDevices;
			CStatic			m_LabelType;
			CStatic			m_LabelPort;
			CStatic			m_LabelFirmware;
			CStatic			m_LabelSerial;
			CStatic			m_LabelDisplay;
			CButton			m_ButtonClearDisplay;
			CButton			m_ButtonStartCancel;
			CButton			m_ButtonRetry;
			CButton			m_ButtonOK;
			CStatic			m_PictureBoxLcd;

	afx_msg void			OnBnClickedCheckhid();
	afx_msg void			OnBnClickedCheckserial();
	afx_msg	void			OnBnClickedButtonDevCount();
	afx_msg void			OnCbnSelchangeComboportsearch();
	afx_msg void			OnLbnSelchangeListOfDevices();
	afx_msg void			OnBnClickedButtonOpenClose();
	afx_msg void			OnBnClickedButtonClearDisplay();
	afx_msg void			OnBnClickedButtonStartCancel();
	afx_msg void			OnBnClickedButtonRetry();
	afx_msg void			OnBnClickedButtonOK();

	DECLARE_EVENTSINK_MAP()

			void			DeviceDisconnectedSTPadCaptCtrl1(long nIndex);
			void			SensorHotSpotPressedSTPadCaptCtrl1(short nHotSpotId);
			void			DisplayScrollPosChangedStpadcaptctrl1(long nXPos, long nYPos);
			void			SensorTimeoutOccuredStpadcaptctrl1(long nPointsCount);
			void			SignatureDataReceivedStpadcaptctrl1(long nXPos, long nYPos, long nPressure, long nTimestamp);
};
