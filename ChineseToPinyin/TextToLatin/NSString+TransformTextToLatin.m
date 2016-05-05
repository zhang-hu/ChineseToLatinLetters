//
//  NSString+TransformTextToLatin.m
//
//  Created by ZhangHu on 14-5-20.
//

#import "NSString+TransformTextToLatin.h"

@implementation NSString (TransformTextToLatin)

+ (NSString *)latinStringFromString:(NSString *)string
{
    if (string.length == 0) {
        return nil;
    }

    CFMutableStringRef cfStr = CFStringCreateMutableCopy(NULL, 0, (CFStringRef)string);

    CFStringTransform(cfStr, NULL, kCFStringTransformToLatin, false);
    CFStringTransform(cfStr, NULL, kCFStringTransformStripDiacritics, false);

    NSString *resultStr = (__bridge NSString *)cfStr;

    CFRelease(cfStr);

    return resultStr;
}


+ (NSString *)latinStringOfFirstCharOfString:(NSString *)string
{
    if (string.length == 0) {
        return nil;
    }

    NSString *firstChar = [string substringToIndex:1];

    return [self latinStringFromString:firstChar];
}


+ (NSString *)firstLatinCharOfFisrtCharOfString:(NSString *)string
{
    NSString *mStr = [self latinStringOfFirstCharOfString:string];

    return [mStr substringToIndex:1];
}

+ (NSString *)firstUppercaseLatinCharOfFirstCharOfString:(NSString *)string
{
    NSString *firstCharStr = [self firstLatinCharOfFisrtCharOfString:string];

    CFMutableStringRef cfStr = CFStringCreateMutableCopy(NULL, 0, (CFStringRef)firstCharStr);
    CFStringUppercase(cfStr, CFLocaleGetSystem());

    NSString *rtStr = (__bridge NSString *)(cfStr);

    CFRelease(cfStr);

    return rtStr;
}

+ (NSString *)latinStringWithoutWhitespaceCharFromString:(NSString *)string
{
    NSString *mStr = [self latinStringFromString:string];

    return [mStr stringByReplacingOccurrencesOfString:@" " withString:@""];
}

@end
