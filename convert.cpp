#include<ahelp.h>
#include<stdlib.h>
#include <stdio.h>
const int lg = 45 ;
int ischar (ushort d)
{
    if(d<' ')
        return 0 ;

    return 1 ;
}
QString * cleartext(QString in,Convert_mode mode)
{
    QChar* cs = in.data();
    int d = in.length();
    QChar * str =new QChar[d+1];
    int dem ,p ;
    int start ;
    dem =0 ;p=0;
    int ispace = 1;
    int size = sizeof (QChar);
    QChar space = QChar(' ');
    for(int i= 0;i<d;i++)
    {
        if(ischar(cs[i].unicode()))
        {
            if(cs[i].unicode()==' ')
            {
                if(!ispace)
                {
                    memcpy(&(str[p]),&(cs[i]),size);
                    p++ ;
                }
                ispace = 1;
            }
            else
            {
                if(!start)
                {
                    start = 1 ;
                }
                memcpy(&(str[p]),&(cs[i]),size);
                p++ ;
                ispace = 0;
            }
        }
        else
        {

            if(i==dem)
            {
                if(p>0)
                {
                    //                    if(cs[i].unicode()!=str[p-1].unicode())
                    {
                        memcpy(&(str[p]),&(cs[i]),size);
                        p++ ;
                    }
                }
                else {
                    memcpy(&(str[p]),&(cs[i]),size);
                    p++ ;
                }


            }
            else
            {
                if((i-dem<lg)||(str[p-1].unicode()=='.' && mode == Convert_PDF))
                {
                    memcpy(&(str[p]),&(cs[i]),size);
                    p++ ;
                }
                else
                {

                    if(!ispace)
                    {
                        if( str[p-1].unicode()!='-')
                        {
                            memcpy(&(str[p]),&(space),size);
                            p++ ;
                        }
                    }
                }

            }
            dem = i +1;
            start =0 ;
            ispace = 1 ;
        }
    }
    str[p] = QChar('\0') ;
    QString *res = new QString(str);
    delete[] str ;
    return res ;
}
