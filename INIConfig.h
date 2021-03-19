/*
 * INIConfig.h
 *
 *  Created on: Sep 7, 2020
 *      Author: admin
 */

#ifndef INICONFIG_H_
#define INICONFIG_H_
#include<stdio.h>
#include<string.h>
#include<errno.h>
FILE* conf_file;
int INI_ERROR;
typedef struct INI_Section{
	const char* section_seperator;
	const char* section_name;
}INI_Section;
typedef struct INI_Option{
	const char* option_name;
	const char* option_seperator;
	const char* option_value;
}INI_Option;
INI_Section* ini_sect;
INI_Option* ini_option;
void WriteINItoFile(const char* file_path,const char* sec_name[],const char* opt_name[],const char* opt_value[]);
void ReadINIFromFile(const char* file_path);

#endif /* INICONFIG_H_ */
