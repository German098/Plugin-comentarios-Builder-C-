//---------------------------------------------------------------------------

#ifndef HeaderH
#define HeaderH

//#include <toolsAPI.hpp>
#include <string>
#include <System.StrUtils.hpp>


extern const std::string h1 = "/\**\r\n * @file\t";
extern const std::string h2 = "\r\n* @brief Descripción fichero.\r\n*\r\n* @author\t";
extern const std::string h3 = "\r\n* @date\t";
extern const std::string h4 = "\r\n*/\r\n";
extern int lengthFile;
extern int lengthAuthor;
extern int lengthDate;

System::UnicodeString __fastcall header_comment(System::UnicodeString file, System::UnicodeString author, System::UnicodeString date);

#endif
