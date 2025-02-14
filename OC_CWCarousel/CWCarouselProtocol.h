//
//  CWCarouselProtocol.h
//  CWCarousel
//
//  Created by WangChen on 2018/4/3.
//  Copyright © 2018年 ChenWang. All rights reserved.
//

#ifndef CWCarouselProtocol_h
#define CWCarouselProtocol_h

@class CWCarousel;
@protocol CWCarouselDelegate<NSObject>
/**
 轮播图点击代理

 @param carousel 轮播图实例对象
 @param index 被点击的下标
 */
- (void)CWCarousel:(CWCarousel *)carousel didSelectedAtIndex:(NSInteger)index;

@optional

/**
将要开始滑动时,会触发该代理

 @param carousel 轮播图控件
 @param index 开始滑动时,处于中心点图片的下标
 @param indexPathRow 开始滑动时,处于中心点图片的在控件内部的实际下标
 */
- (void)CWCarousel:(CWCarousel *)carousel didStartScrollAtIndex:(NSInteger)index indexPathRow:(NSInteger)indexPathRow;

/**
滑动时,会触发该代理

 @param carousel 轮播图控件
 @param index 中心点图片的下标
 @param indexPathRow 开始滑动时,处于中心点图片的在控件内部的实际下标
 */
- (void)CWCarouselDidScroll:(CWCarousel *)carousel didScrollAtIndex:(NSInteger)index indexPathRow:(NSInteger)indexPathRow;


/**
 滑动结束后,会触发该代理

 @param carousel 轮播图控件
 @param index 结束滑动时,处于中心点图片的下标
 @param indexPathRow 结束滑动时,处于中心点图片在控件内部的实际下标
 */
- (void)CWCarousel:(CWCarousel *)carousel didEndScrollAtIndex:(NSInteger)index indexPathRow:(NSInteger)indexPathRow;


/// 开始布局pageControl时会触发该回调
/// @param carousel 轮播组件对象
/// @param pageControl pageControl对象
/// @param isDefault YES: 组件内部默认的UIPageControl, NO: 自定义的customPageControl
///
/// 可以在这个回调中自定义pageControl的布局, 如果没有实现该回调, 将默认在底部居中.
///
/// 注意:
/// 1. 先设置customPageControl, 后将CWCarousel添加到父视图中, 此回调只会被调用一次.
/// 2. 先将CWCarousel添加到父视图中, 后设置customPageControl, 此回调会被调用两次, 第一次isDefault = YES, 第二次isDefault = NO. 因为将CWCarousel添加到父视图时检测到没有customPageControl, 组件内部并不清楚外部调用者是否会设置customPageControl, 会先创建并添加默认的pageControl.
/// 3. 当自定义的customPageControl宽度布局不是自己撑开的时候, 请在该回调中自己布局. 否则采用默认的布局将不可见.
- (void)CWCarousel:(CWCarousel *)carousel addPageControl:(UIView *)pageControl isDefault:(BOOL)isDefault;

@end

@protocol CWCarouselDatasource<NSObject>
/**
 轮播图数量

 @return 轮播图展示个数
 */
- (NSInteger)numbersForCarousel;
/**
 自定义每个轮播图视图

 @param carousel 轮播图控件
 @param indexPath 轮播图cell实际下标
 @param index 业务逻辑需要的下标
 @return 自定义视图
 */
- (UICollectionViewCell *)viewForCarousel:(CWCarousel *)carousel indexPath:(NSIndexPath *)indexPath index:(NSInteger)index;
@end


@protocol CWCarouselPageControlProtocol<NSObject>
@required
/**
 总页数
 */
@property (nonatomic, assign, readonly) NSInteger         pageNumbers;
/**
 当前页
 */
@property (nonatomic, assign, readonly) NSInteger         currentPage;

- (void)setCurrentPage:(NSInteger)currentPage;
- (void)setPageNumbers:(NSInteger)pageNumbers;
@end
#endif /* CWCarouselProtocol_h */


