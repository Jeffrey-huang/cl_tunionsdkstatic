//
//  TUnionSDK.h
//
//



#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#ifndef TUnionSDK_h
#define TUnionSDK_h

#ifdef __cplusplus
extern "C" {
#endif

/** 当前联盟无线SDK版本 */
NSString * _Nonnull getTUnionSDKVersion();

/* 根据Service协议,获取Service实例
 @param protocol : 协议名称,目前支持TUnionLoginService/TUnionJumpService
 */
__nullable id TUnionService(Protocol *__nonnull protocol);


#ifdef __cplusplus
}
#endif

#pragma mark - type define
/** SDK回调Code定义 */
typedef NS_ENUM (NSUInteger, TUnionSDKErrorCode) {
    /* 成功 */
    TUnion_No_Error = 100,
    /** SDK初始化失败 */
    TUnion_INIT_FAILED = 1000,
    /* 用户没有登陆 */
    TUnion_User_Didnt_Login = 120,
    /* UserId or appKey为空 */
    TUnion_Info_Error = 121,
    /* 网络错误 */
    TUnion_Network_Error = 122,
    /* Url 解析错误 */
    TUnion_Url_Parse_Error = 130,
    /* 未知错误 */
    TUnion_Unknow_Error = 123
};

NS_ASSUME_NONNULL_BEGIN

#pragma mark - SDK
/* SDK */
@interface TUnionSDK : NSObject

/** 返回单例 */
+ (TUnionSDK *) shareInstance;

/**
 初始化SDK
 @param appKey      app在联盟无线开放平台申请的AppKey
 @param adzoneId    广告位id
 *
 */
+ (TUnionSDKErrorCode)registerWithAppkey:(NSString *)appKey adzoneId:(NSString *)adzoneId;

/**
 获取TUnionSDK以及所有插件SDK暴露的service 实例
 @param protocol    service的协议
 @return            service实例
 */
- (id)getService:(Protocol *)protocol;

/* 
 获取TUnionSDK的UA，如无特别需要，不需要获取此UA
 */
+ (NSString *)getTUnionUserAgent;

/*
 * 日志开关，用户调试
 */
+ (void)openLog:(BOOL) showWindow;
+ (void)closeLog;
/*
 * 检测接入的各项配置是否正确，用于调试，调试完成后请关闭
 * @param appKey: appKey
 */
+ (void)checkResoucesAndConfigure:(NSString *)appKey;

@end

NS_ASSUME_NONNULL_END

#endif  /* TUnionSDK_h */
