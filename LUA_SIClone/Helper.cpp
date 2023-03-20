#include <assert.h>
#include <iostream>

#include "Helper.h"
using namespace std;

//Week4 calling c++ functions from Lua

std::map<string, Dispatcher::Command> Dispatcher::library;

int Dispatcher::LuaCall(lua_State* L)
{
	string name = lua_tostring(L, 1);
	std::map<string, Command>::iterator it = library.find(name);
	assert(it != library.end());
	Command& cmd = (*it).second;
	if (cmd.voidintfunct)
	{
		int param = lua_tointeger(L, 2);
		cmd.voidintfunct(param);
		lua_pop(L, 1);
	}
	else //add any more cases here
		assert(false);
	return 1;
}

bool LuaOK(lua_State* L, int id) {
	if (id != LUA_OK)
	{
		cout << lua_tostring(L, -1) << endl; //print out the error
		return false;
	}
	return true;
}

int LuaGetInt(lua_State* L, const std::string& name) {
	lua_getglobal(L, name.c_str());
	if (!lua_isinteger(L, -1))
			assert(false);
	return (int)lua_tointeger(L, -1);
}

string LuaGetStr(lua_State* L, const std::string& name) {
	lua_getglobal(L, name.c_str());
	if (!lua_isstring(L, -1))
		assert(false);
	return lua_tostring(L, -1);
}

//Week3 random number generator
int CallRandomNumber(lua_State* L, const string& fname)
{
	lua_getglobal(L, fname.c_str());
	if (!lua_isfunction(L, -1))
		assert(false);
	if (!LuaOK(L, lua_pcall(L, 0, 1, 0)))//calls a function in protected mode. (state, number of parameters, number of values, errorfunc)
		assert(false);
	return (int)lua_tointeger(L, -1);
}

void CallmoveLeft(lua_State* L, const std::string& fname, float& xVal, float& frameVal, float& flag)
{
	lua_getglobal(L, fname.c_str());
	if (!lua_isfunction(L, -1))
		assert(false);
	lua_pushnumber(L, xVal);
	lua_pushnumber(L, frameVal);
	lua_pushnumber(L, flag);
	if (!LuaOK(L, lua_pcall(L, 3, 3, 0)))// calls a function in protected mode. (state, number of parameters, nubrs of return values, errorfunc)
		assert(false);
	xVal = (float)lua_tonumber(L, -3);
	frameVal = (float)lua_tonumber(L, -2);
	flag = (float)lua_tonumber(L, -1);
}

void CallmoveRight(lua_State* L, const std::string& fname, float& xVal, float& frameVal)
{
	lua_getglobal(L, fname.c_str());
	if (!lua_isfunction(L, -1))
		assert(false);
	lua_pushnumber(L, xVal);
	lua_pushnumber(L, frameVal);
	if (!LuaOK(L, lua_pcall(L, 2, 2, 0)))// calls a function in protected mode. (state, number of parameters, nubrs of return values, errorfunc)
		assert(false);
	xVal = (float)lua_tonumber(L, -2);
		frameVal = (float)lua_tonumber(L, -1);
}

void CallUFOmoveLeft(lua_State* L, const std::string& fname, float& xVal, float& frameVal, float& flag)
{
	lua_getglobal(L, fname.c_str());
	if (!lua_isfunction(L, -1))
		assert(false);
	lua_pushnumber(L, xVal);
	lua_pushnumber(L, frameVal);
	lua_pushnumber(L, flag);
	if (!LuaOK(L, lua_pcall(L, 3, 3, 0)))// calls a function in protected mode. (state, number of parameters, nubrs of return values, errorfunc)
		assert(false);
	xVal = (float)lua_tonumber(L, -3);
	frameVal = (float)lua_tonumber(L, -2);
	flag = (float)lua_tonumber(L, -1);
}

void CallUFOmoveRight(lua_State* L, const std::string& fname, float& xVal, float& frameVal, float& flag)
{
	lua_getglobal(L, fname.c_str());
	if (!lua_isfunction(L, -1))
		assert(false);
	lua_pushnumber(L, xVal);
	lua_pushnumber(L, frameVal);
	if (!LuaOK(L, lua_pcall(L, 3, 3, 0)))// calls a function in protected mode. (state, number of parameters, nubrs of return values, errorfunc)
		assert(false);
	xVal = (float)lua_tonumber(L, -2);
	frameVal = (float)lua_tonumber(L, -1);
}

void CallVoidVoidCFunc(lua_State* L, const std::string& fname)//wk4 pt1
{
	lua_getglobal(L, fname.c_str());
	if (!lua_isfunction(L, -1))
		assert(false);
	if (!LuaOK(L, lua_pcall(L, 0, 0, 0)))
		assert(false);
}