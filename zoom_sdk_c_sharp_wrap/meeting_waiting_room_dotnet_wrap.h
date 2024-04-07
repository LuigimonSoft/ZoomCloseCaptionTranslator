#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	public delegate void onWaitingRoomUserJoin(unsigned int userID);
	public delegate void onWaitingRoomUserLeft(unsigned int userID);

	public interface class IMeetingWaitingRoomControllerDotNetWrap
	{
	public:
		bool IsSupportWaitingRoom();
		bool IsWaitingRoomOnEntryFlagOn();
		SDKError EnableWaitingRoomOnEntry(bool bEnable);
		array<unsigned int >^ GetWaitingRoomLst();
		IUserInfoDotNetWrap^ GetWaitingRoomUserInfoByID(unsigned int userid);
		SDKError AdmitToMeeting(unsigned int userid);
		SDKError PutInWaitingRoom(unsigned int userid);

		void Add_CB_onWaitingRoomUserJoin(onWaitingRoomUserJoin^ cb);
		void Add_CB_onWaitingRoomUserLeft(onWaitingRoomUserLeft^ cb);
		void Remove_CB_onWaitingRoomUserJoin(onWaitingRoomUserJoin^ cb);
		void Remove_CB_onWaitingRoomUserLeft(onWaitingRoomUserLeft^ cb);
	};

	private ref class CMeetingWaitingRoomControllerDotNetWrap sealed : public IMeetingWaitingRoomControllerDotNetWrap
	{
	public:
		static property CMeetingWaitingRoomControllerDotNetWrap^ Instance
		{
			CMeetingWaitingRoomControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();
		void procWaitingRoomUserJoin(unsigned int userID);
		void procWaitingRoomUserLeft(unsigned int userID);

		virtual bool IsSupportWaitingRoom();
		virtual bool IsWaitingRoomOnEntryFlagOn();
		virtual SDKError EnableWaitingRoomOnEntry(bool bEnable);
		virtual array<unsigned int >^ GetWaitingRoomLst();
		virtual IUserInfoDotNetWrap^ GetWaitingRoomUserInfoByID(unsigned int userid);
		virtual SDKError AdmitToMeeting(unsigned int userid);
		virtual SDKError PutInWaitingRoom(unsigned int userid);

		virtual void Add_CB_onWaitingRoomUserJoin(onWaitingRoomUserJoin^ cb)
		{
			event_onWaitingRoomUserJoin += cb;
		}

		virtual void Remove_CB_onWaitingRoomUserJoin(onWaitingRoomUserJoin^ cb)
		{
			event_onWaitingRoomUserJoin -= cb;
		}

		virtual void Add_CB_onWaitingRoomUserLeft(onWaitingRoomUserLeft^ cb)
		{
			event_onWaitingRoomUserLeft += cb;
		}

		virtual void Remove_CB_onWaitingRoomUserLeft(onWaitingRoomUserLeft^ cb)
		{
			event_onWaitingRoomUserLeft -= cb;
		}

	private:
		event onWaitingRoomUserJoin^ event_onWaitingRoomUserJoin;
		event onWaitingRoomUserLeft^ event_onWaitingRoomUserLeft;
		static CMeetingWaitingRoomControllerDotNetWrap^ m_Instance = gcnew CMeetingWaitingRoomControllerDotNetWrap;
	};
}