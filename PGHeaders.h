@interface SBChevronView : UIView {
        UIView *_leftGrabberView;
        UIView *_rightGrabberView;
        double _animationDuration;
        int _state;
        UIColor *_color;
        UIView *_colorCompositingView;
        UIView *_darkTintView;
        UIView *_lightTintView;
        UIView *_backgroundView;
        UIView *_alphaContainerView;
}

@property(assign, nonatomic) double animationDuration;
@property(retain, nonatomic) UIColor *color;
@property(assign, nonatomic) int state;

-(SBChevronView *)initWithColor:(UIColor *)color;
-(SBChevronView *)initWithFrame:(CGRect)frame;
-(CGRect)_frameForGrabberView:(id)grabberView forState:(int)state;
-(void)_layoutGrabberView:(id)view forState:(int)state;
-(BOOL)_setState:(int)state;
-(CGAffineTransform)_transformForGrabberView:(id)grabberView forState:(int)state;
-(void)layoutSubviews;
-(void)setBackgroundView:(UIView *)view;
-(void)setState:(int)state animated:(BOOL)animated;
-(CGSize)sizeThatFits:(CGSize)fits;
@end

@interface SBLockScreenView : UIView <UIScrollViewDelegate>
@property(retain, nonatomic) SBChevronView *bottomGrabberView;
@property(retain, nonatomic) SBChevronView *topGrabberView;
@property(readonly, assign, nonatomic) UIScrollView *scrollView;

-(id)initWithFrame:(CGRect)frame;
-(void)_addGrabberViews;
-(void)_addViews;
-(void)_adjustTopAndBottomGrabbersForPercentScrolled:(float)percentScrolled;

-(void)_layoutGrabberView:(id)view atTop:(BOOL)top;
-(void)_layoutGrabberView:(id)view atTop:(BOOL)top percentScrolled:(float)scrolled;

-(float)_bottomGrabberYOriginForPercentScrolled:(float)percentScrolled;
-(float)_topGrabberYOriginForPercentScrolled:(float)percentScrolled;
-(void)_updateBottomGrabberBackground;
-(void)_updateTopGrabberBackground;

-(void)setBottomGrabberHidden:(BOOL)hidden forRequester:(id)requester;
-(void)setTopBottomGrabbersHidden:(BOOL)hidden forRequester:(id)requester;
-(void)setTopGrabberHidden:(BOOL)hidden forRequester:(id)requester;
@end
