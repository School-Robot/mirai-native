/*
 *
 * Mirai Native
 *
 * Copyright (C) 2020-2022 iTX Technologies
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author PeratX
 * @website https://github.com/iTXTech/mirai-native
 *
 */

package org.itxtech.mirainative.util

import org.itxtech.mirainative.plugin.NativePlugin

object NpmHelper {
    fun state(p: NativePlugin, h: Boolean = true) =
        (if (h) "状态：" else "") + (if (p.enabled) "已启用 " else "已禁用 ") + (if (p.loaded) "已加载" else "已卸载")

    fun name(p: NativePlugin) = if (p.pluginInfo != null) p.pluginInfo!!.name else p.identifier

    fun auth(i: Int) = when (i) {
        20 -> "[敏感]取Cookies getCookies / getCsrfToken"
        30 -> "接收语音 getRecord"
        101 -> "发送群消息 sendGroupMsg"
        103 -> "发送讨论组消息 sendDiscussMsg"
        106 -> "发送私聊消息 sendPrivateMsg"
        110 -> "[敏感]发送赞 sendLike"
        120 -> "置群员移除 setGroupKick"
        121 -> "置群员禁言 setGroupBan"
        122 -> "置群管理员 setGroupAdmin"
        123 -> "置全群禁言 setGroupWholeBan"
        124 -> "置匿名群员禁言 setGroupAnonymousBan"
        125 -> "置群匿名设置 setGroupAnonymous"
        126 -> "置群成员名片 setGroupCard"
        127 -> "[敏感]置群退出 setGroupLeave"
        128 -> "置群成员专属头衔 setGroupSpecialTitle"
        130 -> "取群成员信息 getGroupMemberInfo"
        131 -> "取陌生人信息 getStrangerInfo"
        132 -> "取群信息 getGroupInfo"
        140 -> "置讨论组退出 setDiscussLeave"
        150 -> "置好友添加请求 setFriendAddRequest"
        151 -> "置群添加请求 setGroupAddRequest"
        160 -> "取群成员列表 getGroupMemberList"
        161 -> "取群列表 getGroupList"
        162 -> "取好友列表 getFriendList"
        180 -> "撤回消息 deleteMsg"
        else -> "未知权限"
    }

    fun summary(p: NativePlugin) = buildString {
        val i = p.pluginInfo
        appendLine("标识符：${p.identifier}")
        appendLine("状态：${state(p, false)}")
        if (i == null) {
            appendLine("Id：${p.id} （插件信息缺失）")
            appendLine("CQ API：${p.api}")
        } else {
            appendLine("Id：${p.id}")
            appendLine("CQ API：${p.api} CQ API（JSON）：${i.apiver}")
            appendLine("名称：${i.name}")
            appendLine("版本：${i.version} 版本号：${i.version_id}")
            appendLine("描述：${i.description}")
            appendLine("作者：${i.author}")
            appendLine("注册了 ${i.event.size} 个事件")
            i.event.forEach { ev ->
                appendLine("类型：${ev.type} 描述：${ev.name} 方法名：${ev.function}")
            }
            appendLine("注册了 ${i.status.size} 个悬浮窗项目")
            i.status.forEach { s ->
                appendLine("名称：${s.name} 标题：${s.title} 方法名：${s.function}")
            }
            appendLine("注册了 ${i.menu.size} 个菜单入口")
            i.menu.forEach { m ->
                appendLine("名称：${m.name} 方法名：${m.function}")
            }
            appendLine("申请了 ${i.auth.size} 个权限")
            i.auth.forEach { a ->
                appendLine("ID：${a} 权限：${auth(a)}")
            }
        }
    }
}
