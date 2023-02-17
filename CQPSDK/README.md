# 易语言SDK

修改自`CQP_EL_9.25`

## 事件列表

* `_eventDisable` 插件被禁用
* `_eventDiscussMsg` 讨论组消息（不支持）
* `_eventEnable` 插件被启用
* `_eventExit` Mirai停止
* `_eventFriend_Add` 好友已添加
* `_eventFriend_NickChanged` 好友昵称改变
* `_eventFriend_Nudge` 好友戳一戳
* `_eventFriend_Recall` 好友撤回
* `_eventGroup_MemberCardChanged` 群昵称改变
* `_eventGroup_MemberHonorChanged` 群成员荣耀改变
* `_eventGroup_NameChanged` 群名改变
* `_eventGroup_Nudge` 群戳一戳
* `_eventGroup_Recall` 群撤回
* `_eventGroupMsg` 群消息
* `_eventGroupUpload` 群文件上传（不支持）
* `_eventPrivateMsg` 私聊消息
* `_eventRequest_AddFriend` 好友添加请求
* `_eventRequest_AddGroup` 群添加请求
* `_eventStartup` Mirai启动
* `_eventSystem_GroupAdmin` 管理员变动
* `_eventSystem_GroupBan` 群禁言
* `_eventSystem_GroupMemberDecrease` 群成员减少
* `_eventSystem_GroupMemberIncrease` 群成员增加

## 事件类型

```kotlin
const val EVENT_STARTUP = 1001
const val EVENT_EXIT = 1002
const val EVENT_ENABLE = 1003
const val EVENT_DISABLE = 1004

const val EVENT_PRI_MSG = 21
const val EVENT_GROUP_MSG = 2
const val EVENT_DISCUSS_MSG = 4

const val EVENT_GROUP_UPLOAD = 11
const val EVENT_GROUP_ADMIN = 101
const val EVENT_GROUP_MEMBER_DEC = 102
const val EVENT_GROUP_MEMBER_INC = 103
const val EVENT_GROUP_BAN = 104
const val EVENT_GROUP_NAME_CHANGED = 106
const val EVENT_GROUP_MEMBER_CARD_CHANGED = 107
const val EVENT_GROUP_MEMBER_HONOR_CHANGED = 108

const val EVENT_FRIEND_ADD = 201

const val EVENT_REQUEST_FRIEND = 301
const val EVENT_REQUEST_GROUP = 302

const val EVENT_FRIEND_RECALL = 402
const val EVENT_GROUP_RECALL = 401

const val EVENT_GROUP_NUDGE = 501
const val EVENT_FRIEND_NUDGE = 502

const val EVENT_FRIEND_NICK_CHANGED = 202
```

```kotlin
const val GROUP_MEMBER_ARCHIVE = 1
const val GROUP_MEMBER_LOSE = 2

const val PRI_MSG_SUBTYPE_FRIEND = 11
const val PRI_MSG_SUBTYPE_ONLINE_STATE = 1
const val PRI_MSG_SUBTYPE_GROUP = 2
const val PRI_MSG_SUBTYPE_DISCUSS = 3

const val PERM_SUBTYPE_CANCEL_ADMIN = 1
const val PERM_SUBTYPE_SET_ADMIN = 2

const val MEMBER_LEAVE_QUIT = 1
const val MEMBER_LEAVE_KICK = 2

const val MEMBER_JOIN_PERMITTED = 1
const val MEMBER_JOIN_INVITED_BY_ADMIN = 2

const val REQUEST_GROUP_APPLY = 1 //他人申请
const val REQUEST_GROUP_INVITED = 2 //受邀

const val GROUP_UNMUTE = 1
const val GROUP_MUTE = 2

const val GROUP_RECALL_SELF = 1
const val GROUP_RECALL_OTHER = 2

const val GROUP_BOT_NUDGE_SELF = 11
const val GROUP_OTHER_NUDGE_SELF = 12
const val GROUP_OTHER_NUDGE_BOT = 21
const val GROUP_OTHER_NUDGE_OTHER = 22
const val FRIEND_NUDGE_BOT = 1
const val FRIEND_NUDGE_FRIEND = 2
```

## API列表

参考CQPAppSdk

## 权限列表

```kotlin
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
```

## JSON格式参考

```json
{
    "ret":1,
    "_ret":"返回码，固定为1",
    "apiver":10,
    "_apiver":"Api版本，本SDK为10",
    "name":"酷Q样例应用",
    "_name":"应用名称",
    "version":"1.0.0",
    "_version":"应用版本",
    "version_id":1,
    "_version_id":"应用顺序版本（每次发布时至少+1）",
    "author":"Example",
    "_author":"应用作者",
    "description":"酷Q样例应用(V9应用机制)",
    "_description":"插件说明",
    "_event":"事件列表，同一事件类型可重复定义（发布前请删除无用事件）",
    "event":[
        {
            "id":1,
            "_id":"事件ID",
            "type":21,
            "_type":"事件类型",
            "name":"私聊消息处理",
            "_name":"事件名称",
            "function":"_eventPrivateMsg",
            "_function":"事件对应函数",
            "priority":30000,
            "_priority":"事件优先级(参见 https://cqp.im/deveventpriority )（暂不支持）"
        }
    ],
    "_menu":"设置菜单（发布前请删除无用菜单，如果无需设置菜单请全部删除）",
    "menu":[
        {
            "name":"设置A",
            "_name":"菜单名称",
            "function":"_menuA",
            "_function":"菜单对应函数"
        }
    ],
    "_status":"悬浮窗状态（将应用运行状态等显示在酷Q悬浮窗）",
    "status":[
        {
            "id":1,
            "_id":"悬浮窗ID",
            "name":"运行时间",
            "_name":"名称",
            "title":"UPTIME",
            "_title":"英文名称",
            "function":"_statusUptime",
            "_function":"数据更新对应函数",
            "period":"1000",
            "_period":"更新间隔（单位ms（毫秒））"
        }
    ],
    "_auth":"应用权限（发布前请删除无用权限）",
    "auth":[
        101,
        103,
        106
    ]
}
```