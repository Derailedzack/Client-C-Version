#pragma once
typedef void (OnDeath_func)();
//typedef void (OnDeath_Debug_func)();
typedef void (OnInvaild_func)();
typedef void (OnRedraw_Failure_func)();
void OnDeath(OnDeath_func* ondeath_func);
void OnRedraw_Failure(OnRedraw_Failure_func* onredraw_failure_func);