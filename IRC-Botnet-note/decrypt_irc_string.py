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
 
    
def decrypt_all_str(start,end):
    while start <= end:
        text = get_str(start)
        if  text =='':
            start = idc.next_addr(start)
        else:
            print("0x%x  %s"%(start,text))
            start +=len(text)
start = 0x4053A4
end = 0x405A74
decrypt_all_str(start,end)
        



