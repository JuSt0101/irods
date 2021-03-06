/* For copyright information please refer to files in the COPYRIGHT directory
 */


#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <string>
#include "datetime.hpp"

int getModifiedTime( char *fn, time_type *timestamp );
char *getRuleBasePath( char *ruleBaseName, char rulesFileName[MAX_NAME_LEN] );
void getResourceName( std::string &_out_str, const char *rname );

#endif /* FILESYSTEM_H_ */
