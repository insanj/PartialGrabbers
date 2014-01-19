#import <UIKit/UIKit.h>
#import "PGHeaders.h"

#define PADDING 12.0

%hook SBLockScreenView

-(void)_layoutGrabberView:(SBChevronView *)view atTop:(BOOL)top{
	%orig();

	CGRect chevronFrame = view.frame;
	if(top)
		chevronFrame.origin.y -= PADDING;
	else
		chevronFrame.origin.y += PADDING;

	[view setFrame:chevronFrame];
}

-(void)_adjustTopAndBottomGrabbersForPercentScrolled:(float)percentScrolled{
	%orig();

	CGRect topFrame = self.topGrabberView.frame;
	topFrame.origin.y -= PADDING;
	[self.topGrabberView setFrame:topFrame];

	CGRect bottomFrame = self.bottomGrabberView.frame;
	bottomFrame.origin.y += PADDING;
	[self.bottomGrabberView setFrame:bottomFrame];
}

%end