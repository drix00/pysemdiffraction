//Created Date:2016/03/14 09:20
//=============================================================================
//StCamD.h
//=============================================================================
#ifndef STCAMD_H
#define STCAMD_H
#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

//Callback Function
typedef VOID (WINAPI *fStCamPreviewBitmapCallbackFunc)(PBYTE pbyteBitmap,DWORD dwBufferSize, DWORD dwWidth, DWORD dwHeight, DWORD dwFrameNo, DWORD dwPreviewPixelFormat, LPVOID lpContext,LPVOID lpReserved);
typedef VOID (WINAPI *fStCamRawCallbackFunc)(PBYTE pbyteBuffer,DWORD dwBufferSize, DWORD dwWidth, DWORD dwHeight, DWORD dwFrameNo,WORD wColorArray, DWORD dwTransferBitsPerPixel, LPVOID lpContext,LPVOID lpReserved);
typedef VOID (WINAPI *fStCamPreviewGDICallbackFunc)(HDC hDC, DWORD dwWidth, DWORD dwHeight,  DWORD dwFrameNo,LPVOID lpContext,LPVOID lpReserved);

//-----------------------------------------------------------------------------
//Initialize
//-----------------------------------------------------------------------------
HANDLE WINAPI StCam_Open(DWORD dwInstance);
VOID WINAPI StCam_Close(HANDLE hCamera);
DWORD WINAPI StCam_GetLastError(HANDLE hCamera);
DWORD WINAPI StCam_CameraCount(VOID);
BOOL WINAPI StCam_SetReceiveMsgWindow(HANDLE hCamera, HWND hWnd);
BOOL WINAPI StCam_GetUSBSpeed(HANDLE hCamera, PBYTE pbyteUSBSpeed);
BOOL WINAPI StCam_GetUSBMaxSpeed(HANDLE hCamera, PBYTE pbyteUSBSpeed);

//-----------------------------------------------------------------------------
//Image Information
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_GetColorArray(HANDLE hCamera, PWORD pwColorArray);
BOOL WINAPI StCam_GetEnableTransferBitsPerPixel(HANDLE hCamera, PDWORD pdwEnableTransferBitsPerPixel);
BOOL WINAPI StCam_SetTransferBitsPerPixel(HANDLE hCamera, DWORD dwTransferBitsPerPixel);
BOOL WINAPI StCam_GetTransferBitsPerPixel(HANDLE hCamera, PDWORD pdwTransferBitsPerPixel);
BOOL WINAPI StCam_GetMaximumImageSize(HANDLE hCamera, PDWORD pdwMaxWidth, PDWORD pdwMaxHeight);
BOOL WINAPI StCam_GetEnableImageSize(HANDLE hCamera, PDWORD pdwReserved, PWORD pwEnableScanMode);
BOOL WINAPI StCam_SetImageSize(HANDLE hCamera, DWORD dwReserved, WORD wScanMode, DWORD dwOffsetX, DWORD dwOffsetY, DWORD dwWidth, DWORD dwHeight);
BOOL WINAPI StCam_GetImageSize(HANDLE hCamera, PDWORD pdwReserved, PWORD pwScanMode, PDWORD pdwOffsetX, PDWORD pdwOffsetY, PDWORD pdwWidth, PDWORD pdwHeight);
BOOL WINAPI StCam_GetSkippingAndBinning(HANDLE hCamera, PBYTE pbyteHSkipping, PBYTE pbyteVSkipping, PBYTE pbyteHBinning, PBYTE pbyteVBinning);
BOOL WINAPI StCam_SetSkippingAndBinning(HANDLE hCamera, BYTE byteHSkipping, BYTE byteVSkipping, BYTE byteHBinning, BYTE byteVBinning);
BOOL WINAPI StCam_GetBinningSumMode(HANDLE hCamera, PWORD pwMode);
BOOL WINAPI StCam_SetBinningSumMode(HANDLE hCamera, WORD wMode);

//-----------------------------------------------------------------------------
//Preview
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_StartTransfer(HANDLE hCamera);
BOOL WINAPI StCam_StopTransfer(HANDLE hCamera);
BOOL WINAPI StCam_SetPreviewPixelFormat(HANDLE hCamera, DWORD dwPreviewPixelFormat);
BOOL WINAPI StCam_GetPreviewPixelFormat(HANDLE hCamera, PDWORD pdwPreviewPixelFormat);
BOOL WINAPI StCam_GetEnablePreviewPixelFormat(HANDLE hCamera, PDWORD pdwEnablePreviewPixelFormat);
BOOL WINAPI StCam_SetColorInterpolationMethod(HANDLE hCamera, BYTE byteColorInterpolationMethod);
BOOL WINAPI StCam_GetColorInterpolationMethod(HANDLE hCamera, PBYTE pbyteColorInterpolationMethod);
BOOL WINAPI StCam_CreatePreviewWindowA(HANDLE hCamera, PCSTR pszWindowName, DWORD dwStyle, LONG lngPositionX, LONG lngPositionY, DWORD dwWidth, DWORD dwHeight, HWND hWndParent, HMENU hMenu, BOOL bCloseEnable);
BOOL WINAPI StCam_CreatePreviewWindowW(HANDLE hCamera, PCWSTR pszWindowName, DWORD dwStyle, LONG lngPositionX, LONG lngPositionY, DWORD dwWidth, DWORD dwHeight, HWND hWndParent, HMENU hMenu, BOOL bCloseEnable);
BOOL WINAPI StCam_DestroyPreviewWindow(HANDLE hCamera);
BOOL WINAPI StCam_SetPreviewWindowNameA(HANDLE hCamera, PCSTR pszWindowName);
BOOL WINAPI StCam_GetPreviewWindowNameA(HANDLE hCamera, PSTR pszWindowName, LONG lngMaxCount);
BOOL WINAPI StCam_SetPreviewWindowNameW(HANDLE hCamera, PCWSTR pszWindowName);
BOOL WINAPI StCam_GetPreviewWindowNameW(HANDLE hCamera, PWSTR pszWindowName, LONG lngMaxCount);
BOOL WINAPI StCam_SetPreviewMaskSize(HANDLE hCamera, DWORD dwOffsetX, DWORD dwOffsetY, DWORD dwWidth, DWORD dwHeight);
BOOL WINAPI StCam_GetPreviewMaskSize(HANDLE hCamera, PDWORD pdwOffsetX, PDWORD pdwOffsetY, PDWORD pdwWidth, PDWORD pdwHeight);
BOOL WINAPI StCam_SetPreviewWindowSize(HANDLE hCamera, LONG lngPositionX, LONG lngPositionY, DWORD dwWidth, DWORD dwHeight);
BOOL WINAPI StCam_GetPreviewWindowSize(HANDLE hCamera, PLONG plngPositionX, PLONG plngPositionY, PDWORD pdwWidth, PDWORD pdwHeight);
BOOL WINAPI StCam_SetPreviewWindowStyle(HANDLE hCamera, DWORD dwStyle);
BOOL WINAPI StCam_GetPreviewWindowStyle(HANDLE hCamera, PDWORD pdwStyle);
BOOL WINAPI StCam_SetAspectMode(HANDLE hCamera, BYTE byteAspectMode);
BOOL WINAPI StCam_GetAspectMode(HANDLE hCamera, PBYTE pbyteAspectMode);
BOOL WINAPI StCam_SetPreviewDestSize(HANDLE hCamera, DWORD dwOffsetX, DWORD dwOffsetY, DWORD dwWidth, DWORD dwHeight);
BOOL WINAPI StCam_GetPreviewDestSize(HANDLE hCamera, PDWORD pdwOffsetX, PDWORD pdwOffsetY, PDWORD pdwWidth, PDWORD pdwHeight);
BOOL WINAPI StCam_SetMagnificationMode(HANDLE hCamera, BYTE byteMagnificationMode);
BOOL WINAPI StCam_GetMagnificationMode(HANDLE hCamera, PBYTE pbyteMagnificationMode);
BOOL WINAPI StCam_GetDCWithReset(HANDLE hCamera, HDC* phDC);
BOOL WINAPI StCam_GetDC(HANDLE hCamera, HDC* phDC);
BOOL WINAPI StCam_ReleaseDC(HANDLE hCamera, HDC hDC);
BOOL WINAPI StCam_ResetOverlay(HANDLE hCamera);
BOOL WINAPI StCam_SetColorKey(HANDLE hCamera, DWORD dwColorKey);
BOOL WINAPI StCam_GetColorKey(HANDLE hCamera, PDWORD pdwColorKey);
BOOL WINAPI StCam_SetDisplayMode(HANDLE hCamera, BYTE byteDisplayMode);
BOOL WINAPI StCam_GetDisplayMode(HANDLE hCamera, PBYTE pbyteDisplayMode);
BOOL WINAPI StCam_GetAlphaChannel(HANDLE hCamera, PBYTE pbyteAlphaChannel);
BOOL WINAPI StCam_SetAlphaChannel(HANDLE hCamera, BYTE byteAlphaChannel);
BOOL WINAPI StCam_GetPreviewImagePixelValue(HANDLE hCamera, DWORD nX, DWORD nY, PDWORD pdwColor);
BOOL WINAPI StCam_GetPreviewWnd(HANDLE hCamera, HWND* hWnd);

//-----------------------------------------------------------------------------
//Image Acquisition
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_TakeRawSnapShot(HANDLE hCamera, PBYTE pbyteBuffer, DWORD dwBufferSize, PDWORD pdwNumberOfByteTrans, PDWORD pdwFrameNo, DWORD dwMilliseconds);
BOOL WINAPI StCam_TakePreviewSnapShot(HANDLE hCamera, PBYTE pbyteBuffer, DWORD dwBufferSize, PDWORD pdwNumberOfByteTrans, PDWORD pdwFrameNo, DWORD dwMilliseconds);
BOOL WINAPI StCam_SaveImageA(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, DWORD dwPreviewPixelFormat, PBYTE pbyteData, PCSTR pszFileName, DWORD dwParam);
BOOL WINAPI StCam_SaveImageW(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, DWORD dwPreviewPixelFormat, PBYTE pbyteData, PCWSTR pszFileName, DWORD dwParam);
BOOL WINAPI StCam_GetRawDataSize(HANDLE hCamera, PDWORD pdwSize);
BOOL WINAPI StCam_GetPreviewDataSize(HANDLE hCamera, PDWORD pdwSize, PDWORD pdwWidth, PDWORD pdwHeight, PDWORD pdwLinePitch);
BOOL WINAPI StCam_SetROI(HANDLE hCamera, DWORD dwIndex, DWORD dwMode, DWORD dwOffsetX, DWORD dwOffsetY, DWORD dwWidth, DWORD dwHeight);
BOOL WINAPI StCam_GetROI(HANDLE hCamera, DWORD dwIndex, PDWORD pdwMode, PDWORD pdwOffsetX, PDWORD pdwOffsetY, PDWORD pdwWidth, PDWORD pdwHeight);
BOOL WINAPI StCam_GetMaxROICount(HANDLE hCamera, PDWORD pdwRegionCount);

//-----------------------------------------------------------------------------
//Shutter Gain Control
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_GetALCMode(HANDLE hCamera, PBYTE pbyteAlcMode);
BOOL WINAPI StCam_SetALCMode(HANDLE hCamera, BYTE byteAlcMode);
BOOL WINAPI StCam_GetExposureClock(HANDLE hCamera, PDWORD pdwExposureClock);
BOOL WINAPI StCam_SetExposureClock(HANDLE hCamera, DWORD dwExposureClock);
BOOL WINAPI StCam_GetMaxShortExposureClock(HANDLE hCamera, PDWORD pdwMaximumExpClock);
BOOL WINAPI StCam_GetMaxLongExposureClock(HANDLE hCamera, PDWORD pdwMaximumExpClock);
BOOL WINAPI StCam_GetExposureTimeFromClock(HANDLE hCamera, DWORD dwExposureClock, PFLOAT pfExpTime);
BOOL WINAPI StCam_GetExposureClockFromTime(HANDLE hCamera, FLOAT fExpTime, PDWORD pdwExposureClock);
BOOL WINAPI StCam_GetGain(HANDLE hCamera, PWORD pwGain);
BOOL WINAPI StCam_SetGain(HANDLE hCamera, WORD wGain);
BOOL WINAPI StCam_GetMaxGain(HANDLE hCamera, PWORD pwMaxGain);
BOOL WINAPI StCam_GetGainDBFromSettingValue(HANDLE hCamera, WORD wGain, PFLOAT pfGainDB);
BOOL WINAPI StCam_GetTargetBrightness(HANDLE hCamera, PBYTE pbyteTargetBrightness, PBYTE pbyteTolerance, PBYTE pbyteThreshold);
BOOL WINAPI StCam_SetTargetBrightness(HANDLE hCamera, BYTE byteTargetBrightness, BYTE byteTolerance, BYTE byteThreshold);
BOOL WINAPI StCam_GetALCWeight(HANDLE hCamera, PBYTE pbyteALCWeight);
BOOL WINAPI StCam_SetALCWeight(HANDLE hCamera, PBYTE pbyteALCWeight);
BOOL WINAPI StCam_SetAEMinExposureClock(HANDLE hCamera, DWORD dwMinExposureClock);
BOOL WINAPI StCam_GetAEMinExposureClock(HANDLE hCamera, PDWORD pdwMinExposureClock);
BOOL WINAPI StCam_GetAEMaxExposureClock(HANDLE hCamera, PDWORD pdwMaxExposureClock);
BOOL WINAPI StCam_SetAEMaxExposureClock(HANDLE hCamera, DWORD dwMaxExposureClock);
BOOL WINAPI StCam_SetALCControlSpeed(HANDLE hCamera, BYTE byteShutterCtrlSpeedLimit, BYTE byteGainCtrlSpeedLimit, BYTE byteSkipFrameCount, BYTE byteAverageFrameCount);
BOOL WINAPI StCam_GetALCControlSpeed(HANDLE hCamera, PBYTE pbyteShutterCtrlSpeedLimit, PBYTE pbyteGainCtrlSpeedLimit, PBYTE pbyteSkipFrameCount, PBYTE pbyteAverageFrameCount);
BOOL WINAPI StCam_GetGainControlRange(HANDLE hCamera, PWORD pwMinGain, PWORD pwMaxGain);
BOOL WINAPI StCam_SetGainControlRange(HANDLE hCamera, WORD wMinGain, WORD wMaxGain);
BOOL WINAPI StCam_GetDigitalGain(HANDLE hCamera, PWORD pwDigitalGain);
BOOL WINAPI StCam_SetDigitalGain(HANDLE hCamera, WORD wDigitalGain);
BOOL WINAPI StCam_GetMaxDigitalGain(HANDLE hCamera, PWORD pwMaxDigitalGain);
BOOL WINAPI StCam_GetDigitalGainTimesFromSettingValue(HANDLE hCamera, WORD wDigitalGain, PFLOAT pfDigitalGainTimes);
BOOL WINAPI StCam_GetDigitalGainSettingValueFromGainTimes(HANDLE hCamera, FLOAT fDigitalGainTimes, PWORD pwDigitalGain);
BOOL WINAPI StCam_GetShutterSpeed(HANDLE hCamera, PWORD pwShutterLine, PWORD pwShutterClock);
BOOL WINAPI StCam_SetShutterSpeed(HANDLE hCamera, WORD wShutterLine, WORD wShutterClock);
BOOL WINAPI StCam_GetShutterControlRange(HANDLE hCamera, PWORD pwMinShutterLine, PWORD pwMinShutterClock, PWORD pwMaxShutterLine, PWORD pwMaxShutterClock);
BOOL WINAPI StCam_SetShutterControlRange(HANDLE hCamera, WORD wMinShutterLine, WORD wMinShutterClock, WORD wMaxShutterLine, WORD wMaxShutterClock);

