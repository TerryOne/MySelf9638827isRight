#pragma once

// Mit Microsoft Visual C++ generierte IDispatch-Wrapperklasse(n)

// HINWEIS: Der Inhalt dieser Datei darf nicht geändert werden. Wenn diese Klasse von Microsoft Visual C++
// neu generiert wird, werden Ihre Änderungen überschrieben.

/////////////////////////////////////////////////////////////////////////////
// CSTPadCaptCtrl1-Wrapperklasse

class CSTPadCaptCtrl1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CSTPadCaptCtrl1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x3946312B, 0x1829, 0x4D4F, { 0xA2, 0xDF, 0xCD, 0x35, 0xC8, 0x90, 0x8B, 0xA1 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// Attribute
public:


// Operationen
public:

// Methoden
//

	long DeviceGetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long DeviceGetInfo(BSTR * pbstrSerial, long * pnType, long nIndex)
	{
		long result;
		static BYTE parms[] = VTS_PBSTR VTS_PI4 VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pbstrSerial, pnType, nIndex);
		return result;
	}
	long DeviceOpen(long nIndex, bool bEraseDisplay=true)
	{
		VARIANT vaEraseDisplay;
		vaEraseDisplay.vt = VT_BOOL;
		vaEraseDisplay.boolVal = bEraseDisplay;
		long result;
		static BYTE parms[] = VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nIndex, &vaEraseDisplay);
		return result;
	}
	long DeviceClose(long nIndex)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nIndex);
		return result;
	}
	long SignatureStart()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SignatureConfirm()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long DeviceSetLed(short nLedColor)
	{
		long result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nLedColor);
		return result;
	}
	long SensorSetSignRect(short nLeft, short nTop, short nWidth, short nHeight)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nLeft, nTop, nWidth, nHeight);
		return result;
	}
	long DisplayErase()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SensorAddHotSpot(short nLeft, short nTop, short nWidth, short nHeight)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nLeft, nTop, nWidth, nHeight);
		return result;
	}
	long SensorClearHotSpots()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long ControlErase()
	{
		long result;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SensorGetSampleRateMode()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SensorSetSampleRateMode(long nMode)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMode);
		return result;
	}
	long DisplaySetFont(LPCTSTR bstrName, short nSize, short nOptions)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I2 VTS_I2 ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrName, nSize, nOptions);
		return result;
	}
	long DisplaySetText(short nXPos, short nYPos, short nAlignment, LPCTSTR bstrText)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 VTS_BSTR ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nXPos, nYPos, nAlignment, bstrText);
		return result;
	}
	long DisplaySetTextInRect(short nLeft, short nTop, short nWidth, short nHeight, short nAlignment, LPCTSTR bstrText)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_BSTR ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nLeft, nTop, nWidth, nHeight, nAlignment, bstrText);
		return result;
	}
	long DisplaySetImage(short nXPos, short nYPos, long nImageHandle)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_I4 ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nXPos, nYPos, nImageHandle);
		return result;
	}
	long SignatureRetry()
	{
		long result;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SignatureCancel(long nErase=0)
	{
		VARIANT vaErase;
		vaErase.vt = VT_I4;
		vaErase.lVal = nErase;
		long result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, &vaErase);
		return result;
	}
	long DisplaySetImageFromFile(short nXPos, short nYPos, LPCTSTR bstrPath)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_BSTR ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nXPos, nYPos, bstrPath);
		return result;
	}
	long SensorClearSignRect()
	{
		long result;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long DeviceGetVersion(BSTR * pbstrVersion, long nIndex)
	{
		long result;
		static BYTE parms[] = VTS_PBSTR VTS_I4 ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pbstrVersion, nIndex);
		return result;
	}
	long DisplaySetStandbyImage(long nImageHandle)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nImageHandle);
		return result;
	}
	long DisplaySetStandbyImageFromFile(LPCTSTR bstrPath)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrPath);
		return result;
	}
	long DeviceSetComPort(LPCTSTR bstrComPortList)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrComPortList);
		return result;
	}
	long DeviceGetComPort(long nIndex)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nIndex);
		return result;
	}
	VARIANT DisplaySaveImageAsStream(short nFileType, short nOptions)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I2 VTS_I2 ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, nFileType, nOptions);
		return result;
	}
	long DisplaySaveImageAsFile(LPCTSTR bstrPath, short nFileType, short nOptions)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I2 VTS_I2 ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrPath, nFileType, nOptions);
		return result;
	}
	long SignatureGetBounds(short * pnLeft, short * pnTop, short * pnRight, short * pnBottom, short nOptions)
	{
		long result;
		static BYTE parms[] = VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI2 VTS_I2 ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pnLeft, pnTop, pnRight, pnBottom, nOptions);
		return result;
	}
	long SensorStartTimer(long nDurationBeforeAction, long nDurationAfterAction, short nOptions)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I2 ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nDurationBeforeAction, nDurationAfterAction, nOptions);
		return result;
	}
	long SensorStopTimer()
	{
		long result;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long DisplaySetFontColor(unsigned long clrFont)
	{
		long result;
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, clrFont);
		return result;
	}
	long ControlGetErrorString(BSTR * pbstrError, long nErrorId)
	{
		long result;
		static BYTE parms[] = VTS_PBSTR VTS_I4 ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pbstrError, nErrorId);
		return result;
	}
	long DisplaySetImageFromStore(short nStoreId)
	{
		long result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nStoreId);
		return result;
	}
	long DisplaySetTarget(long nTarget)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nTarget);
		return result;
	}
	long DisplayConfigPen(short nWidth, unsigned long color)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_UI4 ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nWidth, color);
		return result;
	}
	long DisplayConfigSlideShow(LPCTSTR bstrSlideList, long nDuration)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrSlideList, nDuration);
		return result;
	}
	VARIANT SignatureSaveAsStreamEx(short nResolution, long nWidth, long nHeight, short nFileType, short nPenWidth, unsigned long penColor, long nOptions)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I2 VTS_I4 VTS_I4 VTS_I2 VTS_I2 VTS_UI4 VTS_I4 ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, nResolution, nWidth, nHeight, nFileType, nPenWidth, penColor, nOptions);
		return result;
	}
	long SignatureSaveAsFileEx(LPCTSTR bstrPath, short nResolution, long nWidth, long nHeight, short nFileType, short nPenWidth, unsigned long penColor, long nOptions)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I2 VTS_I4 VTS_I4 VTS_I2 VTS_I2 VTS_UI4 VTS_I4 ;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrPath, nResolution, nWidth, nHeight, nFileType, nPenWidth, penColor, nOptions);
		return result;
	}
	long SignatureStop()
	{
		long result;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long DisplayGetStandbyId(BSTR * pbstrId)
	{
		long result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pbstrId);
		return result;
	}
	long SensorSetHotspotMode(short nMode, long nHotSpotId)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I4 ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMode, nHotSpotId);
		return result;
	}
	long DisplayEraseRect(short nLeft, short nTop, short nWidth, short nHeight)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nLeft, nTop, nWidth, nHeight);
		return result;
	}
	long DisplaySetBacklight(short nMode)
	{
		long result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nMode);
		return result;
	}
	long DisplaySetOverlayRect(short nLeft, short nTop, short nWidth, short nHeight)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nLeft, nTop, nWidth, nHeight);
		return result;
	}
	long SensorAddScrollHotSpot(short nLeft, short nTop, short nWidth, short nHeight, long nOptions)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I4 ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nLeft, nTop, nWidth, nHeight, nOptions);
		return result;
	}
	long DisplaySetScrollPos(long nXPos, long nYPos)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nXPos, nYPos);
		return result;
	}
	long DisplayGetScrollPos(long * pnXPos, long * pnYPos)
	{
		long result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pnXPos, pnYPos);
		return result;
	}
	VARIANT SignatureGetSignData()
	{
		VARIANT result;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	long SignatureScaleToDisplay(long nSensorValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nSensorValue);
		return result;
	}
	long ControlSetLogDirectory(LPCTSTR bstrPath)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrPath);
		return result;
	}
	long DeviceGetIPAddress(BSTR * pbstrAddress, long nIndex)
	{
		long result;
		static BYTE parms[] = VTS_PBSTR VTS_I4 ;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pbstrAddress, nIndex);
		return result;
	}

