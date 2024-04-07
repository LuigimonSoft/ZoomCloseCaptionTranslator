#include "stdafx.h"
#include "meeting_closedcaption_ctrl_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP 
{
	//translate event
	private ref class CLiveTranscriptionMessageInfo sealed : public ILiveTranscriptionMessageInfo
	{
	public:
		CLiveTranscriptionMessageInfo()
		{
			m_pHandler = NULL;
		}

		CLiveTranscriptionMessageInfo(ZOOM_SDK_NAMESPACE::ILiveTranscriptionMessageInfo* pHandler)
		{
			m_pHandler = pHandler;
		}
		
		~CLiveTranscriptionMessageInfo()
		{
			m_pHandler = NULL;
		}

		virtual String^ GetMessageID()
		{
			if (m_pHandler)
				return WChar2PlatformString(m_pHandler->GetMessageID());
			
			return nullptr;
		}

		virtual String^ GetSpeakerName()
		{
			if (m_pHandler)
				return WChar2PlatformString(m_pHandler->GetSpeakerName());

			return nullptr;
		}

		virtual unsigned int^ GetSpeakerID()
		{
			if (m_pHandler)
				return m_pHandler->GetSpeakerID();

			return nullptr;
		}

		virtual String^ GetMessageContent()
		{
			if (m_pHandler)
				return WChar2PlatformString(m_pHandler->GetMessageContent());

			return nullptr;
		}

		virtual TimeSpan^ GetTimeStamp()
		{
			if (m_pHandler)
				return gcnew TimeSpan(m_pHandler->GetTimeStamp());

			return nullptr;
		}

		virtual SDKLiveTranscriptionOperationType^ GetOperationType()
		{
			if (m_pHandler)
				return (SDKLiveTranscriptionOperationType)m_pHandler->GetMessageOperationType();

			return SDKLiveTranscriptionOperationType::SDK_LiveTranscription_OperationType_None;
		}



	private:
		ZOOM_SDK_NAMESPACE::ILiveTranscriptionMessageInfo* m_pHandler;
	};

	ILiveTranscriptionMessageInfo^ CMeetingClosedCaptionControllerDotNetWrap::TranslateLiveTranscriptionMessageInfo(ZOOM_SDK_NAMESPACE::ILiveTranscriptionMessageInfo* pHandler)
	{
		if (pHandler)
		{
			return gcnew CLiveTranscriptionMessageInfo(pHandler);
		}

		return nullptr;
	}

	class MeetingClosedCaptionCtrlEventHanlder
	{
	public:
		static MeetingClosedCaptionCtrlEventHanlder& GetInst()
		{
			static MeetingClosedCaptionCtrlEventHanlder inst;
			return inst;
		}

		void onLiveTranscriptionMessageReceived(ZOOM_SDK_NAMESPACE::ILiveTranscriptionMessageInfo* pMessageInfo)
		{
			if (CMeetingClosedCaptionControllerDotNetWrap::Instance)
			{
				CMeetingClosedCaptionControllerDotNetWrap::Instance->procLiveTranscriptionMsgInfoReceived(CMeetingClosedCaptionControllerDotNetWrap::TranslateLiveTranscriptionMessageInfo(pMessageInfo));
			}
		}

		void onOriginalLanguageMsgReceived(ZOOM_SDK_NAMESPACE::ILiveTranscriptionMessageInfo* pMessageInfo)
		{
			if (CMeetingClosedCaptionControllerDotNetWrap::Instance)
			{
				CMeetingClosedCaptionControllerDotNetWrap::Instance->procOriginalLanguageMsgReceived(CMeetingClosedCaptionControllerDotNetWrap::TranslateLiveTranscriptionMessageInfo(pMessageInfo));
			}
		}

	private:
		~MeetingClosedCaptionCtrlEventHanlder() {}
	};
	//

	void CMeetingClosedCaptionControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingClosedCaptionController().m_cbonLiveTranscriptionMsgInfoReceived =
			std::bind(&MeetingClosedCaptionCtrlEventHanlder::onLiveTranscriptionMessageReceived,
				&MeetingClosedCaptionCtrlEventHanlder::GetInst(), std::placeholders::_1);

		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingClosedCaptionController().m_cbonOriginalLanguageMsgReceived =
			std::bind(&MeetingClosedCaptionCtrlEventHanlder::onOriginalLanguageMsgReceived,
				&MeetingClosedCaptionCtrlEventHanlder::GetInst(), std::placeholders::_1);
	}

	void CMeetingClosedCaptionControllerDotNetWrap::procLiveTranscriptionMsgInfoReceived(ILiveTranscriptionMessageInfo^ pMessageInfo)
	{
		event_onLiveTranscriptionMsgInfoReceived(pMessageInfo);
	}

	void CMeetingClosedCaptionControllerDotNetWrap::procOriginalLanguageMsgReceived(ILiveTranscriptionMessageInfo^ pMessageInfo)
	{
		event_onOriginalLanguageMsgReceived(pMessageInfo);
	}

	bool CMeetingClosedCaptionControllerDotNetWrap::IsMeetingSupportCC()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingClosedCaptionController().IsMeetingSupportCC();
	}

	bool CMeetingClosedCaptionControllerDotNetWrap::IsLiveTranscriptionFeatureEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingClosedCaptionController().IsLiveTranscriptionFeatureEnabled();
	}
}