//-----------------------------------------------------------------------------
//White Balance Control
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_SetWhiteBalanceMode(HANDLE hCamera, BYTE byteWBMode);
BOOL WINAPI StCam_GetWhiteBalanceMode(HANDLE hCamera, PBYTE pbyteWBMode);
BOOL WINAPI StCam_SetWhiteBalanceGain(HANDLE hCamera, WORD wWBGainR, WORD wWBGainGr, WORD wWBGainGb, WORD wWBGainB);
BOOL WINAPI StCam_GetWhiteBalanceGain(HANDLE hCamera, PWORD pwWBGainR, PWORD pwWBGainGr, PWORD pwWBGainGb, PWORD pwWBGainB);
BOOL WINAPI StCam_SetWhiteBalanceTarget(HANDLE hCamera, WORD wAWBTargetR, WORD wAWBTargetB);
BOOL WINAPI StCam_GetWhiteBalanceTarget(HANDLE hCamera, PWORD pwAWBTargetR, PWORD pwAWBTargetB);
BOOL WINAPI StCam_SetWhiteBalanceToleranceThreshold(HANDLE hCamera, WORD wAWBTolerance, WORD wAWBThreshold);
BOOL WINAPI StCam_GetWhiteBalanceToleranceThreshold(HANDLE hCamera, PWORD pwAWBTolerance, PWORD pwAWBThreshold);
BOOL WINAPI StCam_SetAWBWeight(HANDLE hCamera, PBYTE pbyteAWBWeight);
BOOL WINAPI StCam_GetAWBWeight(HANDLE hCamera, PBYTE pbyteAWBWeight);
BOOL WINAPI StCam_RawWhiteBalance(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, WORD wColorArray, PBYTE pbyteRaw);

//-----------------------------------------------------------------------------
//Gamma
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_SetGammaMode(HANDLE hCamera, BYTE byteGammaTarget, BYTE byteGammaMode, WORD wGamma, PBYTE pbyteGammaTable);
BOOL WINAPI StCam_GetGammaMode(HANDLE hCamera, BYTE byteGammaTarget, PBYTE pbyteGammaMode, PWORD pwGamma, PBYTE pbyteGammaTable);
BOOL WINAPI StCam_SetGammaModeEx(HANDLE hCamera, BYTE byteGammaTarget, BYTE byteGammaMode, WORD wGamma, SHORT shtBrightness, BYTE byteContrast, PBYTE pbyteGammaTable);
BOOL WINAPI StCam_GetGammaModeEx(HANDLE hCamera, BYTE byteGammaTarget, PBYTE pbyteGammaMode, PWORD pwGamma, PSHORT pshtBrightness, PBYTE pbyteContrast, PBYTE pbyteGammaTable);
BOOL WINAPI StCam_GetCameraGammaValue(HANDLE hCamera, PWORD pwValue);
BOOL WINAPI StCam_SetCameraGammaValue(HANDLE hCamera, WORD wValue);

//-----------------------------------------------------------------------------
//Sharpness
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_SetSharpnessMode(HANDLE hCamera, BYTE byteSharpnessMode, WORD wSharpnessGain, BYTE byteSharpnessCoring);
BOOL WINAPI StCam_GetSharpnessMode(HANDLE hCamera, PBYTE pbyteSharpnessMode, PWORD pwSharpnessGain, PBYTE pbyteSharpnessCoring);

//-----------------------------------------------------------------------------
//Hue Saturation
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_SetHueSaturationMode(HANDLE hCamera, BYTE byteHueSaturationMode, SHORT shtHue, WORD wSaturation);
BOOL WINAPI StCam_GetHueSaturationMode(HANDLE hCamera, PBYTE pbyteHueSaturationMode, PSHORT pshtHue, PWORD pwSaturation);

//-----------------------------------------------------------------------------
//Color Matrix
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_SetColorMatrix(HANDLE hCamera, BYTE byteColorMatrixMode, PSHORT pshtColorMatrix);
BOOL WINAPI StCam_GetColorMatrix(HANDLE hCamera, PBYTE pbyteColorMatrixMode, PSHORT pshtColorMatrix);
BOOL WINAPI StCam_SetHighChromaSuppression(HANDLE hCamera, WORD wStartLevel, WORD wSuppression);
BOOL WINAPI StCam_SetLowChromaSuppression(HANDLE hCamera, WORD wStartLevel, WORD wSuppression);
BOOL WINAPI StCam_GetHighChromaSuppression(HANDLE hCamera, PWORD pwStartLevel, PWORD pwSuppression);
BOOL WINAPI StCam_GetLowChromaSuppression(HANDLE hCamera, PWORD pwStartLevel, PWORD pwSuppression);
BOOL WINAPI StCam_SetChromaSuppression(HANDLE hCamera, WORD wStartLevel, WORD wSuppression);
BOOL WINAPI StCam_GetChromaSuppression(HANDLE hCamera, PWORD pwStartLevel, PWORD pwSuppression);

