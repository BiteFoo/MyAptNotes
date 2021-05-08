import binascii
import idaapi
import idautils
import idc

#data = binascii.unhexlify("cbc5d2cec5cc93928ec4cccc")


def decrypt(data):
    key = 'I0L0v3Y0u0V1rUs'
    
    text =  ''
    for d in data:
        for k in key:
            d = d ^ ord(k)
        d = ~d & 0xff
        text +=chr(d)
    return text
    
def get_str(ea):
    bs = []
    for _ in range(500):
        b = idc.get_wide_byte(ea)
        if b == 0:
            break
        bs.append(b)
        ea +=1
    return  decrypt(bs)
 
 
def is_ascii(s):
    return all(ord(c) < 128 for c in s)

def replace_str(ea,new_str):
    base = ea
    for s in new_str:
        idc.patch_byte(ea,ord(s))
        ea+=1
    idc.create_strlit(base,idc.BADADDR)
    print("patched: 0x%x %s"%(base,new_str))
 
    
def decrypt_all_str(start,end):
    while start <= end:
        text = get_str(start)
        if  text =='':
            start = idc.next_addr(start)
        else:
            #print("0x%x  %s"%(start,text))
            if is_ascii(text):
                replace_str(start, text)
            start +=len(text)
start = 0x4053A4
end = 0x405A74
decrypt_all_str(start,end)
        



