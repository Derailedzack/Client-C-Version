#include "Script.h"

void Create_Interperter(Create_Interperter_Func* create_interperter)
{
	(create_interperter)();
}

//void Register_C_Functions(Register_C_functions_Func* register_c_functions)
//{
	//(register_c_functions)();
//}

void Run_Script(Run_Script_Func* run_script)
{
	(run_script)("");
}

void Run_File(Run_File_Func* run_file)
{
	(run_file)("");
}
const char* GetScriptTypeFromEnum(SCRIPT_TYPE script_type){
    switch(script_type){
    case LUA:
        return "lua";
        break;
    case RUBY:
        return "ruby";
        break;
    case PYTHON:
        return "python";
        break;
    case GO:
        return "GO";
        break;
    case SQURRIEL:
        return "squrriel";
        break;
    case CUSTOM_SCRIPT:
        return "custom_script";
        break;
    case NONE:
        return "none";
        break;
    }
}