//-----------------------------------------------------------------------------
//Shading Correction
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_SetShadingCorrectionMode(HANDLE hCamera, DWORD dwMode);
BOOL WINAPI StCam_GetShadingCorrectionMode(HANDLE hCamera, PDWORD pdwMode);
BOOL WINAPI StCam_SetShadingCorrectionTarget(HANDLE hCamera, WORD wTarget);
BOOL WINAPI StCam_GetShadingCorrectionTarget(HANDLE hCamera, PWORD wTarget);

//-----------------------------------------------------------------------------
//Mirro Rotation
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_GetEnableMirrorMode(HANDLE hCamera, PBYTE pbyteMirrorMode);
BOOL WINAPI StCam_SetMirrorMode(HANDLE hCamera, BYTE byteMirrorMode);
BOOL WINAPI StCam_GetMirrorMode(HANDLE hCamera, PBYTE pbyteMirrorMode);
BOOL WINAPI StCam_SetRotationMode(HANDLE hCamera, BYTE byteRotationMode);
BOOL WINAPI StCam_GetRotationMode(HANDLE hCamera, PBYTE pbyteRotationMode);

//-----------------------------------------------------------------------------
//Movie
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_SaveAVIA(HANDLE hCamera, PCSTR pszFileName, DWORD dwCompressor, DWORD dwLength, LPVOID lpReserved);
BOOL WINAPI StCam_SaveAVIW(HANDLE hCamera, PCWSTR pszFileName, DWORD dwCompressor, DWORD dwLength, LPVOID lpReserved);
BOOL WINAPI StCam_SetAVIStatus(HANDLE hCamera, BYTE byteAVIStatus);
BOOL WINAPI StCam_GetAVIStatus(HANDLE hCamera, PBYTE pbyteAVIStatus, PDWORD pdwTotalFrameCounts, PDWORD pdwCurrentFrameCounts);
BOOL WINAPI StCam_SetAVIQuality(HANDLE hCamera, DWORD dwQuality);
BOOL WINAPI StCam_GetAVIQuality(HANDLE hCamera, PDWORD pdwQuality);
BOOL WINAPI StCam_SetAVIPriorityFileFormat(HANDLE hCamera, DWORD dwFileFormat);
BOOL WINAPI StCam_GetAVIPriorityFileFormat(HANDLE hCamera, PDWORD pdwFileFormat);

//-----------------------------------------------------------------------------
//Clock
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_GetEnableClock(HANDLE hCamera, PDWORD pdwEnableClockMode, PDWORD pdwStandardClock, PDWORD pdwMinimumClock, PDWORD pdwMaximumClock);
BOOL WINAPI StCam_SetClock(HANDLE hCamera, DWORD dwClockMode, DWORD dwClock);
BOOL WINAPI StCam_GetClock(HANDLE hCamera, PDWORD pdwClockMode, PDWORD pdwClock);
BOOL WINAPI StCam_GetFrameClock(HANDLE hCamera, PWORD pwCurrentLinePerFrame, PWORD pwCurrentClockPerLine);
BOOL WINAPI StCam_GetOutputFPS(HANDLE hCamera, PFLOAT pfFPS);
BOOL WINAPI StCam_SetVBlankForFPS(HANDLE hCamera, DWORD dwVLines);
BOOL WINAPI StCam_GetVBlankForFPS(HANDLE hCamera, PDWORD pdwVLines);
BOOL WINAPI StCam_GetMaxVBlankForFPS(HANDLE hCamera, PDWORD pdwVLines);

//-----------------------------------------------------------------------------
//IOPin
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_GetDeviceTemperature(HANDLE hCamera, DWORD dwSelector, PLONG pnValue);

//-----------------------------------------------------------------------------
//Defect pixel correction
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_GetEnableDefectPixelCorrectionCount(HANDLE hCamera, PWORD pwCount);
BOOL WINAPI StCam_GetDefectPixelCorrectionMode(HANDLE hCamera, PWORD pwMode);
BOOL WINAPI StCam_SetDefectPixelCorrectionMode(HANDLE hCamera, WORD wMode);
BOOL WINAPI StCam_GetDefectPixelCorrectionPosition(HANDLE hCamera, WORD wIndex, PDWORD pdwX, PDWORD pdwY);
BOOL WINAPI StCam_SetDefectPixelCorrectionPosition(HANDLE hCamera, WORD wIndex, DWORD dwX, DWORD dwY);
BOOL WINAPI StCam_DetectDefectPixel(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, PBYTE pbyteRaw, WORD wThreshold);

//-----------------------------------------------------------------------------
//HDR
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_GetHDRType(HANDLE hCamera, PDWORD pdwHDRType);
BOOL WINAPI StCam_SetHDRParameter(HANDLE hCamera, PDWORD pdwBuffer, DWORD dwSize);
BOOL WINAPI StCam_GetHDRParameter(HANDLE hCamera, PDWORD pdwBuffer, PDWORD pdwSize);

//-----------------------------------------------------------------------------
//Callback Function
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_AddPreviewBitmapCallback(HANDLE hCamera, fStCamPreviewBitmapCallbackFunc pPreviewBitmapCallbackFunc, LPVOID pContext, PDWORD pdwPreviewBitmapCallbackNo);
BOOL WINAPI StCam_RemovePreviewBitmapCallback(HANDLE hCamera, DWORD dwPreviewBitmapCallbackNo);
BOOL WINAPI StCam_RemoveAllPreviewBitmapCallback(HANDLE hCamera);
BOOL WINAPI StCam_GetPreviewBitmapCallbackCount(HANDLE hCamera, PDWORD pdwListCount);
BOOL WINAPI StCam_GetPreviewBitmapCallback(HANDLE hCamera, DWORD dwCallbackIndex, fStCamPreviewBitmapCallbackFunc* ppPreviewBitmapCallbackFunc, PDWORD pdwCallbackFunctionNo);
BOOL WINAPI StCam_AddPreviewGDICallback(HANDLE hCamera, fStCamPreviewGDICallbackFunc pPreviewGDICallbackFunc, LPVOID pContext, PDWORD pdwPreviewGDICallbackNo);
BOOL WINAPI StCam_RemovePreviewGDICallback(HANDLE hCamera, DWORD dwPreviewGDICallbackNo);
BOOL WINAPI StCam_RemoveAllPreviewGDICallback(HANDLE hCamera);
BOOL WINAPI StCam_GetPreviewGDICallbackCount(HANDLE hCamera, PDWORD pdwListCount);
BOOL WINAPI StCam_GetPreviewGDICallback(HANDLE hCamera, DWORD dwCallbackIndex, fStCamPreviewGDICallbackFunc* ppPreviewGDICallbackFunc, PDWORD pdwCallbackFunctionNo);
BOOL WINAPI StCam_AddRawCallback(HANDLE hCamera, fStCamRawCallbackFunc pRawCallbackFunc, LPVOID pContext, PDWORD pdwRawCallbackNo);
BOOL WINAPI StCam_RemoveRawCallback(HANDLE hCamera, DWORD dwRawCallbackNo);
BOOL WINAPI StCam_RemoveAllRawCallback(HANDLE hCamera);
BOOL WINAPI StCam_GetRawCallbackCount(HANDLE hCamera, PDWORD pdwListCount);
BOOL WINAPI StCam_GetRawCallback(HANDLE hCamera, DWORD dwCallbackIndex, fStCamRawCallbackFunc* ppRawCallbackFunc, PDWORD pdwCallbackFunctionNo);

