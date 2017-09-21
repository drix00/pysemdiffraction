//Created Date:2016/03/14 09:20
namespace SensorTechnology {
	namespace StCam {
		using namespace System;
		using namespace System::Runtime::InteropServices;
		typedef System::IntPtr HANDLE;
		public delegate void fStCamPreviewBitmapCallbackFunc(unsigned char* pbyteBitmap,unsigned int dwBufferSize, unsigned int dwWidth, unsigned int dwHeight, unsigned int dwFrameNo, unsigned int dwPreviewPixelFormat, System::IntPtr lpContext,System::IntPtr lpReserved);
		public delegate void fStCamRawCallbackFunc(unsigned char* pbyteBuffer,unsigned int dwBufferSize, unsigned int dwWidth, unsigned int dwHeight, unsigned int dwFrameNo,unsigned short wColorArray, unsigned int dwTransferBitsPerPixel, System::IntPtr lpContext,System::IntPtr lpReserved);
		public delegate void fStCamPreviewGDICallbackFunc(System::IntPtr hDC, unsigned int dwWidth, unsigned int dwHeight,  unsigned int dwFrameNo,System::IntPtr lpContext,System::IntPtr lpReserved);
		//------------------------------------------------------------------------------
		//Function
		//------------------------------------------------------------------------------

		//------------------------------------------------------------------------------
		//Initialize
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_Open")]
		extern System::IntPtr Open(unsigned int dwInstance);
		[DllImport("StCamD.dll", EntryPoint="StCam_Close")]
		extern void Close(System::IntPtr hCamera);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetLastError")]
		extern unsigned int GetLastError(System::IntPtr hCamera);
		[DllImport("StCamD.dll", EntryPoint="StCam_CameraCount")]
		extern unsigned int CameraCount();
		[DllImport("StCamD.dll", EntryPoint="StCam_SetReceiveMsgWindow")]
		extern bool SetReceiveMsgWindow(System::IntPtr hCamera, System::IntPtr hWnd);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetUSBSpeed")]
		extern bool GetUSBSpeed(System::IntPtr hCamera, unsigned char% pbyteUSBSpeed);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetUSBMaxSpeed")]
		extern bool GetUSBMaxSpeed(System::IntPtr hCamera, unsigned char% pbyteUSBSpeed);

