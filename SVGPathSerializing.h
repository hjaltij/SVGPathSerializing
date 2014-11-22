#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  Returns an array of CGPathRefs contained within the passed SVG string.
 *
 *  @param svgString The string containing the SVG formatted path.
 *  @param attributes An optional pointer for storing a map table containing SVG attributes for the paths
 *
 *  @return An array of CGPathRef objects or nil if none are found
 */
NSArray *CGPathsFromSVGString(NSString *svgString, NSMapTable **attributes);


/*!
 *  Returns SVG representing `paths`
 *
 *  @param paths An array of CGPathRefs to construct the SVG from
 *  @param attributes An optional map table of SVG attributes for the paths
 *
 *  @return SVG representing `paths`
 */
NSString *SVGStringFromCGPaths(NSArray *paths, NSMapTable *attributes);

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>

@interface UIBezierPath (SVGPathSerializing)
+ (NSArray *)pathsFromContentsOfSVGFile:(NSString *)aPath;
+ (NSArray *)pathsFromSVGString:(NSString *)svgString;
- (NSString *)SVGRepresentation;
@end
#endif

#ifdef __cplusplus
};
#endif