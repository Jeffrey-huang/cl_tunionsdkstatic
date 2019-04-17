//
//  TUnionPageType.h
//
//

#import "TUnionJumpPageFactory.h"

#pragma mark item
@interface TUnionDetailPage : NSObject<TUnionJumpPageProtocol>
/**
 *  itemId,要跳转到的商品
 */
@property (nonatomic, strong) NSString *itemId;
@property (nonatomic, strong) NSString *backUrl;

/**
 *  初始化,itemId(必传)
 *
 *  @param itemId
 */
-(instancetype)initWithItemId:(NSString *)itemId
                      backUrl:(NSString *)backUrl;

@end



#pragma mark shop
@interface TUnionShopPage : NSObject<TUnionJumpPageProtocol>

/**
 *  sellerId,要跳转到的店铺的卖家ID
 */
@property (nonatomic, strong) NSString *sellerId;
@property (nonatomic, strong) NSString *backUrl;

/**
 *  初始化,sellerId必传
 *
 *  @param sellerId
 */
-(instancetype)initWithShopId:(NSString *)sellerId
                      backUrl:(NSString *)backUrl;

@end




#pragma mark url
@interface TUnionUrlPage : NSObject<TUnionJumpPageProtocol>

/**
 *  要跳转到的H5页面的url
 */
@property (nonatomic, strong) NSString *uri;
@property (nonatomic, strong) NSString *backUrl;

/**
 *  初始化,传入h5URL
 */
- (instancetype)initWithURI:(NSString *)URI
                    backUrl:(NSString *)backUrl;

@end