		//------------------------------------------------------------------------------
		//Image Information
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_GetColorArray")]
		extern bool GetColorArray(System::IntPtr hCamera, unsigned short% pwColorArray);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetEnableTransferBitsPerPixel")]
		extern bool GetEnableTransferBitsPerPixel(System::IntPtr hCamera, unsigned int% pdwEnableTransferBitsPerPixel);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetTransferBitsPerPixel")]
		extern bool SetTransferBitsPerPixel(System::IntPtr hCamera, unsigned int dwTransferBitsPerPixel);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetTransferBitsPerPixel")]
		extern bool GetTransferBitsPerPixel(System::IntPtr hCamera, unsigned int% pdwTransferBitsPerPixel);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMaximumImageSize")]
		extern bool GetMaximumImageSize(System::IntPtr hCamera, unsigned int% pdwMaxWidth, unsigned int% pdwMaxHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetEnableImageSize")]
		extern bool GetEnableImageSize(System::IntPtr hCamera, unsigned int% pdwReserved, unsigned short% pwEnableScanMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetImageSize")]
		extern bool SetImageSize(System::IntPtr hCamera, unsigned int dwReserved, unsigned short wScanMode, unsigned int dwOffsetX, unsigned int dwOffsetY, unsigned int dwWidth, unsigned int dwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetImageSize")]
		extern bool GetImageSize(System::IntPtr hCamera, unsigned int% pdwReserved, unsigned short% pwScanMode, unsigned int% pdwOffsetX, unsigned int% pdwOffsetY, unsigned int% pdwWidth, unsigned int% pdwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetSkippingAndBinning")]
		extern bool GetSkippingAndBinning(System::IntPtr hCamera, unsigned char% pbyteHSkipping, unsigned char% pbyteVSkipping, unsigned char% pbyteHBinning, unsigned char% pbyteVBinning);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetSkippingAndBinning")]
		extern bool SetSkippingAndBinning(System::IntPtr hCamera, unsigned char byteHSkipping, unsigned char byteVSkipping, unsigned char byteHBinning, unsigned char byteVBinning);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetBinningSumMode")]
		extern bool GetBinningSumMode(System::IntPtr hCamera, unsigned short% pwMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetBinningSumMode")]
		extern bool SetBinningSumMode(System::IntPtr hCamera, unsigned short wMode);

		//------------------------------------------------------------------------------
		//Preview
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_StartTransfer")]
		extern bool StartTransfer(System::IntPtr hCamera);
		[DllImport("StCamD.dll", EntryPoint="StCam_StopTransfer")]
		extern bool StopTransfer(System::IntPtr hCamera);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetPreviewPixelFormat")]
		extern bool SetPreviewPixelFormat(System::IntPtr hCamera, unsigned int dwPreviewPixelFormat);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewPixelFormat")]
		extern bool GetPreviewPixelFormat(System::IntPtr hCamera, unsigned int% pdwPreviewPixelFormat);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetEnablePreviewPixelFormat")]
		extern bool GetEnablePreviewPixelFormat(System::IntPtr hCamera, unsigned int% pdwEnablePreviewPixelFormat);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetColorInterpolationMethod")]
		extern bool SetColorInterpolationMethod(System::IntPtr hCamera, unsigned char byteColorInterpolationMethod);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetColorInterpolationMethod")]
		extern bool GetColorInterpolationMethod(System::IntPtr hCamera, unsigned char% pbyteColorInterpolationMethod);
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_CreatePreviewWindowA")]
		extern bool CreatePreviewWindowA(System::IntPtr hCamera, String^ pszWindowName, unsigned int dwStyle, int lngPositionX, int lngPositionY, unsigned int dwWidth, unsigned int dwHeight, System::IntPtr hWndParent, System::IntPtr hMenu, bool bCloseEnable);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_CreatePreviewWindowW")]
		extern bool CreatePreviewWindowW(System::IntPtr hCamera, String^ pszWindowName, unsigned int dwStyle, int lngPositionX, int lngPositionY, unsigned int dwWidth, unsigned int dwHeight, System::IntPtr hWndParent, System::IntPtr hMenu, bool bCloseEnable);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_CreatePreviewWindow")]
		extern bool CreatePreviewWindow(System::IntPtr hCamera, String^ pszWindowName, unsigned int dwStyle, int lngPositionX, int lngPositionY, unsigned int dwWidth, unsigned int dwHeight, System::IntPtr hWndParent, System::IntPtr hMenu, bool bCloseEnable);
		[DllImport("StCamD.dll", EntryPoint="StCam_DestroyPreviewWindow")]
		extern bool DestroyPreviewWindow(System::IntPtr hCamera);
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_SetPreviewWindowNameA")]
		extern bool SetPreviewWindowNameA(System::IntPtr hCamera, String^ pszWindowName);
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_GetPreviewWindowNameA")]
		extern bool GetPreviewWindowNameA(System::IntPtr hCamera, System::Text::StringBuilder^ pszWindowName, int lngMaxCount);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_SetPreviewWindowNameW")]
		extern bool SetPreviewWindowNameW(System::IntPtr hCamera, String^ pszWindowName);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_SetPreviewWindowName")]
		extern bool SetPreviewWindowName(System::IntPtr hCamera, String^ pszWindowName);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_GetPreviewWindowNameW")]
		extern bool GetPreviewWindowNameW(System::IntPtr hCamera, System::Text::StringBuilder^ pszWindowName, int lngMaxCount);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_GetPreviewWindowName")]
		extern bool GetPreviewWindowName(System::IntPtr hCamera, System::Text::StringBuilder^ pszWindowName, int lngMaxCount);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetPreviewMaskSize")]
		extern bool SetPreviewMaskSize(System::IntPtr hCamera, unsigned int dwOffsetX, unsigned int dwOffsetY, unsigned int dwWidth, unsigned int dwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewMaskSize")]
		extern bool GetPreviewMaskSize(System::IntPtr hCamera, unsigned int% pdwOffsetX, unsigned int% pdwOffsetY, unsigned int% pdwWidth, unsigned int% pdwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetPreviewWindowSize")]
		extern bool SetPreviewWindowSize(System::IntPtr hCamera, int lngPositionX, int lngPositionY, unsigned int dwWidth, unsigned int dwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewWindowSize")]
		extern bool GetPreviewWindowSize(System::IntPtr hCamera, int% plngPositionX, int% plngPositionY, unsigned int% pdwWidth, unsigned int% pdwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetPreviewWindowStyle")]
		extern bool SetPreviewWindowStyle(System::IntPtr hCamera, unsigned int dwStyle);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewWindowStyle")]
		extern bool GetPreviewWindowStyle(System::IntPtr hCamera, unsigned int% pdwStyle);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAspectMode")]
		extern bool SetAspectMode(System::IntPtr hCamera, unsigned char byteAspectMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAspectMode")]
		extern bool GetAspectMode(System::IntPtr hCamera, unsigned char% pbyteAspectMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetPreviewDestSize")]
		extern bool SetPreviewDestSize(System::IntPtr hCamera, unsigned int dwOffsetX, unsigned int dwOffsetY, unsigned int dwWidth, unsigned int dwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewDestSize")]
		extern bool GetPreviewDestSize(System::IntPtr hCamera, unsigned int% pdwOffsetX, unsigned int% pdwOffsetY, unsigned int% pdwWidth, unsigned int% pdwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetMagnificationMode")]
		extern bool SetMagnificationMode(System::IntPtr hCamera, unsigned char byteMagnificationMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMagnificationMode")]
		extern bool GetMagnificationMode(System::IntPtr hCamera, unsigned char% pbyteMagnificationMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDCWithReset")]
		extern bool GetDCWithReset(System::IntPtr hCamera, System::IntPtr% phDC);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDC")]
		extern bool GetDC(System::IntPtr hCamera, System::IntPtr% phDC);
		[DllImport("StCamD.dll", EntryPoint="StCam_ReleaseDC")]
		extern bool ReleaseDC(System::IntPtr hCamera, System::IntPtr hDC);
		[DllImport("StCamD.dll", EntryPoint="StCam_ResetOverlay")]
		extern bool ResetOverlay(System::IntPtr hCamera);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetColorKey")]
		extern bool SetColorKey(System::IntPtr hCamera, unsigned int dwColorKey);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetColorKey")]
		extern bool GetColorKey(System::IntPtr hCamera, unsigned int% pdwColorKey);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetDisplayMode")]
		extern bool SetDisplayMode(System::IntPtr hCamera, unsigned char byteDisplayMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDisplayMode")]
		extern bool GetDisplayMode(System::IntPtr hCamera, unsigned char% pbyteDisplayMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAlphaChannel")]
		extern bool GetAlphaChannel(System::IntPtr hCamera, unsigned char% pbyteAlphaChannel);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAlphaChannel")]
		extern bool SetAlphaChannel(System::IntPtr hCamera, unsigned char byteAlphaChannel);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewImagePixelValue")]
		extern bool GetPreviewImagePixelValue(System::IntPtr hCamera, unsigned int nX, unsigned int nY, unsigned int% pdwColor);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewWnd")]
		extern bool GetPreviewWnd(System::IntPtr hCamera, System::IntPtr% hWnd);

		//------------------------------------------------------------------------------
		//Image Acquisition
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_TakeRawSnapShot")]
		extern bool TakeRawSnapShot(System::IntPtr hCamera, System::IntPtr pbyteBuffer, unsigned int dwBufferSize, unsigned int% pdwNumberOfByteTrans, unsigned int* pdwFrameNo, unsigned int dwMilliseconds);
		[DllImport("StCamD.dll", EntryPoint="StCam_TakePreviewSnapShot")]
		extern bool TakePreviewSnapShot(System::IntPtr hCamera, System::IntPtr pbyteBuffer, unsigned int dwBufferSize, unsigned int% pdwNumberOfByteTrans, unsigned int* pdwFrameNo, unsigned int dwMilliseconds);
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_SaveImageA")]
		extern bool SaveImageA(System::IntPtr hCamera, unsigned int dwWidth, unsigned int dwHeight, unsigned int dwPreviewPixelFormat, System::IntPtr pbyteData, String^ pszFileName, unsigned int dwParam);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_SaveImageW")]
		extern bool SaveImageW(System::IntPtr hCamera, unsigned int dwWidth, unsigned int dwHeight, unsigned int dwPreviewPixelFormat, System::IntPtr pbyteData, String^ pszFileName, unsigned int dwParam);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_SaveImage")]
		extern bool SaveImage(System::IntPtr hCamera, unsigned int dwWidth, unsigned int dwHeight, unsigned int dwPreviewPixelFormat, System::IntPtr pbyteData, String^ pszFileName, unsigned int dwParam);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetRawDataSize")]
		extern bool GetRawDataSize(System::IntPtr hCamera, unsigned int% pdwSize);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewDataSize")]
		extern bool GetPreviewDataSize(System::IntPtr hCamera, unsigned int% pdwSize, unsigned int% pdwWidth, unsigned int% pdwHeight, unsigned int% pdwLinePitch);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetROI")]
		extern bool SetROI(System::IntPtr hCamera, unsigned int dwIndex, unsigned int dwMode, unsigned int dwOffsetX, unsigned int dwOffsetY, unsigned int dwWidth, unsigned int dwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetROI")]
		extern bool GetROI(System::IntPtr hCamera, unsigned int dwIndex, unsigned int% pdwMode, unsigned int% pdwOffsetX, unsigned int% pdwOffsetY, unsigned int% pdwWidth, unsigned int% pdwHeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMaxROICount")]
		extern bool GetMaxROICount(System::IntPtr hCamera, unsigned int% pdwRegionCount);

		//------------------------------------------------------------------------------
		//Shutter Gain Control
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_GetALCMode")]
		extern bool GetALCMode(System::IntPtr hCamera, unsigned char% pbyteAlcMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetALCMode")]
		extern bool SetALCMode(System::IntPtr hCamera, unsigned char byteAlcMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetExposureClock")]
		extern bool GetExposureClock(System::IntPtr hCamera, unsigned int% pdwExposureClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetExposureClock")]
		extern bool SetExposureClock(System::IntPtr hCamera, unsigned int dwExposureClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMaxShortExposureClock")]
		extern bool GetMaxShortExposureClock(System::IntPtr hCamera, unsigned int% pdwMaximumExpClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMaxLongExposureClock")]
		extern bool GetMaxLongExposureClock(System::IntPtr hCamera, unsigned int% pdwMaximumExpClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetExposureTimeFromClock")]
		extern bool GetExposureTimeFromClock(System::IntPtr hCamera, unsigned int dwExposureClock, float% pfExpTime);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetExposureClockFromTime")]
		extern bool GetExposureClockFromTime(System::IntPtr hCamera, float fExpTime, unsigned int% pdwExposureClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetGain")]
		extern bool GetGain(System::IntPtr hCamera, unsigned short% pwGain);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetGain")]
		extern bool SetGain(System::IntPtr hCamera, unsigned short wGain);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMaxGain")]
		extern bool GetMaxGain(System::IntPtr hCamera, unsigned short% pwMaxGain);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetGainDBFromSettingValue")]
		extern bool GetGainDBFromSettingValue(System::IntPtr hCamera, unsigned short wGain, float% pfGainDB);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetTargetBrightness")]
		extern bool GetTargetBrightness(System::IntPtr hCamera, unsigned char% pbyteTargetBrightness, unsigned char% pbyteTolerance, unsigned char% pbyteThreshold);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetTargetBrightness")]
		extern bool SetTargetBrightness(System::IntPtr hCamera, unsigned char byteTargetBrightness, unsigned char byteTolerance, unsigned char byteThreshold);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetALCWeight")]
		extern bool GetALCWeight(System::IntPtr hCamera, unsigned char* pbyteALCWeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetALCWeight")]
		extern bool SetALCWeight(System::IntPtr hCamera, unsigned char* pbyteALCWeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAEMinExposureClock")]
		extern bool SetAEMinExposureClock(System::IntPtr hCamera, unsigned int dwMinExposureClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAEMinExposureClock")]
		extern bool GetAEMinExposureClock(System::IntPtr hCamera, unsigned int% pdwMinExposureClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAEMaxExposureClock")]
		extern bool GetAEMaxExposureClock(System::IntPtr hCamera, unsigned int% pdwMaxExposureClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAEMaxExposureClock")]
		extern bool SetAEMaxExposureClock(System::IntPtr hCamera, unsigned int dwMaxExposureClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetALCControlSpeed")]
		extern bool SetALCControlSpeed(System::IntPtr hCamera, unsigned char byteShutterCtrlSpeedLimit, unsigned char byteGainCtrlSpeedLimit, unsigned char byteSkipFrameCount, unsigned char byteAverageFrameCount);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetALCControlSpeed")]
		extern bool GetALCControlSpeed(System::IntPtr hCamera, unsigned char% pbyteShutterCtrlSpeedLimit, unsigned char% pbyteGainCtrlSpeedLimit, unsigned char% pbyteSkipFrameCount, unsigned char% pbyteAverageFrameCount);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetGainControlRange")]
		extern bool GetGainControlRange(System::IntPtr hCamera, unsigned short% pwMinGain, unsigned short% pwMaxGain);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetGainControlRange")]
		extern bool SetGainControlRange(System::IntPtr hCamera, unsigned short wMinGain, unsigned short wMaxGain);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDigitalGain")]
		extern bool GetDigitalGain(System::IntPtr hCamera, unsigned short% pwDigitalGain);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetDigitalGain")]
		extern bool SetDigitalGain(System::IntPtr hCamera, unsigned short wDigitalGain);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMaxDigitalGain")]
		extern bool GetMaxDigitalGain(System::IntPtr hCamera, unsigned short% pwMaxDigitalGain);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDigitalGainTimesFromSettingValue")]
		extern bool GetDigitalGainTimesFromSettingValue(System::IntPtr hCamera, unsigned short wDigitalGain, float% pfDigitalGainTimes);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDigitalGainSettingValueFromGainTimes")]
		extern bool GetDigitalGainSettingValueFromGainTimes(System::IntPtr hCamera, float fDigitalGainTimes, unsigned short% pwDigitalGain);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetShutterSpeed")]
		extern bool GetShutterSpeed(System::IntPtr hCamera, unsigned short% pwShutterLine, unsigned short% pwShutterClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetShutterSpeed")]
		extern bool SetShutterSpeed(System::IntPtr hCamera, unsigned short wShutterLine, unsigned short wShutterClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetShutterControlRange")]
		extern bool GetShutterControlRange(System::IntPtr hCamera, unsigned short% pwMinShutterLine, unsigned short% pwMinShutterClock, unsigned short% pwMaxShutterLine, unsigned short% pwMaxShutterClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetShutterControlRange")]
		extern bool SetShutterControlRange(System::IntPtr hCamera, unsigned short wMinShutterLine, unsigned short wMinShutterClock, unsigned short wMaxShutterLine, unsigned short wMaxShutterClock);

		//------------------------------------------------------------------------------
		//White Balance Control
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_SetWhiteBalanceMode")]
		extern bool SetWhiteBalanceMode(System::IntPtr hCamera, unsigned char byteWBMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetWhiteBalanceMode")]
		extern bool GetWhiteBalanceMode(System::IntPtr hCamera, unsigned char% pbyteWBMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetWhiteBalanceGain")]
		extern bool SetWhiteBalanceGain(System::IntPtr hCamera, unsigned short wWBGainR, unsigned short wWBGainGr, unsigned short wWBGainGb, unsigned short wWBGainB);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetWhiteBalanceGain")]
		extern bool GetWhiteBalanceGain(System::IntPtr hCamera, unsigned short% pwWBGainR, unsigned short% pwWBGainGr, unsigned short% pwWBGainGb, unsigned short% pwWBGainB);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetWhiteBalanceTarget")]
		extern bool SetWhiteBalanceTarget(System::IntPtr hCamera, unsigned short wAWBTargetR, unsigned short wAWBTargetB);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetWhiteBalanceTarget")]
		extern bool GetWhiteBalanceTarget(System::IntPtr hCamera, unsigned short% pwAWBTargetR, unsigned short% pwAWBTargetB);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetWhiteBalanceToleranceThreshold")]
		extern bool SetWhiteBalanceToleranceThreshold(System::IntPtr hCamera, unsigned short wAWBTolerance, unsigned short wAWBThreshold);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetWhiteBalanceToleranceThreshold")]
		extern bool GetWhiteBalanceToleranceThreshold(System::IntPtr hCamera, unsigned short% pwAWBTolerance, unsigned short% pwAWBThreshold);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAWBWeight")]
		extern bool SetAWBWeight(System::IntPtr hCamera, unsigned char* pbyteAWBWeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAWBWeight")]
		extern bool GetAWBWeight(System::IntPtr hCamera, unsigned char* pbyteAWBWeight);
		[DllImport("StCamD.dll", EntryPoint="StCam_RawWhiteBalance")]
		extern bool RawWhiteBalance(System::IntPtr hCamera, unsigned int dwWidth, unsigned int dwHeight, unsigned short wColorArray, System::IntPtr pbyteRaw);

		//------------------------------------------------------------------------------
		//Gamma
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_SetGammaMode")]
		extern bool SetGammaMode(System::IntPtr hCamera, unsigned char byteGammaTarget, unsigned char byteGammaMode, unsigned short wGamma, unsigned char* pbyteGammaTable);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetGammaMode")]
		extern bool GetGammaMode(System::IntPtr hCamera, unsigned char byteGammaTarget, unsigned char% pbyteGammaMode, unsigned short% pwGamma, unsigned char* pbyteGammaTable);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetGammaModeEx")]
		extern bool SetGammaModeEx(System::IntPtr hCamera, unsigned char byteGammaTarget, unsigned char byteGammaMode, unsigned short wGamma, short shtBrightness, unsigned char byteContrast, unsigned char* pbyteGammaTable);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetGammaModeEx")]
		extern bool GetGammaModeEx(System::IntPtr hCamera, unsigned char byteGammaTarget, unsigned char% pbyteGammaMode, unsigned short% pwGamma, short% pshtBrightness, unsigned char% pbyteContrast, unsigned char* pbyteGammaTable);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetCameraGammaValue")]
		extern bool GetCameraGammaValue(System::IntPtr hCamera, unsigned short% pwValue);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetCameraGammaValue")]
		extern bool SetCameraGammaValue(System::IntPtr hCamera, unsigned short wValue);

		//------------------------------------------------------------------------------
		//Sharpness
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_SetSharpnessMode")]
		extern bool SetSharpnessMode(System::IntPtr hCamera, unsigned char byteSharpnessMode, unsigned short wSharpnessGain, unsigned char byteSharpnessCoring);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetSharpnessMode")]
		extern bool GetSharpnessMode(System::IntPtr hCamera, unsigned char% pbyteSharpnessMode, unsigned short% pwSharpnessGain, unsigned char% pbyteSharpnessCoring);

		//------------------------------------------------------------------------------
		//Hue Saturation
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_SetHueSaturationMode")]
		extern bool SetHueSaturationMode(System::IntPtr hCamera, unsigned char byteHueSaturationMode, short shtHue, unsigned short wSaturation);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetHueSaturationMode")]
		extern bool GetHueSaturationMode(System::IntPtr hCamera, unsigned char% pbyteHueSaturationMode, short% pshtHue, unsigned short% pwSaturation);

		//------------------------------------------------------------------------------
		//Color Matrix
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_SetColorMatrix")]
		extern bool SetColorMatrix(System::IntPtr hCamera, unsigned char byteColorMatrixMode, short* pshtColorMatrix);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetColorMatrix")]
		extern bool GetColorMatrix(System::IntPtr hCamera, unsigned char% pbyteColorMatrixMode, short* pshtColorMatrix);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetHighChromaSuppression")]
		extern bool SetHighChromaSuppression(System::IntPtr hCamera, unsigned short wStartLevel, unsigned short wSuppression);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetLowChromaSuppression")]
		extern bool SetLowChromaSuppression(System::IntPtr hCamera, unsigned short wStartLevel, unsigned short wSuppression);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetHighChromaSuppression")]
		extern bool GetHighChromaSuppression(System::IntPtr hCamera, unsigned short% pwStartLevel, unsigned short% pwSuppression);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetLowChromaSuppression")]
		extern bool GetLowChromaSuppression(System::IntPtr hCamera, unsigned short% pwStartLevel, unsigned short% pwSuppression);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetChromaSuppression")]
		extern bool SetChromaSuppression(System::IntPtr hCamera, unsigned short wStartLevel, unsigned short wSuppression);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetChromaSuppression")]
		extern bool GetChromaSuppression(System::IntPtr hCamera, unsigned short% pwStartLevel, unsigned short% pwSuppression);

		//------------------------------------------------------------------------------
		//Shading Correction
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_SetShadingCorrectionMode")]
		extern bool SetShadingCorrectionMode(System::IntPtr hCamera, unsigned int dwMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetShadingCorrectionMode")]
		extern bool GetShadingCorrectionMode(System::IntPtr hCamera, unsigned int% pdwMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetShadingCorrectionTarget")]
		extern bool SetShadingCorrectionTarget(System::IntPtr hCamera, unsigned short wTarget);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetShadingCorrectionTarget")]
		extern bool GetShadingCorrectionTarget(System::IntPtr hCamera, unsigned short% wTarget);

		//------------------------------------------------------------------------------
		//Mirro Rotation
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_GetEnableMirrorMode")]
		extern bool GetEnableMirrorMode(System::IntPtr hCamera, unsigned char% pbyteMirrorMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetMirrorMode")]
		extern bool SetMirrorMode(System::IntPtr hCamera, unsigned char byteMirrorMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMirrorMode")]
		extern bool GetMirrorMode(System::IntPtr hCamera, unsigned char% pbyteMirrorMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetRotationMode")]
		extern bool SetRotationMode(System::IntPtr hCamera, unsigned char byteRotationMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetRotationMode")]
		extern bool GetRotationMode(System::IntPtr hCamera, unsigned char% pbyteRotationMode);

		//------------------------------------------------------------------------------
		//Movie
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_SaveAVIA")]
		extern bool SaveAVIA(System::IntPtr hCamera, String^ pszFileName, unsigned int dwCompressor, unsigned int dwLength, System::IntPtr lpReserved);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_SaveAVIW")]
		extern bool SaveAVIW(System::IntPtr hCamera, String^ pszFileName, unsigned int dwCompressor, unsigned int dwLength, System::IntPtr lpReserved);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_SaveAVI")]
		extern bool SaveAVI(System::IntPtr hCamera, String^ pszFileName, unsigned int dwCompressor, unsigned int dwLength, System::IntPtr lpReserved);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAVIStatus")]
		extern bool SetAVIStatus(System::IntPtr hCamera, unsigned char byteAVIStatus);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAVIStatus")]
		extern bool GetAVIStatus(System::IntPtr hCamera, unsigned char% pbyteAVIStatus, unsigned int% pdwTotalFrameCounts, unsigned int% pdwCurrentFrameCounts);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAVIQuality")]
		extern bool SetAVIQuality(System::IntPtr hCamera, unsigned int dwQuality);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAVIQuality")]
		extern bool GetAVIQuality(System::IntPtr hCamera, unsigned int% pdwQuality);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAVIPriorityFileFormat")]
		extern bool SetAVIPriorityFileFormat(System::IntPtr hCamera, unsigned int dwFileFormat);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAVIPriorityFileFormat")]
		extern bool GetAVIPriorityFileFormat(System::IntPtr hCamera, unsigned int% pdwFileFormat);

		//------------------------------------------------------------------------------
		//Clock
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_GetEnableClock")]
		extern bool GetEnableClock(System::IntPtr hCamera, unsigned int% pdwEnableClockMode, unsigned int% pdwStandardClock, unsigned int% pdwMinimumClock, unsigned int% pdwMaximumClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetClock")]
		extern bool SetClock(System::IntPtr hCamera, unsigned int dwClockMode, unsigned int dwClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetClock")]
		extern bool GetClock(System::IntPtr hCamera, unsigned int% pdwClockMode, unsigned int% pdwClock);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetFrameClock")]
		extern bool GetFrameClock(System::IntPtr hCamera, unsigned short% pwCurrentLinePerFrame, unsigned short% pwCurrentClockPerLine);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetOutputFPS")]
		extern bool GetOutputFPS(System::IntPtr hCamera, float% pfFPS);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetVBlankForFPS")]
		extern bool SetVBlankForFPS(System::IntPtr hCamera, unsigned int dwVLines);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetVBlankForFPS")]
		extern bool GetVBlankForFPS(System::IntPtr hCamera, unsigned int% pdwVLines);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMaxVBlankForFPS")]
		extern bool GetMaxVBlankForFPS(System::IntPtr hCamera, unsigned int% pdwVLines);

		//------------------------------------------------------------------------------
		//IOPin
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDeviceTemperature")]
		extern bool GetDeviceTemperature(System::IntPtr hCamera, unsigned int dwSelector, int% pnValue);

		//------------------------------------------------------------------------------
		//Defect pixel correction
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_GetEnableDefectPixelCorrectionCount")]
		extern bool GetEnableDefectPixelCorrectionCount(System::IntPtr hCamera, unsigned short% pwCount);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDefectPixelCorrectionMode")]
		extern bool GetDefectPixelCorrectionMode(System::IntPtr hCamera, unsigned short% pwMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetDefectPixelCorrectionMode")]
		extern bool SetDefectPixelCorrectionMode(System::IntPtr hCamera, unsigned short wMode);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDefectPixelCorrectionPosition")]
		extern bool GetDefectPixelCorrectionPosition(System::IntPtr hCamera, unsigned short wIndex, unsigned int% pdwX, unsigned int% pdwY);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetDefectPixelCorrectionPosition")]
		extern bool SetDefectPixelCorrectionPosition(System::IntPtr hCamera, unsigned short wIndex, unsigned int dwX, unsigned int dwY);
		[DllImport("StCamD.dll", EntryPoint="StCam_DetectDefectPixel")]
		extern bool DetectDefectPixel(System::IntPtr hCamera, unsigned int dwWidth, unsigned int dwHeight, System::IntPtr pbyteRaw, unsigned short wThreshold);

		//------------------------------------------------------------------------------
		//HDR
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_GetHDRType")]
		extern bool GetHDRType(System::IntPtr hCamera, unsigned int% pdwHDRType);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetHDRParameter")]
		extern bool SetHDRParameter(System::IntPtr hCamera, unsigned int* pdwBuffer, unsigned int dwSize);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetHDRParameter")]
		extern bool GetHDRParameter(System::IntPtr hCamera, unsigned int* pdwBuffer, unsigned int% pdwSize);

		//------------------------------------------------------------------------------
		//Callback Function
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_AddPreviewBitmapCallback")]
		extern bool AddPreviewBitmapCallback(System::IntPtr hCamera, fStCamPreviewBitmapCallbackFunc^ pPreviewBitmapCallbackFunc, System::IntPtr pContext, unsigned int% pdwPreviewBitmapCallbackNo);
		[DllImport("StCamD.dll", EntryPoint="StCam_RemovePreviewBitmapCallback")]
		extern bool RemovePreviewBitmapCallback(System::IntPtr hCamera, unsigned int dwPreviewBitmapCallbackNo);
		[DllImport("StCamD.dll", EntryPoint="StCam_RemoveAllPreviewBitmapCallback")]
		extern bool RemoveAllPreviewBitmapCallback(System::IntPtr hCamera);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewBitmapCallbackCount")]
		extern bool GetPreviewBitmapCallbackCount(System::IntPtr hCamera, unsigned int% pdwListCount);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewBitmapCallback")]
		extern bool GetPreviewBitmapCallback(System::IntPtr hCamera, unsigned int dwCallbackIndex, fStCamPreviewBitmapCallbackFunc^% ppPreviewBitmapCallbackFunc, unsigned int% pdwCallbackFunctionNo);
		[DllImport("StCamD.dll", EntryPoint="StCam_AddPreviewGDICallback")]
		extern bool AddPreviewGDICallback(System::IntPtr hCamera, fStCamPreviewGDICallbackFunc^ pPreviewGDICallbackFunc, System::IntPtr pContext, unsigned int% pdwPreviewGDICallbackNo);
		[DllImport("StCamD.dll", EntryPoint="StCam_RemovePreviewGDICallback")]
		extern bool RemovePreviewGDICallback(System::IntPtr hCamera, unsigned int dwPreviewGDICallbackNo);
		[DllImport("StCamD.dll", EntryPoint="StCam_RemoveAllPreviewGDICallback")]
		extern bool RemoveAllPreviewGDICallback(System::IntPtr hCamera);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewGDICallbackCount")]
		extern bool GetPreviewGDICallbackCount(System::IntPtr hCamera, unsigned int% pdwListCount);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetPreviewGDICallback")]
		extern bool GetPreviewGDICallback(System::IntPtr hCamera, unsigned int dwCallbackIndex, fStCamPreviewGDICallbackFunc^% ppPreviewGDICallbackFunc, unsigned int% pdwCallbackFunctionNo);
		[DllImport("StCamD.dll", EntryPoint="StCam_AddRawCallback")]
		extern bool AddRawCallback(System::IntPtr hCamera, fStCamRawCallbackFunc^ pRawCallbackFunc, System::IntPtr pContext, unsigned int% pdwRawCallbackNo);
		[DllImport("StCamD.dll", EntryPoint="StCam_RemoveRawCallback")]
		extern bool RemoveRawCallback(System::IntPtr hCamera, unsigned int dwRawCallbackNo);
		[DllImport("StCamD.dll", EntryPoint="StCam_RemoveAllRawCallback")]
		extern bool RemoveAllRawCallback(System::IntPtr hCamera);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetRawCallbackCount")]
		extern bool GetRawCallbackCount(System::IntPtr hCamera, unsigned int% pdwListCount);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetRawCallback")]
		extern bool GetRawCallback(System::IntPtr hCamera, unsigned int dwCallbackIndex, fStCamRawCallbackFunc^% ppRawCallbackFunc, unsigned int% pdwCallbackFunctionNo);

		//------------------------------------------------------------------------------
		//Setting
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_SaveSettingFileA")]
		extern bool SaveSettingFileA(System::IntPtr hCamera, String^ pszFileName);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_SaveSettingFileW")]
		extern bool SaveSettingFileW(System::IntPtr hCamera, String^ pszFileName);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_SaveSettingFile")]
		extern bool SaveSettingFile(System::IntPtr hCamera, String^ pszFileName);
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_LoadSettingFileA")]
		extern bool LoadSettingFileA(System::IntPtr hCamera, String^ pszFileName);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_LoadSettingFileW")]
		extern bool LoadSettingFileW(System::IntPtr hCamera, String^ pszFileName);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_LoadSettingFile")]
		extern bool LoadSettingFile(System::IntPtr hCamera, String^ pszFileName);
		[DllImport("StCamD.dll", EntryPoint="StCam_ResetSetting")]
		extern bool ResetSetting(System::IntPtr hCamera);
		[DllImport("StCamD.dll", EntryPoint="StCam_CameraSetting")]
		extern bool CameraSetting(System::IntPtr hCamera, unsigned short wMode);

		//------------------------------------------------------------------------------
		//EEPROM
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_ReadUserMemory")]
		extern bool ReadUserMemory(System::IntPtr hCamera, unsigned char* pbyteBuffer, unsigned short wOffset, unsigned short wLength);
		[DllImport("StCamD.dll", EntryPoint="StCam_WriteUserMemory")]
		extern bool WriteUserMemory(System::IntPtr hCamera, unsigned char* pbyteBuffer, unsigned short wOffset, unsigned short wLength);
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_ReadCameraUserIDA")]
		extern bool ReadCameraUserIDA(System::IntPtr hCamera, unsigned int% pdwCameraID, System::Text::StringBuilder^ pszBuffer, unsigned int dwBufferSize);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_ReadCameraUserIDW")]
		extern bool ReadCameraUserIDW(System::IntPtr hCamera, unsigned int% pdwCameraID, System::Text::StringBuilder^ pszBuffer, unsigned int dwBufferSize);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_ReadCameraUserID")]
		extern bool ReadCameraUserID(System::IntPtr hCamera, unsigned int% pdwCameraID, System::Text::StringBuilder^ pszBuffer, unsigned int dwBufferSize);
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_WriteCameraUserIDA")]
		extern bool WriteCameraUserIDA(System::IntPtr hCamera, unsigned int dwCameraID, String^ pszBuffer, unsigned int dwBufferSize);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_WriteCameraUserIDW")]
		extern bool WriteCameraUserIDW(System::IntPtr hCamera, unsigned int dwCameraID, String^ pszBuffer, unsigned int dwBufferSize);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_WriteCameraUserID")]
		extern bool WriteCameraUserID(System::IntPtr hCamera, unsigned int dwCameraID, String^ pszBuffer, unsigned int dwBufferSize);

		//------------------------------------------------------------------------------
		//Version Information
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", CharSet=CharSet::Ansi, EntryPoint="StCam_GetProductNameA")]
		extern bool GetProductNameA(System::IntPtr hCamera, System::Text::StringBuilder^ pszCameraName, unsigned int dwBufferSize);
		[DllImport("StCamD.dll", CharSet=CharSet::Unicode, EntryPoint="StCam_GetProductNameW")]
		extern bool GetProductNameW(System::IntPtr hCamera, System::Text::StringBuilder^ pszCameraName, unsigned int dwBufferSize);
		[DllImport("StCamD.dll", CharSet=CharSet::Auto, EntryPoint="StCam_GetProductName")]
		extern bool GetProductName(System::IntPtr hCamera, System::Text::StringBuilder^ pszCameraName, unsigned int dwBufferSize);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetCameraVersion")]
		extern bool GetCameraVersion(System::IntPtr hCamera, unsigned short% pwUSBVendorID, unsigned short% pwUSBProductID, unsigned short% pwFPGAVersion, unsigned short% pwFirmVersion);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDriverVersion")]
		extern bool GetDriverVersion(System::IntPtr hCamera, unsigned int% pdwFileVersionMS, unsigned int% pdwFileVersionLS, unsigned int% pdwProductVersionMS, unsigned int% pdwProductVersionLS);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetUSBDllVersion")]
		extern bool GetUSBDllVersion(unsigned int% pdwFileVersionMS, unsigned int% pdwFileVersionLS, unsigned int% pdwProductVersionMS, unsigned int% pdwProductVersionLS);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetCAMDllVersion")]
		extern bool GetCAMDllVersion(unsigned int% pdwFileVersionMS, unsigned int% pdwFileVersionLS, unsigned int% pdwProductVersionMS, unsigned int% pdwProductVersionLS);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetUSBFunctionAddress")]
		extern bool GetUSBFunctionAddress(System::IntPtr hCamera, unsigned char% pbyteUSBFunctionAddress);
		[DllImport("StCamD.dll", EntryPoint="StCam_HasFunction")]
		extern bool HasFunction(System::IntPtr hCamera, unsigned int dwCameraFunctionID, bool% pbHasFunction);

		//------------------------------------------------------------------------------
		//Other
		//------------------------------------------------------------------------------
		[DllImport("StCamD.dll", EntryPoint="StCam_ConvertBitmapBGR24ToRGB24")]
		extern bool ConvertBitmapBGR24ToRGB24(System::IntPtr hCamera, unsigned int dwWidth, unsigned int dwHeight, System::IntPtr pbyteBitmap);
		[DllImport("StCamD.dll", EntryPoint="StCam_ConvertRawToBGR")]
		extern bool ConvertRawToBGR(System::IntPtr hCamera, unsigned int dwWidth, unsigned int dwHeight, System::IntPtr pbyteSrcRaw, System::IntPtr pbyteDstBGR, unsigned char byteColorInterpolationMethod, unsigned int dwPreviewPixelFormat);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetControlArea")]
		extern bool SetControlArea(System::IntPtr hCamera, unsigned short* pwSepalateX, unsigned short* pwSepalateY);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetControlArea")]
		extern bool GetControlArea(System::IntPtr hCamera, unsigned short* pwSepalateX, unsigned short* pwSepalateY);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetDigitalClamp")]
		extern bool GetDigitalClamp(System::IntPtr hCamera, unsigned short% pwValue);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetDigitalClamp")]
		extern bool SetDigitalClamp(System::IntPtr hCamera, unsigned short wValue);
		[DllImport("StCamD.dll", EntryPoint="StCam_ResetRootHub")]
		extern bool ResetRootHub();
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAnalogBlackLevel")]
		extern bool SetAnalogBlackLevel(System::IntPtr hCamera, unsigned short wBlackLevel);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAnalogBlackLevel")]
		extern bool GetAnalogBlackLevel(System::IntPtr hCamera, unsigned short% pwBlackLevel);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMaxAnalogBlackLevel")]
		extern bool GetMaxAnalogBlackLevel(System::IntPtr hCamera, unsigned short% pwBlackLevel);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetMaxDigitalClamp")]
		extern bool GetMaxDigitalClamp(System::IntPtr hCamera, unsigned short% pwDigitalClamp);
		[DllImport("StCamD.dll", EntryPoint="StCam_SetAdjustmentMode")]
		extern bool SetAdjustmentMode(System::IntPtr hCamera, unsigned int dwValue);
		[DllImport("StCamD.dll", EntryPoint="StCam_GetAdjustmentMode")]
		extern bool GetAdjustmentMode(System::IntPtr hCamera, unsigned int% pdwValue);
		//------------------------------------------------------------------------------
		//Const
		//------------------------------------------------------------------------------

		//------------------------------------------------------------------------------
		//ERROR_STCAM
		//------------------------------------------------------------------------------
		const unsigned int ERRST_NOT_FOUND_CAMERA = 0xE0000001;
		const unsigned int ERRST_ALL_CAMARA_OPENED = 0xE0000002;
		const unsigned int ERRST_INVALID_CAMERA_HANDLE = 0xE0000003;
		const unsigned int ERRST_INVALID_FUNCTION_RECEIVING = 0xE0000004;
		const unsigned int ERRST_USB_COMMAND_TRANSFER = 0xE0000005;
		const unsigned int ERRST_WINDOW_ALREADY_EXISTS = 0xE0000006;
		const unsigned int ERRST_WINDOW_DOES_NOT_EXISTS = 0xE0000007;
		const unsigned int ERRST_INVALID_FUNCTION_RECORDING = 0xE0000008;
		const unsigned int ERRST_AVI_STREAM = 0xE0000009;
		const unsigned int ERRST_AVI_NOCOMPRESSOR = 0xE000000A;
		const unsigned int ERRST_AVI_UNSUPPORTED = 0xE000000B;
		const unsigned int ERRST_AVI_DISK = 0xE000000C;
		const unsigned int ERRST_AVI_CANCELED = 0xE000000D;
		const unsigned int ERRST_AVI_WRITE = 0xE000000E;
		const unsigned int ERRST_INVALID_FILE_NAME = 0xE000000F;
		const unsigned int ERRST_FILE_OPEN = 0xE0000010;
		const unsigned int ERRST_FILE_WRITE = 0xE0000011;
		const unsigned int ERRST_NOT_SUPPORTED_FUNCTION = 0xE0000021;

		//------------------------------------------------------------------------------
		//WM_STCAM
		//------------------------------------------------------------------------------
		const int WM_STCAM_TRANSFER_START = 0xB001;
		const int WM_STCAM_TRANSFER_FINISH = 0xB002;
		const int WM_STCAM_PREVIEW_WINDOW_CREATE = 0xB003;
		const int WM_STCAM_PREVIEW_WINDOW_CLOSE = 0xB004;
		const int WM_STCAM_PREVIEW_WINDOW_RESIZE = 0xB005;
		const int WM_STCAM_PREVIEW_MASK_RESIZE = 0xB006;
		const int WM_STCAM_PREVIEW_DEST_RESIZE = 0xB007;
		const int WM_STCAM_AVI_FILE_START = 0xB008;
		const int WM_STCAM_AVI_FILE_FINISH = 0xB009;
		const int WM_STCAM_PREVIEW_MENU_COMMAND = 0xB00A;
		const int WM_STCAM_UPDATED_PREVIEW_IMAGE = 0xB00B;

		//------------------------------------------------------------------------------
		//COLOR_ARRAY
		//------------------------------------------------------------------------------
		const unsigned short STCAM_COLOR_ARRAY_MONO = 0x0001;
		const unsigned short STCAM_COLOR_ARRAY_RGGB = 0x0002;
		const unsigned short STCAM_COLOR_ARRAY_GRBG = 0x0003;
		const unsigned short STCAM_COLOR_ARRAY_GBRG = 0x0004;
		const unsigned short STCAM_COLOR_ARRAY_BGGR = 0x0005;

		//------------------------------------------------------------------------------
		//TRANSER_BITS_PER_PIXEL
		//------------------------------------------------------------------------------
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_RAW_08 = 0x00000001;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_RAW_10 = 0x00000002;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_RAW_10P = 0x00010000;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_RAW_12 = 0x00000004;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_RAW_12P = 0x00020000;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_RAW_14 = 0x00000008;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_RAW_16 = 0x00000010;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_MONO_08 = 0x00000020;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_MONO_10 = 0x00000040;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_MONO_10P = 0x00100000;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_MONO_12 = 0x00000080;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_MONO_12P = 0x00200000;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_MONO_14 = 0x00000100;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_MONO_16 = 0x00000200;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_BGR_08 = 0x00000400;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_BGR_10 = 0x00000800;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_YCBCR411_08 = 0x00001000;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_YCBCR422_08 = 0x00002000;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_YCBCR444_08 = 0x00004000;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_08 = 0x00000001;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_10 = 0x00000002;
		const unsigned int STCAM_TRANSFER_BITS_PER_PIXEL_12 = 0x00000004;
		const unsigned int STCAM_TRANSER_BITS_PER_PIXEL_08 = 0x00000001;
		const unsigned int STCAM_TRANSER_BITS_PER_PIXEL_16 = 0x00000002;

		//------------------------------------------------------------------------------
		//IMAGE_SIZE_MODE
		//------------------------------------------------------------------------------
		const unsigned int STCAM_IMAGE_SIZE_MODE_CUSTOM = 0x00000001;
		const unsigned int STCAM_IMAGE_SIZE_MODE_VGA = 0x00000008;
		const unsigned int STCAM_IMAGE_SIZE_MODE_XGA = 0x00000020;
		const unsigned int STCAM_IMAGE_SIZE_MODE_QUAD_VGA = 0x00000080;
		const unsigned int STCAM_IMAGE_SIZE_MODE_SXGA = 0x00000100;
		const unsigned int STCAM_IMAGE_SIZE_MODE_UXGA = 0x00000400;

		//------------------------------------------------------------------------------
		//SCAN_MODE
		//------------------------------------------------------------------------------
		const unsigned short STCAM_SCAN_MODE_NORMAL = 0x0000;
		const unsigned short STCAM_SCAN_MODE_PARTIAL_2 = 0x0001;
		const unsigned short STCAM_SCAN_MODE_PARTIAL_4 = 0x0002;
		const unsigned short STCAM_SCAN_MODE_PARTIAL_1 = 0x0004;
		const unsigned short STCAM_SCAN_MODE_VARIABLE_PARTIAL = 0x0008;
		const unsigned short STCAM_SCAN_MODE_BINNING = 0x0010;
		const unsigned short STCAM_SCAN_MODE_BINNING_PARTIAL_1 = 0x0020;
		const unsigned short STCAM_SCAN_MODE_BINNING_PARTIAL_2 = 0x0040;
		const unsigned short STCAM_SCAN_MODE_BINNING_PARTIAL_4 = 0x0080;
		const unsigned short STCAM_SCAN_MODE_BINNING_VARIABLE_PARTIAL = 0x0100;
		const unsigned short STCAM_SCAN_MODE_ROI = 0x8000;
		const unsigned short STCAM_SCAN_MODE_AOI = 0x8000;

		//------------------------------------------------------------------------------
		//PIXEL_FORMAT
		//------------------------------------------------------------------------------
		const unsigned int STCAM_PIXEL_FORMAT_08_MONO_OR_RAW = 0x00000001;
		const unsigned int STCAM_PIXEL_FORMAT_24_BGR = 0x00000004;
		const unsigned int STCAM_PIXEL_FORMAT_32_BGR = 0x00000008;

		//------------------------------------------------------------------------------
		//COLOR_INTERPOLATION
		//------------------------------------------------------------------------------
		const unsigned char STCAM_COLOR_INTERPOLATION_NONE_MONO = 0;
		const unsigned char STCAM_COLOR_INTERPOLATION_NONE_COLOR = 1;
		const unsigned char STCAM_COLOR_INTERPOLATION_NEAREST_NEIGHBOR = 2;
		const unsigned char STCAM_COLOR_INTERPOLATION_BILINEAR = 3;
		const unsigned char STCAM_COLOR_INTERPOLATION_BILINEAR_FALSE_COLOR_REDUCTION = 5;
		const unsigned char STCAM_COLOR_INTERPOLATION_BICUBIC = 4;

		//------------------------------------------------------------------------------
		//ASPECT
		//------------------------------------------------------------------------------
		const unsigned char STCAM_ASPECT_MODE_FIXED = 0;
		const unsigned char STCAM_ASPECT_MODE_KEEP_ASPECT = 1;
		const unsigned char STCAM_ASPECT_MODE_ADJUST_WINDOW = 2;
		const unsigned char STCAM_ASPECT_MODE_MASK_SIZE = 3;
		const unsigned char STCAM_ASPECT_MODE_CUSTOM_OFFSET = 254;
		const unsigned char STCAM_ASPECT_MODE_CUSTOM_CENTER = 255;
		const unsigned char STCAM_ASPECT_MODE_CUSTOM = 255;

		//------------------------------------------------------------------------------
		//MAGNIFICATION
		//------------------------------------------------------------------------------
		const unsigned char STCAM_MAGNIFICATION_MODE_OFF = 0;
		const unsigned char STCAM_MAGNIFICATION_MODE_ON = 1;

		//------------------------------------------------------------------------------
		//ALCMODE
		//------------------------------------------------------------------------------
		const unsigned char STCAM_ALCMODE_FIXED_SHUTTER_AGC_OFF = 0;
		const unsigned char STCAM_ALCMODE_AUTO_SHUTTER_ON_AGC_ON = 1;
		const unsigned char STCAM_ALCMODE_AUTO_SHUTTER_ON_AGC_OFF = 2;
		const unsigned char STCAM_ALCMODE_FIXED_SHUTTER_AGC_ON = 3;
		const unsigned char STCAM_ALCMODE_AUTO_SHUTTER_AGC_ONESHOT = 4;
		const unsigned char STCAM_ALCMODE_AUTO_SHUTTER_ONESHOT_AGC_OFF = 5;
		const unsigned char STCAM_ALCMODE_FIXED_SHUTTER_AGC_ONESHOT = 6;
		const unsigned char STCAM_ALCMODE_CAMERA_AE_ON = 16;
		const unsigned char STCAM_ALCMODE_CAMERA_AGC_ON = 32;
		const unsigned char STCAM_ALCMODE_CAMERA_AE_AGC_ON = 48;
		const unsigned char STCAM_ALCMODE_ALC_FIXED_AGC_OFF = 0;
		const unsigned char STCAM_ALCMODE_ALC_FULLAUTO_AGC_ON = 1;
		const unsigned char STCAM_ALCMODE_ALC_FULLAUTO_AGC_OFF = 2;
		const unsigned char STCAM_ALCMODE_ALC_FIXED_AGC_ON = 3;
		const unsigned char STCAM_ALCMODE_ALCAGC_ONESHOT = 4;
		const unsigned char STCAM_ALCMODE_ALC_ONESHOT_AGC_OFF = 5;
		const unsigned char STCAM_ALCMODE_ALC_FIXED_AGC_ONESHOT = 6;

		//------------------------------------------------------------------------------
		//WB
		//------------------------------------------------------------------------------
		const unsigned char STCAM_WB_OFF = 0;
		const unsigned char STCAM_WB_MANUAL = 1;
		const unsigned char STCAM_WB_FULLAUTO = 2;
		const unsigned char STCAM_WB_ONESHOT = 3;

		//------------------------------------------------------------------------------
		//GAMMA
		//------------------------------------------------------------------------------
		const unsigned char STCAM_GAMMA_OFF = 0;
		const unsigned char STCAM_GAMMA_ON = 1;
		const unsigned char STCAM_GAMMA_REVERSE = 2;
		const unsigned char STCAM_GAMMA_TABLE = 255;

		//------------------------------------------------------------------------------
		//GAMMA_TARGET
		//------------------------------------------------------------------------------
		const unsigned char STCAM_GAMMA_TARGET_Y = 0;
		const unsigned char STCAM_GAMMA_TARGET_R = 1;
		const unsigned char STCAM_GAMMA_TARGET_GR = 2;
		const unsigned char STCAM_GAMMA_TARGET_GB = 3;
		const unsigned char STCAM_GAMMA_TARGET_B = 4;

		//------------------------------------------------------------------------------
		//SHARPNESS
		//------------------------------------------------------------------------------
		const unsigned char STCAM_SHARPNESS_OFF = 0;
		const unsigned char STCAM_SHARPNESS_ON = 1;

		//------------------------------------------------------------------------------
		//HUE_SATURATION
		//------------------------------------------------------------------------------
		const unsigned char STCAM_HUE_SATURATION_OFF = 0;
		const unsigned char STCAM_HUE_SATURATION_ON = 1;

		//------------------------------------------------------------------------------
		//COLOR_MATRIX
		//------------------------------------------------------------------------------
		const unsigned char STCAM_COLOR_MATRIX_OFF = 0x00;
		const unsigned char STCAM_COLOR_MATRIX_CUSTOM = 0xFF;

		//------------------------------------------------------------------------------
		//MIRROR
		//------------------------------------------------------------------------------
		const unsigned char STCAM_MIRROR_OFF = 0;
		const unsigned char STCAM_MIRROR_HORIZONTAL = 1;
		const unsigned char STCAM_MIRROR_VERTICAL = 2;
		const unsigned char STCAM_MIRROR_HORIZONTAL_VERTICAL = 3;
		const unsigned char STCAM_MIRROR_HORIZONTAL_CAMERA = 16;
		const unsigned char STCAM_MIRROR_VERTICAL_CAMERA = 32;

		//------------------------------------------------------------------------------
		//ROTATION
		//------------------------------------------------------------------------------
		const unsigned char STCAM_ROTATION_OFF = 0;
		const unsigned char STCAM_ROTATION_CLOCKWISE_90 = 1;
		const unsigned char STCAM_ROTATION_COUNTERCLOCKWISE_90 = 2;

		//------------------------------------------------------------------------------
		//AVI_COMPRESSOR
		//------------------------------------------------------------------------------
		const unsigned int STCAM_AVI_COMPRESSOR_UNCOMPRESSED = 0x00000000;
		const unsigned int STCAM_AVI_COMPRESSOR_MJPG = 0x47504A4D;
		const unsigned int STCAM_AVI_COMPRESSOR_MP42 = 0x3234706D;
		const unsigned int STCAM_AVI_COMPRESSOR_MPV4 = 0x3467706D;
		const unsigned int STCAM_AVI_COMPRESSOR_DIALOG_BOX = 0xFFFFFFFF;

		//------------------------------------------------------------------------------
		//CLOCK_MODE
		//------------------------------------------------------------------------------
		const unsigned int STCAM_CLOCK_MODE_NORMAL = 0x00000000;
		const unsigned int STCAM_CLOCK_MODE_DIV_2 = 0x00000001;
		const unsigned int STCAM_CLOCK_MODE_DIV_4 = 0x00000002;
		const unsigned int STCAM_CLOCK_MODE_VGA_90FPS = 0x00000100;
		const unsigned int STCAM_CLOCK_MODE_CUSTOM = 0x80000000;

		//------------------------------------------------------------------------------
		//USBPID
		//------------------------------------------------------------------------------
		const unsigned short STCAM_USBPID_STC_C33USB = 0x0305;
		const unsigned short STCAM_USBPID_STC_B33USB = 0x0705;
		const unsigned short STCAM_USBPID_STC_B83USB = 0x0805;
		const unsigned short STCAM_USBPID_STC_C83USB = 0x0605;
		const unsigned short STCAM_USBPID_STC_TB33USB = 0x0906;
		const unsigned short STCAM_USBPID_STC_TC33USB = 0x1006;
		const unsigned short STCAM_USBPID_STC_TB83USB = 0x1106;
		const unsigned short STCAM_USBPID_STC_TC83USB = 0x1206;
		const unsigned short STCAM_USBPID_STC_TB133USB = 0x0109;
		const unsigned short STCAM_USBPID_STC_TC133USB = 0x0209;
		const unsigned short STCAM_USBPID_STC_TB152USB = 0x1306;
		const unsigned short STCAM_USBPID_STC_TC152USB = 0x1406;
		const unsigned short STCAM_USBPID_STC_TB202USB = 0x1506;
		const unsigned short STCAM_USBPID_STC_TC202USB = 0x1606;
		const unsigned short STCAM_USBPID_STC_MB33USB = 0x0110;
		const unsigned short STCAM_USBPID_STC_MC33USB = 0x0210;
		const unsigned short STCAM_USBPID_STC_MB83USB = 0x0310;
		const unsigned short STCAM_USBPID_STC_MC83USB = 0x0410;
		const unsigned short STCAM_USBPID_STC_MB133USB = 0x0510;
		const unsigned short STCAM_USBPID_STC_MC133USB = 0x0610;
		const unsigned short STCAM_USBPID_STC_MB152USB = 0x0710;
		const unsigned short STCAM_USBPID_STC_MC152USB = 0x0810;
		const unsigned short STCAM_USBPID_STC_MB202USB = 0x0910;
		const unsigned short STCAM_USBPID_STC_MC202USB = 0x1010;
		const unsigned short STCAM_USBPID_STC_MBA5MUSB3 = 0x0111;
		const unsigned short STCAM_USBPID_STC_MCA5MUSB3 = 0x0211;
		const unsigned short STCAM_USBPID_STC_MBE132U3V = 0x0112;
		const unsigned short STCAM_USBPID_STC_MCE132U3V = 0x0212;
		const unsigned short STCAM_USBPID_STC_MBCM401U3V = 0x0113;
		const unsigned short STCAM_USBPID_STC_MCCM401U3V = 0x0213;
		const unsigned short STCAM_USBPID_STC_MBCM200U3V = 0x0313;
		const unsigned short STCAM_USBPID_STC_MCCM200U3V = 0x0413;
		const unsigned short STCAM_USBPID_STC_MBCM33U3V = 0x0513;
		const unsigned short STCAM_USBPID_STC_MCCM33U3V = 0x0613;
		const unsigned short STCAM_USBPID_STC_MBS241U3V = 0x0713;
		const unsigned short STCAM_USBPID_STC_MCS241U3V = 0x0813;
		const unsigned short STCAM_USBPID_STC_MBE132U3V_IR = 0x0114;
		const unsigned short STCAM_USBPID_STC_RHB33U3V = 0x0115;
		const unsigned short STCAM_USBPID_STC_RHC33U3V = 0x0215;
		const unsigned short STCAM_USBPID_STC_MBS510U3V = 0x0315;
		const unsigned short STCAM_USBPID_STC_MCS510U3V = 0x0415;
		const unsigned short STCAM_USBPID_STC_MBS322U3V = 0x0515;
		const unsigned short STCAM_USBPID_STC_MCS322U3V = 0x0615;

		//------------------------------------------------------------------------------
		//AVI_STATUS
		//------------------------------------------------------------------------------
		const unsigned char STCAM_AVI_STATUS_STOP = 0x00;
		const unsigned char STCAM_AVI_STATUS_START = 0x01;
		const unsigned char STCAM_AVI_STATUS_PAUSE = 0x02;

		//------------------------------------------------------------------------------
		//DISPLAY_MODE
		//------------------------------------------------------------------------------
		const unsigned char STCAM_DISPLAY_MODE_GDI = 0x00;
		const unsigned char STCAM_DISPLAY_MODE_GDI_HALFTONE = 0x08;
		const unsigned char STCAM_DISPLAY_MODE_DD_OFFSCREEN = 0x01;
		const unsigned char STCAM_DISPLAY_MODE_DD_OVERLAY = 0x02;
		const unsigned char STCAM_DISPLAY_MODE_DD_OFFSCREEN_HQ = 0x03;
		const unsigned char STCAM_DISPLAY_MODE_DD_OVERLAY_HQ = 0x04;
		const unsigned char STCAM_DISPLAY_MODE_DIRECTX = 0x05;
		const unsigned char STCAM_DISPLAY_MODE_DIRECTX_VSYNC_ON = 0x06;
		const unsigned char STCAM_DISPLAY_MODE_DIRECTX_VSYNC_ON2 = 0x07;
		const unsigned char STCAM_DISPLAY_MODE_DIRECTX_FPU = 0x09;
		const unsigned char STCAM_DISPLAY_MODE_DIRECTX_VSYNC_ON_FPU = 0x0A;
		const unsigned char STCAM_DISPLAY_MODE_DIRECTX_VSYNC_ON2_FPU = 0x0B;

		//------------------------------------------------------------------------------
		//TRUE_FALSE
		//------------------------------------------------------------------------------
		const unsigned int STCAM_TRUE = 0xFFFFFFFF;
		const unsigned int STCAM_FALSE = 0x00000000;

		//------------------------------------------------------------------------------
		//CAMERA_SETTING
		//------------------------------------------------------------------------------
		const unsigned short STCAM_CAMERA_SETTING_INITIALIZE = 0x8000;
		const unsigned short STCAM_CAMERA_SETTING_WRITE = 0x2000;
		const unsigned short STCAM_CAMERA_SETTING_READ = 0x1000;
		const unsigned short STCAM_CAMERA_SETTING_STANDARD = 0x0800;
		const unsigned short STCAM_CAMERA_SETTING_DEFECT_PIXEL_POSITION = 0x0400;

		//------------------------------------------------------------------------------
		//DEFECT_PIXEL_CORRECTION
		//------------------------------------------------------------------------------
		const unsigned short STCAM_DEFECT_PIXEL_CORRECTION_OFF = 0x0000;
		const unsigned short STCAM_DEFECT_PIXEL_CORRECTION_ON = 0x0001;

		//------------------------------------------------------------------------------
		//BINNING_SUM
		//------------------------------------------------------------------------------
		const unsigned short STCAM_BINNING_SUM_MODE_OFF = 0x0000;
		const unsigned short STCAM_BINNING_SUM_MODE_H = 0x0001;
		const unsigned short STCAM_BINNING_SUM_MODE_V = 0x0100;

		//------------------------------------------------------------------------------
		//AVI_FILE_FORMAT
		//------------------------------------------------------------------------------
		const unsigned int STCAM_AVI_FILE_FORMAT_AVI1 = 0;
		const unsigned int STCAM_AVI_FILE_FORMAT_AVI2 = 1;

		//------------------------------------------------------------------------------
		//SHADING_CORRECTION_MODE
		//------------------------------------------------------------------------------
		const unsigned int STCAM_SHADING_CORRECTION_MODE_OFF = 0x0000;
		const unsigned int STCAM_SHADING_CORRECTION_MODE_CALIBRATION_MULTIPLICATION = 0x0001;
		const unsigned int STCAM_SHADING_CORRECTION_MODE_ON_MULTIPLICATION = 0x0002;
		const unsigned int STCAM_SHADING_CORRECTION_MODE_CALIBRATION_ADDITION = 0x0003;
		const unsigned int STCAM_SHADING_CORRECTION_MODE_ON_ADDITION = 0x0004;

		//------------------------------------------------------------------------------
		//CAMERA_FUNCTION
		//------------------------------------------------------------------------------
		const unsigned int STCAM_CAMERA_FUNCTION_AWB = 24;
		const unsigned int STCAM_CAMERA_FUNCTION_AGC = 25;
		const unsigned int STCAM_CAMERA_FUNCTION_AE = 26;
		const unsigned int STCAM_CAMERA_FUNCTION_STORE_CAMERA_SETTING = 59;
		const unsigned int STCAM_CAMERA_FUNCTION_ANALOG_BLACK_LEVEL = 0x00050006;
		const unsigned int STCAM_CAMERA_FUNCTION_DISABLED_ANALOG_GAIN = 0x00090004;
		const unsigned int STCAM_CAMERA_FUNCTION_AGC_GAIN_TYPE = 0x00090005;
		const unsigned int STCAM_CAMERA_FUNCTION_ADJUSTMENT_MODE_DIGITAL_GAIN = 0x0009000A;
		const unsigned int STCAM_CAMERA_FUNCTION_DEVICE_TEMPERATURE_MAINBOARD = 0x00090009;

		//------------------------------------------------------------------------------
		//ADJUSTMENT_MODE
		//------------------------------------------------------------------------------
		const unsigned int STCAM_ADJUSTMENT_MODE_DIGITAL_GAIN = 0x00000001;

		//------------------------------------------------------------------------------
		//DEVICE_TEMPERATURE
		//------------------------------------------------------------------------------
		const unsigned int STCAM_DEVICE_TEMPERATURE_MAINBOARD = 0x00000001;

		//------------------------------------------------------------------------------
		//HDR_TYPE
		//------------------------------------------------------------------------------
		const unsigned int STCAM_HDR_TYPE_CMOSIS_4M = 0x00000001;

		//------------------------------------------------------------------------------
		//WINDOW_STYLE
		//------------------------------------------------------------------------------
		const unsigned int WS_OVERLAPPED = 0x00000000;
		const unsigned int WS_POPUP = 0x80000000;
		const unsigned int WS_CHILD = 0x40000000;
		const unsigned int WS_MINIMIZE = 0x20000000;
		const unsigned int WS_VISIBLE = 0x10000000;
		const unsigned int WS_DISABLED = 0x08000000;
		const unsigned int WS_CLIPSIBLINGS = 0x04000000;
		const unsigned int WS_CLIPCHILDREN = 0x02000000;
		const unsigned int WS_MAXIMIZE = 0x01000000;
		const unsigned int WS_CAPTION = 0x00C00000;
		const unsigned int WS_BORDER = 0x00800000;
		const unsigned int WS_DLGFRAME = 0x00400000;
		const unsigned int WS_VSCROLL = 0x00200000;
		const unsigned int WS_HSCROLL = 0x00100000;
		const unsigned int WS_SYSMENU = 0x00080000;
		const unsigned int WS_THICKFRAME = 0x00040000;
		const unsigned int WS_GROUP = 0x00020000;
		const unsigned int WS_TABSTOP = 0x00010000;
		const unsigned int WS_MINIMIZEBOX = 0x00020000;
		const unsigned int WS_MAXIMIZEBOX = 0x00010000;
		const unsigned int WS_OVERLAPPEDWINDOW = 0x00CF0000;
		const unsigned int WS_POPUPWINDOW = 0x80880000;
		const unsigned int WS_TILED = 0x00000000;
		const unsigned int WS_ICONIC = 0x00020000;
		const unsigned int WS_SIZEBOX = 0x00040000;
		const unsigned int WS_TILEDWINDOW = 0x00CF0000;
		const unsigned int WS_CHILDWINDOW = 0x40000000;
	}
}

