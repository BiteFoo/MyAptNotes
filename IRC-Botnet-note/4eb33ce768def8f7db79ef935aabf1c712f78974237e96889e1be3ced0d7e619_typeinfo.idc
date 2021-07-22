//
// +-------------------------------------------------------------------------+
// |      This file was generated by The Interactive Disassembler (IDA)      |
// |           Copyright (c) 2020 Hex-Rays, <support@hex-rays.com>           |
// +-------------------------------------------------------------------------+
//
//
//      This file contains the user-defined type definitions.
//      To use it press F2 in IDA and enter the name of this file.
//

#define UNLOADED_FILE   1
#include <idc.idc>

static main(void)
{
        Enums();              // enumerations
        Structures();         // structure types
        ApplyStrucTInfos();
	set_inf_attr(INF_LOW_OFF, 0x401000);
	set_inf_attr(INF_HIGH_OFF, 0x406000);
}

//------------------------------------------------------------------------
// Information about enum types

static Enums(void) {
        auto id;
        begin_type_updating(UTP_ENUM);
        end_type_updating(UTP_ENUM);
}

static ApplyStrucTInfos_0(void) {
        auto id;
	id = get_struc_id("_LUID");
	SetType(get_member_id(id, 0x0), "DWORD");
	SetType(get_member_id(id, 0x4), "LONG");
	id = get_struc_id("_TOKEN_PRIVILEGES");
	SetType(get_member_id(id, 0x0), "DWORD");
	SetType(get_member_id(id, 0x4), "LUID_AND_ATTRIBUTES[1]");
	id = get_struc_id("LUID_AND_ATTRIBUTES");
	SetType(get_member_id(id, 0x0), "LUID");
	SetType(get_member_id(id, 0x8), "DWORD");
	id = get_struc_id("LUID");
	SetType(get_member_id(id, 0x0), "DWORD");
	SetType(get_member_id(id, 0x4), "LONG");
	id = get_struc_id("InjectParam");
	SetType(get_member_id(id, 0x0), "struct api_table *");
	SetType(get_member_id(id, 0x4), "struct FnTable *");
	SetType(get_member_id(id, 0x8), "void *");
	SetType(get_member_id(id, 0xC), "char **");
	SetType(get_member_id(id, 0x10), "char **");
	id = get_struc_id("FnTable");
	SetType(get_member_id(id, 0x0), "void *");
	SetType(get_member_id(id, 0x4), "void *");
	SetType(get_member_id(id, 0x8), "void *");
	SetType(get_member_id(id, 0xC), "void *");
	SetType(get_member_id(id, 0x10), "void *");
	id = get_struc_id("api_table");
	SetType(get_member_id(id, 0x0), "int");
	SetType(get_member_id(id, 0x4), "int");
	SetType(get_member_id(id, 0x8), "int");
	SetType(get_member_id(id, 0xC), "int");
	SetType(get_member_id(id, 0x10), "int");
	SetType(get_member_id(id, 0x14), "int");
	SetType(get_member_id(id, 0x18), "int");
	SetType(get_member_id(id, 0x1C), "int");
	SetType(get_member_id(id, 0x20), "int");
	SetType(get_member_id(id, 0x24), "int");
	SetType(get_member_id(id, 0x28), "int");
	SetType(get_member_id(id, 0x2C), "int");
	SetType(get_member_id(id, 0x30), "int");
	SetType(get_member_id(id, 0x34), "int");
	SetType(get_member_id(id, 0x38), "int");
	SetType(get_member_id(id, 0x3C), "int");
	SetType(get_member_id(id, 0x40), "int");
	SetType(get_member_id(id, 0x44), "int");
	SetType(get_member_id(id, 0x48), "int");
	SetType(get_member_id(id, 0x4C), "int");
	SetType(get_member_id(id, 0x50), "int");
	SetType(get_member_id(id, 0x54), "int");
	SetType(get_member_id(id, 0x58), "int");
	SetType(get_member_id(id, 0x5C), "int");
	SetType(get_member_id(id, 0x60), "int");
	SetType(get_member_id(id, 0x64), "int");
	SetType(get_member_id(id, 0x68), "int");
	SetType(get_member_id(id, 0x6C), "int");
	SetType(get_member_id(id, 0x70), "int");
	SetType(get_member_id(id, 0x74), "int");
	SetType(get_member_id(id, 0x78), "int");
	SetType(get_member_id(id, 0x7C), "int");
	SetType(get_member_id(id, 0x80), "int");
	SetType(get_member_id(id, 0x84), "int");
	SetType(get_member_id(id, 0x88), "int");
	SetType(get_member_id(id, 0x8C), "int");
	SetType(get_member_id(id, 0x90), "int");
	SetType(get_member_id(id, 0x94), "int");
	SetType(get_member_id(id, 0x98), "int");
	SetType(get_member_id(id, 0x9C), "int");
	SetType(get_member_id(id, 0xA0), "int");
	SetType(get_member_id(id, 0xA4), "int");
	SetType(get_member_id(id, 0xA8), "int");
	SetType(get_member_id(id, 0xAC), "int");
	SetType(get_member_id(id, 0xB0), "int");
	SetType(get_member_id(id, 0xB4), "struct FnTable");
	SetType(get_member_id(id, 0xC8), "HMODULE");
	SetType(get_member_id(id, 0xCC), "int");
	SetType(get_member_id(id, 0xD0), "char[4]");
	SetType(get_member_id(id, 0xD4), "int");
	SetType(get_member_id(id, 0xD8), "int");
	SetType(get_member_id(id, 0xDC), "int");
	SetType(get_member_id(id, 0xE0), "HMODULE");
	SetType(get_member_id(id, 0xE4), "HMODULE");
	return id;
}

