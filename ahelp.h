#ifndef AHELP_H
#define AHELP_H
#include <QString>
typedef enum Convert_mode
{
    Convert_RFC =0  ,
    Convert_PDF =1
} Convert_mode ;
QString * cleartext(QString in,Convert_mode mode);

#endif // AHELP_H
