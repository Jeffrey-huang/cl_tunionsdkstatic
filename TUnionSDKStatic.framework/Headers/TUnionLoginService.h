//
//  TUnionLoginService.h
//
//

#import <UIKit/UIKit.h>
#import "TUnionSession.h"
#import "TUnionWebViewProtocol.h"
#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN

/* 登录回调 */
typedef void(^TUnionloginSuccess)(TUnionSession * session);

typedef void(^TUnionloginFailed)(TUnionSession * session, NSError *error);

/* 登陆拦截服务 */
@protocol TUnionLoginService <NSObject>

/* 拦截登陆、登出Url，建议在WebView相应位置调用
 * @param       webView相应参数
 * @return      NO:当前URL SDK已处理，媒体不可继续处理
 *              YES：当前URL SDK未处理，媒体可继续处理
 */
- (BOOL)webView:(id<TUnionWebViewProtocol>)webView
shouldStartLoadWithRequest:(NSURLRequest *)request
 navigationType:(UIWebViewNavigationType)navigationType
currentViewController:(UIViewController *)viewController;

/* @retun       1 SDK未处理/ 2 SDK已处理，登陆请求 / 3 SDK已处理，登出请求
*/
- (NSUInteger)webView:(id<TUnionWebViewProtocol>)webView
shouldStartLoadWithRequest:(NSURLRequest *)request
           navigationType:(UIWebViewNavigationType)navigationType
    currentViewController:(UIViewController *)viewController
             loginSuccess:(TUnionloginSuccess) success
              loginFailed:(TUnionloginFailed) failed;

- (void)webViewDidFinishLoad:(id<TUnionWebViewProtocol>)webView;

/* 授权登陆 返回App后的登陆处理, 建议在AppDelegate相应位置调用 */
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary * _Nullable)options;

/**
 如果未登录或者登录态已经过期,返回NO
 @return 当前会话是否登录有效
 */
- (BOOL)isLogin;

/* 获取用户的头像 */
- (NSString *)avatarUrl;

/* 获取用户昵称 */
- (NSString *)nick;

/* 拉起登陆界面
 * @parma viewController    当前viewController
 * @param success           登陆成功的回调
 * @param failed            登陆失败的回调
 */
- (void)login:(UIViewController *)viewController
      success:(TUnionloginSuccess) success
       failed:(TUnionloginFailed) failed;

/**
 退出登录
 */
- (void)logout;

@end

NS_ASSUME_NONNULL_END
