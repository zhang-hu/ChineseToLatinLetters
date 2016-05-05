//
//  NSString+TransformTextToLatin.h
//
//  Created by ZhangHu on 14-5-20.
//

#import <Foundation/Foundation.h>

@interface NSString (TransformTextToLatin)

/**
 *  Converts a string to a latin letters string. If the input string is already a latin letters string, the returned string is the same as it. If the input string is a chinese characters string, then the returned string is the input string's pinyin without diacritic markings, and the pinyins of each two chinese characters seperated by one whitespace char. Therefore, the conversion may be inreversible.
 *
 *  @param string The input string.
 *
 *  @return The transformed string.
 
 *  @see latinStringWithoutWhitespaceCharFromString:.
 */
+ (NSString *)latinStringFromString:(NSString *)string;

/**
 *  Converts the first character of the input string to a latin letters string. The essence of this method is to passe in the fisrt char of the input string as the parameter of the method latinStringFromString:.
 *
 *  @param string The input string.
 *
 *  @return A latin letters string transformed from the first char of the input string.
 
 *  @see latinStringFromString:.
 */
+ (NSString *)latinStringOfFirstCharOfString:(NSString *)string;

/**
 *  Converts the first character of the input string to a latin letters string, and returns the first letter of the latin letters string.
 *
 *  @param string The input string.
 *
 *  @return The first letter of the latin letters string transformed from the first char of the input string.
 */
+ (NSString *)firstLatinCharOfFisrtCharOfString:(NSString *)string;

+ (NSString *)firstUppercaseLatinCharOfFirstCharOfString:(NSString *)string;

/**
 *  Converts a string to a latin letters string. If the input string is already a latin letters string, the returned string is the same as it. If the input string is a chinese characters string, then the returned is the input string's pinyin without diacritic markings and any whitespace character. Therefore, the conversion may be inreversible.
 *
 *  @param string The input string.
 *
 *  @return The transformed string.
 
 *  @see latinStringFromString:.
 */
+ (NSString *)latinStringWithoutWhitespaceCharFromString:(NSString *)string;

@end
