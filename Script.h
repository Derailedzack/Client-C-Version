#pragma once
typedef void (Create_Interperter_Func)();
typedef void (Register_C_functions_Func)();
typedef void (Run_Script_Func)(const char* script_code);
typedef void (Run_File_Func)(const char* script_path);
typedef enum SCRIPT_TYPE{
    LUA,
    RUBY,
    PYTHON,
    GO,
    SQURRIEL,
    CUSTOM_SCRIPT,
    NONE

}SCRIPT_TYPE;

void Create_Interperter(Create_Interperter_Func* create_interperter);
//void Register_C_Functions(Register_C_functions_Func* register_c_functions);
void Run_Script(Run_Script_Func* run_script);
void Run_File(Run_File_Func* run_file);
const char* GetScriptTypeFromEnum(SCRIPT_TYPE script_type);