// Eigenschaften
//

	long GetDisplayWidth()
	{
		long result;
		GetProperty(0x3, VT_I4, (void*)&result);
		return result;
	}
	long GetDisplayHeight()
	{
		long result;
		GetProperty(0x4, VT_I4, (void*)&result);
		return result;
	}
	BOOL GetSignatureState()
	{
		BOOL result;
		GetProperty(0xd, VT_BOOL, (void*)&result);
		return result;
	}
	unsigned long GetControlBackColor()
	{
		unsigned long result;
		GetProperty(0x11, VT_UI4, (void*)&result);
		return result;
	}
	void SetControlBackColor(unsigned long propVal)
	{
		SetProperty(0x11, VT_UI4, propVal);
	}
	unsigned long GetControlPenColor()
	{
		unsigned long result;
		GetProperty(0x14, VT_UI4, (void*)&result);
		return result;
	}
	void SetControlPenColor(unsigned long propVal)
	{
		SetProperty(0x14, VT_UI4, propVal);
	}
	BOOL GetDeviceLedDefaultFlag()
	{
		BOOL result;
		GetProperty(0x19, VT_BOOL, (void*)&result);
		return result;
	}
	void SetDeviceLedDefaultFlag(BOOL propVal)
	{
		SetProperty(0x19, VT_BOOL, propVal);
	}
	short GetControlPenWidth()
	{
		short result;
		GetProperty(0x20, VT_I2, (void*)&result);
		return result;
	}
	void SetControlPenWidth(short propVal)
	{
		SetProperty(0x20, VT_I2, propVal);
	}
	short GetControlMirrorDisplay()
	{
		short result;
		GetProperty(0x24, VT_I2, (void*)&result);
		return result;
	}
	void SetControlMirrorDisplay(short propVal)
	{
		SetProperty(0x24, VT_I2, propVal);
	}
	unsigned long GetControlRectColor()
	{
		unsigned long result;
		GetProperty(0x25, VT_UI4, (void*)&result);
		return result;
	}
	void SetControlRectColor(unsigned long propVal)
	{
		SetProperty(0x25, VT_UI4, propVal);
	}
	CString GetControlAppName()
	{
		CString result;
		GetProperty(0x3c, VT_BSTR, (void*)&result);
		return result;
	}
	void SetControlAppName(CString propVal)
	{
		SetProperty(0x3c, VT_BSTR, propVal);
	}
	long GetDisplayTargetWidth()
	{
		long result;
		GetProperty(0x40, VT_I4, (void*)&result);
		return result;
	}
	long GetDisplayTargetHeight()
	{
		long result;
		GetProperty(0x41, VT_I4, (void*)&result);
		return result;
	}
	long GetDisplayScrollSpeed()
	{
		long result;
		GetProperty(0x42, VT_I4, (void*)&result);
		return result;
	}
	void SetDisplayScrollSpeed(long propVal)
	{
		SetProperty(0x42, VT_I4, propVal);
	}
	CString GetControlVersion()
	{
		CString result;
		GetProperty(0x44, VT_BSTR, (void*)&result);
		return result;
	}
};
