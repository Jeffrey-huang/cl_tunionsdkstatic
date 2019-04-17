//
//  TUnionJumpService.h
//
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TUnionJumpPageFactory.h"
#import "TUnionWebViewProtocol.h"

typedef NS_ENUM(NSUInteger, TUnionJumpPageType) {
    TUNION_JUMP_WITH_H5 = 1,        //强制用H5进行页面跳转
    TUNION_JUMP_WITH_NATIVE = 2     //强制唤起手淘进行页面跳转
};

NS_ASSUME_NONNULL_BEGIN
/* 跳转回调 */
typedef void(^TUnionJumpSuccess)(TUnionJumpPageType type);

typedef void(^TUnionJumpFailed)(TUnionJumpPageType type, NSError *error);

/** 跳转服务 */
@protocol TUnionJumpService <NSObject>

/**
 使用isv自己的webview打开page，可以实现淘宝账号免登以及电商交易支付流程
 @param parentController            webView所在的view controller.
 @param targetPage                  页面请求
 @param params                      扩展业务请求参数,目前支持的业务参数有：
                                     subpid: 用于三方分成的pid，即支持您的pid和subpid之间会对佣金进行按一定比例设置进行分账
                                     unid: 是媒体传入的自定义数据标示，用来支持媒体和联盟的数据打通
                                     adzoneid：推广位id，默认使用的是全局初始化时候的adoneid，如果此处指定，本次打开详情页使用该推广位id
 @param jumpType                    跳转类型,用H5还是唤起手淘打开页面,默认使用Default
 @param webView                     isv自己的webview,请先设置好自己的delegate先调用本接口,否则拦截登陆等逻辑会失效
 */
- (void) show:(UIViewController *)viewController
   targetPage:(id<TUnionJumpPageProtocol>)targetPage
       params:(nullable NSDictionary *)params
     jumpType:(TUnionJumpPageType)jumpType
      webView:(nullable id<TUnionWebViewProtocol>)webView;

- (void) show:(UIViewController *)viewController
   targetPage:(id<TUnionJumpPageProtocol>)targetPage
       params:(nullable NSDictionary *)params
     jumpType:(TUnionJumpPageType)jumpType
      webView:(nullable id<TUnionWebViewProtocol>)webView
  jumpSuccess:(TUnionJumpSuccess _Nullable) succ
   jumpFailed:(TUnionJumpFailed _Nullable) failed;
@end

NS_ASSUME_NONNULL_END
