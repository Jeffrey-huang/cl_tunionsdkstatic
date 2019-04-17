//
//  TUnionJumpPageFactory.h
//
//

#import <Foundation/Foundation.h>


@protocol TUnionJumpPageProtocol <NSObject>

@property (nonatomic, strong, nullable) NSString *backUrl;

@end

NS_ASSUME_NONNULL_BEGIN

/** 页面工厂类 */
@interface TUnionJumpPageFactory : NSObject

/**
 创建URL指定页面
 @param url     地址
 @return URL指定页面
 */
+ (id<TUnionJumpPageProtocol>)page:(NSString *)url
               backUrl:(NSString *)backUrl;

/**
 创建商品真实ID对应的详情页面
 @param itemId   商品真实ID
 @return 详情页面
 */
+ (id<TUnionJumpPageProtocol>)detailPage:(NSString *)itemId
                     backUrl:(NSString *)backUrl;

/**
 *  创建店铺页面
 *
 *  @param sellerId 店铺的卖家ID
 *
 *  @return 店铺页面
 */
+ (id<TUnionJumpPageProtocol>)shopPage:(NSString *)sellerId
                   backUrl:(NSString *)backUrl;


@end

NS_ASSUME_NONNULL_END