//-----------------------------------------------------------------------------
//Setting
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_SaveSettingFileA(HANDLE hCamera, PCSTR pszFileName);
BOOL WINAPI StCam_SaveSettingFileW(HANDLE hCamera, PCWSTR pszFileName);
BOOL WINAPI StCam_LoadSettingFileA(HANDLE hCamera, PCSTR pszFileName);
BOOL WINAPI StCam_LoadSettingFileW(HANDLE hCamera, PCWSTR pszFileName);
BOOL WINAPI StCam_ResetSetting(HANDLE hCamera);
BOOL WINAPI StCam_CameraSetting(HANDLE hCamera, WORD wMode);

//-----------------------------------------------------------------------------
//EEPROM
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_ReadUserMemory(HANDLE hCamera, PBYTE pbyteBuffer, WORD wOffset, WORD wLength);
BOOL WINAPI StCam_WriteUserMemory(HANDLE hCamera, PBYTE pbyteBuffer, WORD wOffset, WORD wLength);
BOOL WINAPI StCam_ReadCameraUserIDA(HANDLE hCamera, PDWORD pdwCameraID, PSTR pszBuffer, DWORD dwBufferSize);
BOOL WINAPI StCam_ReadCameraUserIDW(HANDLE hCamera, PDWORD pdwCameraID, PWSTR pszBuffer, DWORD dwBufferSize);
BOOL WINAPI StCam_WriteCameraUserIDA(HANDLE hCamera, DWORD dwCameraID, PCSTR pszBuffer, DWORD dwBufferSize);
BOOL WINAPI StCam_WriteCameraUserIDW(HANDLE hCamera, DWORD dwCameraID, PCWSTR pszBuffer, DWORD dwBufferSize);

//-----------------------------------------------------------------------------
//Version Information
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_GetProductNameA(HANDLE hCamera, PSTR pszCameraName, DWORD dwBufferSize);
BOOL WINAPI StCam_GetProductNameW(HANDLE hCamera, PWSTR pszCameraName, DWORD dwBufferSize);
BOOL WINAPI StCam_GetCameraVersion(HANDLE hCamera, PWORD pwUSBVendorID, PWORD pwUSBProductID, PWORD pwFPGAVersion, PWORD pwFirmVersion);
BOOL WINAPI StCam_GetDriverVersion(HANDLE hCamera, PDWORD pdwFileVersionMS, PDWORD pdwFileVersionLS, PDWORD pdwProductVersionMS, PDWORD pdwProductVersionLS);
BOOL WINAPI StCam_GetUSBDllVersion(PDWORD pdwFileVersionMS, PDWORD pdwFileVersionLS, PDWORD pdwProductVersionMS, PDWORD pdwProductVersionLS);
BOOL WINAPI StCam_GetCAMDllVersion(PDWORD pdwFileVersionMS, PDWORD pdwFileVersionLS, PDWORD pdwProductVersionMS, PDWORD pdwProductVersionLS);
BOOL WINAPI StCam_GetUSBFunctionAddress(HANDLE hCamera, PBYTE pbyteUSBFunctionAddress);
BOOL WINAPI StCam_HasFunction(HANDLE hCamera, DWORD dwCameraFunctionID, BOOL* pbHasFunction);

//-----------------------------------------------------------------------------
//Other
//-----------------------------------------------------------------------------
BOOL WINAPI StCam_ConvertBitmapBGR24ToRGB24(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, PBYTE pbyteBitmap);
BOOL WINAPI StCam_ConvertRawToBGR(HANDLE hCamera, DWORD dwWidth, DWORD dwHeight, PBYTE pbyteSrcRaw, PBYTE pbyteDstBGR, BYTE byteColorInterpolationMethod, DWORD dwPreviewPixelFormat);
BOOL WINAPI StCam_SetControlArea(HANDLE hCamera, PWORD pwSepalateX, PWORD pwSepalateY);
BOOL WINAPI StCam_GetControlArea(HANDLE hCamera, PWORD pwSepalateX, PWORD pwSepalateY);
BOOL WINAPI StCam_GetDigitalClamp(HANDLE hCamera, PWORD pwValue);
BOOL WINAPI StCam_SetDigitalClamp(HANDLE hCamera, WORD wValue);
BOOL WINAPI StCam_ResetRootHub();
BOOL WINAPI StCam_SetAnalogBlackLevel(HANDLE hCamera, WORD wBlackLevel);
BOOL WINAPI StCam_GetAnalogBlackLevel(HANDLE hCamera, PWORD pwBlackLevel);
BOOL WINAPI StCam_GetMaxAnalogBlackLevel(HANDLE hCamera, PWORD pwBlackLevel);
BOOL WINAPI StCam_GetMaxDigitalClamp(HANDLE hCamera, PWORD pwDigitalClamp);
BOOL WINAPI StCam_SetAdjustmentMode(HANDLE hCamera, DWORD dwValue);
BOOL WINAPI StCam_GetAdjustmentMode(HANDLE hCamera, PDWORD pdwValue);
//Use the correct version depending on the UNICODE identifier
#ifdef UNICODE
#define StCam_CreatePreviewWindow StCam_CreatePreviewWindowW
#define StCam_SetPreviewWindowName StCam_SetPreviewWindowNameW
#define StCam_GetPreviewWindowName StCam_GetPreviewWindowNameW
#define StCam_ReadCameraUserID StCam_ReadCameraUserIDW
#define StCam_WriteCameraUserID StCam_WriteCameraUserIDW
#define StCam_SaveSettingFile StCam_SaveSettingFileW
#define StCam_LoadSettingFile StCam_LoadSettingFileW
#define StCam_SaveImage StCam_SaveImageW
#define StCam_SaveAVI StCam_SaveAVIW
#define StCam_GetProductName StCam_GetProductNameW
#else
#define StCam_CreatePreviewWindow StCam_CreatePreviewWindowA
#define StCam_SetPreviewWindowName StCam_SetPreviewWindowNameA
#define StCam_GetPreviewWindowName StCam_GetPreviewWindowNameA
#define StCam_ReadCameraUserID StCam_ReadCameraUserIDA
#define StCam_WriteCameraUserID StCam_WriteCameraUserIDA
#define StCam_SaveSettingFile StCam_SaveSettingFileA
#define StCam_LoadSettingFile StCam_LoadSettingFileA
#define StCam_SaveImage StCam_SaveImageA
#define StCam_SaveAVI StCam_SaveAVIA
#define StCam_GetProductName StCam_GetProductNameA
#endif  //UNICODE

