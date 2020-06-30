//
//  RTMClient+Broadcast_Chat.h
//  Rtm
//
//  Created by zsl on 2019/12/24.
//  Copyright © 2019 FunPlus. All rights reserved.
//

#import <Rtm/Rtm.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Broadcast_Chat)
/// 获取广播历史消息  对 getBroadCastHistoryMessageWithNum 的封装 mtypes = [30,31,32,40,41,42]
/// @param num int16 条数
/// @param desc 是否降序排列
/// @param begin int64 开始时间戳，精确到 毫秒
/// @param end int64 结束时间戳，精确到 毫秒
/// @param lastid int64 最后一条消息的id
/// @param timeout 请求超时时间 秒
/// @param tag 请求标识
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getBroadCastHistoryMessageChatWithNum:(NSNumber * _Nonnull)num
                                        desc:(BOOL)desc
                                       begin:(NSNumber * _Nullable)begin
                                         end:(NSNumber * _Nullable)end
                                      lastid:(NSNumber * _Nullable)lastid
                                     timeout:(int)timeout
                                         tag:(id _Nullable)tag
                                     success:(RTMAnswerSuccessCallBack)successCallback
                                        fail:(RTMAnswerFailCallBack)failCallback;
-(RTMAnswer*)getBroadCastHistoryMessageChatWithNum:(NSNumber * _Nonnull)num
                                              desc:(BOOL)desc
                                             begin:(NSNumber * _Nullable)begin
                                               end:(NSNumber * _Nullable)end
                                            lastid:(NSNumber * _Nullable)lastid
                                           timeout:(int)timeout;
@end

NS_ASSUME_NONNULL_END