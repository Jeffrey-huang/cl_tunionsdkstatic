//
//  TUnionSession.h
//  TUnionSDK
//
//  Created by knight on 16/8/30.
//  Copyright © 2016年 HuXiaoNing. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef TUnionSession_h
#define TUnionSession_h

@interface TUnionSession : NSObject

@property(nonatomic, assign)BOOL isCanceledByUser;

/**
 @return 返回单例
 */
+ (TUnionSession *)sharedInstance;

/**
 如果未登录或者登录态已经过期,返回NO
 @return 当前会话是否登录有效
 */
- (BOOL)isLogin;

@end

#endif
