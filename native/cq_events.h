#pragma once

#include "native.h"

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvPrivateMessage(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint msg_id, jlong acct, jbyteArray msg, jint font)
{
	const auto m = EvPriMsg(GetMethod(env, id, method));
	if (m)
	{
		auto result = m(type, msg_id, acct, ByteArrayToString(env, msg).c_str(), font);
		return result;
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvGroupMessage(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint msg_id, jlong grp,
	jlong acct, jbyteArray anon, jbyteArray msg, jint font)
{
	const auto m = EvGroupMsg(GetMethod(env, id, method));
	if (m)
	{
		auto result = m(type, msg_id, grp, acct, ByteArrayToString(env, anon).c_str(),
		                ByteArrayToString(env, msg).c_str(), font);
		return result;
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvGroupAdmin(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint time, jlong grp, jlong acct)
{
	const auto m = EvGroupAdmin(GetMethod(env, id, method));
	if (m)
	{
		return m(type, time, grp, acct);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvGroupMember(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint time, jlong grp, jlong acct, jlong mbr)
{
	const auto m = EvGroupMember(GetMethod(env, id, method));
	if (m)
	{
		return m(type, time, grp, acct, mbr);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvGroupBan(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint time, jlong grp,
	jlong acct, jlong mbr, jlong dur)
{
	const auto m = EvGroupBan(GetMethod(env, id, method));
	if (m)
	{
		return m(type, time, grp, acct, mbr, dur);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvRequestAddGroup(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint time,
	jlong grp, jlong acct, jbyteArray msg, jbyteArray flag)
{
	const auto m = EvRequestAddGroup(GetMethod(env, id, method));
	if (m)
	{
		auto result = m(type, time, grp, acct, ByteArrayToString(env, msg).c_str(),
		                ByteArrayToString(env, flag).c_str());
		return result;
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvRequestAddFriend(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint time,
	jlong acct, jbyteArray msg, jbyteArray flag)
{
	const auto m = EvRequestAddFriend(GetMethod(env, id, method));
	if (m)
	{
		auto result = m(type, time, acct, ByteArrayToString(env, msg).c_str(), ByteArrayToString(env, flag).c_str());
		return result;
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvFriendAdd(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint time, jlong acct)
{
	const auto m = EvFriendAdd(GetMethod(env, id, method));
	if (m)
	{
		return m(type, time, acct);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvFriendRecall(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint time, jlong acct, jbyteArray msg
)
{
	const auto m = EvFriendRecall(GetMethod(env, id, method));
	if (m)
	{
		return m(type, time, acct, ByteArrayToString(env, msg).c_str());
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvGroupRecall(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jint time, jlong grp, jlong acct, jlong mbr, jbyteArray msg
)
{
	const auto m = EvGroupRecall(GetMethod(env, id, method));
	if (m)
	{
		return m(type, time, grp, acct, mbr, ByteArrayToString(env, msg).c_str());
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvGroupNudge(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jlong grp, jlong acct, jlong mbr, jbyteArray action, jbyteArray suffix
)
{
	const auto m = EvGroupNudge(GetMethod(env, id, method));
	if (m)
	{
		return m(type, grp, acct, mbr, ByteArrayToString(env, action).c_str(), ByteArrayToString(env, suffix).c_str());
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvFriendNudge(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jlong acct, jlong mbr, jbyteArray action, jbyteArray suffix
)
{
	const auto m = EvFriendNudge(GetMethod(env, id, method));
	if (m)
	{
		return m(type, acct, mbr, ByteArrayToString(env, action).c_str(), ByteArrayToString(env, suffix).c_str());
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvFriendNickChanged(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jlong acct, jbyteArray fromNick, jbyteArray toNick
)
{
	const auto m = EvFriendNickChanged(GetMethod(env, id, method));
	if (m)
	{
		return m(type, acct, ByteArrayToString(env, fromNick).c_str(), ByteArrayToString(env, toNick).c_str());
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvGroupNameChanged(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jlong grp, jlong acct, jbyteArray fromName, jbyteArray toName
)
{
	const auto m = EvGroupNameChanged(GetMethod(env, id, method));
	if (m)
	{
		return m(type, grp, acct, ByteArrayToString(env, fromName).c_str(), ByteArrayToString(env, toName).c_str());
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_org_itxtech_mirainative_Bridge_pEvGroupMemberCardChanged(
	JNIEnv* env, jclass clz, jint id, jbyteArray method, jint type, jlong grp, jlong mbr, jbyteArray fromCard, jbyteArray toCard
)
{
	const auto m = EvGroupMemberCardChanged(GetMethod(env, id, method));
	if (m)
	{
		return m(type, grp, mbr, ByteArrayToString(env, fromCard).c_str(), ByteArrayToString(env, toCard).c_str());
	}
	return 0;
}