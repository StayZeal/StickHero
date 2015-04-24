/*
 * IconvTest.cpp
 *
 *  Created on: 2015年4月23日
 *      Author: Administrator
 */
#include "cocos2d.h"
#include "IconvTest.h"
#include "iconv.h"
int IconvTest::convert( char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
    iconv_t iconvH;
    iconvH = iconv_open(to_charset, from_charset);
    if( !iconvH ) return NULL;
    memset(outbuf, 0, outlen);

	if( !iconv(iconvH, &inbuf, &inlen, &outbuf, &outlen) )
	{
		iconv_close(iconvH);
		return NULL;
	}

    iconv_close(iconvH);
    return NULL;
}

int IconvTest::gbk2utf8(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
    return convert("utf-8", "utf-8", inbuf, inlen, outbuf, outlen);
}

IconvTest::IconvTest() {
	// TODO Auto-generated constructor stub

}

IconvTest::~IconvTest() {
	// TODO Auto-generated destructor stub
}

/*
status_t IconvTest::code_convert(const char *from_charset,const char *to_charset,char *inleft,size_t inlen,char *outbuf,size_t *outleft)
{
   char **pin = &inbuf;
   char **pout = &outbuf;
   iconv_t cd = iconv_open(to_charset,from_charset);
    if (cd==NULL)
   {
       LOGE("open error");
        return UNKNOWN_ERROR;
    }
    if (iconv(cd,pin,&inleft,pout,outleft)==(size_t)-1)
    {
        LOGE("failed to  convert.error code is %d",errno);
        iconv_close(cd);
        return UNKNOWN_ERROR;
    }
    iconv_close(cd);
    return OK;
}
*/


