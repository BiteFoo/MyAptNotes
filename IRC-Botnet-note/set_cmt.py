"""
get comment string
"""
import idc
import idautils
import idaapi

ea = 0x402848

#fnc = idaapi.get_func(ea)

print("0x%x %s "%(start,idc.get_func_name(ea)))


def set_hexray_cmmts(ea,text):
    cfunc = idaapi.decompile(ea)
    tl = idaapi.treeloc_t()
    tl.ea = ea
    tl.itp = idaapi.ITP_SEMI
    cfunc.set_user_cmt(tl,text)
    cfunc.save_user_cmts()

def set_cmmts(ea,text):
    idc.set_cmt(ea,text,0)
    set_hexray_cmmts(ea,text)

def get_cmmt(ea,offset):
    addr = idc.get_wide_word(offset)+0x400000
    text = idc.get_strlit_contents(addr)
    if text is not None:
        text = str(text,encoding="utf-8")
        print("0x%x %s  addr:0x%x "%(offset,text,addr))
        set_cmmts(ea,text)
    

def cmmt_func(start):
    ea_start = idc.get_func_attr(start,FUNCATTR_START)
    ea_end = idc.get_func_attr(start,FUNCATTR_END)
    while ea_start<=  end:
        mnem = idc.print_insn_mnem(ea_start)
        ins = idc.generate_disasm_line(ea_start,0)
        offset = idc.get_operand_value(ea_start,0)
        tp = idc.get_operand_type(ea_start,0)
        op2 = idc.print_operand(ea_start,0)
     
        if tp == o_mem and op2.startswith('off_') and mnem == 'push' :
            print('0x%x  %s  0x%x '%(ea_start,ins,offset))
            get_cmmt(ea_start,offset)
        ea_start = idc.next_head(ea_start,ea_end)
        

cmmt_func(ea)
#get_cmmt(0x4028A7,0x405038)
