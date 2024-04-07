#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingSmartSummaryController* InitIMeetingSmartSummaryControllerFunc(IMeetingSmartSummaryControllerEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingSmartSummaryControllerFunc(IMeetingSmartSummaryController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingSmartSummaryController, IMeetingSmartSummaryControllerEvent)
NORMAL_CLASS(IMeetingSmartSummaryController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingSmartSummaryController, IMeetingServiceWrap)
virtual SDKError SetEvent(IMeetingSmartSummaryControllerEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual bool IsSmartSummarySupported() = 0;
DEFINE_FUNC_0(IsSmartSummarySupported, bool)
//virtual bool IsSmartSummaryEnabled() = 0;
DEFINE_FUNC_0(IsSmartSummaryEnabled, bool)
//virtual SDKError CanEnableSmartSummaryFeature() = 0;
DEFINE_FUNC_0(CanEnableSmartSummaryFeature, SDKError)
//virtual SDKError EnableSmartSummaryFeature() = 0;
DEFINE_FUNC_0(EnableSmartSummaryFeature, SDKError)
//virtual SDKError CanStartSmartSummary() = 0;
DEFINE_FUNC_0(CanStartSmartSummary, SDKError)
//virtual SDKError StartSmartSummary() = 0;
DEFINE_FUNC_0(StartSmartSummary, SDKError)
//virtual SDKError StopSmartSummary() = 0;
DEFINE_FUNC_0(StopSmartSummary, SDKError)
//virtual bool IsSmartSummaryStarted() = 0;
DEFINE_FUNC_0(IsSmartSummaryStarted, bool)
//virtual SDKError CanRequestEnableSmartSummaryFeature() = 0;
DEFINE_FUNC_0(CanRequestEnableSmartSummaryFeature, SDKError)
//virtual SDKError RequestEnableSmartSummaryFeature() = 0;
DEFINE_FUNC_0(RequestEnableSmartSummaryFeature, SDKError)
//virtual SDKError CanRequestStartSmartSummary() = 0;
DEFINE_FUNC_0(CanRequestStartSmartSummary, SDKError)
//virtual SDKError RequestStartSmartSummary() = 0;
DEFINE_FUNC_0(RequestStartSmartSummary, SDKError)

//virtual void onSmartSummaryStatusChange(bool isStarted) = 0;
CallBack_FUNC_1(onSmartSummaryStatusChange, bool, isStarted)
//virtual void onSmartSummaryPrivilegeRequested(unsigned int senderId, ISmartSummaryPrivilegeHandler* handler) = 0;
CallBack_FUNC_2(onSmartSummaryPrivilegeRequested, unsigned int, senderId, ISmartSummaryPrivilegeHandler*, handler)
//virtual void onSmartSummaryStartReqResponse(bool timeout, bool decline) = 0;
CallBack_FUNC_2(onSmartSummaryStartReqResponse, bool, timeout, bool, decline)
//virtual void onEnableSmartSummary() = 0;
CallBack_FUNC_0(onEnableSmartSummary)
END_CLASS_DEFINE(IMeetingSmartSummaryController)
END_ZOOM_SDK_NAMESPACE