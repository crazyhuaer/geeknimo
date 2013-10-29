#ifndef _OS_UTILS_H_
#define _OS_UTILS_H_


#ifdef __cplusplus
extern "C" {
#endif

/*
从XML字符串中获取一个标签内的字符串，譬如:

in_xml指针指向:
<a>
	<b>xxx</b>
</a>

如果调用get_xml_node_str(xmlbuf,"a",outbuf,20); 最后返回的是<b>xxx</b>
如果调用get_xml_node_str(xmlbuf,"b",outbuf,20); 最后返回的是xxx

参数说明:
in_xml  -- 输入xml指针，注意可以是xml中间一段，不一定要完整的xml
node    -- xml node名称，不能超过56字节，不包括前后的<>，而且要求前后<>之间不能有空格
out_buf -- 输出buf
len       -- 输出buf长度
p_tail   -- 最后完成分析时指针位置。可用用作下一次的查找

函数优缺点说明:
这个函数很适合简单而且效率高。适合符合一定规则的内部xml通信的
分析和解析

注意:   node name的长度最多不得超过56字节
*/
int os_get_xml_node_value(char * in_xml,char *node,char *out_buf,int len, char ** p_tail);


//获取输入指针开始的第一个节点名，并返回指针指向结点尾
// 注意: 这里获取的xml里面不能有注释，有注释的话可能会出错
int os_get_xml_node_name(char * in_xml,char *node_name,int len, char ** p_tail);

#ifdef __cplusplus
}
#endif

#endif


