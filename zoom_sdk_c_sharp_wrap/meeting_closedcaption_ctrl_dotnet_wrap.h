#pragma once
using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "wrap/meeting_service_components_wrap/meeting_closedcaption_ctrl_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class SDKLiveTranscriptionOperationType : int
	{
		SDK_LiveTranscription_OperationType_None = 0,
		SDK_LiveTranscription_OperationType_Add,
		SDK_LiveTranscription_OperationType_Update,
		SDK_LiveTranscription_OperationType_Delete,
		SDK_LiveTranscription_OperationType_Complete,
		SDK_LiveTranscription_OperationType_NotSupported
	};

	public interface class ILiveTranscriptionMessageInfo
	{
	public:
		String^ GetMessageID();
		unsigned int^ GetSpeakerID();
		String^ GetSpeakerName();
		String^ GetMessageContent();
		TimeSpan^ GetTimeStamp();
		SDKLiveTranscriptionOperationType^ GetOperationType();
	};
	public delegate void onLiveTranscriptionMsgInfoReceived(ILiveTranscriptionMessageInfo^ pLiveTranscriptionMsgInfo);
	public delegate void onOriginalLanguageMsgReceived(ILiveTranscriptionMessageInfo^ pLiveTranscriptionMsgInfo);

	public interface class IMeetingClosedCaptionControllerDotNetWrap
	{
		public:
			bool IsMeetingSupportCC();
			bool IsLiveTranscriptionFeatureEnabled();
			void Add_CB_onLiveTranscriptionMsgInfoReceived(onLiveTranscriptionMsgInfoReceived^ cb);
			void Remove_CB_onLiveTranscriptionMsgInfoReceived(onLiveTranscriptionMsgInfoReceived^ cb);
			void Add_CB_onOriginalLanguageMsgReceived(onOriginalLanguageMsgReceived^ cb);
			void Remove_CB_onOriginalLanguageMsgReceived(onOriginalLanguageMsgReceived^ cb);
	};

	public ref class CMeetingClosedCaptionControllerDotNetWrap sealed : public IMeetingClosedCaptionControllerDotNetWrap
	{
	public:
		static property CMeetingClosedCaptionControllerDotNetWrap^ Instance
		{
			CMeetingClosedCaptionControllerDotNetWrap^ get() { return m_Instance; }
		}

		virtual bool IsMeetingSupportCC();
		virtual bool IsLiveTranscriptionFeatureEnabled();

		virtual void Add_CB_onLiveTranscriptionMsgInfoReceived(onLiveTranscriptionMsgInfoReceived^ cb) 
		{
			event_onLiveTranscriptionMsgInfoReceived += cb;
		}
		virtual void Remove_CB_onLiveTranscriptionMsgInfoReceived(onLiveTranscriptionMsgInfoReceived^ cb)
		{
			event_onLiveTranscriptionMsgInfoReceived -= cb;
		}
		virtual void Add_CB_onOriginalLanguageMsgReceived(onOriginalLanguageMsgReceived^ cb)
		{
			event_onOriginalLanguageMsgReceived += cb;
		}
		virtual void Remove_CB_onOriginalLanguageMsgReceived(onOriginalLanguageMsgReceived^ cb)
		{
			event_onOriginalLanguageMsgReceived -= cb;
		}

		void BindEvent();
		void procLiveTranscriptionMsgInfoReceived(ILiveTranscriptionMessageInfo^ pLiveTranscriptionMsgInfo);
		void procOriginalLanguageMsgReceived(ILiveTranscriptionMessageInfo^ pLiveTranscriptionMsgInfo);

		static ILiveTranscriptionMessageInfo^ CMeetingClosedCaptionControllerDotNetWrap::TranslateLiveTranscriptionMessageInfo(ZOOM_SDK_NAMESPACE::ILiveTranscriptionMessageInfo* pHandler);

	private:
		CMeetingClosedCaptionControllerDotNetWrap() {};
		virtual ~CMeetingClosedCaptionControllerDotNetWrap() {};
		event onLiveTranscriptionMsgInfoReceived^ event_onLiveTranscriptionMsgInfoReceived;
		event onOriginalLanguageMsgReceived^ event_onOriginalLanguageMsgReceived;
		static CMeetingClosedCaptionControllerDotNetWrap^ m_Instance = gcnew CMeetingClosedCaptionControllerDotNetWrap;
	};
}
