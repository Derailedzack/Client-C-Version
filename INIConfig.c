/*
 * INIConfig.c
 *
 *  Created on: Sep 7, 2020
 *      Author: admin
 */

#include"INIConfig.h"
void WriteINItoFile(const char* file_path,const char* sec_name[],const char* opt_name[],const char* opt_value[]){
	conf_file = fopen(file_path,"w");
	if(conf_file == NULL){
		if(fclose(conf_file) == EOF){
			return;
		}else{
			printf("Failed to open File! Reason:%s",strerror(errno));
		}
	}else{
		for(int sect_name_index = 0; sect_name_index < strlen(sec_name); sect_name_index++){
				for(int opt_name_index = 0; opt_name_index < strlen(opt_name); opt_name_index++){
					for(int opt_value_index = 0; opt_value_index < strlen(opt_value); opt_value_index++ ){

					}
				}
			}
	}

}
void ReadINIFromFile(const char* file_path){

}
