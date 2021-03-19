#pragma once
typedef void (Render_Func)();
typedef void (Rerender_Func)();
void Render(Render_Func* render);
void Rerender(Rerender_Func* rerender);