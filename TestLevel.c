#include"TestLevel.h"
//void CreateLevel(){

	//data->level_data = level_data;

//}
const char* level_data[] = {"T","T","T","T","0","0","T","T","T","T"};
const char* test = "T";
const char* LoadLevel(){
	//for(int i = 0; i < 90; i++){
	//	assert(strstr(level_data[i],"T") == "TRE");
	for(int i = 0; i < strlen(level_data); i++){
        if(strcmp(level_data[i],test) != NULL ){
          	printf("SOLID");
			return "SOLID";
        }else{
            printf("Test!");
            return "Test";
        }
	}

		//if(strcmp(level_data, test) != NULL ){
		//printf("%s",strchr(level_data,'T'));


		//if(strcmp(level_data[i],'0')  != 0 ){
			//		printf("BLANK");
				//	return "BLANK";
				//}
	//}

	//}
}
