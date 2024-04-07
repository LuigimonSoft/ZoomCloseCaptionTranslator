#include "meeting_smart_summary_wrap.h"
#include "meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingSmartSummaryController* InitIMeetingSmartSummaryControllerFunc(IMeetingSmartSummaryControllerEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingSmartSummaryController* pObj = pOwner->GetSDKObj()->GetMeetingSmartSummaryController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingSmartSummaryControllerFunc(IMeetingSmartSummaryController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual bool IsSmartSummarySupported() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, IsSmartSummarySupported, bool, false)
//virtual bool IsSmartSummaryEnabled() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, IsSmartSummaryEnabled, bool, false)
//virtual SDKError CanEnableSmartSummaryFeature() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, CanEnableSmartSummaryFeature, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError EnableSmartSummaryFeature() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, EnableSmartSummaryFeature, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError CanStartSmartSummary() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, CanStartSmartSummary, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError StartSmartSummary() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, StartSmartSummary, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError StopSmartSummary() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, StopSmartSummary, SDKError, SDKERR_UNINITIALIZE)
//virtual bool IsSmartSummaryStarted() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, IsSmartSummaryStarted, bool, false)
//virtual SDKError CanRequestEnableSmartSummaryFeature() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, CanRequestEnableSmartSummaryFeature, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError RequestEnableSmartSummaryFeature() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, RequestEnableSmartSummaryFeature, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError CanRequestStartSmartSummary() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, CanRequestStartSmartSummary, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError RequestStartSmartSummary() = 0;
IMPL_FUNC_0(IMeetingSmartSummaryController, RequestStartSmartSummary, SDKError, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE