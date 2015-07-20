//
//  OMColorHelper.h
//  OMColorHelper
//
//  Created by Ole Zorn on 09/07/12.
//
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

typedef enum OMColorType {
	OMColorTypeNone = 0,
	
	OMColorTypeUIRGBA,				//[UIColor colorWithRed:1.0 green:0.0 blue:0.0 alpha:1.0]
	OMColorTypeUIRGBAInit,			//[[UIColor alloc] initWithRed:1.0 green:0.0 blue:0.0 alpha:1.0]
	OMColorTypeUIWhite,				//[UIColor colorWithWhite:0.5 alpha:1.0]
	OMColorTypeUIWhiteInit,			//[[UIColor alloc] initWithWhite:0.5 alpha:1.0]
	OMColorTypeUIConstant,			//[UIColor redColor]
	
	OMColorTypeNSRGBACalibrated,	//[NSColor colorWithCalibratedRed:1.0 green:0.0 blue:0.0 alpha:1.0]
	OMColorTypeNSRGBADevice,		//[NSColor colorWithDeviceRed:1.0 green:0.0 blue:0.0 alpha:1.0]
	OMColorTypeNSWhiteCalibrated,	//[NSColor colorWithCalibratedWhite:0.5 alpha:1.0]
	OMColorTypeNSWhiteDevice,		//[NSColor colorWithDeviceWhite:0.5 alpha:1.0]
	OMColorTypeNSConstant,			//[NSColor redColor]
	
} OMColorType;

typedef enum OMColorLanguage {
  OMColorLanguageDefault = 0,
  OMColorLanguageObjectiveC = 1,
  OMColorLanguageSwift = 2,
} OMColorLanguage;

BOOL OMColorTypeIsNSColor(OMColorType colorType) { return colorType >= OMColorTypeNSRGBACalibrated; }
BOOL OMColorLanguageIsSwift(OMColorLanguage colorLanguage) { return colorLanguage == OMColorLanguageSwift; }

//TODO: Maybe support HSB and CMYK color types...

@class OMColorFrameView, OMPlainColorWell;

@interface OMColorHelper : NSObject {
	
	OMPlainColorWell *_colorWell;
	OMColorFrameView *_colorFrameView;
	NSRange _selectedColorRange;
	OMColorType _selectedColorType;
	NSTextView *_textView;
	NSDictionary *_constantColorsByName;
	
	NSRegularExpression *_rgbaUIColorRegex;
	NSRegularExpression *_rgbaNSColorRegex;
	NSRegularExpression *_whiteNSColorRegex;
	NSRegularExpression *_whiteUIColorRegex;
	NSRegularExpression *_constantColorRegex;
  NSRegularExpression *_constantSwiftColorRegex;
  NSRegularExpression *_rgbaSwiftUIColorRegex;
  NSRegularExpression *_whiteSwiftUIColorRegex;
}

@property (nonatomic, strong) OMPlainColorWell *colorWell;
@property (nonatomic, strong) OMColorFrameView *colorFrameView;
@property (nonatomic, strong) NSTextView *textView;
@property (nonatomic, assign) NSRange selectedColorRange;
@property (nonatomic, assign) OMColorType selectedColorType;
@property (nonatomic, assign) OMColorLanguage selectedColorLanguage;

- (void)dismissColorWell;
- (void)activateColorHighlighting;
- (void)deactivateColorHighlighting;
- (NSColor *)colorInText:(NSString *)text selectedRange:(NSRange)selectedRange type:(OMColorType *)type language:(OMColorLanguage *)language matchedRange:(NSRangePointer)matchedRange;
- (NSString *)colorStringForColor:(NSColor *)color withType:(OMColorType)colorType language:(OMColorLanguage)colorLanguage;
- (double)dividedValue:(double)value withDivisorRange:(NSRange)divisorRange inString:(NSString *)text;

@end
