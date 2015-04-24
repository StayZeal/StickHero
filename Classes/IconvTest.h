/*
 * IconvTest.h
 *
 *  Created on: 2015年4月23日
 *      Author: Administrator
 */

#ifndef ICONVTEST_H_
#define ICONVTEST_H_

#include "iconv.h"
class IconvTest {
public:
	IconvTest();
	virtual ~IconvTest();

	static int convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen);

	static int gbk2utf8( char *inbuf, size_t inlen, char *outbuf, size_t outlen);

//	static status_t code_convert(const char *from_charset,const char *to_charset,char *inleft,size_t inlen,char *outbuf,size_t *outleft);

};

#endif /* ICONVTEST_H_ */
