/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#import <ABI45_0_0React/ABI45_0_0renderer/attributedstring/AttributedString.h>
#import <ABI45_0_0React/ABI45_0_0renderer/attributedstring/ParagraphAttributes.h>
#import <ABI45_0_0React/ABI45_0_0renderer/core/LayoutConstraints.h>
#import <ABI45_0_0React/ABI45_0_0renderer/graphics/Geometry.h>
#import <ABI45_0_0React/ABI45_0_0renderer/textlayoutmanager/TextMeasureCache.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @abstract Enumeration block for text fragments.
*/

using ABI45_0_0RCTTextLayoutFragmentEnumerationBlock =
    void (^)(CGRect fragmentRect, NSString *_Nonnull fragmentText, NSString *value);

/**
 * iOS-specific TextLayoutManager
 */
@interface ABI45_0_0RCTTextLayoutManager : NSObject

- (ABI45_0_0facebook::ABI45_0_0React::TextMeasurement)measureAttributedString:(ABI45_0_0facebook::ABI45_0_0React::AttributedString)attributedString
                                        paragraphAttributes:(ABI45_0_0facebook::ABI45_0_0React::ParagraphAttributes)paragraphAttributes
                                          layoutConstraints:(ABI45_0_0facebook::ABI45_0_0React::LayoutConstraints)layoutConstraints;

- (ABI45_0_0facebook::ABI45_0_0React::TextMeasurement)measureNSAttributedString:(NSAttributedString *)attributedString
                                          paragraphAttributes:(ABI45_0_0facebook::ABI45_0_0React::ParagraphAttributes)paragraphAttributes
                                            layoutConstraints:(ABI45_0_0facebook::ABI45_0_0React::LayoutConstraints)layoutConstraints;

- (void)drawAttributedString:(ABI45_0_0facebook::ABI45_0_0React::AttributedString)attributedString
         paragraphAttributes:(ABI45_0_0facebook::ABI45_0_0React::ParagraphAttributes)paragraphAttributes
                       frame:(CGRect)frame;

- (ABI45_0_0facebook::ABI45_0_0React::LinesMeasurements)getLinesForAttributedString:(ABI45_0_0facebook::ABI45_0_0React::AttributedString)attributedString
                                              paragraphAttributes:
                                                  (ABI45_0_0facebook::ABI45_0_0React::ParagraphAttributes)paragraphAttributes
                                                             size:(CGSize)size;

- (ABI45_0_0facebook::ABI45_0_0React::SharedEventEmitter)
    getEventEmitterWithAttributeString:(ABI45_0_0facebook::ABI45_0_0React::AttributedString)attributedString
                   paragraphAttributes:(ABI45_0_0facebook::ABI45_0_0React::ParagraphAttributes)paragraphAttributes
                                 frame:(CGRect)frame
                               atPoint:(CGPoint)point;

- (void)getRectWithAttributedString:(ABI45_0_0facebook::ABI45_0_0React::AttributedString)attributedString
                paragraphAttributes:(ABI45_0_0facebook::ABI45_0_0React::ParagraphAttributes)paragraphAttributes
                 enumerateAttribute:(NSString *)enumerateAttribute
                              frame:(CGRect)frame
                         usingBlock:(ABI45_0_0RCTTextLayoutFragmentEnumerationBlock)block;

@end

NS_ASSUME_NONNULL_END
