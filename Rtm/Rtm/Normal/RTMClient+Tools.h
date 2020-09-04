//
//  RTMClient+Administrator.h
//  Rtm
//
//  Created by zsl on 2019/12/12.
//  Copyright © 2019 FunPlus. All rights reserved.
//


#import <Rtm/Rtm.h>
#import "RTMTranslatedInfo.h"
#import "RTMSendAnswer.h"
#import "RTMHistoryMessageAnswer.h"
#import "RTMGetMessageAnswer.h"
#import "RTMMemberAnswer.h"
#import "RTMInfoAnswer.h"
#import "RTMBaseAnswer.h"
#import "RTMAttriAnswer.h"
#import "RTMP2pGroupMemberAnswer.h"
#import "RTMMemberAnswer.h"
#import "RTMTranslatedInfoAnswer.h"
#import "RTMSpeechRecognitionAnswer.h"
#import "RTMTextProfanityAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Tools)
/// 设置当前用户需要的翻译语言
/// @param language 对应语言
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)setLanguage:(NSString * _Nonnull)language
           timeout:(int)timeout
           success:(void(^)(void))successCallback
              fail:(RTMAnswerFailCallBack)failCallback;
-(RTMBaseAnswer*)setLanguage:(NSString * _Nonnull)language
                 timeout:(int)timeout;


/// 翻译, 返回翻译后的字符串及 经过翻译系统检测的 语言类型（调用此接口需在管理系统启用翻译系统）
/// @param translateText 翻译文本
/// @param originalLanguage 原语言类型 
/// @param targetLanguage 目标语言类型
/// @param type 可选值为chat或mail。如未指定，则默认使用chat
/// @param profanity 敏感词过滤   默认：off  stop: 返回错误，censor: 用星号(*)替换敏感词
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)translateText:(NSString * _Nonnull)translateText
    originalLanguage:(NSString * _Nullable)originalLanguage
      targetLanguage:(NSString * _Nonnull)targetLanguage
                type:(NSString * _Nullable)type
           profanity:(NSString * _Nullable)profanity
             timeout:(int)timeout
             success:(void(^)(RTMTranslatedInfo * _Nullable translatedInfo))successCallback
                fail:(RTMAnswerFailCallBack)failCallback;
-(RTMTranslatedInfoAnswer*)translateText:(NSString * _Nonnull)translateText
                        originalLanguage:(NSString * _Nullable)originalLanguage
                          targetLanguage:(NSString * _Nonnull)targetLanguage
                                    type:(NSString * _Nullable)type
                               profanity:(NSString * _Nullable)profanity
                                 timeout:(int)timeout;



/// 敏感词过滤, 返回过滤后的字符串或者返回错误（调用此接口需在管理系统启用文本检测系统）
/// @param profanityText 翻译文本
/// @param classify 是否进行文本分类检测
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)textProfanity:(NSString * _Nonnull)profanityText
            classify:(BOOL)classify
             timeout:(int)timeout
             success:(void(^)(RTMTextProfanityAnswer * _Nullable textProfanity))successCallback
                fail:(RTMAnswerFailCallBack)failCallback;
-(RTMTextProfanityAnswer*)textProfanity:(NSString * _Nonnull)profanityText
                               classify:(BOOL)classify
                                timeout:(int)timeout;


/// 语音识别（调用此接口需在管理系统启用语音识别系统）调用这个接口的超时时间得加大到120s
/// @param audioFilePath 语音文件路径
/// @param lang 当前语音的语言
/// @param duration 音频长度 毫秒
/// @param profanityFilter 文本过滤
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)speechRecognition:(NSString * _Nonnull)audioFilePath
                    lang:(NSString * _Nonnull)lang
                duration:(long long)duration
         profanityFilter:(BOOL)profanityFilter
                 timeout:(int)timeout
                 success:(void(^)(RTMSpeechRecognitionAnswer * _Nullable textProfanity))successCallback
                    fail:(RTMAnswerFailCallBack)failCallback;
-(RTMSpeechRecognitionAnswer*)speechRecognition:(NSData * _Nonnull)audioSource
                                           lang:(NSString * _Nullable)lang
                                       duration:(long long)duration
                                profanityFilter:(BOOL)profanityFilter
                                        timeout:(int)timeout;



/// 添加debug日志
/// @param msg msg
/// @param attrs 属性
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)addDebugLogWithMsg:(NSString * _Nonnull)msg
                    attrs:(NSString * _Nonnull)attrs
                  timeout:(int)timeout
                  success:(void(^)(void))successCallback
                     fail:(RTMAnswerFailCallBack)failCallback;
-(RTMBaseAnswer*)addDebugLogWithMsg:(NSString * _Nonnull)msg
                              attrs:(NSString * _Nonnull)attrs
                            timeout:(int)timeout;


/// 添加设备，应用信息
/// @param apptype app类型
/// @param deviceToken token
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)addDeviceWithApptype:(NSString * _Nonnull)apptype
                deviceToken:(NSString * _Nonnull)deviceToken
                    timeout:(int)timeout
                    success:(void(^)(void))successCallback
                       fail:(RTMAnswerFailCallBack)failCallback;
-(RTMBaseAnswer*)addDeviceWithApptype:(NSString * _Nonnull)apptype
                          deviceToken:(NSString * _Nonnull)deviceToken
                              timeout:(int)timeout;


/// 删除设备，应用信息，解除绑定的意思
/// @param deviceToken token
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)removeDeviceWithToken:(NSString * _Nonnull)deviceToken
                     timeout:(int)timeout
                     success:(void(^)(void))successCallback
                        fail:(RTMAnswerFailCallBack)failCallback;
-(RTMBaseAnswer*)removeDeviceWithToken:(NSString * _Nonnull)deviceToken
                               timeout:(int)timeout;



@end

NS_ASSUME_NONNULL_END