//-----------------------------------------------------------------------------
//ERROR_STCAM
//-----------------------------------------------------------------------------
#define ERRST_NOT_FOUND_CAMERA	0xE0000001
#define ERRST_ALL_CAMARA_OPENED	0xE0000002
#define ERRST_INVALID_CAMERA_HANDLE	0xE0000003
#define ERRST_INVALID_FUNCTION_RECEIVING	0xE0000004
#define ERRST_USB_COMMAND_TRANSFER	0xE0000005
#define ERRST_WINDOW_ALREADY_EXISTS	0xE0000006
#define ERRST_WINDOW_DOES_NOT_EXISTS	0xE0000007
#define ERRST_INVALID_FUNCTION_RECORDING	0xE0000008
#define ERRST_AVI_STREAM	0xE0000009
#define ERRST_AVI_NOCOMPRESSOR	0xE000000A
#define ERRST_AVI_UNSUPPORTED	0xE000000B
#define ERRST_AVI_DISK	0xE000000C
#define ERRST_AVI_CANCELED	0xE000000D
#define ERRST_AVI_WRITE	0xE000000E
#define ERRST_INVALID_FILE_NAME	0xE000000F
#define ERRST_FILE_OPEN	0xE0000010
#define ERRST_FILE_WRITE	0xE0000011
#define ERRST_NOT_SUPPORTED_FUNCTION	0xE0000021
//-----------------------------------------------------------------------------
//WM_STCAM
//-----------------------------------------------------------------------------
#define WM_STCAM_TRANSFER_START	0xB001
#define WM_STCAM_TRANSFER_FINISH	0xB002
#define WM_STCAM_PREVIEW_WINDOW_CREATE	0xB003
#define WM_STCAM_PREVIEW_WINDOW_CLOSE	0xB004
#define WM_STCAM_PREVIEW_WINDOW_RESIZE	0xB005
#define WM_STCAM_PREVIEW_MASK_RESIZE	0xB006
#define WM_STCAM_PREVIEW_DEST_RESIZE	0xB007
#define WM_STCAM_AVI_FILE_START	0xB008
#define WM_STCAM_AVI_FILE_FINISH	0xB009
#define WM_STCAM_PREVIEW_MENU_COMMAND	0xB00A
#define WM_STCAM_UPDATED_PREVIEW_IMAGE	0xB00B
//-----------------------------------------------------------------------------
//COLOR_ARRAY
//-----------------------------------------------------------------------------
#define STCAM_COLOR_ARRAY_MONO	0x0001
#define STCAM_COLOR_ARRAY_RGGB	0x0002
#define STCAM_COLOR_ARRAY_GRBG	0x0003
#define STCAM_COLOR_ARRAY_GBRG	0x0004
#define STCAM_COLOR_ARRAY_BGGR	0x0005
//-----------------------------------------------------------------------------
//TRANSER_BITS_PER_PIXEL
//-----------------------------------------------------------------------------
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_08	0x00000001
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_10	0x00000002
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_10P	0x00010000
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_12	0x00000004
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_12P	0x00020000
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_14	0x00000008
#define STCAM_TRANSFER_BITS_PER_PIXEL_RAW_16	0x00000010
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_08	0x00000020
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_10	0x00000040
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_10P	0x00100000
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_12	0x00000080
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_12P	0x00200000
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_14	0x00000100
#define STCAM_TRANSFER_BITS_PER_PIXEL_MONO_16	0x00000200
#define STCAM_TRANSFER_BITS_PER_PIXEL_BGR_08	0x00000400
#define STCAM_TRANSFER_BITS_PER_PIXEL_BGR_10	0x00000800
#define STCAM_TRANSFER_BITS_PER_PIXEL_YCBCR411_08	0x00001000
#define STCAM_TRANSFER_BITS_PER_PIXEL_YCBCR422_08	0x00002000
#define STCAM_TRANSFER_BITS_PER_PIXEL_YCBCR444_08	0x00004000
#define STCAM_TRANSFER_BITS_PER_PIXEL_08	0x00000001
#define STCAM_TRANSFER_BITS_PER_PIXEL_10	0x00000002
#define STCAM_TRANSFER_BITS_PER_PIXEL_12	0x00000004
#define STCAM_TRANSER_BITS_PER_PIXEL_08	0x00000001
#define STCAM_TRANSER_BITS_PER_PIXEL_16	0x00000002
//-----------------------------------------------------------------------------
//IMAGE_SIZE_MODE
//-----------------------------------------------------------------------------
#define STCAM_IMAGE_SIZE_MODE_CUSTOM	0x00000001
#define STCAM_IMAGE_SIZE_MODE_VGA	0x00000008
#define STCAM_IMAGE_SIZE_MODE_XGA	0x00000020
#define STCAM_IMAGE_SIZE_MODE_QUAD_VGA	0x00000080
#define STCAM_IMAGE_SIZE_MODE_SXGA	0x00000100
#define STCAM_IMAGE_SIZE_MODE_UXGA	0x00000400
//-----------------------------------------------------------------------------
//SCAN_MODE
//-----------------------------------------------------------------------------
#define STCAM_SCAN_MODE_NORMAL	0x0000
#define STCAM_SCAN_MODE_PARTIAL_2	0x0001
#define STCAM_SCAN_MODE_PARTIAL_4	0x0002
#define STCAM_SCAN_MODE_PARTIAL_1	0x0004
#define STCAM_SCAN_MODE_VARIABLE_PARTIAL	0x0008
#define STCAM_SCAN_MODE_BINNING	0x0010
#define STCAM_SCAN_MODE_BINNING_PARTIAL_1	0x0020
#define STCAM_SCAN_MODE_BINNING_PARTIAL_2	0x0040
#define STCAM_SCAN_MODE_BINNING_PARTIAL_4	0x0080
#define STCAM_SCAN_MODE_BINNING_VARIABLE_PARTIAL	0x0100
#define STCAM_SCAN_MODE_AOI	0x8000
#define STCAM_SCAN_MODE_ROI	0x8000
//-----------------------------------------------------------------------------
//PIXEL_FORMAT
//-----------------------------------------------------------------------------
#define STCAM_PIXEL_FORMAT_08_MONO_OR_RAW	0x00000001
#define STCAM_PIXEL_FORMAT_24_BGR	0x00000004
#define STCAM_PIXEL_FORMAT_32_BGR	0x00000008
//-----------------------------------------------------------------------------
//COLOR_INTERPOLATION
//-----------------------------------------------------------------------------
#define STCAM_COLOR_INTERPOLATION_NONE_MONO	0
#define STCAM_COLOR_INTERPOLATION_NONE_COLOR	1
#define STCAM_COLOR_INTERPOLATION_NEAREST_NEIGHBOR	2
#define STCAM_COLOR_INTERPOLATION_BILINEAR	3
#define STCAM_COLOR_INTERPOLATION_BILINEAR_FALSE_COLOR_REDUCTION	5
#define STCAM_COLOR_INTERPOLATION_BICUBIC	4
//-----------------------------------------------------------------------------
//ASPECT
//-----------------------------------------------------------------------------
#define STCAM_ASPECT_MODE_FIXED	0
#define STCAM_ASPECT_MODE_KEEP_ASPECT	1
#define STCAM_ASPECT_MODE_ADJUST_WINDOW	2
#define STCAM_ASPECT_MODE_MASK_SIZE	3
#define STCAM_ASPECT_MODE_CUSTOM_OFFSET	254
#define STCAM_ASPECT_MODE_CUSTOM	255
#define STCAM_ASPECT_MODE_CUSTOM_CENTER	255
//-----------------------------------------------------------------------------
//MAGNIFICATION
//-----------------------------------------------------------------------------
#define STCAM_MAGNIFICATION_MODE_OFF	0
#define STCAM_MAGNIFICATION_MODE_ON	1
//-----------------------------------------------------------------------------
//ALCMODE
//-----------------------------------------------------------------------------
#define STCAM_ALCMODE_FIXED_SHUTTER_AGC_OFF	0
#define STCAM_ALCMODE_AUTO_SHUTTER_ON_AGC_ON	1
#define STCAM_ALCMODE_AUTO_SHUTTER_ON_AGC_OFF	2
#define STCAM_ALCMODE_FIXED_SHUTTER_AGC_ON	3
#define STCAM_ALCMODE_AUTO_SHUTTER_AGC_ONESHOT	4
#define STCAM_ALCMODE_AUTO_SHUTTER_ONESHOT_AGC_OFF	5
#define STCAM_ALCMODE_FIXED_SHUTTER_AGC_ONESHOT	6
#define STCAM_ALCMODE_CAMERA_AE_ON	16
#define STCAM_ALCMODE_CAMERA_AGC_ON	32
#define STCAM_ALCMODE_CAMERA_AE_AGC_ON	48
#define STCAM_ALCMODE_ALC_FIXED_AGC_OFF	0
#define STCAM_ALCMODE_ALC_FULLAUTO_AGC_ON	1
#define STCAM_ALCMODE_ALC_FULLAUTO_AGC_OFF	2
#define STCAM_ALCMODE_ALC_FIXED_AGC_ON	3
#define STCAM_ALCMODE_ALCAGC_ONESHOT	4
#define STCAM_ALCMODE_ALC_ONESHOT_AGC_OFF	5
#define STCAM_ALCMODE_ALC_FIXED_AGC_ONESHOT	6
//-----------------------------------------------------------------------------
//WB
//-----------------------------------------------------------------------------
#define STCAM_WB_OFF	0
#define STCAM_WB_MANUAL	1
#define STCAM_WB_FULLAUTO	2
#define STCAM_WB_ONESHOT	3
//-----------------------------------------------------------------------------
//GAMMA
//-----------------------------------------------------------------------------
#define STCAM_GAMMA_OFF	0
#define STCAM_GAMMA_ON	1
#define STCAM_GAMMA_REVERSE	2
#define STCAM_GAMMA_TABLE	255
//-----------------------------------------------------------------------------
//GAMMA_TARGET
//-----------------------------------------------------------------------------
#define STCAM_GAMMA_TARGET_Y	0
#define STCAM_GAMMA_TARGET_R	1
#define STCAM_GAMMA_TARGET_GR	2
#define STCAM_GAMMA_TARGET_GB	3
#define STCAM_GAMMA_TARGET_B	4
//-----------------------------------------------------------------------------
//SHARPNESS
//-----------------------------------------------------------------------------
#define STCAM_SHARPNESS_OFF	0
#define STCAM_SHARPNESS_ON	1
//-----------------------------------------------------------------------------
//HUE_SATURATION
//-----------------------------------------------------------------------------
#define STCAM_HUE_SATURATION_OFF	0
#define STCAM_HUE_SATURATION_ON	1
//-----------------------------------------------------------------------------
//COLOR_MATRIX
//-----------------------------------------------------------------------------
#define STCAM_COLOR_MATRIX_OFF	0x00
#define STCAM_COLOR_MATRIX_CUSTOM	0xFF
//-----------------------------------------------------------------------------
//MIRROR
//-----------------------------------------------------------------------------
#define STCAM_MIRROR_OFF	0
#define STCAM_MIRROR_HORIZONTAL	1
#define STCAM_MIRROR_VERTICAL	2
#define STCAM_MIRROR_HORIZONTAL_VERTICAL	3
#define STCAM_MIRROR_HORIZONTAL_CAMERA	16
#define STCAM_MIRROR_VERTICAL_CAMERA	32
//-----------------------------------------------------------------------------
//ROTATION
//-----------------------------------------------------------------------------
#define STCAM_ROTATION_OFF	0
#define STCAM_ROTATION_CLOCKWISE_90	1
#define STCAM_ROTATION_COUNTERCLOCKWISE_90	2
//-----------------------------------------------------------------------------
//AVI_COMPRESSOR
//-----------------------------------------------------------------------------
#define STCAM_AVI_COMPRESSOR_UNCOMPRESSED	0x00000000
#define STCAM_AVI_COMPRESSOR_MJPG	0x47504A4D
#define STCAM_AVI_COMPRESSOR_MP42	0x3234706D
#define STCAM_AVI_COMPRESSOR_MPV4	0x3467706D
#define STCAM_AVI_COMPRESSOR_DIALOG_BOX	0xFFFFFFFF
//-----------------------------------------------------------------------------
//CLOCK_MODE
//-----------------------------------------------------------------------------
#define STCAM_CLOCK_MODE_NORMAL	0x00000000
#define STCAM_CLOCK_MODE_DIV_2	0x00000001
#define STCAM_CLOCK_MODE_DIV_4	0x00000002
#define STCAM_CLOCK_MODE_VGA_90FPS	0x00000100
#define STCAM_CLOCK_MODE_CUSTOM	0x80000000
//-----------------------------------------------------------------------------
//USBPID
//-----------------------------------------------------------------------------
#define STCAM_USBPID_STC_C33USB	0x0305
#define STCAM_USBPID_STC_B33USB	0x0705
#define STCAM_USBPID_STC_B83USB	0x0805
#define STCAM_USBPID_STC_C83USB	0x0605
#define STCAM_USBPID_STC_TB33USB	0x0906
#define STCAM_USBPID_STC_TC33USB	0x1006
#define STCAM_USBPID_STC_TB83USB	0x1106
#define STCAM_USBPID_STC_TC83USB	0x1206
#define STCAM_USBPID_STC_TB133USB	0x0109
#define STCAM_USBPID_STC_TC133USB	0x0209
#define STCAM_USBPID_STC_TB152USB	0x1306
#define STCAM_USBPID_STC_TC152USB	0x1406
#define STCAM_USBPID_STC_TB202USB	0x1506
#define STCAM_USBPID_STC_TC202USB	0x1606
#define STCAM_USBPID_STC_MB33USB	0x0110
#define STCAM_USBPID_STC_MC33USB	0x0210
#define STCAM_USBPID_STC_MB83USB	0x0310
#define STCAM_USBPID_STC_MC83USB	0x0410
#define STCAM_USBPID_STC_MB133USB	0x0510
#define STCAM_USBPID_STC_MC133USB	0x0610
#define STCAM_USBPID_STC_MB152USB	0x0710
#define STCAM_USBPID_STC_MC152USB	0x0810
#define STCAM_USBPID_STC_MB202USB	0x0910
#define STCAM_USBPID_STC_MC202USB	0x1010
#define STCAM_USBPID_STC_MBA5MUSB3	0x0111
#define STCAM_USBPID_STC_MCA5MUSB3	0x0211
#define STCAM_USBPID_STC_MBE132U3V	0x0112
#define STCAM_USBPID_STC_MCE132U3V	0x0212
#define STCAM_USBPID_STC_MBCM401U3V	0x0113
#define STCAM_USBPID_STC_MCCM401U3V	0x0213
#define STCAM_USBPID_STC_MBCM200U3V	0x0313
#define STCAM_USBPID_STC_MCCM200U3V	0x0413
#define STCAM_USBPID_STC_MBCM33U3V	0x0513
#define STCAM_USBPID_STC_MCCM33U3V	0x0613
#define STCAM_USBPID_STC_MBS241U3V	0x0713
#define STCAM_USBPID_STC_MCS241U3V	0x0813
#define STCAM_USBPID_STC_MBE132U3V_IR	0x0114
#define STCAM_USBPID_STC_RHB33U3V	0x0115
#define STCAM_USBPID_STC_RHC33U3V	0x0215
#define STCAM_USBPID_STC_MBS510U3V	0x0315
#define STCAM_USBPID_STC_MCS510U3V	0x0415
#define STCAM_USBPID_STC_MBS322U3V	0x0515
#define STCAM_USBPID_STC_MCS322U3V	0x0615
//-----------------------------------------------------------------------------
//AVI_STATUS
//-----------------------------------------------------------------------------
#define STCAM_AVI_STATUS_STOP	0x00
#define STCAM_AVI_STATUS_START	0x01
#define STCAM_AVI_STATUS_PAUSE	0x02
//-----------------------------------------------------------------------------
//DISPLAY_MODE
//-----------------------------------------------------------------------------
#define STCAM_DISPLAY_MODE_GDI	0x00
#define STCAM_DISPLAY_MODE_GDI_HALFTONE	0x08
#define STCAM_DISPLAY_MODE_DD_OFFSCREEN	0x01
#define STCAM_DISPLAY_MODE_DD_OVERLAY	0x02
#define STCAM_DISPLAY_MODE_DD_OFFSCREEN_HQ	0x03
#define STCAM_DISPLAY_MODE_DD_OVERLAY_HQ	0x04
#define STCAM_DISPLAY_MODE_DIRECTX	0x05
#define STCAM_DISPLAY_MODE_DIRECTX_VSYNC_ON	0x06
#define STCAM_DISPLAY_MODE_DIRECTX_VSYNC_ON2	0x07
#define STCAM_DISPLAY_MODE_DIRECTX_FPU	0x09
#define STCAM_DISPLAY_MODE_DIRECTX_VSYNC_ON_FPU	0x0A
#define STCAM_DISPLAY_MODE_DIRECTX_VSYNC_ON2_FPU	0x0B
//-----------------------------------------------------------------------------
//CAMERA_SETTING
//-----------------------------------------------------------------------------
#define STCAM_CAMERA_SETTING_INITIALIZE	0x8000
#define STCAM_CAMERA_SETTING_WRITE	0x2000
#define STCAM_CAMERA_SETTING_READ	0x1000
#define STCAM_CAMERA_SETTING_STANDARD	0x0800
#define STCAM_CAMERA_SETTING_DEFECT_PIXEL_POSITION	0x0400
//-----------------------------------------------------------------------------
//DEFECT_PIXEL_CORRECTION
//-----------------------------------------------------------------------------
#define STCAM_DEFECT_PIXEL_CORRECTION_OFF	0x0000
#define STCAM_DEFECT_PIXEL_CORRECTION_ON	0x0001
//-----------------------------------------------------------------------------
//BINNING_SUM
//-----------------------------------------------------------------------------
#define STCAM_BINNING_SUM_MODE_OFF	0x0000
#define STCAM_BINNING_SUM_MODE_H	0x0001
#define STCAM_BINNING_SUM_MODE_V	0x0100
//-----------------------------------------------------------------------------
//AVI_FILE_FORMAT
//-----------------------------------------------------------------------------
#define STCAM_AVI_FILE_FORMAT_AVI1	0
#define STCAM_AVI_FILE_FORMAT_AVI2	1
//-----------------------------------------------------------------------------
//SHADING_CORRECTION_MODE
//-----------------------------------------------------------------------------
#define STCAM_SHADING_CORRECTION_MODE_OFF	0x0000
#define STCAM_SHADING_CORRECTION_MODE_CALIBRATION_MULTIPLICATION	0x0001
#define STCAM_SHADING_CORRECTION_MODE_ON_MULTIPLICATION	0x0002
#define STCAM_SHADING_CORRECTION_MODE_CALIBRATION_ADDITION	0x0003
#define STCAM_SHADING_CORRECTION_MODE_ON_ADDITION	0x0004
//-----------------------------------------------------------------------------
//CAMERA_FUNCTION
//-----------------------------------------------------------------------------
#define STCAM_CAMERA_FUNCTION_AWB	24
#define STCAM_CAMERA_FUNCTION_AGC	25
#define STCAM_CAMERA_FUNCTION_AE	26
#define STCAM_CAMERA_FUNCTION_STORE_CAMERA_SETTING	59
#define STCAM_CAMERA_FUNCTION_ANALOG_BLACK_LEVEL	0x00050006
#define STCAM_CAMERA_FUNCTION_DISABLED_ANALOG_GAIN	0x00090004
#define STCAM_CAMERA_FUNCTION_AGC_GAIN_TYPE	0x00090005
#define STCAM_CAMERA_FUNCTION_DEVICE_TEMPERATURE_MAINBOARD	0x00090009
#define STCAM_CAMERA_FUNCTION_ADJUSTMENT_MODE_DIGITAL_GAIN	0x0009000A
//-----------------------------------------------------------------------------
//ADJUSTMENT_MODE
//-----------------------------------------------------------------------------
#define STCAM_ADJUSTMENT_MODE_DIGITAL_GAIN	0x00000001
//-----------------------------------------------------------------------------
//DEVICE_TEMPERATURE
//-----------------------------------------------------------------------------
#define STCAM_DEVICE_TEMPERATURE_MAINBOARD	0x00000001
//-----------------------------------------------------------------------------
//HDR_TYPE
//-----------------------------------------------------------------------------
#define STCAM_HDR_TYPE_CMOSIS_4M	0x00000001
#ifdef __cplusplus
};
#endif  //__cplusplus
#endif //STCAMD_H

