/*Lua helper which links lua with c++*/
//WEEK 1
#pragma once

#include <string>
#include <functional>
#include <map>

extern "C"
{
#include "../lua-5.4.4/include/lua.h"
#include "../lua-5.4.4/include/lauxlib.h"
#include "../lua-5.4.4/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "../lua-5.4.4/liblua54.a")
#endif // _WIN32

//check for errors
bool LuaOK(lua_State* L, int id);

//get an int from lua
int LuaGetInt(lua_State* L, const std::string& name);

//get a string from lua
std::string LuaGetStr(lua_State* L, const std::string& name);

struct Vector2
{
	int x, y;

	void FromLua(lua_State* L, const std::string& name) {
		lua_getglobal(L, name.c_str());
		if (!lua_istable(L, -1))
			assert(false);

		lua_pushstring(L, "x");
		lua_gettable(L, -2);//pops x off and replaces it with the value, so pop the value off when you've got it 
			x = (int)lua_tointeger(L, -1); //got the alue
		lua_pop(L, 1);

		lua_pushstring(L, "y");
		lua_gettable(L, -2);
		y = (int)lua_tointeger(L, -1);
		lua_pop(L, 1);
	}
};

class Dispatcher 
{
public:
	//capture game functions here
	struct Command 
	{
		typedef std::function<void(int)> voidintfunc; // a function which returns nothing and takes an int
		voidintfunc voidintfunct;
		//add any other function signatures here
	};
	// call once at start
	void Init(lua_State* L)
	{
		lua_register(L, "CDispatcher", LuaCall);
	}
	//register game functions
	void Register(const std::string& name, Command cmd)
	{
		if(library.find(name) == library.end())
		library[name] = cmd;
	}
	//lua calls this then the data gets dispatched to the named function
	//lua is old school C based, so cannot call class member functions without help
	static int LuaCall(lua_State* L);
private:
	static std::map<std::string, Command> library; //this is where the game functions are stored
};

//Week 3 calling LUA functions
int CallRandomNumber(lua_State* L, const std::string& fname);
void CallmoveLeft(lua_State* L, const std::string& fname, float& xVal, float& frameVal, float& flag);
void CallmoveRight(lua_State* L, const std::string& fname, float& xVal, float& frameVal);
void CallUFOmoveLeft(lua_State* L, const std::string& fname, float& xVal, float& frameVal, float& flag);
void CallUFOmoveRight(lua_State* L, const std::string& fname, float& xVal, float& frameVal, float& flag);
void CallVoidVoidCFunc(lua_State* L, const std::string& fname);
