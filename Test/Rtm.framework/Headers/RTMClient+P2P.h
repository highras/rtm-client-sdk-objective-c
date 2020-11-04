//
//  RTMClient+PtoP.h
//  Rtm
//
//  Created by zsl on 2019/12/11.
//  Copyright © 2019 FunPlus. All rights reserved.
//

#import <Rtm/Rtm.h>
#import "RTMHistoryMessage.h"
#import "RTMGetMessage.h"
#import "RTMHistory.h"
#import "RTMSendAnswer.h"
#import "RTMHistoryMessageAnswer.h"
#import "RTMGetMessageAnswer.h"
#import "RTMSpeechRecognitionAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (P2P)

/// 发送P2P消息 
/// @param userId int64 接收人id
/// @param messageType int8 消息类型 请使用51-127
/// @param message 消息内容
/// @param attrs 属性 建议使用可解析的json字符串
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)sendP2PMessageToUserId:(NSNumber * _Nonnull)userId
                  messageType:(NSNumber * _Nonnull)messageType
                      message:(NSString * _Nonnull)message
                        attrs:(NSString * _Nonnull)attrs
                      timeout:(int)timeout
                      success:(void(^)(RTMSendAnswer * sendAnswer))successCallback
                         fail:(RTMAnswerFailCallBack)failCallback;
-(RTMSendAnswer*)sendP2PMessageToUserId:(NSNumber * _Nonnull)userId
                             messageType:(NSNumber * _Nonnull)messageType
                                 message:(NSString * _Nonnull)message
                                   attrs:(NSString * _Nonnull)attrs
                                 timeout:(int)timeout;


/// 发送P2P消息
/// @param userId int64 接收人id
/// @param messageType int8 消息类型 请使用51-127
/// @param data 消息内容 二进制数据
/// @param attrs 属性 建议使用可解析的json字符串
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)sendP2PMessageToUserId:(NSNumber * _Nonnull)userId
                  messageType:(NSNumber * _Nonnull)messageType
                         data:(NSData * _Nonnull)data
                        attrs:(NSString * _Nonnull)attrs
                      timeout:(int)timeout
                      success:(void(^)(RTMSendAnswer * sendAnswer))successCallback
                         fail:(RTMAnswerFailCallBack)failCallback;
-(RTMSendAnswer*)sendP2PMessageToUserId:(NSNumber * _Nonnull)userId
                            messageType:(NSNumber * _Nonnull)messageType
                                   data:(NSData * _Nonnull)data
                                  attrs:(NSString * _Nonnull)attrs
                                timeout:(int)timeout;



/// 获取历史P2P消息（包括自己发送的消息）
/// @param userId int64 获取和哪个uid之间的历史消息
/// @param desc 是否降序排列
/// @param num int16 条数
/// @param begin int64 开始时间戳，精确到 毫秒
/// @param end int64 结束时间戳，精确到 毫秒
/// @param lastid int64 最后一条消息的id  对应RTMGetMessage RTMHistoryMessage 的 cursorId字段
/// @param mtypes [int8] 消息类型
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getP2PHistoryMessageWithUserId:(NSNumber * _Nonnull)userId
                                 desc:(BOOL)desc
                                  num:(NSNumber * _Nonnull)num
                                begin:(NSNumber * _Nullable)begin
                                  end:(NSNumber * _Nullable)end
                               lastid:(NSNumber * _Nullable)lastid
                               mtypes:(NSArray <NSNumber *> * _Nullable)mtypes
                              timeout:(int)timeout
                              success:(void(^)(RTMHistory* _Nullable history))successCallback
                                 fail:(RTMAnswerFailCallBack)failCallback;
-(RTMHistoryMessageAnswer*)getP2PHistoryMessageWithUserId:(NSNumber * _Nonnull)userId
                                                     desc:(BOOL)desc
                                                      num:(NSNumber * _Nonnull)num
                                                    begin:(NSNumber * _Nullable)begin
                                                      end:(NSNumber * _Nullable)end
                                                   lastid:(NSNumber * _Nullable)lastid
                                                   mtypes:(NSArray <NSNumber *> * _Nullable)mtypes
                                                  timeout:(int)timeout;





/// 删除消息 p2p
/// @param messageId int64 消息id
/// @param fromUserId int64
/// @param toUserId int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)deleteMessageWithMessageId:(NSNumber * _Nonnull)messageId
                       fromUserId:(NSNumber * _Nonnull)fromUserId
                         toUserId:(NSNumber * _Nonnull)toUserId
                          timeout:(int)timeout
                          success:(void(^)(void))successCallback
                             fail:(RTMAnswerFailCallBack)failCallback;
-(RTMBaseAnswer*)deleteMessageWithMessageId:(NSNumber * _Nonnull)messageId
                                 fromUserId:(NSNumber * _Nonnull)fromUserId
                                   toUserId:(NSNumber * _Nonnull)toUserId
                                    timeout:(int)timeout;




/// 获取消息 p2p
/// @param messageId int64 消息id
/// @param fromUserId int64 发送者
/// @param toUserId int64 接收者
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getP2pMessageWithId:(NSNumber * _Nonnull)messageId
                fromUserId:(NSNumber * _Nonnull)fromUserId
                  toUserId:(NSNumber * _Nonnull)toUserId
                   timeout:(int)timeout
                   success:(void(^)(RTMGetMessage * _Nullable message))successCallback
                      fail:(RTMAnswerFailCallBack)failCallback;
-(RTMGetMessageAnswer*)getP2pMessageWithId:(NSNumber * _Nonnull)messageId
                                fromUserId:(NSNumber * _Nonnull)fromUserId
                                  toUserId:(NSNumber * _Nonnull)toUserId
                                   timeout:(int)timeout;



///// 语音识别 （调用此接口需在管理系统启用语音识别系统）调用这个接口的超时时间得加大到120s，此接口只支持通过rtm发送的语音消息，无需把原始语音再一次发送，节省流量
///// @param messageId int64 消息ID
///// @param fromUserId int64 发送者ID
///// @param toUserId int64 接收者ID
///// @param profanityFilter 敏感词过滤
///// @param timeout 请求超时时间 秒
///// @param successCallback 成功回调
///// @param failCallback 失败回调
//-(void)stranscribeP2pWithId:(NSNumber * _Nonnull)messageId
//                 fromUserId:(NSNumber * _Nonnull)fromUserId
//                   toUserId:(NSNumber * _Nonnull)toUserId
//            profanityFilter:(BOOL)profanityFilter
//                    timeout:(int)timeout
//                    success:(void(^)(RTMSpeechRecognitionAnswer * _Nullable recognition))successCallback
//                       fail:(RTMAnswerFailCallBack)failCallback;
//-(RTMSpeechRecognitionAnswer*)stranscribeP2pWithId:(NSNumber * _Nonnull)messageId
//                                        fromUserId:(NSNumber * _Nonnull)fromUserId
//                                          toUserId:(NSNumber * _Nonnull)toUserId
//                                   profanityFilter:(BOOL)profanityFilter
//                                           timeout:(int)timeout;


@end

NS_ASSUME_NONNULL_END