//------------------------------------------------------------------------
// Information about type information for structure members

static ApplyStrucTInfos() {
	ApplyStrucTInfos_0();
}

static Structures_0(id) {
        auto mid;

	id = add_struc(-1,"_LUID",0);
	id = add_struc(-1,"_TOKEN_PRIVILEGES",0);
	id = add_struc(-1,"LUID_AND_ATTRIBUTES",0);
	id = add_struc(-1,"LUID",0);
	id = add_struc(-1,"InjectParam",0);
	id = add_struc(-1,"FnTable",0);
	id = add_struc(-1,"api_table",0);
	
	id = get_struc_id("_LUID");
	mid = add_struc_member(id,"LowPart",	0,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"HighPart",	0X4,	0x20000400,	-1,	4);
	set_struc_align(id,2);
	
	id = get_struc_id("LUID");
	mid = add_struc_member(id,"LowPart",	0,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"HighPart",	0X4,	0x20000400,	-1,	4);
	set_struc_align(id,2);
	
	id = get_struc_id("LUID_AND_ATTRIBUTES");
	mid = add_struc_member(id,"Luid",	0,	0x60000400,	get_struc_id("LUID"),	8);
	mid = add_struc_member(id,"Attributes",	0X8,	0x20000400,	-1,	4);
	set_struc_align(id,2);
	
	id = get_struc_id("_TOKEN_PRIVILEGES");
	mid = add_struc_member(id,"PrivilegeCount",	0,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"Privileges",	0X4,	0x60000400,	get_struc_id("LUID_AND_ATTRIBUTES"),	12);
	set_struc_align(id,2);
	
	id = get_struc_id("InjectParam");
	mid = add_struc_member(id,"papi_table",	0,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"pFnTable",	0X4,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"p3",	0X8,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"str1",	0XC,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"str2",	0X10,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	set_struc_align(id,2);
	
	id = get_struc_id("FnTable");
	mid = add_struc_member(id,"p1",	0,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"p2",	0X4,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"p3",	0X8,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"p4",	0XC,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"p5",	0X10,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	set_struc_align(id,2);
	
	id = get_struc_id("api_table");
	mid = add_struc_member(id,"WaitForSingleObject",	0,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"CreateMutexA",	0X4,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"CreateThread",	0X8,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"ExitThread",	0XC,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"Sleep",	0X10,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"GetTickCount",	0X14,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"CreateFileA",	0X18,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"WriteFile",	0X1C,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"var_C8",	0X20,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"CreateProcessA",	0X24,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"GetLogicalDriveStringsA",	0X28,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"GetDriveTypeA",	0X2C,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"CreateDirectoryA",	0X30,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"GetLastError",	0X34,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"CopyFileA",	0X38,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"DeleteFileA",	0X3C,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"lstrlen",	0X40,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"lstrcat",	0X44,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"var_A0",	0X48,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"lstrcmpi",	0X4C,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"lstrcpyn",	0X50,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"WSAStartup",	0X54,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"socket",	0X58,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"connect",	0X5C,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"inet_addr",	0X60,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"htons",	0X64,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"send",	0X68,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"recv",	0X6C,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"closesocket",	0X70,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"gethostbyname",	0X74,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"sendto",	0X78,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"WSASocketA",	0X7C,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"htonl",	0X80,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"setsockopt",	0X84,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"InternetOpenA_",	0X88,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"InternetOpenUrlA",	0X8C,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"InternetReadFile",	0X90,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"InternetCloseHandle",	0X94,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"ShellExecuteA",	0X98,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"RegCloseKey",	0X9C,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"RegCloseKey_",	0XA0,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"RegCreateKeyExA",	0XA4,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"RegDeleteKeyA",	0XA8,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"RegDeleteValueA",	0XAC,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"var_38",	0XB0,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"var_fn_tbl",	0XB4,	0x60000400,	get_struc_id("FnTable"),	20);
	mid = add_struc_member(id,"ShellExecuteA_",	0XC8,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"var_1C",	0XCC,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"var_18",	0XD0,	0x000400,	-1,	4);
	mid = add_struc_member(id,"VirtualAllocEx",	0XD4,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"var_10",	0XD8,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"ZwWriteVirtualMemory",	0XDC,	0x20000400,	-1,	4);
	mid = add_struc_member(id,"hModule",	0XE0,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	mid = add_struc_member(id,"InternetOpenA",	0XE4,	0x25500400,	0XFFFFFFFF,	4,	0XFFFFFFFF,	0,	0x000002);
	set_struc_align(id,2);
	return id;
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
        begin_type_updating(UTP_STRUCT);
	id = Structures_0(id);
        end_type_updating(UTP_STRUCT);
}

// End of file.
