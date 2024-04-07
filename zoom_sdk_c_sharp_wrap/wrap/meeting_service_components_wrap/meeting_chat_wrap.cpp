#include "meeting_chat_wrap.h"
#include "meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingChatController* InitIMeetingChatControllerFunc(IMeetingChatCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingChatController* pObj = pOwner->GetSDKObj()->GetMeetingChatController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingChatControllerFunc(IMeetingChatController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError SendChatMsgTo(const zchar_t* content, unsigned int receiver, SDKChatMessageType type) = 0;
IMPL_FUNC_3(IMeetingChatController, SendChatMsgTo, SDKError, const zchar_t*, content, unsigned int, receiver, SDKChatMessageType, type, SDKERR_UNINITIALIZE)
//virtual const ChatStatus* GetChatStatus() = 0;
IMPL_FUNC_0(IMeetingChatController, GetChatStatus, const ChatStatus*, NULL)
//virtual bool IsMeetingChatLegalNoticeAvailable() = 0;
IMPL_FUNC_0(IMeetingChatController, IsMeetingChatLegalNoticeAvailable, bool, false)
//virtual const zchar_t* getChatLegalNoticesPrompt() = 0;
IMPL_FUNC_0(IMeetingChatController, getChatLegalNoticesPrompt, const zchar_t*, NULL)
//virtual const zchar_t* getChatLegalNoticesExplained() = 0;
IMPL_FUNC_0(IMeetingChatController, getChatLegalNoticesExplained, const zchar_t*, NULL)
//virtual bool IsChatMessageCanBeDeleted(const zchar_t* msgID) = 0;
IMPL_FUNC_1(IMeetingChatController, IsChatMessageCanBeDeleted, bool, const zchar_t*, msgID, false)
//virtual SDKError DeleteChatMessage(const zchar_t* msgID) = 0;
IMPL_FUNC_1(IMeetingChatController, DeleteChatMessage, SDKError, const zchar_t*, msgID, SDKERR_UNINITIALIZE)
//virtual IList<const zchar_t*>* GetAllChatMessageID() = 0;
IMPL_FUNC_0(IMeetingChatController, GetAllChatMessageID, IList<const zchar_t*>*, NULL)
//virtual bool IsShareMeetingChatLegalNoticeAvailable() = 0;
IMPL_FUNC_0(IMeetingChatController, IsShareMeetingChatLegalNoticeAvailable, bool, false)
//virtual const zchar_t* GetShareMeetingChatStartedLegalNoticeContent() = 0;
IMPL_FUNC_0(IMeetingChatController, GetShareMeetingChatStartedLegalNoticeContent, const zchar_t*, NULL)
//virtual const zchar_t* GetShareMeetingChatStoppedLegalNoticeContent() = 0;
IMPL_FUNC_0(IMeetingChatController, GetShareMeetingChatStoppedLegalNoticeContent, const zchar_t*, NULL)
//virtual IChatMsgInfo* GetChatMessageById(const zchar_t* msgID) = 0;
IMPL_FUNC_1(IMeetingChatController, GetChatMessageById, IChatMsgInfo*, const zchar_t*, msgID, NULL)
//virtual IChatMsgInfoBuilder* GetChatMessageBuilder() = 0;
IMPL_FUNC_0(IMeetingChatController, GetChatMessageBuilder, IChatMsgInfoBuilder*, NULL)
//virtual SDKError SendChatMsgTo(IChatMsgInfo* msg) = 0;
IMPL_FUNC_1(IMeetingChatController, SendChatMsgTo, SDKError, IChatMsgInfo*, msg, SDKERR_UNINITIALIZE)
//virtual SDKError SetParticipantsChatPrivilege(SDKChatPrivilege privilege) = 0;
IMPL_FUNC_1(IMeetingChatController, SetParticipantsChatPrivilege, SDKError, SDKChatPrivilege, privilege, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE