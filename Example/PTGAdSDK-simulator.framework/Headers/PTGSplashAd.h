//
//  PTGSplashAd.h
//  PTGAdSDK
//
//  Created by admin on 2021/1/13.
//

#import <UIKit/UIKit.h>
@class PTGSplashAd;

NS_ASSUME_NONNULL_BEGIN

@protocol PTGSplashAdDelegate <NSObject>
@optional
/// 开屏加载成功
- (void)ptg_splashAdDidLoad:(PTGSplashAd *)splashAd;

/// 开屏加载失败
- (void)ptg_splashAd:(PTGSplashAd *)splashAd didFailWithError:(NSError * _Nullable)error;

/// 开屏广告被点击了
- (void)ptg_splashAdDidClick:(PTGSplashAd *)splashAd;

/// 开屏广告关闭了
- (void)ptg_splashAdDidClose:(PTGSplashAd *)splashAd;
 
///  开屏广告将要展示
- (void)ptg_splashAdWillVisible:(PTGSplashAd *)splashAd;

@end

@interface PTGSplashAd : NSObject

/// buttomView  底部视图 可为空
@property(nonatomic,strong)UIView *bottomView;

/// 是否隐藏跳过按钮 默认NO
@property(nonatomic,assign)BOOL hideSkipButton;

/// 根控制器 广告加载的根控制器 需要传入当前的栈顶可见的控制器
@property(nonatomic, weak)UIViewController *rootViewController;

/// 广告id
@property(nonatomic,copy,readonly)NSString *placementId;

/// 开屏广告代理
@property(nonatomic,weak)id<PTGSplashAdDelegate> delegate;

/// 禁止使用此方法来初始化
+ (instancetype)new NS_UNAVAILABLE;

/// 禁止使用此方法来初始化
- (instancetype)init NS_UNAVAILABLE;

///  初始化
/// @param placementId 广告id
- (instancetype)initWithPlacementId:(nonnull NSString *)placementId NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)loadAd;

/// 展示广告
- (void)showAdWithViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
