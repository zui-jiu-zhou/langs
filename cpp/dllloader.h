#pragma once
#ifndef _DLLLOADER_H_
#define _DLLLOADER_H_

#ifdef _MSC_VER
#include <windows.h>
#define LOAD_DLL( dll ) LoadLibrary( L#dll )
#define GET_MEMBER( handle, name ) GetProcAddress(handle, #name)
#define UNLOAD_DLL( handle ) FreeLibrary( handle )
#else
#include <dlfcn.h>
#define LOAD_DLL( dll ) dlopen( #dll, RTLD_LAZY)
#define GET_MEMBER(handle, name) dlsym(handle, #name)
#define UNLOAD_DLL( handle ) dlclose( handle )
#endif
#endif

